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

#ifndef TABORDEREDITOR_H
#define TABORDEREDITOR_H

#include "tabordereditor_global.h"

#include <QtCore/qpointer.h>
#include <QtWidgets/qwidget.h>
#include <QtGui/qregion.h>
#include <QtGui/qfont.h>
#include <QtGui/qfontmetrics.h>

QT_BEGIN_NAMESPACE

class QUndoStack;
class QDesignerFormWindowInterface;

namespace qdesigner_internal {

class QT_TABORDEREDITOR_EXPORT TabOrderEditor : public QWidget
{
    Q_OBJECT

public:
    TabOrderEditor(QDesignerFormWindowInterface *form, QWidget *parent);

    QDesignerFormWindowInterface *formWindow() const;

public slots:
    void setBackground(QWidget *background);
    void updateBackground();
    void widgetRemoved(QWidget*);
    void initTabOrder();

private slots:
    void showTabOrderDialog();

protected:
    void paintEvent(QPaintEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;
    void resizeEvent(QResizeEvent *e) override;
    void showEvent(QShowEvent *e) override;

private:
    QRect indicatorRect(int index) const;
    int widgetIndexAt(const QPoint &pos) const;
    bool skipWidget(QWidget *w) const;

    QPointer<QDesignerFormWindowInterface> m_form_window;

    QWidgetList m_tab_order_list;

    QWidget *m_bg_widget;
    QUndoStack *m_undo_stack;
    QRegion m_indicator_region;

    QFontMetrics m_font_metrics;
    int m_current_index;
    bool m_beginning;
};

}  // namespace qdesigner_internal

QT_END_NAMESPACE

#endif
