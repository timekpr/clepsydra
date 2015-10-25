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
        m_limitTab->ckLimitAccessDuration->setDisabled(bounded);
        ckLimitDayStateChanged(bounded);

        bool boundedByDay = limitMap.value(CLEPSYDRA_LIMIT_BOUNDEDBYDAY).toBool();
        m_limitTab->ckBoundDay->setDisabled(boundedByDay);
        ckBoundDayStateChanged(boundedByDay);

        QStringList limits = limitMap.value(CLEPSYDRA_LIMIT_LIMITS).toStringList();
        if (limits.length())  {
            // Limit time based on time:
            // How much user can use his/her account per day
            // m_limitTab->sbLimit_7->setTime(QTime::fromString(limits.at(7), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_mon->setTime(QTime::fromString(limits.at(0), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_tue->setTime(QTime::fromString(limits.at(1), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_wed->setTime(QTime::fromString(limits.at(2), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_thu->setTime(QTime::fromString(limits.at(3), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_fri->setTime(QTime::fromString(limits.at(4), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_sat->setTime(QTime::fromString(limits.at(5), FORMAT_STRING_FMT));
            m_limitTab->sbLimit_sun->setTime(QTime::fromString(limits.at(6), FORMAT_STRING_FMT));
        }

        QStringList time_from = limitMap.value(CLEPSYDRA_LIMIT_TIME_FROM).toStringList();
        if (time_from.length())  {
//            // Limit time frame, every day 'From' value
//            m_limitTab->sbLTFEveryFrom->setTime(QTime::fromString(time_from.at(7), FORMAT_STRING_FMT));
//            // Limit time frame, per day 'From' values
//            m_limitTab->sbFrom_0->setTime(QTime::fromString(time_from.at(0), FORMAT_STRING_FMT));
//            m_limitTab->sbFrom_1->setTime(QTime::fromString(time_from.at(1), FORMAT_STRING_FMT));
//            m_limitTab->sbFrom_2->setTime(QTime::fromString(time_from.at(2), FORMAT_STRING_FMT));
//            m_limitTab->sbFrom_3->setTime(QTime::fromString(time_from.at(3), FORMAT_STRING_FMT));
//            m_limitTab->sbFrom_4->setTime(QTime::fromString(time_from.at(4), FORMAT_STRING_FMT));
//            m_limitTab->sbFrom_5->setTime(QTime::fromString(time_from.at(5), FORMAT_STRING_FMT));
//            m_limitTab->sbFrom_6->setTime(QTime::fromString(time_from.at(6), FORMAT_STRING_FMT));
        }

        QStringList lstTimeTo = limitMap.value(CLEPSYDRA_LIMIT_TIME_TO).toStringList();
        if (lstTimeTo.length())  {
//            // Limit time frame, every day 'To' value
//            m_limitTab->sbLTFEveryTo->setTime(QTime::fromString(lstTimeTo.at(7),FORMAT_STRING_FMT));
//            // Limit time frame, per day 'To' values
//            m_limitTab->sbTo_0->setTime(QTime::fromString(lstTimeTo.at(0),FORMAT_STRING_FMT));
//            m_limitTab->sbTo_1->setTime(QTime::fromString(lstTimeTo.at(1),FORMAT_STRING_FMT));
//            m_limitTab->sbTo_2->setTime(QTime::fromString(lstTimeTo.at(2),FORMAT_STRING_FMT));
//            m_limitTab->sbTo_3->setTime(QTime::fromString(lstTimeTo.at(3),FORMAT_STRING_FMT));
//            m_limitTab->sbTo_4->setTime(QTime::fromString(lstTimeTo.at(4),FORMAT_STRING_FMT));
//            m_limitTab->sbTo_5->setTime(QTime::fromString(lstTimeTo.at(5),FORMAT_STRING_FMT));
//            m_limitTab->sbTo_6->setTime(QTime::fromString(lstTimeTo.at(6),FORMAT_STRING_FMT));
        }
    }
}

