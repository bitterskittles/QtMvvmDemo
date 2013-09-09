# Add more folders to ship with the application, here
folder_01.source = qml
folder_01.target =
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    ViewModels/mainviewmodel.cpp \
    ViewModels/itemviewmodel.cpp \
    Controls/contentcontrol.cpp \
    ViewModels/baritemviewmodel.cpp \
    ViewModels/fooitemviewmodel.cpp

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qml/Controls/Button.qml \
    qml/Views/MainView.qml \
    qml/Views/ItemView.qml \
    qml/Views/FooItemView.qml \
    qml/Views/BarItemView.qml

HEADERS += \
    ViewModels/mainviewmodel.h \
    ViewModels/itemviewmodel.h \
    Controls/contentcontrol.h \
    ViewModels/fooitemviewmodel.h \
    ViewModels/baritemviewmodel.h
