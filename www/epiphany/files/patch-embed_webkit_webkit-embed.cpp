--- embed/webkit/webkit-embed.cpp.orig	2007-10-21 23:15:17.980341634 -0400
+++ embed/webkit/webkit-embed.cpp	2007-10-21 23:20:01.971961239 -0400
@@ -27,6 +27,7 @@
 #include "ephy-string.h"
 #include "ephy-embed-event.h"
 
+#include <webkitgtkframe.h>
 #include <webkitgtkpage.h>
 #include <webkitgtkglobal.h>
 #include <string.h>
@@ -40,34 +41,6 @@
 static void	webkit_embed_finalize		(GObject *object);
 static void	ephy_embed_iface_init		(EphyEmbedIface *iface);
 
-#if 0
-static void    load_started_cb                 (WebKitGtkPage *page,
-                                               WebKitGtkFrame *frame,
-                                               WebKitEmbed *wembed);
-
-static void webkit_embed_location_changed_cb	(GtkMozEmbed *embed,
-						 WebKitEmbed *membed);
-static void webkit_embed_net_state_all_cb	(GtkMozEmbed *embed,
-						 const char *aURI,
-						 gint state,
-						 guint status,
-						 WebKitEmbed *membed);
-static gboolean webkit_embed_dom_mouse_click_cb(GtkMozEmbed *embed,
-                                                gpointer dom_event,
-                                                WebKitEmbed *membed);
-static gboolean webkit_embed_dom_mouse_down_cb	(GtkMozEmbed *embed,
-
-						 
-						 WebKitEmbed *membed);
-static gboolean webkit_embed_dom_key_press_cb	(GtkMozEmbed *embed,
-						 gpointer dom_event, 
-						 WebKitEmbed *membed);
-static void webkit_embed_new_window_cb		(GtkMozEmbed *embed, 
-						 GtkMozEmbed **newEmbed,
-						 guint chrome_mask,
-						 WebKitEmbed *membed);
-#endif
-
 #define WEBKIT_EMBED_GET_PRIVATE(object)(G_TYPE_INSTANCE_GET_PRIVATE ((object), WEBKIT_TYPE_EMBED, WebKitEmbedPrivate))
 
 typedef enum
@@ -80,8 +53,9 @@
 
 struct WebKitEmbedPrivate
 {
-  WebKitGtkPage *page;
+  WebKitPage *page;
   WebKitEmbedLoadState load_state;
+  char *loading_uri;
 };
 
 static void
@@ -121,14 +95,95 @@
 }
 
 static void
