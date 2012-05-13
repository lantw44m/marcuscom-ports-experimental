--- glib/gthread-posix.c.orig	2012-05-13 18:23:49.000000000 -0400
+++ glib/gthread-posix.c	2012-05-13 18:30:37.000000000 -0400
@@ -89,7 +89,7 @@ g_mutex_impl_new (void)
   if G_UNLIKELY (mutex == NULL)
     g_thread_abort (errno, "malloc");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP
+#if defined(PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP) && !defined(__FreeBSD__)
   pthread_mutexattr_t attr;
   pthread_mutexattr_init (&attr);
   pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_ADAPTIVE_NP);
@@ -99,7 +99,7 @@ g_mutex_impl_new (void)
   if G_UNLIKELY ((status = pthread_mutex_init (mutex, pattr)) != 0)
     g_thread_abort (status, "pthread_mutex_init");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_NP
+#if defined(PTHREAD_ADAPTIVE_MUTEX_NP) && !defined(__FreeBSD__)
   pthread_mutexattr_destroy (&attr);
 #endif
 
