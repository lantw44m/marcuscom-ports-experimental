--- libmediaart/cache.c.org	2014-03-16 11:53:11.915202364 +0000
+++ libmediaart/cache.c	2014-03-16 11:54:55.221194135 +0000
@@ -410,7 +410,7 @@
 	gchar *target = NULL;
 	gchar *album_path = NULL;
 
-	g_return_if_fail (artist != NULL && artist[0] != '\0');
+	g_return_val_if_fail (artist != NULL && artist[0] != '\0', FALSE);
 
 	dirname = g_build_filename (g_get_user_cache_dir (), "media-art", NULL);
 
