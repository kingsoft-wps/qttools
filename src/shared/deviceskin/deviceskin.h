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
**
**
**
**
**
**
**
**
**
**
**
******************************************************************************/

#ifndef SKIN_H
#define SKIN_H

#include <QtWidgets/QWidget>

#include <QtGui/QPixmap>
#include <QtGui/QPolygon>
#include <QtGui/QRegion>

#include <QtCore/QList>

QT_BEGIN_NAMESPACE

namespace qvfb_internal {
    class CursorWindow;
}

class QTextStream;

// ------- Button Area
struct DeviceSkinButtonArea {
    QString name;
    int keyCode{0};
    QPolygon area;
    QString text;
    bool activeWhenClosed{false};
    bool toggleArea{false};
    bool toggleActiveArea{false};
};

// -------- Parameters
struct DeviceSkinParameters {
    enum ReadMode { ReadAll, ReadSizeOnly };
    bool read(const QString &skinDirectory,  ReadMode rm,  QString *errorMessage);
    bool read(QTextStream &ts, ReadMode rm, QString *errorMessage);

    QSize screenSize() const { return screenRect.size(); }
    QSize secondaryScreenSize() const;
    bool hasSecondaryScreen() const;

    QString skinImageUpFileName;
    QString skinImageDownFileName;
    QString skinImageClosedFileName;
    QString skinCursorFileName;

    QImage skinImageUp;
    QImage skinImageDown;
    QImage skinImageClosed;
    QImage skinCursor;

    QRect screenRect;
    QRect backScreenRect;
    QRect closedScreenRect;
    int screenDepth;
    QPoint cursorHot;
    QList<DeviceSkinButtonArea> buttonAreas;
    QList<int> toggleAreaList;

    int joystick;
    QString prefix;
    bool hasMouseHover;
};

// --------- Skin Widget
class DeviceSkin : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceSkin(const DeviceSkinParameters &parameters,  QWidget *p );
    ~DeviceSkin( );

    QWidget *view() const { return m_view; }
    void setView( QWidget *v );

    QWidget *secondaryView() const { return m_secondaryView; }
    void setSecondaryView( QWidget *v );

    void setZoom( double );
    void setTransform(const QTransform &);

    bool hasCursor() const;

    QString prefix() const  {return m_parameters.prefix;}

signals:
    void popupMenu();
    void skinKeyPressEvent(int code, const QString& text, bool autorep);
    void skinKeyReleaseEvent(int code, const QString& text, bool autorep);

protected slots:
    void skinKeyRepeat();
    void moveParent();

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *) override;

private:
    void calcRegions();
    void flip(bool open);
    void updateSecondaryScreen();
    void loadImages();
    void startPress(int);
    void endPress();

    const DeviceSkinParameters m_parameters;
    QList<QRegion> buttonRegions;
    QPixmap skinImageUp;
    QPixmap skinImageDown;
    QPixmap skinImageClosed;
    QPixmap skinCursor;
    QWidget *parent;
    QWidget  *m_view;
    QWidget *m_secondaryView;
    QPoint parentpos;
    QPoint clickPos;
    bool buttonPressed;
    int buttonIndex;
    QTransform transform;
    qvfb_internal::CursorWindow *cursorw;

    bool joydown;
    QTimer *t_skinkey;
    QTimer *t_parentmove;
    int onjoyrelease;

    bool flipped_open;
};

QT_END_NAMESPACE

#endif
