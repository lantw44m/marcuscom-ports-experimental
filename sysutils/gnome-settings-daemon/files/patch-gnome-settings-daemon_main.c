From bd693987ec67cdb997db325d18d15f4e356a1428 Mon Sep 17 00:00:00 2001
From: Rui Matos <tiagomatos@gmail.com>
Date: Wed, 26 Mar 2014 15:52:17 +0100
Subject: [PATCH] main: Unown our DBus name when gnome-session says "Stop"

We don't want to quit yet because if we do, gnome-shell and still
mapped windows lose their theme and icons. But we have to unown our
DBus name otherwise gnome-session will hang waiting for us.

https://bugzilla.gnome.org/show_bug.cgi?id=727049
---
 gnome-settings-daemon/main.c | 19 +++++++++++++++++++
 1 file changed, 19 insertions(+)

diff --git a/gnome-settings-daemon/main.c b/gnome-settings-daemon/main.c
index 748a33c..4e99a97 100644
--- a/gnome-settings-daemon/main.c
+++ b/gnome-settings-daemon/main.c
@@ -45,6 +45,7 @@
 static gboolean   replace      = FALSE;
 static gboolean   debug        = FALSE;
 static gboolean   do_timed_exit = FALSE;
+static gboolean   ignore_name_lost = FALSE;
 static guint      name_id      = 0;
 static GnomeSettingsManager *manager = NULL;
 
@@ -75,6 +76,18 @@ respond_to_end_session (GDBusProxy *proxy)
 }
 
 static void
+do_stop (void)
+{
+        /* We don't want to quit yet because if we do, gnome-shell
+         * and still mapped windows lose their theme and icons. But
+         * we have to unown our DBus name otherwise gnome-session
+         * will hang waiting for us. */
+        ignore_name_lost = TRUE;
+        g_bus_unown_name (name_id);
+        name_id = 0;
+}
+
+static void
 client_proxy_signal_cb (GDBusProxy *proxy,
                         gchar *sender_name,
                         gchar *signal_name,
@@ -87,6 +100,9 @@ client_proxy_signal_cb (GDBusProxy *proxy,
         } else if (g_strcmp0 (signal_name, "EndSession") == 0) {
                 g_debug ("Got EndSession signal");
                 respond_to_end_session (proxy);
+        } else if (g_strcmp0 (signal_name, "Stop") == 0) {
+                g_debug ("Got Stop signal");
+                do_stop ();
         }
 }
 
@@ -307,6 +323,9 @@ name_lost_handler (GDBusConnection *connection,
                    const gchar *name,
                    gpointer user_data)
 {
+        if (ignore_name_lost)
+                return;
+
         /* Name was already taken, or the bus went away */
 
         g_warning ("Name taken or bus went away - shutting down");
-- 
1.9.0
