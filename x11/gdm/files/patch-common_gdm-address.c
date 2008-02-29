--- common/gdm-address.c.orig	2008-02-03 11:52:26.000000000 -0500
+++ common/gdm-address.c	2008-02-13 01:23:07.000000000 -0500
@@ -25,8 +25,9 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <stropts.h>
 #include <string.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif
@@ -35,7 +36,6 @@
 #endif
 #include <netdb.h>
 #include <sys/ioctl.h>
-#include <net/if.h>
 
 #ifndef G_OS_WIN32
 #include <sys/socket.h>
@@ -46,6 +46,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #endif
+#include <net/if.h>
 
 #include <glib-object.h>
 
