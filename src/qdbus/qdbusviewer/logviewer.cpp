/****************************************************************************
**
** Copyright (C) 2016 Tasuku Suzuki <stasuku@gmail.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
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

#include "logviewer.h"

#include <QtGui/QContextMenuEvent>
#include <QtWidgets/QMenu>

LogViewer::LogViewer(QWidget *parent)
    : QTextBrowser(parent)
{
}

void LogViewer::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = createStandardContextMenu();
    QAction *action = menu->addAction(tr("Clear"));
    connect(action, &QAction::triggered, this, &QTextEdit::clear);
    menu->exec(event->globalPos());
    delete menu;
}
