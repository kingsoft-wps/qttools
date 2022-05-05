/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
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

#ifndef HEADERNODE_H
#define HEADERNODE_H

#include "aggregate.h"

#include <QtCore/qglobal.h>
#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class HeaderNode : public Aggregate
{
public:
    HeaderNode(Aggregate *parent, const QString &name);
    [[nodiscard]] bool docMustBeGenerated() const override;
    [[nodiscard]] bool isFirstClassAggregate() const override { return true; }
    [[nodiscard]] bool isRelatableType() const override { return true; }
    [[nodiscard]] QString title() const override { return (m_title.isEmpty() ? name() : m_title); }
    [[nodiscard]] QString subtitle() const override { return m_subtitle; }
    [[nodiscard]] QString fullTitle() const override
    {
        return (m_title.isEmpty() ? name() : name() + " - " + m_title);
    }
    bool setTitle(const QString &title) override
    {
        m_title = title;
        return true;
    }
    bool setSubtitle(const QString &subtitle) override
    {
        m_subtitle = subtitle;
        return true;
    }
    [[nodiscard]] QString nameForLists() const override { return title(); }
    [[nodiscard]] bool hasDocumentedChildren() const;

private:
    QString m_title {};
    QString m_subtitle {};
};

QT_END_NAMESPACE

#endif // HEADERNODE_H
