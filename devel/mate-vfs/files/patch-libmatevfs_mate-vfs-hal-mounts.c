--- libmatevfs/mate-vfs-hal-mounts.c.orig	Mon Aug  7 04:16:27 2006
+++ libmatevfs/mate-vfs-hal-mounts.c	Sun Sep 17 17:39:48 2006
@@ -627,20 +629,30 @@ _hal_volume_policy_check (MateVFSVolume
 		"/",
 		"/bin",
 		"/boot",
+		"/compat/linux/proc",
+		"/compat/linux/sys",
 		"/dev",
 		"/etc",
 		"/home",
 		"/lib",
 		"/lib64",
+		"/libexec",
 		"/media",
 		"/mnt",
 		"/opt",
+		"/rescue",
 		"/root",
 		"/sbin",
 		"/srv",
 		"/tmp",
 		"/usr",
+		"/usr/local",
+		"/usr/obj",
+		"/usr/ports",
+		"/usr/src",
+		"/usr/X11R6",
 		"/var",
+		"/var/tmp",
 		"/proc",
 		"/sbin",
 		NULL