#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#
# Please view me with 4 column tabs!

.if !defined(_POSTMKINCLUDED) && !defined(Gnome_Experimental_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gnome_Experimental_Include_MAINTAINER=	gnome@FreeBSD.org
Gnome_Experimental_Include=				bsd.gnome.mk

.if !defined(Gnome_Pre_Include)
.error bsd.gnome-experimental.mk is meant only to be included by bsd.gnome.mk.
.endif

# The contents of this file are designed to override those in bsd.gnome.mk.
# Only include in here what must be overridden. Otherwise, you're just
# asking for trouble inevitably.

glib20_LIB_DEPENDS=	glib-2.0.505:${PORTSDIR}/devel/glib20

gtk20_LIB_DEPENDS=	gtk-x11-2.0.505:${PORTSDIR}/x11-toolkits/gtk20

gal2_LIB_DEPENDS=   gal-2.4.0:${PORTSDIR}/x11-toolkits/gal2
.endif
# End of use part.
