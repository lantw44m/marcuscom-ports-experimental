--- glib/gthread-posix.c.orig	2012-05-07 20:32:49.000000000 -0500
+++ glib/gthread-posix.c	2012-05-07 20:33:45.000000000 -0500
@@ -89,20 +89,9 @@
   if G_UNLIKELY (mutex == NULL)
     g_thread_abort (errno, "malloc");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP
-  pthread_mutexattr_t attr;
-  pthread_mutexattr_init (&attr);
-  pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_ADAPTIVE_NP);
-  pattr = &attr;
-#endif
-
   if G_UNLIKELY ((status = pthread_mutex_init (mutex, pattr)) != 0)
     g_thread_abort (status, "pthread_mutex_init");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_NP
-  pthread_mutexattr_destroy (&attr);
-#endif
-
   return mutex;
 }
 
