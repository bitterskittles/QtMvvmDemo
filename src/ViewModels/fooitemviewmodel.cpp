// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#include "fooitemviewmodel.h"

namespace ViewModels {

FooItemViewModel::FooItemViewModel() :
    ItemViewModel()
{
}

FooItemViewModel::FooItemViewModel(const FooItemViewModel &other) :
    ItemViewModel(other)
{
}

FooItemViewModel::FooItemViewModel(const int &id, const QString &name) :
    ItemViewModel(id, name)
{
}

FooItemViewModel::~FooItemViewModel()
{
}

}
