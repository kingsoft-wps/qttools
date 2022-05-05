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

#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "ui_connectdialog.h"
#include <QtWidgets/qdialog.h>

QT_BEGIN_NAMESPACE

class QDesignerFormWindowInterface;
class QPushButton;

namespace qdesigner_internal {

class ConnectDialog : public QDialog
{
    Q_OBJECT
public:
    ConnectDialog(QDesignerFormWindowInterface *formWindow, QWidget *sender, QWidget *receiver, QWidget *parent = nullptr);

    QString signal() const;
    QString slot() const;

    void setSignalSlot(const QString &signal, const QString &slot);

    bool showAllSignalsSlots() const;
    void setShowAllSignalsSlots(bool showIt);

private slots:
    void populateLists();
    void selectSignal(QListWidgetItem *item);
    void selectSlot(QListWidgetItem *item);
    void populateSignalList();
    void populateSlotList(const QString &signal = QString());
    void editSignals();
    void editSlots();

private:
    enum WidgetMode { NormalWidget, MainContainer, PromotedWidget };

    static WidgetMode widgetMode(QWidget *w,  QDesignerFormWindowInterface *formWindow);
    QPushButton *okButton();
    void setOkButtonEnabled(bool);
    void editSignalsSlots(QWidget *w, WidgetMode mode, int signalSlotDialogMode);

    QWidget *m_source;
    QWidget *m_destination;
    const WidgetMode m_sourceMode;
    const WidgetMode m_destinationMode;
    QDesignerFormWindowInterface *m_formWindow;
    Ui::ConnectDialog m_ui;
};

}

QT_END_NAMESPACE

#endif // CONNECTDIALOG_H
