// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#include "itemviewmodel.h"

namespace ViewModels {

ItemViewModel::ItemViewModel() :
    QObject(),
    m_id(0),
    m_name(QString::null)
{
}

ItemViewModel::ItemViewModel(const ItemViewModel &other) :
    QObject(),
    m_id(other.m_id),
    m_name(other.m_name)
{
}

ItemViewModel::ItemViewModel(const int &id, const QString &name) :
    QObject(),
    m_id(id),
    m_name(name)
{
}

ItemViewModel::~ItemViewModel()
{
}

int ItemViewModel::id() const
{
    return this->m_id;
}

QString ItemViewModel::name() const
{
    return this->m_name;
}

void ItemViewModel::setId(const int &value)
{
    if (this->m_id == value)
    {
        return;
    }

    this->m_id = value;
    emit idChanged();
}

void ItemViewModel::setName(const QString &value)
{
    if (this->m_name == value)
    {
        return;
    }

    this->m_name = value;
    emit nameChanged();
}

}
