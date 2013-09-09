// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"

#include <QtQml>
#include "Controls/contentcontrol.h"
#include "ViewModels/mainviewmodel.h"
#include "ViewModels/fooitemviewmodel.h"
#include "ViewModels/baritemviewmodel.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<ViewModels::ItemViewModel>("ViewModels", 1, 0, "ItemViewModel");
    qmlRegisterType<ViewModels::FooItemViewModel>("ViewModels", 1, 0, "FooItemViewModel");
    qmlRegisterType<ViewModels::BarItemViewModel>("ViewModels", 1, 0, "BarItemViewModel");
    qmlRegisterType<ViewModels::MainViewModel>("ViewModels", 1, 0, "MainViewModel");
    qmlRegisterType<ContentControl>("Controls", 1, 0, "ContentControl");

    QGuiApplication app(argc, argv);

    ViewModels::MainViewModel mainViewModel;

    QtQuick2ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("dataContext", &mainViewModel);
    viewer.setMainQmlFile(QStringLiteral("qml/Views/MainView.qml"));
    viewer.showExpanded();

    return app.exec();
}
