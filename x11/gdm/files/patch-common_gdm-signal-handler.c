--- common/gdm-signal-handler.c.orig	2007-10-30 11:41:48.000000000 -0400
+++ common/gdm-signal-handler.c	2007-11-02 15:07:28.000000000 -0400
@@ -27,7 +27,6 @@
 #include <unistd.h>
 #include <string.h>
 #include <signal.h>
-#include <execinfo.h>
 #include <syslog.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
@@ -151,6 +150,7 @@ signal_io_watch (GIOChannel       *ioc,
 static void
 fallback_get_backtrace (void)
 {
+/*
         void *  frames[64];
         size_t  size;
         char ** strings;
@@ -167,13 +167,14 @@ fallback_get_backtrace (void)
         } else {
                 g_warning ("GDM crashed, but symbols couldn't be retrieved.");
         }
+*/
 }
 
 
 static gboolean
 crashlogger_get_backtrace (void)
-{
-        gboolean success = FALSE;
+{ 
+       gboolean success = FALSE;
         int      pid;
 
         pid = fork();
