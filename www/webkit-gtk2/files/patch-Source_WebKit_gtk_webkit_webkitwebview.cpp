--- Source/WebKit/gtk/webkit/webkitwebview.cpp.orig	2013-03-26 18:25:31.000000000 +0000
+++ Source/WebKit/gtk/webkit/webkitwebview.cpp	2013-03-31 11:49:59.000000000 +0000
@@ -5061,6 +5061,8 @@ void webkit_web_view_add_main_resource(W
 
     priv->mainResource = adoptGRef(webResource);
     priv->mainResourceIdentifier = identifier;
+
+    g_object_ref(webView);
 }
 
 void webkit_web_view_add_resource(WebKitWebView* webView, const char* identifier, WebKitWebResource* webResource)
@@ -5078,6 +5080,8 @@ void webkitWebViewRemoveSubresource(WebK
     if (!mainResource.isNull() && g_str_equal(identifier, mainResource.data()))
         return;
     g_hash_table_remove(webView->priv->subResources.get(), identifier);
+
+    g_object_unref(webView);
 }
 
 WebKitWebResource* webkit_web_view_get_resource(WebKitWebView* webView, char* identifier)
