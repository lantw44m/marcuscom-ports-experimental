From 858ef953928933d516a90b30873eea5d8f1d452b Mon Sep 17 00:00:00 2001
From: Ryan Lortie <desrt@desrt.ca>
Date: Wed, 26 Mar 2014 12:04:14 -0400
Subject: [PATCH] Don't disable ConsoleKit with new upower

ConsoleKit is still useful, even if we can't suspend/hibernate using
upower anymore.  Don't disable the whole thing.

https://bugzilla.gnome.org/show_bug.cgi?id=727099


diff -u -r gnome-session/Makefile.am gnome-session/Makefile.am
--- gnome-session/Makefile.am	2014-03-26 12:12:00.000000000 -0400
+++ gnome-session/Makefile.am	2014-03-26 12:12:14.000000000 -0400
@@ -59,9 +59,7 @@
 	gsm-xsmp-server.c			\
 	gsm-xsmp-server.h
 
-if HAVE_OLD_UPOWER
 gnome_session_SOURCES += gsm-consolekit.c gsm-consolekit.h
-endif
 
 gnome_session_CPPFLAGS =			\
 	$(AM_CPPFLAGS)				\
diff -u -r gnome-session/Makefile.in gnome-session/Makefile.in
--- gnome-session/Makefile.in	2014-03-26 12:12:00.000000000 -0400
+++ gnome-session/Makefile.in	2014-03-26 12:12:38.000000000 -0400
@@ -83,7 +83,7 @@
 libexec_PROGRAMS = gnome-session-failed$(EXEEXT)
 noinst_PROGRAMS = test-client-dbus$(EXEEXT) test-inhibit$(EXEEXT) \
 	test-process-helper$(EXEEXT)
-@HAVE_OLD_UPOWER_TRUE@am__append_1 = gsm-consolekit.c gsm-consolekit.h
+am__append_1 = gsm-consolekit.c gsm-consolekit.h
 subdir = gnome-session
 DIST_COMMON = $(srcdir)/Makefile.in $(srcdir)/Makefile.am \
 	$(top_srcdir)/depcomp README
@@ -125,8 +125,8 @@
 	gsm-shell-extensions.h gsm-shell.c gsm-shell.h \
 	gsm-xsmp-server.c gsm-xsmp-server.h gsm-consolekit.c \
 	gsm-consolekit.h
-@HAVE_OLD_UPOWER_TRUE@am__objects_1 =  \
-@HAVE_OLD_UPOWER_TRUE@	gnome_session-gsm-consolekit.$(OBJEXT)
+am__objects_1 =  \
+	gnome_session-gsm-consolekit.$(OBJEXT)
 am_gnome_session_OBJECTS = gnome_session-gsm-app.$(OBJEXT) \
 	gnome_session-gsm-autostart-app.$(OBJEXT) \
 	gnome_session-gsm-client.$(OBJEXT) \
diff -u -r gnome-session/gsm-consolekit.c gnome-session/gsm-consolekit.c
--- gnome-session/gsm-consolekit.c	2014-03-26 12:12:00.000000000 -0400
+++ gnome-session/gsm-consolekit.c	2014-03-26 12:12:14.000000000 -0400
@@ -29,8 +29,10 @@
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
+#ifdef HAVE_OLD_UPOWER
 #define UPOWER_ENABLE_DEPRECATED 1
 #include <upower.h>
+#endif
 
 #include "gsm-system.h"
 #include "gsm-consolekit.h"
@@ -54,7 +56,9 @@
         DBusGProxy      *bus_proxy;
         DBusGProxy      *ck_proxy;
         DBusGProxy      *session_proxy;
+#ifdef HAVE_OLD_UPOWER
         UpClient        *up_client;
+#endif
 
         gboolean         is_active;
         gboolean         restarting;
@@ -304,8 +308,10 @@
                                              G_CALLBACK (on_active_changed), manager, NULL);
         }
 
+#ifdef HAVE_OLD_UPOWER
         g_clear_object (&manager->priv->up_client);
         manager->priv->up_client = up_client_new ();
+#endif
 
         is_connected = TRUE;
 
@@ -382,7 +388,9 @@
         g_clear_object (&manager->priv->ck_proxy);
         g_clear_object (&manager->priv->session_proxy);
         g_clear_object (&manager->priv->session_id);
+#ifdef HAVE_OLD_UPOWER
         g_clear_object (&manager->priv->up_client);
+#endif
 
         if (manager->priv->dbus_connection != NULL) {
                 DBusConnection *connection;
@@ -951,7 +959,11 @@
 {
         GsmConsolekit *consolekit = GSM_CONSOLEKIT (system);
 
+#ifdef HAVE_OLD_UPOWER
         return up_client_get_can_suspend (consolekit->priv->up_client);
+#else
+        return FALSE;
+#endif
 }
 
 static gboolean
@@ -959,12 +971,17 @@
 {
         GsmConsolekit *consolekit = GSM_CONSOLEKIT (system);
 
+#ifdef HAVE_OLD_UPOWER
         return up_client_get_can_hibernate (consolekit->priv->up_client);
+#else
+        return FALSE;
+#endif
 }
 
 static void
 gsm_consolekit_suspend (GsmSystem *system)
 {
+#ifdef HAVE_OLD_UPOWER
         GsmConsolekit *consolekit = GSM_CONSOLEKIT (system);
         GError *error = NULL;
         gboolean ret;
@@ -974,11 +991,13 @@
                 g_warning ("Unexpected suspend failure: %s", error->message);
                 g_error_free (error);
         }
+#endif
 }
 
 static void
 gsm_consolekit_hibernate (GsmSystem *system)
 {
+#ifdef HAVE_OLD_UPOWER
         GsmConsolekit *consolekit = GSM_CONSOLEKIT (system);
         GError *error = NULL;
         gboolean ret;
@@ -988,6 +1007,7 @@
                 g_warning ("Unexpected hibernate failure: %s", error->message);
                 g_error_free (error);
         }
+#endif
 }
 
 static void
diff -u -r gnome-session/gsm-system.c gnome-session/gsm-system.c
--- gnome-session/gsm-system.c	2014-03-26 12:12:00.000000000 -0400
+++ gnome-session/gsm-system.c	2014-03-26 12:14:29.000000000 -0400
@@ -22,9 +22,7 @@
 #include <glib/gi18n.h>
 
 #include "gsm-system.h"
-#ifdef HAVE_OLD_UPOWER
 #include "gsm-consolekit.h"
-#endif
 #include "gsm-systemd.h"
 
 enum {
@@ -254,14 +252,13 @@
                         g_debug ("Using systemd for session tracking");
                 }
         }
-#ifdef HAVE_OLD_UPOWER
+
         if (system == NULL) {
                 system = GSM_SYSTEM (gsm_consolekit_new ());
                 if (system != NULL) {
                         g_debug ("Using ConsoleKit for session tracking");
                 }
         }
-#endif
 
         if (system == NULL) {
                 system = g_object_new (gsm_system_null_get_type (), NULL);
