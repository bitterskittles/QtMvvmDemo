// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#include "baritemviewmodel.h"

namespace ViewModels {

BarItemViewModel::BarItemViewModel() :
    ItemViewModel()
{
}

BarItemViewModel::BarItemViewModel(const BarItemViewModel &other) :
    ItemViewModel(other)
{
}

BarItemViewModel::BarItemViewModel(const int &id, const QString &name) :
    ItemViewModel(id, name)
{
}

BarItemViewModel::~BarItemViewModel()
{
}

}
