TEMPLATE = app
CONFIG += console
#CONFIG -= qt
QT       += core gui

#QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ../../boost_minGW/boost_1_49_0
#INCLUDEPATH += ../Qt_simple_gui

SOURCES += main.cpp \
    iview_factory_unit_test.cpp \
    format_table.cpp

HEADERS += \
    is_const_source.hpp \
    is_const_view.hpp \
    iview_factory_unit_test.hpp \
    image_view_exception.hpp \
    image_view_typedef.hpp \
    iview_factory.hpp \
    format_table.hpp

