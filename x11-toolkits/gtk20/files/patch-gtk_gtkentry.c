--- gtk/gtkentry.c.orig	Sun Aug  8 17:21:07 2004
+++ gtk/gtkentry.c	Sun Aug  8 17:21:49 2004
@@ -1592,9 +1592,10 @@
 				    event->x + entry->scroll_offset, event->y))
 	{
 	  GdkDragContext *context;
+	  guint actions;
 	  GtkTargetList *target_list = gtk_target_list_new (NULL, 0);
 	  gtk_target_list_add_text_targets (target_list);
-	  guint actions = entry->editable ? GDK_ACTION_COPY | GDK_ACTION_MOVE : GDK_ACTION_COPY;
+	  actions = entry->editable ? GDK_ACTION_COPY | GDK_ACTION_MOVE : GDK_ACTION_COPY;
 	  
 	  context = gtk_drag_begin (widget, target_list, actions,
 			  entry->button, (GdkEvent *)event);
