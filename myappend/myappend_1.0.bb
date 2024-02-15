DESCRIPTION = "APPEND  application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://userprog.c"

S = "${WORKDIR}"
#PROVIDES += "myphy"
FILESEXTRAPATHS:prepend := "${THISDIR}/phy:"
do_compile() {
    ${CC} userprog.c ${LDFLAGS} -o userproge 
}
#DEPENDS = "mystatic"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 userproge ${D}${bindir}
}
