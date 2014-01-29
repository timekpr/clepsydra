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

#include "mainwindow.h"
#include "limitstabwidget.h"

LimitsTabWidget::LimitsTabWidget(QWidget *parent) :
    QWidget(parent), m_limitTab(new Ui::limitForm)
{
    m_limitTab->setupUi(this);
    setLimitTbCbs();
}

void LimitsTabWidget::setLimitTbCbs ()
{

    connect(m_limitTab->ckLimit, SIGNAL(stateChanged (int)), parent(),
            SLOT(ckLimitStateChanged(int)));
    connect(m_limitTab->ckLimitDay, SIGNAL(stateChanged (int)), parent(),
            SLOT(ckLimitDayStateChanged(int)));
    connect(m_limitTab->ckBound, SIGNAL(stateChanged (int)), parent(),
            SLOT(ckBoundStateChanged(int)));
    connect(m_limitTab->ckBoundDay, SIGNAL(stateChanged (int)), parent(),
            SLOT(ckBoundDayStateChanged(int)));

}
