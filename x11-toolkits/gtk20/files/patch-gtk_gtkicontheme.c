--- gtk/gtkicontheme.c.orig	Wed Aug 18 11:45:13 2004
+++ gtk/gtkicontheme.c	Wed Aug 25 12:50:40 2004
@@ -544,6 +544,8 @@
   i = 0;
   priv->search_path[i++] = g_build_filename (g_get_home_dir (), ".icons", NULL);
   priv->search_path[i++] = g_build_filename (g_get_user_data_dir (), "icons", NULL);
+  priv->search_path[i++] = g_build_filename (g_get_user_data_dir (), "gnome", "pixmaps", NULL);
+  priv->search_path[i++] = g_build_filename (g_get_user_data_dir (), "gnome", "icons", NULL);
   
   for (j = 0; xdg_data_dirs[j]; j++) 
     priv->search_path[i++] = g_build_filename (xdg_data_dirs[j], "icons", NULL);
