# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-utils
PORTVERSION=	3.12.0
PORTEPOCH=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 support utilities

RUN_DEPENDS=	baobab>=3.0:${PORTSDIR}/deskutils/baobab \
		gnome-screenshot>=3.0:${PORTSDIR}/deskutils/gnome-screenshot \
		gnote>=3.0:${PORTSDIR}/deskutils/gnote \
		gnome-contacts>=3.0:${PORTSDIR}/deskutils/gnome-contacts \
		gnome-search-tool>=3.0:${PORTSDIR}/deskutils/gnome-search-tool \
		gnome-dictionary>=3.0:${PORTSDIR}/deskutils/gnome-dictionary \
		gnome-system-log>=3.0:${PORTSDIR}/deskutils/gnome-system-log \
		gnome-font-viewer>=3.0:${PORTSDIR}/deskutils/gnome-font-viewer \
		gnome-system-monitor>=3.0:${PORTSDIR}/sysutils/gnome-system-monitor \
		gnome-photos>=3.0:${PORTSDIR}/deskutils/gnome-photos \
		gnome-clocks>=3.0:${PORTSDIR}/deskutils/gnome-clocks \
		gnome-maps>=3.0:${PORTSDIR}/deskutils/gnome-maps

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	DOCS 
DOCS_DESC=	Build Gnome Documents (pulls in tracker)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
RUN_DEPENDS+=	gnome-documents>=0:${PORTSDIR}/deskutils/gnome-documents
.endif

.include <bsd.port.mk>