+webkit_embed_title_changed_cb (WebKitFrame *frame,
+			       gchar *title,
+			       gchar *location,
+			       EphyEmbed *embed)
+{
+  /* FIXME: We emit ge-location signal here, but it should really belong
+   * to a "location_changed" signal by WebKit, as we can change title
+   * without changing location or change location without changing title
+   */
+
+  g_signal_emit_by_name (embed, "ge-location", location);
+}
+
+static void
+update_load_state (WebKitEmbed *embed, WebKitPage *page)
+{
+  EphyEmbedNetState estate = EPHY_EMBED_STATE_UNKNOWN;
+
+  if (embed->priv->load_state == WEBKIT_EMBED_LOAD_STARTED)
+      estate = (EphyEmbedNetState) (estate | 
+                                    EPHY_EMBED_STATE_START |
+                                    EPHY_EMBED_STATE_NEGOTIATING |
+                                    EPHY_EMBED_STATE_IS_REQUEST | 
+                                    EPHY_EMBED_STATE_IS_NETWORK);
+
+  if (embed->priv->load_state == WEBKIT_EMBED_LOAD_LOADING)
+      estate = (EphyEmbedNetState) (estate |
+                                    EPHY_EMBED_STATE_TRANSFERRING |
+                                    EPHY_EMBED_STATE_IS_REQUEST |
+                                    EPHY_EMBED_STATE_IS_NETWORK);
+
+  if (embed->priv->load_state == WEBKIT_EMBED_LOAD_STOPPED)
+      estate = (EphyEmbedNetState) (estate |
+                                    EPHY_EMBED_STATE_STOP |
+                                    EPHY_EMBED_STATE_IS_DOCUMENT |
+                                    EPHY_EMBED_STATE_IS_NETWORK);
+
+  g_signal_emit_by_name (EPHY_EMBED (embed), "ge_net_state",
+                         embed->priv->loading_uri, estate);
+}
+
+static void
+webkit_embed_load_started_cb (WebKitPage *page,
+			      WebKitFrame *frame,
+			      EphyEmbed *embed)
+{
+  WebKitEmbed *wembed = WEBKIT_EMBED (embed);
+  wembed->priv->load_state = WEBKIT_EMBED_LOAD_STARTED;
+
+  update_load_state (wembed, page);
+}
+
+static void
+webkit_embed_load_progress_changed_cb (WebKitPage *page,
+				       int progress,
+				       EphyEmbed *embed)
+{
+  WebKitEmbed *wembed = WEBKIT_EMBED (embed);
+
+  if (wembed->priv->load_state == WEBKIT_EMBED_LOAD_STARTED)
+    wembed->priv->load_state = WEBKIT_EMBED_LOAD_LOADING;
+
+  /* FIXME: EphyTab seems to have a strange way of calculating progress,
+   * and it's not compatible with the simple integer value WebKit emits.
+   * EphyTab IMHO should use "progress" signal from GtkMozEmbed. That way,
+   * we could use the same functions for WebKit too.
+   */
+
+  update_load_state (wembed, page);
+}
+
+static void
+webkit_embed_load_finished_cb (WebKitPage *page,
+			       WebKitFrame *frame,
+			       EphyEmbed *embed)
+{
+  WebKitEmbed *wembed = WEBKIT_EMBED (embed);
+  wembed->priv->load_state = WEBKIT_EMBED_LOAD_STOPPED;
+
+  update_load_state (wembed, page);
+}
+
+static void
 webkit_embed_class_init (WebKitEmbedClass *klass)
 {
   GObjectClass *object_class = G_OBJECT_CLASS (klass);
   GtkObjectClass *gtk_object_class = GTK_OBJECT_CLASS (klass); 
   GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass); 
 
-  webkit_embed_parent_class = (GObjectClass *) g_type_class_peek_parent (klass);
-
   object_class->finalize = webkit_embed_finalize;
 
   gtk_object_class->destroy = webkit_embed_destroy;
@@ -141,29 +196,30 @@
 static void
 webkit_embed_init (WebKitEmbed *embed)
 {
-  WebKitGtkPage *page;
+  WebKitPage *page;
 
   embed->priv = WEBKIT_EMBED_GET_PRIVATE (embed);
+  embed->priv->loading_uri = NULL;
 
   gtk_scrolled_window_set_vadjustment (GTK_SCROLLED_WINDOW (embed), NULL);
   gtk_scrolled_window_set_hadjustment (GTK_SCROLLED_WINDOW (embed), NULL);
 
   gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (embed),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
-  webkit_gtk_init ();
-  page = WEBKIT_GTK_PAGE (webkit_gtk_page_new ());
+  webkit_init ();
+  page = WEBKIT_PAGE (webkit_page_new ());
   embed->priv->page = page;
   gtk_container_add (GTK_CONTAINER (embed), GTK_WIDGET (page));
   gtk_widget_show (GTK_WIDGET (page));
 
-#if 0
   g_signal_connect (G_OBJECT (page), "load-started",
-		  G_CALLBACK (load_started_cb), embed);
+                    G_CALLBACK (webkit_embed_load_started_cb), embed);
+  g_signal_connect (G_OBJECT (page), "load_finished",
+                    G_CALLBACK (webkit_embed_load_finished_cb), embed);
   g_signal_connect (G_OBJECT (page), "title-changed",
-                    G_CALLBACK (title_changed_cb), page);
+                    G_CALLBACK (webkit_embed_title_changed_cb), embed);
   g_signal_connect (G_OBJECT (page), "load-progress-changed",
-                    G_CALLBACK (load_progress_changed), page);
-#endif
+                    G_CALLBACK (webkit_embed_load_progress_changed_cb), embed);
 }
 
 static void
@@ -175,19 +231,12 @@
 static void
 webkit_embed_finalize (GObject *object)
 {
-  G_OBJECT_CLASS (webkit_embed_parent_class)->finalize (object);
-}
+  WebKitEmbed *wembed = WEBKIT_EMBED (object);
 
