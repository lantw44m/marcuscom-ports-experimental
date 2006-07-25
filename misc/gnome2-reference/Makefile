# New ports collection makefile for:	gnome2-reference
# Date created:		2006-07-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	gnome2-reference
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for GNOME 2 programming references

REF_LIST=	accessibility/at-spi-reference \
		accessibility/atk-reference \
		accessibility/gail-reference \
		databases/libgda2-reference \
		databases/libgda3-reference \
		databases/libgnomedb-reference \
		devel/ORBit2-reference \
		devel/gconf2-reference \
		devel/glib20-reference \
		devel/glibmm-reference \
		devel/gnome-vfs-reference \
		devel/libbonobo-reference \
		devel/libglade2-reference \
		devel/libsoup-reference \
		graphics/cairo-reference \
		graphics/libgnomecanvas-reference \
		net/linc-reference \
		print/libgnomeprint-reference \
		textproc/gtkspell-reference \
		textproc/libxml2-reference \
		textproc/libxslt-reference \
		x11/gnome-desktop-reference \
		x11/gnome-panel-reference \
		x11/libgnome-reference \
		x11-fonts/fontconfig-reference \
		x11-toolkits/gal2-reference \
		x11-toolkits/gtk20-reference \
		x11-toolkits/gtkmm20-reference \
		x11-toolkits/gtkmm24-reference \
		x11-toolkits/gtksourceview-reference \
		x11-toolkits/libbonoboui-reference \
		x11-toolkits/libgnomeui-reference \
		x11-toolkits/libwnck-reference \
		x11-toolkits/pango-reference \
		x11-toolkits/vte-reference

OPTIONS=	# empty
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.for ref in ${REF_LIST}
OPTIONS+=	${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//:U} "Install ${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//} programing reference " on
.endfor

.for ref in ${REF_LIST}
.if !defined(WITHOUT_${ref:C|^[^/]+/([^/]+).*|\1|:S/-reference//:U})
RUN_DEPENDS+=	${ref:C|^[^/]+/([^/]+).*|\1|}>0:${PORTSDIR}/${ref}
.endif
.endfor

do-install:	# empty

.include <bsd.port.post.mk>
