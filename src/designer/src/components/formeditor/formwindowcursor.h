/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
******************************************************************************/

#ifndef FORMWINDOWCURSOR_H
#define FORMWINDOWCURSOR_H

#include "formeditor_global.h"
#include "formwindow.h"
#include <QtDesigner/abstractformwindowcursor.h>

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

namespace qdesigner_internal {

class QT_FORMEDITOR_EXPORT FormWindowCursor: public QObject, public QDesignerFormWindowCursorInterface
{
    Q_OBJECT
public:
    explicit FormWindowCursor(FormWindow *fw, QObject *parent = nullptr);
    ~FormWindowCursor() override;

    QDesignerFormWindowInterface *formWindow() const override;

    bool movePosition(MoveOperation op, MoveMode mode) override;

    int position() const override;
    void setPosition(int pos, MoveMode mode) override;

    QWidget *current() const override;

    int widgetCount() const override;
    QWidget *widget(int index) const override;

    bool hasSelection() const override;
    int selectedWidgetCount() const override;
    QWidget *selectedWidget(int index) const override;

    void setProperty(const QString &name, const QVariant &value) override;
    void setWidgetProperty(QWidget *widget, const QString &name, const QVariant &value) override;
    void resetWidgetProperty(QWidget *widget, const QString &name) override;

public slots:
    void update();

private:
    FormWindow *m_formWindow;
};

}  // namespace qdesigner_internal

QT_END_NAMESPACE

#endif // FORMWINDOWCURSOR_H
