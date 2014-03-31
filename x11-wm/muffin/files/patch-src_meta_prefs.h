--- src/meta/prefs.h.orig	2014-03-31 10:09:49.951591487 +0000
+++ src/meta/prefs.h	2014-03-31 10:10:29.806588931 +0000
@@ -310,13 +310,13 @@
    */
   GSList *bindings;
 
-  /** for keybindings that can have shift or not like Alt+Tab */
+  /* for keybindings that can have shift or not like Alt+Tab */
   gboolean      add_shift:1;
 
-  /** for keybindings that apply only to a window */
+  /* for keybindings that apply only to a window */
   gboolean      per_window:1;
 
-  /** for keybindings not added with meta_display_add_keybinding() */
+  /* for keybindings not added with meta_display_add_keybinding() */
   gboolean      builtin:1;
 } MetaKeyPref;
 
