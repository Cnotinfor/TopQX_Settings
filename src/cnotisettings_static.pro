# ------------------------------
# CnotiSettings project has shared lib
#
TEMPLATE = lib
TARGET   = CnotiSettings
CONFIG  += staticlib create_prl

# Qt Modules
QT      -= gui

# ------------------------------
# The root folder where the folders ( src, tmp, docs, scripts ) are
#
ROOT_PROJECT_FOLDER = ..

DEFINES += CNOTI_STATIC_LIB
DEFINES += CNOTISETTINGS_LIB

CONFIG( debug, debug|release ) {
	TARGET = $${TARGET}_d
	BUILD_NAME = debug
}

CONFIG( release, debug|release ) {
	BUILD_NAME = release
}

# -------------------------------
# Customize folders
#
DESTDIR      = $${ROOT_PROJECT_FOLDER}/lib/static

include( files.pri )

HEADERS +=
