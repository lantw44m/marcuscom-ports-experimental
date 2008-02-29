--- gui/simple-greeter/gdm-languages.c.orig	2008-02-25 17:21:43.000000000 -0500
+++ gui/simple-greeter/gdm-languages.c	2008-02-27 01:17:09.000000000 -0500
@@ -50,6 +50,8 @@
 #define ISO_CODES_DATADIR ISO_CODES_PREFIX "/share/xml/iso-codes"
 #define ISO_CODES_LOCALESDIR ISO_CODES_PREFIX "/share/locale"
 
+#define GDM_DEFAULT_LOCALE "C"
+
 typedef struct _GdmLocale {
         char *id;
         char *name;
@@ -479,7 +481,7 @@ select_dirs (const struct dirent *dirent
                                 struct stat st;
                                 char       *path;
 
-                                path = g_build_filename (LIBLOCALEDIR, dirent->d_name, NULL);
+                                path = g_build_filename ("/usr/share/locale", dirent->d_name, NULL);
                                 if (g_stat (path, &st) == 0) {
                                         mode = st.st_mode;
                                 }
@@ -499,7 +501,7 @@ collect_locales_from_directory (void)
         int             ndirents;
         int             cnt;
 
-        ndirents = scandir (LIBLOCALEDIR, &dirents, select_dirs, alphasort);
+        ndirents = scandir ("/usr/share/locale", &dirents, select_dirs, alphasort);
 
         for (cnt = 0; cnt < ndirents; ++cnt) {
                 char      *path;
@@ -533,7 +535,7 @@ collect_locales_from_directory (void)
                 }
 
                 /* try to get additional information from LC_IDENTIFICATION */
-                path = g_build_filename (LIBLOCALEDIR, dirents[cnt]->d_name, "LC_IDENTIFICATION", NULL);
+                path = g_build_filename ("/usr/share/locale", dirents[cnt]->d_name, "LC_IDENTIFICATION", NULL);
                 res = g_file_test (path, G_FILE_TEST_IS_REGULAR);
                 if (res) {
                         GMappedFile      *mapped;
@@ -568,6 +570,35 @@ collect_locales_from_aliases (void)
 }
 
 static void
+collect_default_locale (void)
+{
+        GdmLocale  *locale;
+        GdmLocale  *old_locale;
+
+        locale = g_new0 (GdmLocale, 1);
+        gdm_parse_language_name (GDM_DEFAULT_LOCALE,
+                                 &locale->language_code,
+                                 &locale->territory_code,
+                                 &locale->codeset,
+                                 &locale->modifier);
+
+        locale->id = construct_language_name (locale->language_code, locale->territory_code,
+                                              NULL, locale->modifier);
+        locale->name = construct_language_name (locale->language_code, locale->territory_code,
+                                                locale->codeset, locale->modifier);
+
+        old_locale = g_hash_table_lookup (gdm_available_locales_map, locale->id);
+        if (old_locale != NULL) {
+                if (strlen (old_locale->name) > strlen (locale->name)) {
+                        chooser_locale_free (locale);
+                        return;
+                }
+        }
+
+        g_hash_table_insert (gdm_available_locales_map, g_strdup (locale->id), locale);
+}
+
+static void
 collect_locales (void)
 {
 
@@ -575,6 +606,7 @@ collect_locales (void)
                 gdm_available_locales_map = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, (GDestroyNotify) chooser_locale_free);
         }
 
+        collect_default_locale ();
         collect_locales_from_archive ();
         collect_locales_from_directory ();
         collect_locales_from_aliases ();
@@ -957,6 +989,8 @@ gdm_get_language_from_name (const char *
         }
 
         language = get_translated_language (language_code, name);
+        if (language == NULL && ! strcmp (language_code, GDM_DEFAULT_LOCALE))
+                language = GDM_DEFAULT_LOCALE;
 
         if (territory_code != NULL) {
                 territory = get_translated_territory (territory_code, name);
