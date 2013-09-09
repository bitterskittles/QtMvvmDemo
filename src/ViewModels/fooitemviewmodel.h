// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#ifndef FOOITEMVIEWMODEL_H
#define FOOITEMVIEWMODEL_H

#include <QQuickItem>

#include "itemviewmodel.h"

namespace ViewModels {

class FooItemViewModel : public ItemViewModel
{
    Q_OBJECT
public:
    explicit FooItemViewModel();
    FooItemViewModel(const FooItemViewModel& other);
    FooItemViewModel(const int& id, const QString& name);

    virtual ~FooItemViewModel();
    
signals:
    
public slots:
    
};

}

Q_DECLARE_METATYPE(ViewModels::FooItemViewModel)

#endif // FOOITEMVIEWMODEL_H
