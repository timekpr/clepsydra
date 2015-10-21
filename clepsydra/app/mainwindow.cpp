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

#include <QJsonObject>
#include <QDesktopWidget>
#include <QJsonDocument>
#include <QDebug>
#include <QList>
#include <QFile>
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

    limits->readGroups2Map(m_defaultLimitsMap, "/etc/clepsydra/clepsydradefault");
    QVariantMap map = m_defaultLimitsMap.value("default").toMap();
    m_limitWidget->setLimits(map);
    m_statusWidget->setStatus(map);

    int userId = m_accounts->getFirstNonAdminUserIndex();
    setCurrentUserIndex (userId);

    // LoadJsonData ();

    // temp
    QVariantMap limitMap;
    m_limitWidget->getLimits(limitMap);

    map2Json (limitMap);

    delete limits;
    }

void MainWindow::map2Json(const QVariantMap& map )
{
    QJsonDocument d = QJsonDocument::fromVariant(map);
    if (d.isEmpty())  {
        qDebug () << "empty";
    } else {
        QFile file("/tmp/tempcheck.json");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << d.toJson();
        file.close();
    }
}

void MainWindow::LoadJsonData ()
{
    QString val;
    QFile file;
    file.setFileName("/tmp/clepsydra.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        val = file.readAll();
        file.close();
    } else {
        qDebug () << "json file not found";
        return;
    }

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    if (d.isEmpty()) {
        qDebug () << "Not valid document.";
        return;
    }

    QJsonObject obj = d.object();
    foreach (QJsonValue usersO , obj) {
        qDebug () << usersO;
    }
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
        // admin accounts.
        emit disableControls(true);        
    } else {
        emit disableControls(false);
        bool locked = m_accounts->getUser(index)->isLocked();
        m_grantWidget->disableLockBtns (locked);
    }

    m_curUserIndex = index;
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
    // m_accounts->getUser(index)->isAdmin()
}

void MainWindow::btnLockAccountClicked ()
{
     m_accounts->getUser(m_curUserIndex)
             ->setValue(QString(CLEPSYDRA_LOCKED), true );

     m_grantWidget->disableLockBtns (true);
}

void MainWindow::btnUnlockAccountClicked ()
{
    m_accounts->getUser(m_curUserIndex)
            ->setValue(CLEPSYDRA_LOCKED, false);
    m_grantWidget->disableLockBtns (false);
}

void MainWindow::btnAddTimeClicked ()
{
    qDebug() << "TODO : btnAddTimeClicked, wait for implementation";
}

void MainWindow::btnResetTimeClicked ()
{
    qDebug() << "TODO : btnResetTimeClicked, wait for implementation";
}
