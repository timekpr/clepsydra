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

#include <QDebug>
#include <QList>
#include <QProgressBar>
#include "user.h"
#include "settings.h"
#include "mainwindow.h"

#include "mainwindow.h"
#include "ui_main.h"
#include "ui_status.h"
#include "ui_limits.h"
#include "ui_grant.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);

    m_accounts = new Accounts(this);

    QList<User*> users = m_accounts->getUsers();
    int count = users.count();
    if (count)  {
        for (int i=0; i < count; i++) {
            User* auser =users.at(i);
            ui->cbActiveUser->insertItem(0, auser->UserName());
            qDebug() << auser->UserName() << "is admin:" << auser->isAdmin();
        }
        ui->cbActiveUser->setCurrentIndex(0);
    }
    connect(ui->cbActiveUser, SIGNAL(currentIndexChanged (const QString&)), this,
            SLOT(currentIndexChanged(QString)));

    QWidget* grantWidget = new QWidget(this);
    Ui::grantForm uiG;
    uiG.setupUi(grantWidget);

    QWidget* limitWidget = new QWidget(this);
    Ui::limitForm uiLimit;
    uiLimit.setupUi(limitWidget);

    // Probably we need separate limits and bounds to different tabs ...
    ui->tab->addTab(grantWidget, tr("Grant"));
    ui->tab->addTab(limitWidget, tr("Limits and Bounds"));

    // yes,  both first two tabs ...
    ui->tab->removeTab(0);
    ui->tab->removeTab(0);

    Settings* settings = new Settings (this);
    delete settings;

//    Ui::statusForm statusForm;
//    QFrame* statusFrame  = ui->frStatus;
    //statusFramestatusFrame->setParent(statusForm);

}

void MainWindow::currentIndexChanged (const QString& newsUser)
{
    qDebug() << newsUser ;
}

void MainWindow::addGrantForm()
{

}

