// --------------------------------------------------------------------------------------------------------------------
//   Copyright © 2013 BitterSkittles.
//   This program is free software. It comes without any warranty, to
//   the extent permitted by applicable law. You can redistribute it
//   and/or modify it under the terms of the Do What The Fuck You Want
//   To Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
// --------------------------------------------------------------------------------------------------------------------

#ifndef CONTENTCONTROL_H
#define CONTENTCONTROL_H

#include <QQuickItem>

class ContentControl : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY (QQuickItem *content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY (QVariant model READ model WRITE setModel NOTIFY modelChanged)
public:
    explicit ContentControl(QQuickItem *parent = 0);
    
    virtual ~ContentControl();

    QQuickItem *content() const;
    QVariant model() const;
public slots:
    void setModel(const QVariant&);
    void setContent(QQuickItem*);

signals:
    void contentChanged();
    void modelChanged();

protected:
    virtual void onModelChanged();

private:
    QQuickItem *m_content;
    QVariant m_model;

    void connectContent();
    void disconnectContent();
    QString findViewFor(const QObject *obj);
    QQuickItem *initializeView(const QString &viewFilename, const QVariant &model);

private slots:
    void doUpdate();
};

#endif // CONTENTCONTROL_H
