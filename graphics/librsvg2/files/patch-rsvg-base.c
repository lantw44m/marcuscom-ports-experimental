--- rsvg-base.c.orig	2013-05-11 09:19:07.000000000 +0000
+++ rsvg-base.c	2014-03-10 13:59:00.951409514 +0000
@@ -2191,7 +2191,7 @@
     g_object_unref (base);
 
     /* FIXME portability */
-    cdir = canonicalize_file_name (dir);
+    cdir = realpath(dir, NULL);
     g_free (dir);
     if (cdir == NULL)
         goto deny;
@@ -2201,7 +2201,7 @@
         goto deny;
 
     /* FIXME portability */
-    cpath = canonicalize_file_name (path);
+    cpath = realpath (path, NULL);
     g_free (path);
 
     if (cpath == NULL)
