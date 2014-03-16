--- libmediaart/extractdummy.c.orig	2014-03-16 12:29:51.840049649 +0000
+++ libmediaart/extractdummy.c	2014-03-16 12:30:45.751046055 +0000
@@ -23,7 +23,7 @@
 #include "extractgeneric.h"
 
 void
-media_art_plugin_init (void)
+media_art_plugin_init (gint maxwidth)
 {
 }
 
