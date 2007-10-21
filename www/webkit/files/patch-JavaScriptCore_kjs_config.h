--- JavaScriptCore/kjs/config.h.orig	2007-10-21 18:03:53.025920053 -0400
+++ JavaScriptCore/kjs/config.h	2007-10-21 18:04:04.504783428 -0400
@@ -72,7 +72,7 @@
 #define HAVE_PTHREAD_NP_H 1
 #endif
 
-#define HAVE_PCREPOSIX 1
+#undef HAVE_PCREPOSIX
 
 /* FIXME: if all platforms have these, do they really need #defines? */
 #define HAVE_STDINT_H 1
