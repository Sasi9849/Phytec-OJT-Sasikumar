require recipes-core/images/core-image-minimal.bb
#IMAGE_INSTALL:append = "usbutils"
IMAGE_FEATURES = "splash debug-tweaks"
#IMAGE_INSTALL += "mystatic-dev mystatic-staticdev myhello"
IMAGE_INSTALL += "hello"