-#if 0
-static void
-load_started_cb (WebKitGtkPage *page,
-                 WebKitGtkFrame *frame,
-                 WebKitEmbed *wembed)
-{
-  g_debug("load-started, emitting ge_location with www.google.com as location");
-  g_signal_emit_by_name (wembed, "ge_location", "www.google.com");
+  g_free (wembed->priv->loading_uri);
+
+  G_OBJECT_CLASS (webkit_embed_parent_class)->finalize (object);
 }
-#endif
 
 static void
 impl_load_url (EphyEmbed *embed,
@@ -195,13 +244,9 @@
 {
   WebKitEmbed *wembed = WEBKIT_EMBED (embed);
 
-  g_debug ("a url %s", url);
-  
-  webkit_gtk_page_open (wembed->priv->page, url);
+  webkit_page_open (wembed->priv->page, url);
 }
 
-static char * impl_get_location (EphyEmbed *embed, gboolean toplevel);
-
 static void
 impl_load (EphyEmbed *embed, 
            const char *url,
@@ -209,27 +254,45 @@
 	   EphyEmbed *preview_embed)
 {
   WebKitEmbed *wembed = WEBKIT_EMBED (embed);
+  char *effective_url = NULL;
 
-  g_debug ("url %s", url);
-  webkit_gtk_page_open (wembed->priv->page, url);
+  /* FIXME: WebKit has some strange bug for which there must be
+   * protocol prefix into the parsed URL, or it will not show images
+   * and lock badly.  I copied this function from WebKit's
+   * GdkLauncher.
+   */
+  if (strncmp ("http://", url, 7) != 0 &&
+      strncmp ("https://", url, 8) != 0 &&
+      strncmp ("file://", url, 7) != 0 &&
+      strncmp ("ftp://", url, 6) != 0)
+    effective_url = g_strconcat ("http://", url, NULL);
+  else
+    effective_url = g_strdup (url);
+
+  g_free (wembed->priv->loading_uri);
+  wembed->priv->loading_uri = g_strdup (effective_url);
+
+  webkit_page_open (wembed->priv->page, effective_url);
+
+  g_free (effective_url);
 }
 
 static void
 impl_stop_load (EphyEmbed *embed)
 {
-  webkit_gtk_page_stop_loading (WEBKIT_EMBED (embed)->priv->page);
+  webkit_page_stop_loading (WEBKIT_EMBED (embed)->priv->page);
 }
 
 static gboolean
 impl_can_go_back (EphyEmbed *embed)
 {
-  return webkit_gtk_page_can_go_backward (WEBKIT_EMBED (embed)->priv->page);
+  return webkit_page_can_go_backward (WEBKIT_EMBED (embed)->priv->page);
 }
 
 static gboolean
 impl_can_go_forward (EphyEmbed *embed)
 {
-  return webkit_gtk_page_can_go_forward (WEBKIT_EMBED (embed)->priv->page);
+  return webkit_page_can_go_forward (WEBKIT_EMBED (embed)->priv->page);
 }
 
 static gboolean
@@ -247,13 +310,13 @@
 static void
 impl_go_back (EphyEmbed *embed)
 {
-  webkit_gtk_page_go_backward (WEBKIT_EMBED (embed)->priv->page);
+  webkit_page_go_backward (WEBKIT_EMBED (embed)->priv->page);
 }
 		
 static void
 impl_go_forward (EphyEmbed *embed)
 {
-  webkit_gtk_page_go_forward (WEBKIT_EMBED (embed)->priv->page);
+  webkit_page_go_forward (WEBKIT_EMBED (embed)->priv->page);
 }
 
 static void
@@ -264,7 +327,8 @@
 static char *
 impl_get_title (EphyEmbed *embed)
 {
-  return NULL;
+  WebKitFrame *frame = webkit_page_get_main_frame (WEBKIT_EMBED (embed)->priv->page);
+  return g_strdup (webkit_frame_get_title (frame));
 }
 
 static char *
@@ -283,14 +347,15 @@
 impl_get_location (EphyEmbed *embed, 
                    gboolean toplevel)
 {
-  return NULL;
+  WebKitFrame *frame = webkit_page_get_main_frame (WEBKIT_EMBED (embed)->priv->page);
+  return g_strdup (webkit_frame_get_location (frame));
 }
 
 static void
 impl_reload (EphyEmbed *embed, 
              gboolean force)
 {
-  webkit_gtk_page_reload (WEBKIT_EMBED (embed)->priv->page);  
+  webkit_page_reload (WEBKIT_EMBED (embed)->priv->page);  
 }
 
 static void
