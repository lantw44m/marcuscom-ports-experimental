--- src/htmlgdkpainter.c.orig	Thu Sep  2 19:43:58 2004
+++ src/htmlgdkpainter.c	Thu Sep  2 19:44:28 2004
@@ -739,9 +739,10 @@
 item_gc (HTMLPainter *p, PangoItem *item, GdkDrawable *drawable, GdkGC *orig_gc, HTMLPangoProperties *properties, GdkGC **bg_gc)
 {
 	GdkGC *new_gc = NULL;
-	html_pango_get_item_properties (item, properties);
 
 	HTMLEngine *e = GTK_HTML (p->widget)->engine;
+
+	html_pango_get_item_properties (item, properties);
 
 	*bg_gc = NULL;
 
