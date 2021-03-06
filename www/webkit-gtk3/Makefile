# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	webkit
PORTVERSION=	2.4.1
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc \
		geoclue>=0:${PORTSDIR}/net/geoclue
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libicutu.so:${PORTSDIR}/devel/icu \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue 

USE_GSTREAMER1=	yes
USE_XORG=	xt xdamage xcomposite
USES=		bison gettext gmake libtool perl5 pkgconfig shebangfix tar:xz
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gnomehier gtk20 gtk30 introspection:build \
		libxslt:build
USE_SQLITE=	3
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOLT_BASH=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 \
		--enable-svg-fonts \
		--enable-geolocation \
		--enable-introspection
MAKEFILE=	GNUmakefile
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

#CONFIGURE_ARGS+=--disable-silent-rules
CONFIGURE_ARGS+=--disable-egl \
		--disable-gles2
#		--with-acceleration-backend=opengl # clutter broken?
# opengl, clutter, none (clutter unsupported)

SHEBANG_FILES=	\
	Source/JavaScriptCore/create_hash_table \
	Source/JavaScriptCore/inspector/scripts/xxd.pl \
	Source/WebCore/css/*.pl \
	Source/WebCore/dom/*.pl \
	Source/WebCore/make-hash-tools.pl \
	Source/WebCore/page/make_settings.pl \
	Source/WebCore/platform/text/mac/make-charset-table.pl \
	Source/WebKit2/Scripts/generate-forwarding-headers.pl \
	Source/WebCore/bindings/scripts/*.p[lm] \
	Source/JavaScriptCore/create_hash_table

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	WEBGL WEBAUDIO DEBUG FULLDEBUG WEBKIT2
OPTIONS_DEFAULT=WEBGL WEBAUDIO WEBKIT2
WEBKIT2_DESC=	Build WebKit2 API library
WEBAUDIO_DESC=	Web audio support
WEBGL_DESC=	Enable Web GL support
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable asserts and other debug support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBGL}
USE_GL=		gl
CONFIGURE_ARGS+=--enable-webgl
.else
CONFIGURE_ARGS+=--disable-webgl
.endif

.if ${PORT_OPTIONS:MWEBAUDIO}
CONFIGURE_ARGS+=--enable-web-audio
.else
CONFIGURE_ARGS+=--disable-web-audio
.endif

.if ${PORT_OPTIONS:MFULLDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug-symbols=yes
.endif

# gtest to use <tr1/tuple,> while libc++ only has <tuple>
CPPFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE
# Shutup warning spam
CXXFLAGS+=	-Wno-c++11-extensions -Qunused-arguments

.if ${PORT_OPTIONS:MWEBKIT2}
CONFIGURE_ARGS+=--enable-webkit2
PLIST_SUB+=	WEBKIT2=""

# We need clang + libc++ or gcc 4.7+. gcc has libstdc++ conflict between
# gcc port and base. This originates from icu
CXXFLAGS+=	-stdlib=libc++
LDFLAGS+=	-stdlib=libc++
. if ${OSVERSION}<1000019
BUILD_DEPENDS+=	clang33>=3.3_1:${PORTSDIR}/lang/clang33 \
		libc++>=0:${PORTSDIR}/devel/libc++
RUN_DEPENDS+=	libc++>=0:${PORTSDIR}/devel/libc++
CC=		clang33
CXX=		clang++33
CPP=		clang-cpp33
CONFIGURE_ENV+=	CC=${CC} CXX=${CXX} CPP=${CPP}
. endif
.else
# we need clang also for !Webkit2 builds
. if ${OSVERSION}<1000019
BUILD_DEPENDS+=	clang33>=3.3_1:${PORTSDIR}/lang/clang33
CC=		clang33
CXX=		clang++33
CPP=		clang-cpp33
CONFIGURE_ARGS+=--disable-webkit2
. endif
PLIST_SUB+=	WEBKIT2="@comment "
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+=	p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp
	@${FIND} ${WRKSRC} -name GNUmakefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	@${REINPLACE_CMD} -e 's|"gperf|"${LOCALBASE}/bin/gperf|g' \
		${WRKSRC}/Source/WebCore/css/makevalues.pl \
		${WRKSRC}/Source/WebCore/css/makeprop.pl \
		${WRKSRC}/Source/WebCore/make-hash-tools.pl

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/GtkLauncher \
		${STAGEDIR}${PREFIX}/bin/GtkLauncher-3
.if ${PORT_OPTIONS:MWEBKIT2}
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/MiniBrowser \
		${STAGEDIR}${PREFIX}/bin/
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkit2gtk-3.0/injected-bundle/libwebkit2gtkinjectedbundle.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

.include <bsd.port.post.mk>
