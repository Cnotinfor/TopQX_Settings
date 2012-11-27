<<<<<<< HEAD
# ------------------------------
# CnotiSettings project has shared lib
#
TEMPLATE = lib
TARGET   = CnotiSettings

# Qt Modules
QT      -=  gui

# ------------------------------
# The root folder where the folders ( src, tmp, docs, scripts ) are
#
ROOT_PROJECT_FOLDER = ..

DEFINES += CNOTI_SHARED_LIB
DEFINES += CNOTISETTINGS_LIB

CONFIG( debug, debug|release ) {
	TARGET = $${TARGET}_d
	BUILD_NAME = debug
}

CONFIG(release, debug|release) {
	BUILD_NAME = release
}

# -------------------------------
# Customize folders
#
DESTDIR      = $${ROOT_PROJECT_FOLDER}/lib/shared

include( files.pri )
=======
TEMPLATE = lib
TARGET   = CnotiSettings
PRIFILE  = cnotisettings.pri


INCLUDEPATH += ../include

#####################################################################
# FOLDER OF THIS PROJECT ON WE HAVE (src, shared, static, docs )
# IF YOU DON'T HAVE SUB PROJECTS IS ONLY "ROOT_PROJECT_FOLDER = .."
ROOT_PROJECT_FOLDER = ..

# ###################################################################
# DEFAULT CONFIGURATIONS
# ###################################################################

DESTDIR = $${ROOT_PROJECT_FOLDER}/lib/shared

DEFINES += _BIND_TO_CURRENT_VCLIBS_VERSION CNOTISETTINGS_LIB CNOTI_SHARED_LIB

#MAKEFILE = Makefile_shared

CONFIG( debug, debug|release ) { 
    TARGET = $${TARGET}_d
    BUILD_NAME = debug
}
CONFIG( release, debug|release ) {
	BUILD_NAME = release
}

INCLUDEPATH += $${ROOT_PROJECT_FOLDER}/tmp/shared/$$BUILD_NAME/GeneratedFiles \
            $${ROOT_PROJECT_FOLDER}/tmp/shared/GeneratedFiles
OBJECTS_DIR += $${ROOT_PROJECT_FOLDER}/tmp/shared/$$BUILD_NAME/GeneratedFiles
MOC_DIR += $${ROOT_PROJECT_FOLDER}/tmp/shared/$$BUILD_NAME/GeneratedFiles
UI_DIR += $${ROOT_PROJECT_FOLDER}/tmp/shared/GeneratedFiles
RCC_DIR += $${ROOT_PROJECT_FOLDER}/tmp/shared/GeneratedFiles

include( $$PRIFILE )
>>>>>>> 5bf0f7860ade4c06b5161589d1f061403205e3e5
