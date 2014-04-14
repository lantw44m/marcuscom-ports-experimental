From b8a0905c92774683c2a90ca74b899e4ef784bc90 Mon Sep 17 00:00:00 2001
From: Gustau Perez <gustau.perez@gmail.com>
Date: Fri, 28 Mar 2014 19:31:08 +0000
Subject: [PATCH] During the build of Evince with introspection support, it
 crashes.

Using GI_SCANNER_DEBUG=save-temps, the temporal files remained. It was
possible to reproduce the problem. The backtrace can be found at:

    http://pastebin.com/yVDiQTUN

It has been suggested that calling gtk_style_context_add_provider_for_screen()
should, inside a g_once_init(), be in the class's _init() (not class_init()) hook.

This apparently fixes the problem.
---
 libview/ev-view-presentation.c | 27 ++++++++++++++++-----------
 1 file changed, 16 insertions(+), 11 deletions(-)

diff --git a/libview/ev-view-presentation.c b/libview/ev-view-presentation.c
index 3bdf4e6..4fdd6b6 100644
--- libview/ev-view-presentation.c
+++ libview/ev-view-presentation.c
@@ -1419,7 +1419,6 @@ ev_view_presentation_class_init (EvViewPresentationClass *klass)
 	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
 	GObjectClass   *gobject_class = G_OBJECT_CLASS (klass);
 	GtkBindingSet  *binding_set;
-        GtkCssProvider *provider;
 
 	klass->change_page = ev_view_presentation_change_page;
 
@@ -1533,16 +1532,6 @@ ev_view_presentation_class_init (EvViewPresentationClass *klass)
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
@@ -1550,6 +1539,22 @@ ev_view_presentation_init (EvViewPresentation *pview)
 {
 	gtk_widget_set_can_focus (GTK_WIDGET (pview), TRUE);
         pview->is_constructing = TRUE;
+
+	static gsize initialization_value = 0;
+
+	if (g_once_init_enter (&initialization_value)){
+		GtkCssProvider *provider;
+		provider = gtk_css_provider_new ();
+		gtk_css_provider_load_from_data (provider,
+						 "EvViewPresentation {\n"
+						 " background-color: black; }",
+						 -1, NULL);
+		gtk_style_context_add_provider_for_screen (gdk_screen_get_default (),
+							   GTK_STYLE_PROVIDER (provider),
+							   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
+		g_object_unref (provider);
+		g_once_init_leave (&initialization_value, 1);
+	}
 }
 
 GtkWidget *
-- 
1.8.2.3
