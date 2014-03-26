From fb84d220c7105ae74098fa601229ce11680141a7 Mon Sep 17 00:00:00 2001
From: Ryan Lortie <desrt@desrt.ca>
Date: Wed, 26 Mar 2014 10:34:36 -0400
Subject: [PATCH] exit on receipt of Stop signal from gnome-session

gnome-session expects clients to unregister and/or exit upon receipt of
the Stop signal, so make sure we do that.  This prevents the logout
being blocked in cases where the session is not being explicitly managed
from outside (like by consolekit or logind).

https://bugzilla.gnome.org/show_bug.cgi?id=727092
---
 gnome-settings-daemon/main.c | 3 +++
 1 file changed, 3 insertions(+)

diff --git gnome-settings-daemon/main.c.orig gnome-settings-daemon/main.c
index 748a33c..f3a0bb0 100644
--- gnome-settings-daemon/main.c.orig
+++ gnome-settings-daemon/main.c
@@ -87,6 +87,9 @@ client_proxy_signal_cb (GDBusProxy *proxy,
         } else if (g_strcmp0 (signal_name, "EndSession") == 0) {
                 g_debug ("Got EndSession signal");
                 respond_to_end_session (proxy);
+        } else if (g_strcmp0 (signal_name, "Stop") == 0) {
+                g_debug ("Got Stop signal -- exiting");
+                gtk_main_quit ();
         }
 }
 
-- 
1.8.5.3
