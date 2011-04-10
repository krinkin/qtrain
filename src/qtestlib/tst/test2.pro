
SOURCES += \
    main.cpp \
    ../app/summator.cpp \
    ../app/summatorform.cpp

CONFIG   += qtestlib
#CONFIG   -= app_bundle

TEMPLATE = app

QT       += testlib

TARGET = tst_testtest

HEADERS += \
    testsum.h \
    testform.h \
    ../app/summator.h \
    ../app/summatorform.h
