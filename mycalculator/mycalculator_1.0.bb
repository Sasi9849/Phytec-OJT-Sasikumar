DESCRIPTION = "Simple calculator application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://math.h \
           file://add.c \
 	   file://sub.c \
	   file://mul.c \
           file://div.c \
           file://math.c "

S = "${WORKDIR}"

#SRCREV = "${AUTOREV}"

do_compile() {
    ${CC} math.c add.c sub.c mul.c div.c math.h ${LDFLAGS} -o app
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 app ${D}${bindir}
}
