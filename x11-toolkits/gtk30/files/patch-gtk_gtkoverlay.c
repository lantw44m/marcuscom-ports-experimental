--- gtk/gtkoverlay.c.orig	2014-04-05 22:02:00.377874498 +0000
+++ gtk/gtkoverlay.c	2014-04-05 22:03:15.223868654 +0000
@@ -206,13 +206,20 @@
       main_alloc.width = gtk_widget_get_allocated_width (grandchild);
       main_alloc.height = gtk_widget_get_allocated_height (grandchild);
     }
-  else
+  else if (GTK_IS_WIDGET (main_widget))
     {
       main_alloc.x = 0;
       main_alloc.y = 0;
       main_alloc.width = gtk_widget_get_allocated_width (main_widget);
       main_alloc.height = gtk_widget_get_allocated_height (main_widget);
     }
+  else
+    {
+      main_alloc.x = 0;
+      main_alloc.y = 0;
+      main_alloc.width = 1;
+      main_alloc.height = 1;
+ }
 
   if (main_alloc_out)
     *main_alloc_out = main_alloc;
