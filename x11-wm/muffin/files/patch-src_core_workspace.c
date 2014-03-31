--- src/core/workspace.c.orig	2014-03-31 10:09:40.196592078 +0000
+++ src/core/workspace.c	2014-03-31 10:10:09.573592076 +0000
@@ -194,7 +194,7 @@
   return workspace;
 }
 
-/** Foreach function for workspace_free_struts() */
+/* Foreach function for workspace_free_struts() */
 static void
 free_this (gpointer candidate, gpointer dummy)
 {
