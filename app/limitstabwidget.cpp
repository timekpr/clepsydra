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
#include "limitstabwidget.h"

LimitsTabWidget::LimitsTabWidget(QWidget *parent) :
    QWidget(parent), m_limitTab(new Ui::limitForm)
{
    m_limitTab->setupUi(this);
    setLimitTbCbs();
}

void LimitsTabWidget::setLimits (const QVariantMap& limitMap)
{
    if (!m_controlsDisabled) {
        qDebug() << limitMap;
        bool bounded = limitMap.value("bounded").toBool();
        if (bounded)  {
            m_limitTab->ckBound->setDisabled(bounded);
        } else {

        }
        QStringList limits = limitMap.value("limits").toStringList();
        if (limits.length())  {
            QTime limitTime(limitTime.fromString("0300", "hhmm"));

            qDebug() << limitTime;
            m_limitTab->sbLimit_7->setTime(limitTime);
            qDebug() << limits.at(0);
        }
//        locked=false
//        bounded=false
//        boundedByDay=false
//        limited=false
//        limitedByday=false
//        limits=['0300','0300','0300','0300','0300','0300','0300','0300']
//        time_from=['0700','0700','0700','0700','0700','0700','0700','0700']
//        time_to=['2200','2200','2200','2200','2200','2200','2200','2200']

    }
}

void LimitsTabWidget::disableControls(bool toDisable)
{
    if (m_controlsDisabled != toDisable)  {
        m_limitTab->ckLimit->setDisabled(toDisable);
        m_limitTab->ckLimitDay->setDisabled(toDisable);
        m_limitTab->ckBound->setDisabled(toDisable);
        m_limitTab->ckBoundDay->setDisabled(toDisable);

        // limit  ..
        m_limitTab->sbLimit_0->setDisabled(toDisable);
        m_limitTab->sbLimit_1->setDisabled(toDisable);
        m_limitTab->sbLimit_2->setDisabled(toDisable);
        m_limitTab->sbLimit_3->setDisabled(toDisable);
        m_limitTab->sbLimit_4->setDisabled(toDisable);
        m_limitTab->sbLimit_5->setDisabled(toDisable);
        m_limitTab->sbLimit_6->setDisabled(toDisable);
        m_limitTab->sbLimit_7->setDisabled(toDisable);

        // from  ... to
        m_limitTab->sbFrom_0->setDisabled(toDisable);
        m_limitTab->sbFrom_1->setDisabled(toDisable);
        m_limitTab->sbFrom_2->setDisabled(toDisable);
        m_limitTab->sbFrom_3->setDisabled(toDisable);
        m_limitTab->sbFrom_4->setDisabled(toDisable);
        m_limitTab->sbFrom_5->setDisabled(toDisable);
        m_limitTab->sbFrom_6->setDisabled(toDisable);
        m_limitTab->sbFrom_7->setDisabled(toDisable);

        m_limitTab->sbTo_0->setDisabled(toDisable);
        m_limitTab->sbTo_1->setDisabled(toDisable);
        m_limitTab->sbTo_2->setDisabled(toDisable);
        m_limitTab->sbTo_3->setDisabled(toDisable);
        m_limitTab->sbTo_4->setDisabled(toDisable);
        m_limitTab->sbTo_5->setDisabled(toDisable);
        m_limitTab->sbTo_6->setDisabled(toDisable);
        m_limitTab->sbTo_7->setDisabled(toDisable);

        m_controlsDisabled = toDisable;
    }
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
