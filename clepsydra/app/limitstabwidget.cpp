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
#include "config.h"
#include "mainwindow.h"
#include "limitstabwidget.h"

#define FORMAT_STRING_FMT "hhmm"


LimitsTabWidget::LimitsTabWidget(QWidget *parent) :
    QWidget(parent), m_limitTab(new Ui::limitForm)
{
    m_limitTab->setupUi(this);
    setLimitTbCbs();
}

void LimitsTabWidget::setLimits (const QVariantMap& limitMap)
{
    if (!m_controlsDisabled) {

        bool bounded = limitMap.value(CLEPSYDRA_LIMIT_BOUNDED).toBool();
        m_limitTab->ckBound->setDisabled(bounded);
        ckLimitDayStateChanged(bounded);

        bool boundedByDay = limitMap.value(CLEPSYDRA_LIMIT_BOUNDEDBYDAY).toBool();
        m_limitTab->ckBoundDay->setDisabled(boundedByDay);
        ckBoundDayStateChanged(boundedByDay);

        QStringList limits = limitMap.value(CLEPSYDRA_LIMIT_LIMITS).toStringList();
        if (limits.length())  {
            m_limitTab->sbLimit_7->setTime(QTime::fromString(limits.at(7), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_0->setTime(QTime::fromString(limits.at(0), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_1->setTime(QTime::fromString(limits.at(1), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_2->setTime(QTime::fromString(limits.at(2), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_3->setTime(QTime::fromString(limits.at(3), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_4->setTime(QTime::fromString(limits.at(4), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_5->setTime(QTime::fromString(limits.at(5), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_6->setTime(QTime::fromString(limits.at(6), FORMAT_STRING_FMT));
        }

        QStringList time_from = limitMap.value(CLEPSYDRA_LIMIT_TIME_FROM).toStringList();
        if (time_from.length())  {
            m_limitTab->sbFrom_7->setTime(QTime::fromString(time_from.at(7), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_0->setTime(QTime::fromString(time_from.at(0), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_1->setTime(QTime::fromString(time_from.at(1), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_2->setTime(QTime::fromString(time_from.at(2), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_3->setTime(QTime::fromString(time_from.at(3), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_4->setTime(QTime::fromString(time_from.at(4), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_5->setTime(QTime::fromString(time_from.at(5), FORMAT_STRING_FMT));
            m_limitTab->sbFrom_6->setTime(QTime::fromString(time_from.at(6), FORMAT_STRING_FMT));
        }

        QStringList lstTimeTo = limitMap.value(CLEPSYDRA_LIMIT_TIME_TO).toStringList();
        if (lstTimeTo.length())  {
            m_limitTab->sbTo_7->setTime(QTime::fromString(lstTimeTo.at(7),FORMAT_STRING_FMT));
            m_limitTab->sbTo_0->setTime(QTime::fromString(lstTimeTo.at(0),FORMAT_STRING_FMT));
            m_limitTab->sbTo_1->setTime(QTime::fromString(lstTimeTo.at(1),FORMAT_STRING_FMT));
            m_limitTab->sbTo_2->setTime(QTime::fromString(lstTimeTo.at(2),FORMAT_STRING_FMT));
            m_limitTab->sbTo_3->setTime(QTime::fromString(lstTimeTo.at(3),FORMAT_STRING_FMT));
            m_limitTab->sbTo_4->setTime(QTime::fromString(lstTimeTo.at(4),FORMAT_STRING_FMT));
            m_limitTab->sbTo_5->setTime(QTime::fromString(lstTimeTo.at(5),FORMAT_STRING_FMT));
            m_limitTab->sbTo_6->setTime(QTime::fromString(lstTimeTo.at(6),FORMAT_STRING_FMT));
        }

    //        locked=false
    //        bounded=false
    //        boundedByDay=false
    //        limited=false
    //        limitedByday=false
    //        limits=0300,0300,0300,0300,0300,0300,0300,0300
    //        time_from=0700,0700,0700,0700,0700,0700,0700,0700
    //        time_to=2200,2200,2200,2200,2200,2200,2200,2200

    }
}

void LimitsTabWidget::getLimits(QVariantMap &map)
{
    map.clear();
    bool bound = false;
    if (m_limitTab->ckBound->checkState()==Qt::Checked) {
        bound = true;
    }

    bool boundByDay = false;
    if (m_limitTab->ckBoundDay->checkState()==Qt::Checked) {
        boundByDay = true;
    }

    bool limits = false;
    if (m_limitTab->ckLimit->checkState()==Qt::Checked) {
        limits = true;
    }

    bool limitsbyday = false;
    if (m_limitTab->ckLimitDay->checkState()==Qt::Checked) {
        limitsbyday = true;
    }

    map.insert(CLEPSYDRA_LIMIT_BOUNDED, bound);
    map.insert(CLEPSYDRA_LIMIT_BOUNDEDBYDAY, boundByDay);
    map.insert(CLEPSYDRA_LIMIT_LIMITS, limits);
    map.insert(CLEPSYDRA_LIMIT_LIMITSBYDAY, limitsbyday);

    QStringList limitsList;
    limitsList.append( m_limitTab->sbLimit_7->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_0->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_1->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_2->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_3->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_4->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_5->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_6->time().toString(FORMAT_STRING_FMT));
    map.insert(CLEPSYDRA_LIMIT_LIMITS, limitsList);
    limitsList.clear();

    // time_from
    limitsList.append( m_limitTab->sbFrom_7->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_0->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_1->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_2->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_3->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_4->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_5->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_6->time().toString(FORMAT_STRING_FMT));
    map.insert(CLEPSYDRA_LIMIT_TIME_FROM, limitsList);
    limitsList.clear();

    // time_to
    limitsList.append( m_limitTab->sbTo_7->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_0->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_1->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_2->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_3->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_4->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_5->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_6->time().toString(FORMAT_STRING_FMT));
    map.insert(CLEPSYDRA_LIMIT_TIME_TO, limitsList);

    qDebug() << map;
}

void LimitsTabWidget::ckLimitDayStateChanged(int checked)
{
    m_limitTab->wgLimitWeek->setHidden(!checked);
}


void LimitsTabWidget::ckBoundDayStateChanged (int checked)
{
    m_limitTab->wgBoundWeek->setHidden(!checked);
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

void LimitsTabWidget::ckLimitStateChanged(int state)
{
    if (state == Qt::Checked && m_limitTab->ckBound->checkState()==Qt::Checked) {
        m_limitTab->ckBound->setCheckState(Qt::Unchecked);
    }
}

void LimitsTabWidget::ckBoundStateChanged(int state)
{
    if (state == Qt::Checked && m_limitTab->ckBound->checkState()==Qt::Checked) {
        m_limitTab->ckLimit->setCheckState(Qt::Unchecked);
    }
}

void LimitsTabWidget::setLimitTbCbs ()
{

    connect(m_limitTab->ckLimit, SIGNAL(stateChanged (int)), this,
            SLOT(ckLimitStateChanged(int)));
    connect(m_limitTab->ckLimitDay, SIGNAL(stateChanged (int)), this ,
            SLOT(ckLimitDayStateChanged(int)));
    connect(m_limitTab->ckBound, SIGNAL(stateChanged (int)), this,
            SLOT(ckBoundStateChanged(int)));
    connect(m_limitTab->ckBoundDay, SIGNAL(stateChanged (int)), this,
            SLOT(ckBoundDayStateChanged(int)));
}
