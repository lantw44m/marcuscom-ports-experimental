--- gtk/gtkicontheme.c.orig	Wed Aug 18 11:45:13 2004
+++ gtk/gtkicontheme.c	Sat Sep  4 16:26:21 2004
@@ -537,7 +537,7 @@
   xdg_data_dirs = g_get_system_data_dirs ();
   for (i = 0; xdg_data_dirs[i]; i++) ;
 
-  priv->search_path_len = i + 3;
+  priv->search_path_len = (i * 2) + 3;
   
   priv->search_path = g_new (char *, priv->search_path_len);
   
@@ -545,8 +545,10 @@
   priv->search_path[i++] = g_build_filename (g_get_home_dir (), ".icons", NULL);
   priv->search_path[i++] = g_build_filename (g_get_user_data_dir (), "icons", NULL);
   
-  for (j = 0; xdg_data_dirs[j]; j++) 
+  for (j = 0; xdg_data_dirs[j]; j++) {
     priv->search_path[i++] = g_build_filename (xdg_data_dirs[j], "icons", NULL);
+    priv->search_path[i++] = g_build_filename (xdg_data_dirs[j], "pixmaps", NULL);
+  }
 
   priv->search_path[i++] = g_strdup ("/usr/share/pixmaps");
 
