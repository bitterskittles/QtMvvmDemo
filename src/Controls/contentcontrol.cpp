// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#include "contentcontrol.h"

#include <QQmlContext>
#include <QQmlEngine>

ContentControl::ContentControl(QQuickItem *parent) :
    QQuickItem(parent),
    m_content(NULL)
{
}

ContentControl::~ContentControl()
{
    this->setContent(NULL);
}

QQuickItem *ContentControl::content() const
{
    return this->m_content;
}

QVariant ContentControl::model() const
{
    return this->m_model;
}

void ContentControl::setContent(QQuickItem *value)
{
    if (this->m_content == value)
    {
        return;
    }

    this->disconnectContent();
    this->m_content = value;
    this->connectContent();
    emit contentChanged();
}

void ContentControl::setModel(const QVariant& value)
{
    if (this->m_model == value)
    {
        return;
    }

    this->m_model = value;
    this->onModelChanged();
    emit modelChanged();
}

void ContentControl::onModelChanged()
{
    if (this->m_model.isValid() == false)
    {
        this->setContent(NULL);
        return;
    }

    QObject *viewModel = qvariant_cast<QObject*>(this->m_model);
    if (viewModel == NULL)
    {
        this->setContent(NULL);
        return;
    }

    QString viewFilename = this->findViewFor(viewModel);
    if (viewFilename.isNull())
    {
        this->setContent(NULL);
        return;
    }

    QQuickItem *view = this->initializeView(viewFilename, this->m_model);
    if (view == NULL)
    {
        this->setContent(NULL);
        return;
    }

    this->setContent(view);
}

void ContentControl::connectContent()
{
    if  (this->m_content == NULL)
    {
        return;
    }

    this->m_content->setParentItem(this);
    this->doUpdate();

    static int heightChangedSignalIdx = -1;
    static int widthChangedSignalIdx = -1;
    static int doUpdateSlotIdx = -1;

    if (widthChangedSignalIdx < 0)
        widthChangedSignalIdx = QMetaMethod::fromSignal(&QQuickItem::widthChanged).methodIndex();
    if (heightChangedSignalIdx < 0)
        heightChangedSignalIdx = QMetaMethod::fromSignal(&QQuickItem::heightChanged).methodIndex();
    if (doUpdateSlotIdx < 0)
        doUpdateSlotIdx = ContentControl::staticMetaObject.indexOfSlot("doUpdate()");
    QMetaObject::connect(this->m_content, widthChangedSignalIdx, this, doUpdateSlotIdx);
    QMetaObject::connect(this->m_content, heightChangedSignalIdx, this, doUpdateSlotIdx);
}

void ContentControl::disconnectContent()
{
    if  (this->m_content == NULL)
    {
        return;
    }

    QQuickItem* oldContent = this->m_content;
    this->m_content = NULL;
    oldContent->setParentItem(NULL);
    delete oldContent;
}

QString ContentControl::findViewFor(const QObject *obj)
{
    QString modelName(obj->metaObject()->className());

    QString viewModelConvention = QStringLiteral("ViewModel");

    if (modelName.endsWith(viewModelConvention) == false)
    {
        return QString();
    }

    QString viewName = QString(modelName)
            .replace(
                modelName.length() - viewModelConvention.length(),
                viewModelConvention.length(),
                "View")
            .replace("ViewModels::", "Views::");

    QString viewFilename = "qml/" + QString(viewName).replace("::", "/") + ".qml";

    return viewFilename;
}

QQuickItem *ContentControl::initializeView(const QString &viewFilename, const QVariant &model)
{
    QQmlEngine engine;
    QQmlContext context(&engine, this);
    context.setContextProperty("dataContext", model);

    QQmlComponent component(&engine, QUrl::fromLocalFile(viewFilename));
    QQuickItem* view = qobject_cast<QQuickItem*>(component.create(&context));

    return view;
}

void ContentControl::doUpdate()
{
    if (this->m_content == NULL)
    {
        return;
    }

    this->setImplicitWidth(this->m_content->width());
    this->setImplicitHeight(this->m_content->height());
}
