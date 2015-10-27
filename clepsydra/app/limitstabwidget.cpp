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
    bool vcurValue = false;
    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION).toBool();
    m_limitTab->ckLimitAccessTimeDuration->setChecked(vcurValue);
    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY).toBool();
    m_limitTab->chkLimitAccessTimeDurationEachDay->setChecked(vcurValue);


    // time frame section
    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME).toBool();
    m_limitTab->ckLimitAccessTimeFrame->setChecked(vcurValue);
    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY).toBool();
    m_limitTab->ckLimitAccessTimeFrameEachDay->setChecked(vcurValue);
    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_PER_DAY).toBool();
    m_limitTab->chLimitAccessTimeFramePerDay->setChecked(vcurValue);

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
        m_limitTab->sbFrom_mon->setTime(QTime::fromString(time_from.at(0), FORMAT_STRING_FMT));
        m_limitTab->sbFrom_tue->setTime(QTime::fromString(time_from.at(1), FORMAT_STRING_FMT));
        m_limitTab->sbFrom_wed->setTime(QTime::fromString(time_from.at(2), FORMAT_STRING_FMT));
        m_limitTab->sbFrom_thu->setTime(QTime::fromString(time_from.at(3), FORMAT_STRING_FMT));
        m_limitTab->sbFrom_fri->setTime(QTime::fromString(time_from.at(4), FORMAT_STRING_FMT));
        m_limitTab->sbFrom_sat->setTime(QTime::fromString(time_from.at(5), FORMAT_STRING_FMT));
        m_limitTab->sbFrom_sun->setTime(QTime::fromString(time_from.at(6), FORMAT_STRING_FMT));
    }

    QStringList lstTimeTo = limitMap.value(CLEPSYDRA_LIMIT_TIME_TO).toStringList();
    if (lstTimeTo.length())  {
//            // Limit time frame, every day 'To' value
//            m_limitTab->sbLTFEveryTo->setTime(QTime::fromString(lstTimeTo.at(7),FORMAT_STRING_FMT));
//            // Limit time frame, per day 'To' values
        m_limitTab->sbTo_mon->setTime(QTime::fromString(lstTimeTo.at(0),FORMAT_STRING_FMT));
        m_limitTab->sbTo_tue->setTime(QTime::fromString(lstTimeTo.at(1),FORMAT_STRING_FMT));
        m_limitTab->sbTo_wed->setTime(QTime::fromString(lstTimeTo.at(2),FORMAT_STRING_FMT));
        m_limitTab->sbTo_thu->setTime(QTime::fromString(lstTimeTo.at(3),FORMAT_STRING_FMT));
        m_limitTab->sbTo_fri->setTime(QTime::fromString(lstTimeTo.at(4),FORMAT_STRING_FMT));
        m_limitTab->sbTo_sat->setTime(QTime::fromString(lstTimeTo.at(5),FORMAT_STRING_FMT));
        m_limitTab->sbTo_sun->setTime(QTime::fromString(lstTimeTo.at(6),FORMAT_STRING_FMT));
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

// Set all controls to disabled but not hide them.
// Useful selected user is admin.
void LimitsTabWidget::disableControls(bool toEnable)
{
    if (m_controlsEnabled != toEnable)  {
        //
        // Enable/disable access duration side
        //
        m_limitTab->ckLimitAccessTimeDuration->setDisabled(toEnable);
        m_limitTab->chkLimitAccessTimeDurationEachDay->setDisabled(toEnable);

        m_limitTab->sbLimitAccessDurarationEveryDay->setDisabled(toEnable);
        m_limitTab->ckLimitAccessDurationPerEachDay->setDisabled(toEnable);

        m_limitTab->lblEveryDay->setDisabled(toEnable);
        m_limitTab->lblAccessMon->setDisabled(toEnable);
        m_limitTab->lblAccessTue->setDisabled(toEnable);
        m_limitTab->lblAccessWed->setDisabled(toEnable);
        m_limitTab->lblAccessThu->setDisabled(toEnable);
        m_limitTab->lblAccessFri->setDisabled(toEnable);
        m_limitTab->lblAccessSat->setDisabled(toEnable);
        m_limitTab->lblAccessSun->setDisabled(toEnable);

        // Set limit time frame per each day..
        m_limitTab->sbLimit_mon->setDisabled(toEnable);
        m_limitTab->sbLimit_tue->setDisabled(toEnable);
        m_limitTab->sbLimit_wed->setDisabled(toEnable);
        m_limitTab->sbLimit_thu->setDisabled(toEnable);
        m_limitTab->sbLimit_fri->setDisabled(toEnable);
        m_limitTab->sbLimit_sat->setDisabled(toEnable);
        m_limitTab->sbLimit_sun->setDisabled(toEnable);

        //
        // Limit Access On Time Frame
        //

        m_limitTab->ckLimitAccessTimeFrame->setDisabled(toEnable);
        m_limitTab->ckLimitAccessTimeFrameEachDay->setDisabled(toEnable);
        m_limitTab->chLimitAccessTimeFramePerDay->setDisabled(toEnable);

        m_limitTab->sbEveryFrom->setDisabled(toEnable);
        m_limitTab->sbEveryTo->setDisabled(toEnable);
        m_limitTab->lblAccessTF_everyday->setDisabled(toEnable);

        m_limitTab->lblEveryDay->setDisabled(toEnable);
        m_limitTab->lblAccessTF_mon->setDisabled(toEnable);
        m_limitTab->lblAccessTF_tue->setDisabled(toEnable);
        m_limitTab->lblAccessTF_wed->setDisabled(toEnable);
        m_limitTab->lblAccessTF_thu->setDisabled(toEnable);
        m_limitTab->lblAccessTF_fri->setDisabled(toEnable);
        m_limitTab->lblAccessTF_sat->setDisabled(toEnable);
        m_limitTab->lblAccessTF_sun->setDisabled(toEnable);

        // from  ... to
        m_limitTab->sbFrom_mon->setDisabled(toEnable);
        m_limitTab->sbFrom_tue->setDisabled(toEnable);
        m_limitTab->sbFrom_wed->setDisabled(toEnable);
        m_limitTab->sbFrom_thu->setDisabled(toEnable);
        m_limitTab->sbFrom_fri->setDisabled(toEnable);
        m_limitTab->sbFrom_sat->setDisabled(toEnable);
        m_limitTab->sbFrom_sun->setDisabled(toEnable);

        m_limitTab->sbTo_mon->setDisabled(toEnable);
        m_limitTab->sbTo_tue->setDisabled(toEnable);
        m_limitTab->sbTo_wed->setDisabled(toEnable);
        m_limitTab->sbTo_thu->setDisabled(toEnable);
        m_limitTab->sbTo_fri->setDisabled(toEnable);
        m_limitTab->sbTo_sat->setDisabled(toEnable);
        m_limitTab->sbTo_sun->setDisabled(toEnable);

        m_controlsEnabled = toEnable;
    }
}

void LimitsTabWidget::ckBoundAccessDurationStateChanged (int state)
{
    if (state == Qt::Checked && m_limitTab->ckLimitAccessTimeFrame->checkState()==Qt::Checked) {
        m_limitTab->ckLimitAccessTimeFrame->setCheckState(Qt::Unchecked);
    }
}

void LimitsTabWidget::ckBoundTimeFrameStateChanged(int state)
{
    if (state == Qt::Checked && m_limitTab->ckLimitAccessTimeDuration->checkState()==Qt::Checked) {
        m_limitTab->ckLimitAccessTimeDuration->setCheckState(Qt::Unchecked);
    }
}

void LimitsTabWidget::setLimitTbCbs ()
{

    connect(m_limitTab->ckLimitAccessTimeDuration, SIGNAL(stateChanged (int)), this,
            SLOT(ckBoundAccessDurationStateChanged(int)));
    connect(m_limitTab->ckLimitAccessTimeFrame, SIGNAL(stateChanged (int)), this ,
            SLOT(ckBoundTimeFrameStateChanged(int)));
//    connect(m_limitTab->ckBound, SIGNAL(stateChanged (int)), this,
//            SLOT(ckBoundStateChanged(int)));
//    connect(m_limitTab->ckBoundDay, SIGNAL(stateChanged (int)), this,
//            SLOT(ckBoundDayStateChanged(int)));
}
