// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#ifndef ITEMVIEWMODEL_H
#define ITEMVIEWMODEL_H

#include <QObject>

namespace ViewModels {

class ItemViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY (int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY (QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit ItemViewModel();
    ItemViewModel(const ItemViewModel& other);
    ItemViewModel(const int& id, const QString& name);

    virtual ~ItemViewModel();

    int id() const;
    QString name() const;

public slots:
    void setId(const int&);
    void setName(const QString&);

signals:
    void idChanged();
    void nameChanged();

private:
    int m_id;
    QString m_name;
};

}

Q_DECLARE_METATYPE(ViewModels::ItemViewModel)

#endif // ITEMVIEWMODEL_H
