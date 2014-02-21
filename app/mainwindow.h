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

// limit tab
public slots:
    void ckLimitStateChanged (int);
    void ckLimitDayStateChanged (int);
    void ckBoundStateChanged (int);
    void ckBoundDayStateChanged (int);

private:
    Ui::Form *m_ui;
    GrantTabWidget*  m_grantWidget;
    StatusTabWidget* m_statusWidget;
    LimitsTabWidget* m_limitWidget;
    Accounts* m_accounts;
    QVariantMap m_settingsMap;
    QVariantMap m_defaultLimitsMap;

};

#endif // MAINWINDOW_H
