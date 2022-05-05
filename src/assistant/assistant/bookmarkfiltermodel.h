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
#ifndef BOOKMARKFILTERMODEL_H
#define BOOKMARKFILTERMODEL_H

#include <QtCore/QPersistentModelIndex>

#include <QtCore/QAbstractProxyModel>
#include <QtCore/QSortFilterProxyModel>

QT_BEGIN_NAMESPACE

class BookmarkItem;
class BookmarkModel;

typedef QList<QPersistentModelIndex> PersistentModelIndexCache;

class BookmarkFilterModel : public QAbstractProxyModel
{
    Q_OBJECT
public:
    explicit BookmarkFilterModel(QObject *parent = nullptr);

    void setSourceModel(QAbstractItemModel *sourceModel) override;

    int rowCount(const QModelIndex &index) const override;
    int columnCount(const QModelIndex &index) const override;

    QModelIndex mapToSource(const QModelIndex &proxyIndex) const override;
    QModelIndex mapFromSource(const QModelIndex &sourceIndex) const override;

    QModelIndex parent(const QModelIndex &child) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    Qt::DropActions supportedDropActions () const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    void filterBookmarks();
    void filterBookmarkFolders();

private slots:
    void changed(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void rowsInserted(const QModelIndex &parent, int start, int end);
    void rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end);
    void rowsRemoved(const QModelIndex &parent, int start, int end);
    void layoutAboutToBeChanged();
    void layoutChanged();
    void modelAboutToBeReset();
    void modelReset();

private:
    void setupCache(const QModelIndex &parent);
    void collectItems(const QModelIndex &parent);

private:
    BookmarkModel *sourceModel = nullptr;
    PersistentModelIndexCache cache;
    QPersistentModelIndex indexToRemove;
    bool hideBookmarks = true;
};

// -- BookmarkTreeModel

class BookmarkTreeModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    BookmarkTreeModel(QObject *parent = nullptr);
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

QT_END_NAMESPACE

#endif // BOOKMARKFILTERMODEL_H
