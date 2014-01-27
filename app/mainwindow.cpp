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

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::Form)
{
    m_ui->setupUi(this);

    m_accounts = new Accounts(this);

    // QList<User*> users = m_accounts->getUsers();
    int count = m_accounts->usersCount();
    if (count)  {
        for (int i=0; i < count; i++) {
            User* auser = m_accounts->getUser(i);
            if (auser)  {
                m_ui->cbActiveUser->addItem(auser->UserName());
            }
        }
        m_ui->cbActiveUser->setCurrentIndex(0);
    }
    connect(m_ui->cbActiveUser, SIGNAL(currentIndexChanged (int)), this,
            SLOT(currentIndexChanged(int)));

    QWidget* grantWidget = new QWidget(this);
    m_uiG = new Ui::grantForm();
    m_uiG->setupUi(grantWidget);

    QWidget* limitWidget = new QWidget(this);
    m_uilimit = new Ui::limitForm();
    m_uilimit->setupUi(limitWidget);

    QWidget* statusWidget = new QWidget(this);
    Ui::statusForm uiStatus;
    uiStatus.setupUi(statusWidget);

    m_ui->tab->insertTab(0, statusWidget, tr ("Status"));
    m_ui->tab->insertTab(1, grantWidget, tr("Grant"));
    // Probably we need separate limits and bounds to different tabs ...
    m_ui->tab->insertTab(2,limitWidget, tr("Limits and Bounds"));

    // yes,  all rest stub tabs
    m_ui->tab->removeTab(3);
    m_ui->tab->removeTab(3);
    m_ui->tab->removeTab(3);

    m_ui->tab->setCurrentIndex(0);

    setGrantTbCbs ();
    setLimitTbCbs ();

    Settings* settings = new Settings (this);

    QString workdir(settings->workdir());
    qDebug() << workdir;

    QString logfile(settings->logDir());
    qDebug() << logfile;

    QString version(settings->version());
    qDebug() << version;

    QString clepsydraD(settings->clepsydraDir());
    qDebug () << clepsydraD;

    qDebug () << settings->gracePeriod();
    qDebug () << settings->polltime();

    QString lockLasts(settings->lockLasts());
    qDebug () << lockLasts;

    delete settings;
    }

void MainWindow::currentIndexChanged (int index)
{
    qDebug() << index;
    if (m_accounts->getUser(index)->isAdmin() ) {
        // Disable all buttons and other controls since we should not
        // admin accounts.
        qDebug() << "Admin" << m_accounts->getUser(index)->UserName();
    } else {
        qDebug() << "Not admin"  << m_accounts->getUser(index)->UserName();
    }

}

void MainWindow::setGrantTbCbs ()
{
    connect(m_uiG->btnClearAllRestriction, SIGNAL(clicked ()), this,
            SLOT(btnClearAllRestrictionClicked()));
    connect(m_uiG->btnBypass, SIGNAL(clicked ()), this,
            SLOT(btnBypassClicked()));
    connect(m_uiG->btnClearBypass, SIGNAL(clicked ()), this,
            SLOT(btnClearBypassClicked()));
    connect(m_uiG->btnLockAccount, SIGNAL(clicked ()), this,
            SLOT(btnLockAccountClicked()));
    connect(m_uiG->btnUnlockAccount, SIGNAL(clicked ()), this,
            SLOT(btnUnlockAccountClicked()));
    connect(m_uiG->btnAddTime, SIGNAL(clicked ()), this,
            SLOT(btnAddTimeClicked()));
    connect(m_uiG->btnResetTime, SIGNAL(clicked ()), this,
            SLOT(btnResetTimeClicked()));
}

void MainWindow::setLimitTbCbs ()
{

    connect(m_uilimit->ckLimit, SIGNAL(stateChanged (int)), this,
            SLOT(ckLimitStateChanged(int)));
    connect(m_uilimit->ckLimitDay, SIGNAL(stateChanged (int)), this,
            SLOT(ckLimitDayStateChanged(int)));
    connect(m_uilimit->ckBound, SIGNAL(stateChanged (int)), this,
            SLOT(ckBoundStateChanged(int)));
    connect(m_uilimit->ckBoundDay, SIGNAL(stateChanged (int)), this,
            SLOT(ckBoundDayStateChanged(int)));

}

void MainWindow::btnClearAllRestrictionClicked ()
{
    qDebug() << "TODO : btnClearAllRestrictionClicked, wait for implementation";
}

void MainWindow::btnBypassClicked()
{
    qDebug() << "TODO : btnBypassClicked, wait for implementation";
}

void MainWindow::btnClearBypassClicked()
{
    qDebug() << "TODO : btnClearBypassClicked, wait for implementation";
}

void MainWindow::btnLockAccountClicked ()
{
    qDebug() << "TODO : btnLockAccountClicked, wait for implementation";
}

void MainWindow::btnUnlockAccountClicked ()
{
    qDebug() << "TODO : btnUnlockAccountClicked, wait for implementation";
}

void MainWindow::btnAddTimeClicked ()
{
    qDebug() << "TODO : btnAddTimeClicked, wait for implementation";
}

void MainWindow::btnResetTimeClicked ()
{
    qDebug() << "TODO : btnResetTimeClicked, wait for implementation";
}

void MainWindow::ckLimitStateChanged(int /*state*/)
{
    qDebug() << "TODO : ckLimitStateChanged, wait for implementation";
}

void MainWindow::ckLimitDayStateChanged(int /*state*/)
{
    qDebug() << "TODO : ckLimitDayStateChanged, wait for implementation";
}

void MainWindow::ckBoundStateChanged(int /*state*/)
{
    qDebug() << "TODO : ckckBoundStateChanged, wait for implementation";
}

void MainWindow::ckBoundDayStateChanged(int /*state*/)
{
    qDebug() << "TODO : ckckBoundDayStateChanged, wait for implementation";
}

