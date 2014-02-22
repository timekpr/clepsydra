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
#include "config.h"
#include "src/limitsmapper.h"
#include "settings.h"
#include "mainwindow.h"

#include "mainwindow.h"
#include "ui_main.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::Form)
{
    m_ui->setupUi(this);
    m_grantWidget = new GrantTabWidget(this);
    m_statusWidget = new StatusTabWidget(this);
    m_limitWidget =  new LimitsTabWidget(this);
    connect(this, SIGNAL(disableControls(bool) ),m_limitWidget, SLOT(disableControls(bool)));
    connect(this, SIGNAL(disableControls(bool) ),m_grantWidget, SLOT(disableControls(bool)));
    connect(this, SIGNAL(disableControls(bool) ),m_statusWidget, SLOT(disableControls(bool)));

    m_accounts = new Accounts(this);

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
    m_ui->tab->insertTab(0, m_statusWidget, tr ("Status"));
    m_ui->tab->insertTab(1, m_grantWidget, tr("Grant"));
    // Probably we need separate limits and bounds to different tabs ...
    m_ui->tab->insertTab(2, m_limitWidget, tr("Limits and Bounds"));

    // yes,  all rest stub tabs
    m_ui->tab->removeTab(3);
    m_ui->tab->removeTab(3);
    m_ui->tab->removeTab(3);

    m_ui->tab->setCurrentIndex(0);

    LimitsMapper* limits = new LimitsMapper(this);
    limits->readGroups2Map(m_settingsMap, "/etc/clepsydra/clepsydra.conf");
    qDebug() << m_settingsMap.keys();

    limits->readGroups2Map(m_defaultLimitsMap, "/etc/clepsydra/clepsydradefault");
    qDebug() << m_defaultLimitsMap.keys();
    QVariantMap map = m_defaultLimitsMap.value("default").toMap();
    m_limitWidget->setLimits(map);

    // map 'var'  ---> default settings for everyone, format ('var'), QMap ?
    //     'user' ---> user name in string format, QString ('user'), QString('joe')
    //     'bound' ---> Bound info?, format, QString, QString?
    //     'subaction' ---> action to execute, enum { ClearAllRestriction, Lock, Bypass, ClearBypass, ResetTime, AddTime };
    //     'operation'
    //     'time'

    delete limits;
    }

void MainWindow::currentIndexChanged (int index)
{
    if (m_accounts->getUser(index)->isAdmin() ) {
        // Disable all buttons and other controls since we should not
        // admin accounts.
        emit disableControls(true);
        qDebug() << "Admin" << m_accounts->getUser(index)->UserName();
    } else {
        emit disableControls(false);
        qDebug() << "Not admin"  << m_accounts->getUser(index)->UserName();
    }
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

