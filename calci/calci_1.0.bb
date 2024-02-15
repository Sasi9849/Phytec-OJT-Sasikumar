DESCRIPTION = "Simple helloworld application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/Sasi9849/calculator;protocol=https;branch=master"

S = "${WORKDIR}/git"

#SRCREV = "${AUTOREV}"
#PROVIDES += "myphy"
do_compile() {
    ${CC} math.c add.c sub.c mul.c div.c math.h ${LDFLAGS} -o app
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 app ${D}${bindir}
}
