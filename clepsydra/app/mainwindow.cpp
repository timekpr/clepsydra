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

#include <QDesktopWidget>
#include <QDebug>
#include <QList>
#include <QMap>
#include <QProgressBar>

#include "user.h"
#include "config.h"
#include "src/limitsmapper.h"
#include "mainwindow.h"

#include "mainwindow.h"
#include "ui_main.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::Form)
{
    m_ui->setupUi(this);
    m_limits = new LimitsMapper(this);
    m_grantWidget = new GrantTabWidget(this);    
    m_statusWidget = new StatusTabWidget(this);
    m_limitWidget =  new LimitsTabWidget(this);
    connect(this, SIGNAL(disableControls(bool) ),m_limitWidget, SLOT(disableControls(bool)));
    connect(this, SIGNAL(disableControls(bool) ),m_grantWidget, SLOT(disableControls(bool)));
    connect(this, SIGNAL(disableControls(bool) ),m_statusWidget, SLOT(disableControls(bool)));

    QRect windowRect = qApp->desktop()->availableGeometry ();
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            windowRect
        )
    );

    // get list of actual accounts in this computer
    m_accounts = new Accounts(this);

    int count = m_accounts->usersCount();
    // Fill required widgets components to account names
    if (count)  {
        for (int i=0; i < count; i++) {
            User* anuser = m_accounts->getUser(i);
            QVariantMap map4user;
            // Get users limits !
            bool found = m_limits->json2Map(anuser->UserName(), map4user );
            if (!found)  {
                map4user = m_limits->getDefaultLimits();
            }
            if (anuser)  {
                anuser->setUserLimits(map4user);
                m_ui->cbActiveUser->addItem(anuser->UserName());
            }
        }
    }

    connect(m_ui->cbActiveUser, SIGNAL(currentIndexChanged (int)), this,
            SLOT(currentIndexChanged(int)));
    m_ui->tab->insertTab(0, m_statusWidget, tr ("Status"));
    m_ui->tab->insertTab(1, m_grantWidget, tr("Grant"));
    // Probably we need separate limits and bounds to different tabs ...
    m_ui->tab->insertTab(2, m_limitWidget, tr("Limits and Bounds"));

    // yes,  all rest of tabs are stub
    m_ui->tab->removeTab(3);
    m_ui->tab->removeTab(3);
    m_ui->tab->removeTab(3);
    m_ui->tab->setCurrentIndex(0);

    int userIndex = m_accounts->getFirstNonAdminUserIndex();
    setCurrentUserIndex (userIndex);

    // Read application settings
    m_limits->readGroups2Map(m_settingsMap, "/etc/clepsydra/clepsydra.conf");

    // Read json limist for current user
    QVariantMap limits = m_accounts->getUser(m_curUserIndex)->getUserLimits();
    updateChangesToWidgets (limits);

    }

void MainWindow::setCurrentUserIndex(int nwIndex)
{
    m_ui->cbActiveUser->setCurrentIndex(nwIndex);
    m_curUserIndex = nwIndex;
    currentIndexChanged(m_curUserIndex);
}


void MainWindow::currentIndexChanged (int index)
{
    if (m_accounts->getUser(index)->isAdmin() ) {
        // Disable all buttons and other controls since we should not
        // close admin accounts.
        emit disableControls(true);
    } else {
        emit disableControls(false);
        bool locked = m_accounts->getUser(index)->isLocked();
        m_grantWidget->enableLockButton (locked);
    }
    m_curUserIndex = index;
}

void MainWindow::btnClearAllRestrictionClicked ()
{
    QVariantMap defaults;
    defaults = m_limits->getDefaultLimits();
    m_accounts->getUser(m_curUserIndex)->setUserLimits(defaults);
    // m_limits->map2Json(m_accounts->getUser(m_curUserIndex)->UserName(),
    //   m_accounts->getUser(m_curUserIndex)->getUserLimits());
    m_grantWidget->enableLockButton (false);
}

void MainWindow::updateChangesToWidgets (const QVariantMap& map)
{
    m_limitWidget->setLimits(map);
    m_statusWidget->setStatus(map);
}

void MainWindow::btnBypassClicked()
{
    qDebug() << "TODO : btnBypassClicked, wait for implementation";
}

void MainWindow::btnClearBypassClicked()
{
    qDebug() << "TODO : btnClearBypassClicked, wait for implementation";
    // m_accounts->getUser(index)->isAdmin()
}

void MainWindow::btnLockAccountClicked ()
{
     m_accounts->getUser(m_curUserIndex)
             ->setValue(QString(CLEPSYDRA_LOCKED), true );
//     m_limits->map2Json(m_accounts->getUser(m_curUserIndex)->UserName(),
//        m_accounts->getUser(m_curUserIndex)->getUserLimits());
     m_grantWidget->enableLockButton (true);
}

void MainWindow::btnUnlockAccountClicked ()
{
    m_accounts->getUser(m_curUserIndex)
            ->setValue(CLEPSYDRA_LOCKED, false);
//    m_limits->map2Json(m_accounts->getUser(m_curUserIndex)->UserName(),
//       m_accounts->getUser(m_curUserIndex)->getUserLimits());
    m_grantWidget->enableLockButton (false);
}

void MainWindow::btnAddTimeClicked ()
{
    qDebug() << "TODO : btnAddTimeClicked, wait for implementation";
}

void MainWindow::btnResetTimeClicked ()
{
    qDebug() << "TODO : btnResetTimeClicked, wait for implementation";
}
