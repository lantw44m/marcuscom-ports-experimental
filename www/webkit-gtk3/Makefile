# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/webkit-gtk3/Makefile,v 1.32 2013/03/09 09:12:39 kwm Exp $

PORTNAME=	webkit
PORTVERSION=	2.0.3
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	enchant:${PORTSDIR}/textproc/enchant \
		secret-1:${PORTSDIR}/security/libsecret \
		icutu:${PORTSDIR}/devel/icu \
		webp:${PORTSDIR}/graphics/webp \
		curl:${PORTSDIR}/ftp/curl \
		soup-2.4:${PORTSDIR}/devel/libsoup

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_XZ=		yes
USE_GSTREAMER1=	yes
MAKE_JOBS_SAFE=	yes
USE_XORG=	xt xdamage xcomposite
USES=		bison gettext pkgconfig shebangfix
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GMAKE=	yes
#USE_AUTOTOOLS=	libtool
USE_GNOME=	cairo gnomehier gtk20 gtk30 introspection:build \
		libxslt:build
#ltverhack lthack
USE_SQLITE=	3
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_FLEX="${LOCALBASE}/bin/flex" \
		ZLIB_CFLAGS="-I/usr/include" \
		ZLIB_LIBS="-L/usr/lib -lz" \
		ac_cv_path_DOLT_BASH=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 \
		--enable-svg-fonts \
		--disable-geolocation \
		--enable-introspection
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=--disable-silent-rules
CONFIGURE_ARGS+=--disable-egl \
		--disable-gles2
#		--with-acceleration-backend=opengl # clutter broken?
# opengl, clutter, none (clutter unsupported)

SHEBANG_FILES=	\
	Source/JavaScriptCore/create_hash_table \
	Source/WebCore/css/*.pl \
	Source/WebCore/dom/*.pl \
	Source/WebCore/inspector/xxd.pl \
	Source/WebCore/make-hash-tools.pl \
	Source/WebCore/page/make_settings.pl \
	Source/WebCore/platform/text/mac/make-charset-table.pl \
	Source/WebKit2/Scripts/generate-forwarding-headers.pl \
	Source/WebCore/bindings/scripts/*.p[lm] \
	Source/JavaScriptCore/create_hash_table \
	Tools/Scripts/webkit-build-directory

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	WEBGL WEBAUDIO DEBUG FULLDEBUG
OPTIONS_DEFAULT=WEBGL WEBAUDIO
WEBAUDIO_DESC=	Web audio support
WEBGL_DESC=	Enable Web GL support
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable fullblown debug support

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

.if ${PORT_OPTIONS:MDEBUG} || ${PORT_OPTIONS:MFULLDEBUG}
CONFIGURE_ARGS+=--enable-debug-symbols=yes
.endif

# We need clang + libc++ or gcc 4.7+. gcc has libstdc++ conflict between
# gcc port and base. This originates from icu
# gtest to use <tr1/tuple,> while libc++ only has <tuple>
CPPFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE
CXXFLAGS+=	-Wno-c++11-extensions -Qunused-arguments -stdlib=libc++
LDFLAGS+=	-stdlib=libc++
.if ${OSVERSION}<1000024
LDFLAGS+=	-Wl,-Bstatic -licu
#BUILD_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33 \
#		libc++>=0:${PORTSDIR}/devel/libc++
#RUN_DEPENDS+=	libc++>=0:${PORTSDIR}/devel/libc++
#CC=		clang33
#CXX=		clang++33
#CPP=		clang-cpp33
#CONFIGURE_ENV+=	CC=${CC} CXX=${CXX} CPP=${CPP}
#CPPFLAGS+=	-I${LOCALBASE}/include/c++/v1
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+=	p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp
	@${FIND} ${WRKSRC} -name GNUmakefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
# disable static library.
#	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|' \
#		${WRKDIR}/gnome-libtool
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|' \
		${WRKSRC}/Source/WebCore/dom/make_names.pl \
		${WRKSRC}/Source/WebCore/css/make-css-file-arrays.pl \
		${WRKSRC}/Source/WebCore/bindings/scripts/IDLParser.pm
	@${REINPLACE_CMD} -e 's|"gperf|"${LOCALBASE}/bin/gperf|g' \
		${WRKSRC}/Source/WebCore/css/makevalues.pl \
		${WRKSRC}/Source/WebCore/css/makeprop.pl \
		${WRKSRC}/Source/WebCore/make-hash-tools.pl
#.if !defined(WITH_GCC_COMPILER)
#	@${REINPLACE_CMD} -e 's|-lstdc++|-lc++|g' \
#	@${REINPLACE_CMD} -e 's|-lstdc++||g' \
#		${WRKSRC}/GNUmakefile.in
#.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/GtkLauncher \
		${PREFIX}/bin/GtkLauncher-3

.include <bsd.port.post.mk>
