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

#include "abstractobjectinspector.h"

QT_BEGIN_NAMESPACE

/*!
    \class QDesignerObjectInspectorInterface

    \brief The QDesignerObjectInspectorInterface class allows you to
    change the focus of Qt Designer's object inspector.

    \inmodule QtDesigner

    You can use the QDesignerObjectInspectorInterface to change the
    current form window selection. For example, when implementing a
    custom widget plugin:

    \snippet lib/tools_designer_src_lib_sdk_abstractobjectinspector.cpp 0

    The QDesignerObjectInspectorInterface class is not intended to be
    instantiated directly. You can retrieve an interface to \QD's
    object inspector using the
    QDesignerFormEditorInterface::objectInspector() function.  A
    pointer to \QD's current QDesignerFormEditorInterface object (\c
    formEditor in the example above) is provided by the
    QDesignerCustomWidgetInterface::initialize() function's
    parameter. When implementing a custom widget plugin, you must
    subclass the QDesignerCustomWidgetInterface to expose your plugin
    to \QD.

    The interface provides the core() function that you can use to
    retrieve a pointer to \QD's current QDesignerFormEditorInterface
    object, and the setFormWindow() function that enables you to
    change the current form window selection.

    \sa QDesignerFormEditorInterface, QDesignerFormWindowInterface
*/

/*!
    Constructs an object inspector interface with the given \a parent
    and the specified window \a flags.
*/
QDesignerObjectInspectorInterface::QDesignerObjectInspectorInterface(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
}

/*!
    Destroys the object inspector interface.
*/
QDesignerObjectInspectorInterface::~QDesignerObjectInspectorInterface() = default;

/*!
    Returns a pointer to \QD's current QDesignerFormEditorInterface
    object.
*/
QDesignerFormEditorInterface *QDesignerObjectInspectorInterface::core() const
{
    return nullptr;
}

/*!
    \fn void QDesignerObjectInspectorInterface::setFormWindow(QDesignerFormWindowInterface *formWindow)

    Sets the currently selected form window to \a formWindow.
*/

QT_END_NAMESPACE
