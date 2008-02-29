--- daemon/gdm-server.c.orig	2007-11-19 22:53:12.000000000 +0100
+++ daemon/gdm-server.c	2007-12-25 11:56:07.000000000 +0100
@@ -44,6 +44,10 @@
 #include "gdm-common.h"
 #include "gdm-signal-handler.h"
 
+#include "gdm-settings.h"
+#include "gdm-settings-direct.h"
+#include "gdm-settings-keys.h"
+
 #include "gdm-server.h"
 
 extern char **environ;
@@ -77,6 +81,7 @@
         char    *parent_display_name;
         char    *parent_auth_file;
         char    *chosen_hostname;
+        char    *vt;
 
         guint    child_watch_id;
 };
@@ -663,7 +668,7 @@
         gboolean res;
 
         /* fork X server process */
-        res = gdm_server_spawn (server, NULL);
+        res = gdm_server_spawn (server, server->priv->vt);
 
         return res;
 }
@@ -890,12 +895,33 @@
 gdm_server_init (GdmServer *server)
 {
 
+        int vt;
+        gboolean has_vt;
+        GdmSettings *settings = NULL;
         server->priv = GDM_SERVER_GET_PRIVATE (server);
 
+
+        settings = gdm_settings_new();
+        if (settings == NULL) {
+                g_assert ("Unable to initialize settings");
+        }
+
+        if (! gdm_settings_direct_init (settings, GDMCONFDIR "/gdm.schemas", "/")) {
+                g_assert ("Unable to initialize settings");
+        }
+
+        has_vt =  gdm_settings_direct_get_int (GDM_KEY_VT, &vt);
+
+        g_object_unref (settings);
+
         server->priv->pid = -1;
         server->priv->command = g_strdup (X_SERVER " -br -verbose");
         server->priv->log_dir = g_strdup (LOGDIR);
 
+        if (has_vt) {
+                server->priv->vt = g_strdup_printf ("vt %d", vt);
+        }
+
         add_ready_handler (server);
 }
 
