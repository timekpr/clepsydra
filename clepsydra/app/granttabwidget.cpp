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
#include "mainwindow.h"
#include "granttabwidget.h"

GrantTabWidget::GrantTabWidget(QWidget *parent) :
    QWidget(parent), m_grantTab(new Ui::grantForm())
{
    m_grantTab->setupUi(this);
    setGrantTbCbs();
    m_controlsDisabled = false;
}

void GrantTabWidget::setGranSettings (const QVariantMap& values)
{

}

void GrantTabWidget::disableControls(bool toDisable)
{
    m_grantTab->btnClearAllRestriction->setDisabled(toDisable);
    m_grantTab->btnBypass->setDisabled(toDisable);
    m_grantTab->btnClearBypass->setDisabled(toDisable);
    m_grantTab->btnLockAccount->setDisabled(toDisable);
    m_grantTab->btnUnlockAccount->setDisabled(toDisable);
    m_grantTab->btnAddTime->setDisabled(toDisable);
    m_grantTab->btnResetTime->setDisabled(toDisable);
    m_grantTab->sbAddTime->setDisabled(toDisable);
    m_controlsDisabled = toDisable;
}

void GrantTabWidget::setGrantTbCbs ()
{

    connect(m_grantTab->btnClearAllRestriction, SIGNAL(clicked ()), parent(),
            SLOT(btnClearAllRestrictionClicked()));
    connect(m_grantTab->btnBypass, SIGNAL(clicked ()), parent(),
            SLOT(btnBypassClicked()));
    connect(m_grantTab->btnClearBypass, SIGNAL(clicked ()), parent(),
            SLOT(btnClearBypassClicked()));
    connect(m_grantTab->btnLockAccount, SIGNAL(clicked ()), parent(),
            SLOT(btnLockAccountClicked()));
    connect(m_grantTab->btnUnlockAccount, SIGNAL(clicked ()), parent(),
            SLOT(btnUnlockAccountClicked()));
    connect(m_grantTab->btnAddTime, SIGNAL(clicked ()), parent(),
            SLOT(btnAddTimeClicked()));
    connect(m_grantTab->btnResetTime, SIGNAL(clicked ()), parent(),
            SLOT(btnResetTimeClicked()));
}

