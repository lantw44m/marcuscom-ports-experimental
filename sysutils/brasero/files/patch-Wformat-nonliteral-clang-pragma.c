--- libbrasero-burn/brasero-session.c.orig	2014-03-12 14:27:51.294380905 +0000
+++ libbrasero-burn/brasero-session.c	2014-03-12 14:28:32.953379735 +0000
@@ -2143,7 +2143,10 @@
 	if (!priv->session)
 		return;
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	message = g_strdup_vprintf (format, arg_list);
+#pragma clang diagnostic pop
 
 	/* we also need to validate the messages to be in UTF-8 */
 	if (!g_utf8_validate (message, -1, (const gchar**) &offending))
--- libbrasero-burn/burn-debug.c.orig	2014-03-12 14:23:01.326400700 +0000
+++ libbrasero-burn/burn-debug.c	2014-03-12 14:24:01.539399089 +0000
@@ -108,7 +108,10 @@
 				       format);
 
 	va_start (arg_list, format);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	va_end (arg_list);
 
 	g_free (format_real);
@@ -128,7 +131,10 @@
 				       location,
 				       format);
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	g_free (format_real);
 }
 
@@ -187,7 +193,10 @@
 				       buffer);
 
 	va_start (arg_list, format);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	va_end (arg_list);
 
 	g_free (format_real);
@@ -325,7 +334,10 @@
 				       buffer);
 
 	va_start (arg_list, format);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	va_end (arg_list);
 
 	g_free (format_real);
@@ -392,7 +404,10 @@
 				       buffer);
 
 	va_start (arg_list, format);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	va_end (arg_list);
 
 	g_free (format_real);
--- libbrasero-burn/burn-plugin.c.orig	2014-03-12 14:31:57.282363587 +0000
+++ libbrasero-burn/burn-plugin.c	2014-03-12 14:32:33.282363765 +0000
@@ -277,8 +277,11 @@
 
 	for (i = 0; i < 3 && version [i] >= 0; i++);
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	if ((standard_output && sscanf (standard_output, version_format, &major, &minor, &sub) == i)
 	||  (standard_error && sscanf (standard_error, version_format, &major, &minor, &sub) == i)) {
+#pragma clang diagnostic pop
 		if (major < version [0]
 		||  (version [1] >= 0 && minor < version [1])
 		||  (version [2] >= 0 && sub < version [2]))
--- libbrasero-burn/burn-process.c.orig	2010-03-07 15:07:48.000000000 -0500
+++ libbrasero-burn/burn-process.c	2010-03-07 15:08:41.000000000 -0500
@@ -609,6 +609,7 @@ brasero_process_start (BraseroJob *job, 
 	gchar *envp [] = {	"LANG=C",
 				"LANGUAGE=C",
 				"LC_ALL=C",
+				"PATH=/bin:/sbin:/usr/bin:/usr/sbin:%%LOCALBASE%%/bin:%%LOCALBASE%%/sbin",
 				NULL};
 
 	if (priv->pid)
--- libbrasero-media/brasero-media.c.orig	2014-03-12 14:21:00.629409865 +0000
+++ libbrasero-media/brasero-media.c	2014-03-12 14:22:05.991408578 +0000
@@ -498,7 +498,10 @@
 				       format);
 
 	va_start (arg_list, format);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	va_end (arg_list);
 
 	g_free (format_real);
--- libbrasero-utils/brasero-misc.c.orig	2014-03-12 14:18:58.233416331 +0000
+++ libbrasero-utils/brasero-misc.c	2014-03-12 14:20:21.769416831 +0000
@@ -112,7 +112,10 @@
 				       format);
 
 	va_start (arg_list, format);
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	vprintf (format_real, arg_list);
+#pragma clang diagnostic pop
 	va_end (arg_list);
 
 	g_free (format_real);
