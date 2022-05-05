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

#include "tablewidget_taskmenu.h"
#include "tablewidgeteditor.h"

#include <QtDesigner/abstractformwindow.h>

#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qstyle.h>
#include <QtWidgets/qstyleoption.h>

#include <QtGui/qaction.h>

#include <QtCore/qcoreevent.h>
#include <QtCore/qvariant.h>
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

using namespace qdesigner_internal;

TableWidgetTaskMenu::TableWidgetTaskMenu(QTableWidget *button, QObject *parent)
    : QDesignerTaskMenu(button, parent),
      m_tableWidget(button),
      m_editItemsAction(new QAction(tr("Edit Items..."), this))
{
    connect(m_editItemsAction, &QAction::triggered, this, &TableWidgetTaskMenu::editItems);
    m_taskActions.append(m_editItemsAction);

    QAction *sep = new QAction(this);
    sep->setSeparator(true);
    m_taskActions.append(sep);
}


TableWidgetTaskMenu::~TableWidgetTaskMenu() = default;

QAction *TableWidgetTaskMenu::preferredEditAction() const
{
    return m_editItemsAction;
}

QList<QAction*> TableWidgetTaskMenu::taskActions() const
{
    return m_taskActions + QDesignerTaskMenu::taskActions();
}

void TableWidgetTaskMenu::editItems()
{
    m_formWindow = QDesignerFormWindowInterface::findFormWindow(m_tableWidget);
    if (m_formWindow.isNull())
        return;

    Q_ASSERT(m_tableWidget != nullptr);

    TableWidgetEditorDialog dlg(m_formWindow, m_tableWidget->window());
    TableWidgetContents oldCont = dlg.fillContentsFromTableWidget(m_tableWidget);
    if (dlg.exec() == QDialog::Accepted) {
        TableWidgetContents newCont = dlg.contents();
        if (newCont != oldCont) {
            ChangeTableContentsCommand *cmd = new ChangeTableContentsCommand(m_formWindow);
            cmd->init(m_tableWidget, oldCont, newCont);
            m_formWindow->commandHistory()->push(cmd);
        }
    }
}

void TableWidgetTaskMenu::updateSelection()
{
    if (m_editor)
        m_editor->deleteLater();
}

QT_END_NAMESPACE
