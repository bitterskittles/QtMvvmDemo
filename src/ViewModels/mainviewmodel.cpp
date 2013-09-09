// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#include "mainviewmodel.h"
#include "fooitemviewmodel.h"
#include "baritemviewmodel.h"

namespace ViewModels {

MainViewModel::MainViewModel() :
    QObject()
{
    this->m_displayName = QStringLiteral("Test application");
}

MainViewModel::MainViewModel(const MainViewModel &other) :
    QObject(),
    m_displayName(other.m_displayName),
    m_items(other.m_items)
{
}

MainViewModel::~MainViewModel()
{
}

QString MainViewModel::displayName() const
{
    return this->m_displayName;
}

QQmlListProperty<ItemViewModel> MainViewModel::items()
{
    return QQmlListProperty<ItemViewModel>(this, 0, &MainViewModel::count_items, &MainViewModel::at_items);
}

void MainViewModel::addItem()
{
    ItemViewModel *item = NULL;
    int type = qrand() % 3;
    int id = qrand() % 1000;

    switch (type)
    {
    case 0:
        item = new ItemViewModel(id, "item:" + QString::number(id));
        break;
    case 1:
        item = new FooItemViewModel(id, "item:" + QString::number(id));
        break;
    case 2:
        item = new BarItemViewModel(id, "item:" + QString::number(id));
        break;
    default:
        return;
    }

    this->m_items.append(item);
    emit itemsChanged();
}

void MainViewModel::quit()
{
}

void MainViewModel::setDisplayName(const QString &value)
{
    if (this->m_displayName == value)
    {
        return;
    }

    this->m_displayName = value;
    emit displayNameChanged();
}

int MainViewModel::count_items(QQmlListProperty<ItemViewModel> *list)
{
    MainViewModel* main = qobject_cast<MainViewModel*>(list->object);

    if (main)
    {
        return main->m_items.count();
    }

    return 0;
}

ItemViewModel *MainViewModel::at_items(QQmlListProperty<ItemViewModel> *list, int index)
{
    MainViewModel* main = qobject_cast<MainViewModel*>(list->object);

    if (main)
    {
        return main->m_items.at(index);
    }

    return NULL;
}

}
