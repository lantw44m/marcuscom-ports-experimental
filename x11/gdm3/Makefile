# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gdm
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 version of xdm display manager

BUILD_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity3 \
		itstool:${PORTSDIR}/textproc/itstool \
    		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	ck-connector:${PORTSDIR}/sysutils/consolekit \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gtk-1:${PORTSDIR}/sysutils/polkit-gnome \
		upower-glib:${PORTSDIR}/sysutils/upower \
		nss3:${PORTSDIR}/security/nss \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		accountsservice:${PORTSDIR}/sysutils/accountsservice \
		xklavier:${PORTSDIR}/x11/libxklavier \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity3 \
		gnome-settings-daemon>=3.0.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		gnome-keyring-3:${PORTSDIR}/security/gnome-keyring3 \
		gnome-session>=3.0.0:${PORTSDIR}/x11/gnome-session3 \
		gnome-icon-theme-symbolic>=0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
# used in scripts
RUN_DEPENDS+=	xrdb:${PORTSDIR}/x11/xrdb \
		setxkbmap:${PORTSDIR}/x11/setxkbmap \
		xmodmap:${PORTSDIR}/x11/xmodmap \
		xterm:${PORTSDIR}/x11/xterm

CONFLICTS=	gdm-2.[0-9]*

USERS=		gdm
GROUPS=		gdm

LATEST_LINK=	gdm3
USE_XZ=		yes
USE_LDCONFIG=	yes
USE_XORG=	dmx dmxproto
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_RC_SUBR=	gdm
USE_GNOME_SUBR=	yes
USE_GMAKE=	yes
USES=		gettext pathfix pkgconfig
USE_GNOME=	intlhack gnomehier librsvg2 gnomeprefix gnomepanel3 dconf
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	org.gnome.login-screen.gschema.xml
CONFIGURE_ARGS=	--with-working-directory=${PREFIX}/etc/gdm/home \
		--with-at-spi-registryd-directory=${LOCALBASE}/libexec \
		--enable-authentication-scheme=pam \
		--with-console-kit \
		--with-initial-vt=9 \
		--with-systemd=no
# this is a hack until we can get our own pam dir and dir in order.
CONFIGURE_ARGS+=--with-default-pam-config=redhat
CPPFLAGS+=	-I${LOCALBASE}/include -DHAS_SA_LEN
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGLIBS=	-lm
CONFIGURE_ENV=	LIBS="${CONFIGLIBS}" \
		GTKDOC="false" \
		ac_cv_header_execinfo_h=no

SUB_FILES+=	gdm.pam

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

GNOME_LOCALSTATEDIR=	/var

OPTIONS_DEFINE=	IPV6 KEYRING
OPTIONS_DEFAULT=KEYRING

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MKEYRING}
LIB_DEPENDS+=	gnome-keyring:${PORTSDIR}/security/libgnome-keyring
SUB_LIST+=	PAM_KEYRING=
.else
SUB_LIST+=	PAM_KEYRING=\#
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|root:root|root:wheel|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/daemon/gdm-session-worker.c
#		${WRKSRC}/gui/simple-greeter/extensions/password/gdm-password.pam
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|/usr/bin/X|${LOCALBASE}/bin/X|g' \
		-e 's|/usr/bin/Xorg|${LOCALBASE}/bin/Xorg|g' \
		${WRKSRC}/configure ${WRKSRC}/daemon/*.c ${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e 's|/at-spi-registryd|/at-spi2-registryd|g' \
		${WRKSRC}/gui/simple-chooser/gdm-host-chooser.c \
		${WRKSRC}/gui/simple-chooser/chooser-main.c
	@${REINPLACE_CMD} -e 's|/etc/X11|${LOCALBASE}/etc/X11|g' \
		${WRKSRC}/data/Init.in \
		${WRKSRC}/data/PostLogin \
		${WRKSRC}/data/PostSession.in \
		${WRKSRC}/data/PreSession.in \
		${WRKSRC}/data/Xsession.in
	@${RM}	${WRKSRC}/data/applications/gdm-simple-greeter.desktop \
		${WRKSRC}/data/applications/gdm-simple-greeter.desktop.in \
		${WRKSRC}/data/applications/gnome-mag.desktop \
		${WRKSRC}/data/applications/gnome-shell.desktop \
		${WRKSRC}/data/applications/gok.desktop
#		${WRKSRC}/data/applications/orca-screen-reader.desktop

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${INSTALL_DATA} ${WRKSRC}/data/gdm.conf-custom \
		${PREFIX}/etc/gdm/custom.conf.default
	${MKDIR} ${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/gdm.pam ${PREFIX}/etc/pam.d/gdm-welcome
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}
	@dconf update
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# logwtmp lives here.
.if ${OSVERSION} < 900000
CONFIGLIBS+=	-lutil
.endif

.include <bsd.port.post.mk>
