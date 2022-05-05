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

#ifndef TASKMENU_H
#define TASKMENU_H

#include <QtDesigner/extension.h>

QT_BEGIN_NAMESPACE

class QAction;

class QDesignerTaskMenuExtension
{
public:
    Q_DISABLE_COPY_MOVE(QDesignerTaskMenuExtension)

    QDesignerTaskMenuExtension() = default;
    virtual ~QDesignerTaskMenuExtension() = default;

    virtual QAction *preferredEditAction() const;

    virtual QList<QAction*> taskActions() const = 0;
};
Q_DECLARE_EXTENSION_INTERFACE(QDesignerTaskMenuExtension, "org.qt-project.Qt.Designer.TaskMenu")


inline QAction *QDesignerTaskMenuExtension::preferredEditAction() const
{ return nullptr; }

QT_END_NAMESPACE

#endif // TASKMENU_H
