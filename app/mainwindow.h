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
#include <QMainWindow>

#include "accounts.h"
#include "ui_grant.h"

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

public slots:
    //
    void currentIndexChanged (int);

// grant UI tab
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
    //
    void addGrantForm();

private:
    Ui::Form *m_ui;
    Ui::grantForm *m_uiG;
    Accounts* m_accounts;

};

#endif // MAINWINDOW_H
