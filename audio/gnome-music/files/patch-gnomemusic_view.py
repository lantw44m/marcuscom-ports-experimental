--- gnomemusic/view.py.orig	2014-03-24 15:56:54.000000000 +0000
+++ gnomemusic/view.py	2014-04-02 15:24:37.243382133 +0000
@@ -67,7 +67,7 @@
     countQuery = None
     filter = None
 
-    def __init__(self, title, header_bar, selection_toolbar, use_sidebar=False, sidebar=None):
+    def __init__(self, title, header_bar, selection_toolbar, view_type, use_sidebar=False, sidebar=None):
         Stack.__init__(self,
                        transition_type=StackTransitionType.CROSSFADE)
         self._grid = Gtk.Grid(orientation=Gtk.Orientation.HORIZONTAL)
@@ -93,7 +93,7 @@
         self.view = Gd.MainView(
             shadow_type=Gtk.ShadowType.NONE
         )
-        self.view.set_view_type(Gd.MainViewType.ICON)
+        self.view.set_view_type(view_type)
         self.filter = self._model.filter_new(None)
         self.view.set_model(self.filter)
         self.vadjustment = self.view.get_vadjustment()
@@ -327,8 +327,7 @@
 class Albums(ViewContainer):
     def __init__(self, header_bar, selection_toolbar, player):
         ViewContainer.__init__(self, _("Albums"), header_bar,
-                               selection_toolbar)
-        self.view.set_view_type(Gd.MainViewType.ICON)
+                               selection_toolbar, Gd.MainViewType.ICON)
         self.countQuery = Query.ALBUMS_COUNT
         self._albumWidget = Widgets.AlbumWidget(player)
         self.player = player
@@ -399,13 +398,12 @@
 
 class Songs(ViewContainer):
     def __init__(self, header_bar, selection_toolbar, player):
-        ViewContainer.__init__(self, _("Songs"), header_bar, selection_toolbar)
+        ViewContainer.__init__(self, _("Songs"), header_bar, selection_toolbar, Gd.MainViewType.LIST)
         self.countQuery = Query.SONGS_COUNT
         self._items = {}
         self.monitors = []
         self.isStarred = None
         self.iter_to_clean = None
-        self.view.set_view_type(Gd.MainViewType.LIST)
         self.view.get_generic_view().get_style_context()\
             .add_class('songs-list')
         self._iconHeight = 32
@@ -564,7 +562,7 @@
 class Artists (ViewContainer):
     def __init__(self, header_bar, selection_toolbar, player):
         ViewContainer.__init__(self, _("Artists"), header_bar,
-                               selection_toolbar, True)
+                               selection_toolbar, Gd.MainViewType.LIST, True)
         self.artists_counter = 0
         self.player = player
         self._artists = {}
@@ -581,7 +579,6 @@
         )
         self.artistAlbumsStack.add_named(self._artistAlbumsWidget, "sidebar")
         self.artistAlbumsStack.set_visible_child_name("sidebar")
-        self.view.set_view_type(Gd.MainViewType.LIST)
         self.view.set_hexpand(False)
         self.view.get_style_context().add_class('artist-panel')
         self.view.get_generic_view().get_selection().set_mode(
@@ -741,9 +738,8 @@
         )
 
         ViewContainer.__init__(self, _("Playlists"), header_bar,
-                               selection_toolbar, True, self.playlists_sidebar)
+                               selection_toolbar, Gd.MainViewType.LIST, True, self.playlists_sidebar)
 
-        self.view.set_view_type(Gd.MainViewType.LIST)
         self.view.get_generic_view().get_style_context()\
             .add_class('songs-list')
         self._add_list_renderers()
@@ -774,8 +770,8 @@
             GObject.TYPE_BOOLEAN,
             GObject.TYPE_BOOLEAN
         )
-        self.playlists_sidebar.set_model(self.playlists_model)
         self.playlists_sidebar.set_view_type(Gd.MainViewType.LIST)
+        self.playlists_sidebar.set_model(self.playlists_model)
         self.playlists_sidebar.set_hexpand(False)
         self.playlists_sidebar.get_style_context().add_class('artist-panel')
         self.playlists_sidebar.get_generic_view().get_selection().set_mode(
