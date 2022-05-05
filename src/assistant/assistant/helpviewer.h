/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Assistant of the Qt Toolkit.
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

#ifndef HELPVIEWER_H
#define HELPVIEWER_H

#include <QtCore/qglobal.h>
#include <QtCore/QUrl>

#include <QtGui/QFont>
#include <QtGui/QTextDocument>

#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class HelpViewerPrivate;

class HelpViewer : public QWidget
{
    Q_OBJECT
public:
    enum FindFlag {
        FindBackward = 0x01,
        FindCaseSensitively = 0x02
    };
    Q_DECLARE_FLAGS(FindFlags, FindFlag)

    HelpViewer(qreal zoom, QWidget *parent = nullptr);
    ~HelpViewer() override;

    QFont viewerFont() const;
    void setViewerFont(const QFont &font);

    void scaleUp();
    void scaleDown();

    void resetScale();
    qreal scale() const;

    QString title() const;

    QUrl source() const;
    void reload();
    void setSource(const QUrl &url);

    void print(QPagedPaintDevice *printer);

    QString selectedText() const;
    bool isForwardAvailable() const;
    bool isBackwardAvailable() const;

    bool findText(const QString &text, FindFlags flags, bool incremental,
        bool fromSearch);

    static bool isLocalUrl(const QUrl &url);
    static bool canOpenPage(const QString &url);
    static QString mimeFromUrl(const QUrl &url);
    static bool launchWithExternalApp(const QUrl &url);

    // implementation detail, not a part of the interface
    bool eventFilter(QObject *src, QEvent *event) override;

public slots:
#if QT_CONFIG(clipboard)
    void copy();
#endif
    void home();
    void forward();
    void backward();

signals:
    void titleChanged();
    void copyAvailable(bool yes);
    void sourceChanged(const QUrl &url);
    void forwardAvailable(bool enabled);
    void backwardAvailable(bool enabled);
    void highlighted(const QUrl &link);
    void printRequested();
    void loadFinished();
private:
    void doSetSource(const QUrl &url, bool reload);

    HelpViewerPrivate *d;
};

QT_END_NAMESPACE

#endif  // HELPVIEWER_H
