// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#ifndef BARITEMVIEWMODEL_H
#define BARITEMVIEWMODEL_H

#include <QQuickItem>

#include "itemviewmodel.h"

namespace ViewModels {

class BarItemViewModel : public ItemViewModel
{
    Q_OBJECT
public:
    explicit BarItemViewModel();
    BarItemViewModel(const BarItemViewModel& other);
    BarItemViewModel(const int& id, const QString& name);

    virtual ~BarItemViewModel();
    
signals:
    
public slots:
    
};

}

Q_DECLARE_METATYPE(ViewModels::BarItemViewModel)

#endif // BARITEMVIEWMODEL_H