void LimitsTabWidget::getLimits(QVariantMap &map)
{
    map.clear();
    bool bound = false;
//    if (m_limitTab->ckBound->checkState()==Qt::Checked) {
//        bound = true;
//    }

//    bool boundByDay = false;
//    if (m_limitTab->ckBoundDay->checkState()==Qt::Checked) {
//        boundByDay = true;
//    }

//    bool limits = false;
//    if (m_limitTab->ckLimit->checkState()==Qt::Checked) {
//        limits = true;
//    }

//    bool limitsbyday = false;
//    if (m_limitTab->ckLimitByDay->checkState()==Qt::Checked) {
//        limitsbyday = true;
//    }

    map.insert(CLEPSYDRA_LIMIT_BOUNDED, bound);
//    map.insert(CLEPSYDRA_LIMIT_BOUNDEDBYDAY, boundByDay);
//    map.insert(CLEPSYDRA_LIMIT_LIMITS, limits);
//    map.insert(CLEPSYDRA_LIMIT_LIMITSBYDAY, limitsbyday);

    QStringList limitsList;
    //limitsList.append( m_limitTab->sbLimit_7->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_mon->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_tue->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_wed->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_thu->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_fri->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_sat->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbLimit_sun->time().toString(FORMAT_STRING_FMT));
    map.insert(CLEPSYDRA_LIMIT_LIMITS, limitsList);
    limitsList.clear();

    // time_from
    //limitsList.append( m_limitTab->sbFrom_7->time().toString(FORMAT_STRING_FMT));

    limitsList.append( m_limitTab->sbFrom_mon->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_tue->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_wed->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_thu->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_fri->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_sat->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbFrom_sun->time().toString(FORMAT_STRING_FMT));
    map.insert(CLEPSYDRA_LIMIT_TIME_FROM, limitsList);
    limitsList.clear();

    // time_to
    // limitsList.append( m_limitTab->sbTo_7->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_mon->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_tue->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_wed->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_thu->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_fri->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_sat->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_sun->time().toString(FORMAT_STRING_FMT));
    map.insert(CLEPSYDRA_LIMIT_TIME_TO, limitsList);

    // qDebug() << map;
}

void LimitsTabWidget::ckLimitDayStateChanged(int checked)
{
    //m_limitTab->wgLimitWeek->setHidden(!checked);
}


void LimitsTabWidget::ckBoundDayStateChanged (int checked)
{
    // m_limitTab->wgBoundWeek->setHidden(!checked);
}


void LimitsTabWidget::disableControls(bool toDisable)
{
    if (m_controlsDisabled != toDisable)  {
//        m_limitTab->ckLimit->setDisabled(toDisable);
//        m_limitTab->ckLimitByDay->setDisabled(toDisable);
//        m_limitTab->ckBound->setDisabled(toDisable);
        m_limitTab->ckBoundDay->setDisabled(toDisable);

        // limit  ..
//        m_limitTab->sbLimit_0->setDisabled(toDisable);
//        m_limitTab->sbLimit_1->setDisabled(toDisable);
//        m_limitTab->sbLimit_2->setDisabled(toDisable);
//        m_limitTab->sbLimit_3->setDisabled(toDisable);
//        m_limitTab->sbLimit_4->setDisabled(toDisable);
//        m_limitTab->sbLimit_5->setEnabled(toDisable);
//        m_limitTab->sbLimit_6->setDisabled(toDisable);
        //m_limitTab->sbLimit_7->setDisabled(toDisable);

        // from  ... to
        m_limitTab->sbFrom_mon->setEnabled(toDisable);
        m_limitTab->sbFrom_tue->setEnabled(toDisable);
        m_limitTab->sbFrom_wed->setEnabled(toDisable);
        m_limitTab->sbFrom_thu->setEnabled(toDisable);
        m_limitTab->sbFrom_fri->setEnabled(toDisable);
        m_limitTab->sbFrom_sat->setEnabled(toDisable);
        m_limitTab->sbFrom_sun->setEnabled(toDisable);

        //m_limitTab->sbFrom_7->setDisabled(toDisable);

        m_limitTab->sbTo_mon->setEnabled(toDisable);
        m_limitTab->sbTo_tue->setEnabled(toDisable);
        m_limitTab->sbTo_wed->setEnabled(toDisable);
        m_limitTab->sbTo_thu->setEnabled(toDisable);
        m_limitTab->sbTo_fri->setEnabled(toDisable);
        m_limitTab->sbTo_sat->setEnabled(toDisable);
        m_limitTab->sbTo_sun->setEnabled(toDisable);
        //
        //m_limitTab->sbTo_7->setDisabled(toDisable);

        m_controlsDisabled = toDisable;
    }
}

void LimitsTabWidget::ckLimitStateChanged(int state)
{
//    if (state == Qt::Checked && m_limitTab->ckBound->checkState()==Qt::Checked) {
//        m_limitTab->ckBound->setCheckState(Qt::Unchecked);
//    }
}

void LimitsTabWidget::ckBoundStateChanged(int state)
{
//    if (state == Qt::Checked && m_limitTab->ckBound->checkState()==Qt::Checked) {
//        m_limitTab->ckLimit->setCheckState(Qt::Unchecked);
//    }
}

void LimitsTabWidget::setLimitTbCbs ()
{

//    connect(m_limitTab->ckLimit, SIGNAL(stateChanged (int)), this,
//            SLOT(ckLimitStateChanged(int)));
//    connect(m_limitTab->ckLimitByDay, SIGNAL(stateChanged (int)), this ,
//            SLOT(ckLimitDayStateChanged(int)));
//    connect(m_limitTab->ckBound, SIGNAL(stateChanged (int)), this,
//            SLOT(ckBoundStateChanged(int)));
//    connect(m_limitTab->ckBoundDay, SIGNAL(stateChanged (int)), this,
//            SLOT(ckBoundDayStateChanged(int)));
}
