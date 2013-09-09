// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QList>
#include <QObject>
#include <QQmlListProperty>

#include "itemviewmodel.h"

namespace ViewModels {

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString displayName READ displayName WRITE setDisplayName NOTIFY displayNameChanged)
    Q_PROPERTY (QQmlListProperty<ViewModels::ItemViewModel> items READ items NOTIFY itemsChanged)

public:
    explicit MainViewModel();
    MainViewModel(const MainViewModel& other);

    virtual ~MainViewModel();

    QString displayName() const;
    QQmlListProperty<ItemViewModel> items();

    Q_INVOKABLE void addItem();
    Q_INVOKABLE void quit();

public slots:
    void setDisplayName(const QString&);

signals:
    void displayNameChanged();
    void itemsChanged();

private:
    QString m_displayName;
    QList<ItemViewModel *> m_items;

    static int count_items(QQmlListProperty<ItemViewModel> *list);
    static ItemViewModel *at_items(QQmlListProperty<ItemViewModel> *list, int index);
};

}

Q_DECLARE_METATYPE(ViewModels::MainViewModel)

#endif // MAINVIEWMODEL_H
