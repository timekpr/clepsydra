// Copyright (c) 2014 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QVariantMap>
#include <QMainWindow>

#include "granttabwidget.h"
#include "limitstabwidget.h"
#include "statustabwidget.h"
#include "accounts.h"
#include "database.h"
#include "storage.h"

namespace Ui {
    class Form;
}

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    
private:
    //
    void setGrantTbCbs ();
    void setLimitTbCbs();

   void setCurrentUserIndex (int index);

   void LoadJsonData (const QString&);
   void map2Json (const QString&, const QVariantMap&);

   void updateChangesToWidgets (const QVariantMap&);

signals:
    void disableControls (bool);

public slots:
    //
    void currentIndexChanged (int);

    // grant tab
public slots:
    //
    void btnClearAllRestrictionClicked();
    void btnBypassClicked ();
    void btnClearBypassClicked ();
    void btnLockAccountClicked();
    void btnUnlockAccountClicked ();
    void btnAddTimeClicked ();
    void btnResetTimeClicked ();

private:
    Ui::Form *m_ui;
    GrantTabWidget*  m_grantWidget;
    StatusTabWidget* m_statusWidget;
    LimitsTabWidget* m_limitWidget;
    Accounts* m_accounts;
    QVariantMap m_settingsMap;
    Database *m_limits;
    // Storage* m_limits;
    QVariantMap m_defaultLimitsMap;
    int m_curUserIndex;
};

#endif // MAINWINDOW_H
