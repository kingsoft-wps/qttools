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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of Qt Designer.  This header
// file may change from version to version without notice, or even be removed.
//
// We mean it.
//

#ifndef QDESIGNER_FORMWINDOWCOMMAND_H
#define QDESIGNER_FORMWINDOWCOMMAND_H

#include "shared_global_p.h"

#include <QtGui/qundostack.h>

#include <QtCore/qpointer.h>

QT_BEGIN_NAMESPACE

class QDesignerFormEditorInterface;
class QDesignerFormWindowInterface;
class QDesignerPropertySheetExtension;

namespace qdesigner_internal {

class QDESIGNER_SHARED_EXPORT QDesignerFormWindowCommand: public QUndoCommand
{

public:
    QDesignerFormWindowCommand(const QString &description,
                               QDesignerFormWindowInterface *formWindow,
                               QUndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

    static void updateBuddies(QDesignerFormWindowInterface *form,
                              const QString &old_name, const QString &new_name);
protected:
    QDesignerFormWindowInterface *formWindow() const;
    QDesignerFormEditorInterface *core() const;
    QDesignerPropertySheetExtension* propertySheet(QObject *object) const;

    void cheapUpdate();

    void selectUnmanagedObject(QObject *unmanagedObject);
private:
    QPointer<QDesignerFormWindowInterface> m_formWindow;
};

} // namespace qdesigner_internal

QT_END_NAMESPACE

#endif // QDESIGNER_COMMAND_H
