--- daemon/gdm-session-worker.c.orig	2008-01-15 17:23:12.000000000 -0500
+++ daemon/gdm-session-worker.c	2008-01-15 17:22:36.000000000 -0500
@@ -226,7 +226,7 @@ gdm_session_execute (const char *file,
                          * what to search if PATH is unset. POSIX may, dunno.
                          */
 
-                        path = "/bin:/usr/bin:.";
+                        path = "/bin:/usr/bin:%%LOCALBASE%%/bin:.";
                 }
 
                 len = strlen (file) + 1;
