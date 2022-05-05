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

#ifndef ABSTRACTACTIONEDITOR_H
#define ABSTRACTACTIONEDITOR_H

#include <QtDesigner/sdk_global.h>

#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QDesignerFormEditorInterface;
class QDesignerFormWindowInterface;

class QDESIGNER_SDK_EXPORT QDesignerActionEditorInterface: public QWidget
{
    Q_OBJECT
public:
    explicit QDesignerActionEditorInterface(QWidget *parent, Qt::WindowFlags flags = {});
    virtual ~QDesignerActionEditorInterface();

    virtual QDesignerFormEditorInterface *core() const;

    virtual void manageAction(QAction *action) = 0;
    virtual void unmanageAction(QAction *action) = 0;

public Q_SLOTS:
    virtual void setFormWindow(QDesignerFormWindowInterface *formWindow) = 0;
};

QT_END_NAMESPACE

#endif // ABSTRACTACTIONEDITOR_H
