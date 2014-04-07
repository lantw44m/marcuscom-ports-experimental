Add temporary patch/hack to fix display issues in webkit2.

https://bugs.webkit.org/show_bug.cgi?id=125558

Index: Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp
===================================================================
--- Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp	(revision 166850)
+++ Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp	(working copy)
@@ -205,7 +205,7 @@
         }
     }
 
-    while (fcntl(duplicatedHandle, F_SETFD, FD_CLOEXEC) == -1 || fcntl(duplicatedHandle, F_SETFL, accessModeFile(protection)) == -1) {
+    while (fcntl(duplicatedHandle, F_SETFD, FD_CLOEXEC) == -1) {
         if (errno != EINTR) {
             ASSERT_NOT_REACHED();
             closeWithRetry(duplicatedHandle);
