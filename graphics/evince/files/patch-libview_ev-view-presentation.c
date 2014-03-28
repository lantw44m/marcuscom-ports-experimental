--- libview/ev-view-presentation.c.orig	2014-03-28 09:25:14.912641754 +0000
+++ libview/ev-view-presentation.c	2014-03-28 09:27:39.906632628 +0000
@@ -1428,7 +1428,6 @@
 	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
 	GObjectClass   *gobject_class = G_OBJECT_CLASS (klass);
 	GtkBindingSet  *binding_set;
-        GtkCssProvider *provider;
 
 	klass->change_page = ev_view_presentation_change_page;
 
@@ -1542,16 +1541,6 @@
 	gtk_binding_entry_add_signal (binding_set, GDK_KEY_K, 0,
 				      "change_page", 1,
 				      GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_PAGE_BACKWARD);
-
-        provider = gtk_css_provider_new ();
-        gtk_css_provider_load_from_data (provider,
-                                         "EvViewPresentation {\n"
-                                         " background-color: black; }",
-                                         -1, NULL);
-        gtk_style_context_add_provider_for_screen (gdk_screen_get_default (),
-                                                   GTK_STYLE_PROVIDER (provider),
-                                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
-        g_object_unref (provider);
 }
 
 static void
@@ -1567,8 +1556,24 @@
 			  guint       rotation,
 			  gboolean    inverted_colors)
 {
-	g_return_val_if_fail (EV_IS_DOCUMENT (document), NULL);
-	g_return_val_if_fail (current_page < ev_document_get_n_pages (document), NULL);
+        GtkCssProvider *provider;
+        static gsize initialization_value = 0;
+
+        g_return_val_if_fail (EV_IS_DOCUMENT (document), NULL);
+        g_return_val_if_fail (current_page < ev_document_get_n_pages (document), NULL);
+
+	if (g_once_init_enter (&initialization_value)){
+		provider = gtk_css_provider_new ();
+		gtk_css_provider_load_from_data (provider,
+						"EvViewPresentation {\n"
+						" background-color: black; }",
+						-1, NULL);
+		gtk_style_context_add_provider_for_screen (gdk_screen_get_default (),
+							   GTK_STYLE_PROVIDER (provider),
+							   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
+		g_object_unref (provider);
+		g_once_init_leave (&initialization_value, 42);
+	}
 
 	return GTK_WIDGET (g_object_new (EV_TYPE_VIEW_PRESENTATION,
 					 "document", document,
