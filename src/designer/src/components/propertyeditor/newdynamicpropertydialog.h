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

#ifndef NEWDYNAMICPROPERTYDIALOG_P_H
#define NEWDYNAMICPROPERTYDIALOG_P_H

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

#include "propertyeditor_global.h"
#include <QtWidgets/qdialog.h>
#include <QtCore/qvariant.h>

QT_BEGIN_NAMESPACE

class QAbstractButton;
class QDesignerDialogGuiInterface;

namespace qdesigner_internal {

namespace Ui
{
    class NewDynamicPropertyDialog;
}

class QT_PROPERTYEDITOR_EXPORT NewDynamicPropertyDialog: public QDialog
{
    Q_OBJECT
public:
    explicit NewDynamicPropertyDialog(QDesignerDialogGuiInterface *dialogGui, QWidget *parent = nullptr);
    ~NewDynamicPropertyDialog();

    void setReservedNames(const QStringList &names);
    void setPropertyType(int  t);

    QString propertyName() const;
    QVariant propertyValue() const;

private slots:

    void on_m_buttonBox_clicked(QAbstractButton *btn);
    void nameChanged(const QString &);

private:
    bool validatePropertyName(const QString& name);
    void setOkButtonEnabled(bool e);
    void information(const QString &message);

    QDesignerDialogGuiInterface *m_dialogGui;
    Ui::NewDynamicPropertyDialog *m_ui;
    QStringList m_reservedNames;
};

}  // namespace qdesigner_internal

QT_END_NAMESPACE

#endif // NEWDYNAMICPROPERTYDIALOG_P_H
