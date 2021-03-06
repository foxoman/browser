/*
 * This file is part of Liri Browser
 *
 * Copyright (C) 2016 Tim Süberkrüb <tim.sueberkrueb@web.de>
 *
 * $BEGIN_LICENSE:GPL3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
*/

#ifndef TAB_H
#define TAB_H

#include <QObject>
#include <QUrl>
#include <QColor>

class Tab : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int uid READ uid  WRITE setUid  NOTIFY uidChanged)
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QUrl iconUrl READ iconUrl WRITE setIconUrl NOTIFY iconUrlChanged)
    Q_PROPERTY(QColor iconColor READ iconColor WRITE setIconColor NOTIFY iconColorChanged)
    Q_PROPERTY(bool adaptIconColor READ adaptIconColor WRITE setAdaptIconColor NOTIFY adaptIconColorChanged)
    Q_PROPERTY(bool canGoBack READ canGoBack  WRITE setCanGoBack  NOTIFY canGoBackChanged)
    Q_PROPERTY(bool canGoForward READ canGoForward WRITE setCanGoForward NOTIFY canGoForwardChanged)
    Q_PROPERTY(bool canReload READ canReload WRITE setCanReload NOTIFY canReloadChanged)
    Q_PROPERTY(bool loading READ loading WRITE setLoading NOTIFY loadingChanged)
    Q_PROPERTY(unsigned int loadProgress READ loadProgress WRITE setLoadProgress NOTIFY loadProgressChanged)
    Q_PROPERTY(bool valid READ valid NOTIFY validChanged)
    Q_PROPERTY(bool hasThemeColor READ hasThemeColor WRITE setHasThemeColor NOTIFY hasThemeColorChanged)
    Q_PROPERTY(QColor themeColor READ themeColor WRITE setThemeColor NOTIFY themeColorChanged)
public:
    explicit Tab(QObject *parent = nullptr, bool valid = true);

    unsigned int uid() const;
    void setUid(int uid);

    QUrl url() const;
    void setUrl(QUrl url);

    QString title() const;
    void setTitle(QString title);

    QUrl iconUrl() const;
    void setIconUrl(QUrl iconUrl);

    QColor iconColor() const;
    void setIconColor(QColor iconColor);

    bool adaptIconColor() const;
    void setAdaptIconColor(bool adaptIconColor);

    bool canGoBack() const;
    void setCanGoBack(bool canGoBack);

    bool canGoForward() const;
    void setCanGoForward(bool canGoForward);

    bool canReload() const;
    void setCanReload(bool canReload);

    bool loading() const;
    void setLoading(bool loading);

    unsigned int loadProgress() const;
    void setLoadProgress(unsigned int loadProgress);

    bool valid() const;

    bool hasThemeColor() const;
    void setHasThemeColor(bool hasThemeColor);

    QColor themeColor() const;
    void setThemeColor(QColor themeColor);

signals:
    void uidChanged(unsigned int uid);
    void urlChanged(QUrl url);
    void titleChanged(QString title);
    void iconUrlChanged(QUrl iconUrl);
    void iconColorChanged(QColor iconColor);
    void adaptIconColorChanged(bool adaptIconColor);
    void canGoBackChanged(bool canGoBack);
    void canGoForwardChanged(bool canGoForward);
    void canReloadChanged(bool canReload);
    void validChanged(bool valid);
    void loadingChanged(bool loading);
    void loadProgressChanged(unsigned int loadProgress);
    void hasThemeColorChanged(bool hasThemeColor);
    void themeColorChanged(QColor themeColor);

    void goBack();
    void goForward();
    void reload();
    void stop();
    void findText(QString text, bool backwards, bool caseSensitive);

public slots:

private:
    unsigned int m_uid;
    QUrl m_url;
    QString m_title;
    QUrl m_iconUrl;
    QColor m_iconColor;
    bool m_adaptIconColor;
    bool m_canGoBack;
    bool m_canGoForward;
    bool m_canReload;
    bool m_loading;
    int m_loadProgress;
    bool m_hasThemeColor;
    QColor m_themeColor;

    bool m_valid;
};

#endif // TAB_H
