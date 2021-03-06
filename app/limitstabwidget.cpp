// Copyright (c) 2016 Olli-Pekka Wallin <opwallin@gmail.com>

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

#define FORMAT_STRING_FMT "HH:mm"

LimitsTabWidget::LimitsTabWidget(QWidget *parent) :
    QWidget(parent), m_limitTab(new Ui::limitForm)
{
    m_limitTab->setupUi(this);
    setLimitTbCbs();
}

void LimitsTabWidget::setLimits (const QVariantMap& limitMap)
{
    m_allowSignalChange = false;
    bool vcurValue = false;
    // Set first values to Time edit controls (Access Duration side)
    QString time = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY_TIME).toString();
    m_limitTab->sbLimitAccessDurarationEveryDay->setTime(QTime().fromString(time, FORMAT_STRING_FMT ));
    QString weekData = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_PER_DAY_TIME).toString();
    if (weekData.length())  {
        QStringList times = weekData.split (",");

        // Decided later on
        // QTime limit = QTime (0, 10, 0, 0);
        // m_limitTab->sbLimitAccessDurarationEveryDay->setMinimumTime(limit);

        m_limitTab->sbLimit_mon->setTime(QTime().fromString(times[0]));
        m_limitTab->sbLimit_tue->setTime(QTime().fromString(times[1]));
        m_limitTab->sbLimit_wed->setTime(QTime().fromString(times[2]));
        m_limitTab->sbLimit_thu->setTime(QTime().fromString(times[3]));
        m_limitTab->sbLimit_fri->setTime(QTime().fromString(times[4]));
        m_limitTab->sbLimit_sat->setTime(QTime().fromString(times[5]));
        m_limitTab->sbLimit_sun->setTime(QTime().fromString(times[6]));
    }

    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY).toBool();
    if (vcurValue)  {
        m_limitTab->chkLimitAccessTimeDurationEachDay->setChecked(vcurValue);
        m_limitTab->ckLimitAccessDurationPerEachDay->setChecked(false);
        disableAccessDurationControls (false, SelectEveryDayConfig);
        disableAccessDurationControls (true, SelectPerEachDayConfig);
    } else {
        m_limitTab->chkLimitAccessTimeDurationEachDay->setChecked(false);
        m_limitTab->ckLimitAccessDurationPerEachDay->setChecked(true);
        disableAccessDurationControls (true, SelectEveryDayConfig);
        disableAccessDurationControls (false, SelectPerEachDayConfig);
    }

    //
    // Access control on Time Frame side
    //

    QString eachDayLimits = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY_TIME).toString();

    if (eachDayLimits.length())  {
        QStringList list = eachDayLimits.split(",");
        m_limitTab->sbEveryFrom->setTime(QTime::fromString(list[0], FORMAT_STRING_FMT));
        m_limitTab->sbEveryTo->setTime(QTime::fromString(list[1], FORMAT_STRING_FMT));
    }

    QStringList time_from = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_PER_DAY_TIME).toString().split(",");
    if (time_from.length() == 7)  {
        // Monday
        QString timeMon = time_from[0];
        m_limitTab->sbFrom_mon->setTime(QTime::fromString(timeMon.split(".")[0].trimmed(), FORMAT_STRING_FMT));
        m_limitTab->sbTo_mon->setTime(QTime::fromString(timeMon.split(".")[1].trimmed(),FORMAT_STRING_FMT));

        // Tuesday
        QString timeTue = time_from[1];
        m_limitTab->sbFrom_tue->setTime(QTime::fromString(timeTue.split(".")[0].trimmed(), FORMAT_STRING_FMT));
        m_limitTab->sbTo_tue->setTime(QTime::fromString(timeTue.split(".")[1].trimmed(),FORMAT_STRING_FMT));
        // Wednesday
        QString timeWed = time_from[2];
        m_limitTab->sbFrom_wed->setTime(QTime::fromString(timeWed.split(".")[0].trimmed(), FORMAT_STRING_FMT));
        m_limitTab->sbTo_wed->setTime(QTime::fromString(timeWed.split(".")[1].trimmed(),FORMAT_STRING_FMT));
        // Thursday
        QString timeThu = time_from[3];
        m_limitTab->sbFrom_thu->setTime(QTime::fromString(timeThu.split(".")[0].trimmed(),FORMAT_STRING_FMT));
        m_limitTab->sbTo_thu->setTime(QTime::fromString(timeThu.split(".")[1].trimmed(),FORMAT_STRING_FMT));
        // Friday
        QString timeFri = time_from[4];
        m_limitTab->sbFrom_fri->setTime(QTime::fromString(timeFri.split(".")[0].trimmed(),FORMAT_STRING_FMT));
        m_limitTab->sbTo_thu->setTime(QTime::fromString(timeFri.split(".")[1].trimmed(),FORMAT_STRING_FMT));
        // Saturday
        QString timeSat = time_from[5];
        m_limitTab->sbFrom_sat->setTime(QTime::fromString(timeSat.split(".")[0].trimmed(), FORMAT_STRING_FMT));
        m_limitTab->sbTo_sat->setTime(QTime::fromString(timeSat.split(".")[1].trimmed(),FORMAT_STRING_FMT));
        // Sunday
        QString timeSun = time_from[6];
        m_limitTab->sbFrom_sun->setTime(QTime::fromString(timeSun.split(".")[0].trimmed(), FORMAT_STRING_FMT));
        m_limitTab->sbTo_sun->setTime(QTime::fromString(timeSun.split(".")[1].trimmed(),FORMAT_STRING_FMT));
    }

    vcurValue = limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY).toBool();
    if (vcurValue)  {
        m_limitTab->ckLimitAccessTimeFrameEachDay->setChecked(true);
        m_limitTab->chLimitAccessTimeFramePerDay->setChecked(false);

        disableAccessTimeFrameControls (false, SelectEveryDayConfig);
        disableAccessTimeFrameControls (true, SelectPerEachDayConfig);
    } else {
        m_limitTab->ckLimitAccessTimeFrameEachDay->setChecked(false);
        m_limitTab->chLimitAccessTimeFramePerDay->setChecked(true);

        disableAccessTimeFrameControls (true, SelectEveryDayConfig);
        disableAccessTimeFrameControls (false, SelectPerEachDayConfig);
    }

    // Set main checkbox first,  on have to be selected, not both
    if (limitMap.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION).toBool()) {
        m_limitTab->ckLimitAccessTimeDuration->setChecked(true);
        m_limitTab->ckLimitAccessTimeFrame->setChecked(false);

    } else {
        m_limitTab->ckLimitAccessTimeDuration->setChecked(false);
        m_limitTab->ckLimitAccessTimeFrame->setChecked(true);
    }

    m_limitMap = limitMap;
    m_allowSignalChange = true;

}

void LimitsTabWidget::getLimits(QVariantMap &map)
{
    map.clear();
    bool bound = false;

    map.insert(CLEPSYDRA_LIMIT_BOUNDED, bound);
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
    limitsList.append( m_limitTab->sbTo_mon->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_tue->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_wed->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_thu->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_fri->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_sat->time().toString(FORMAT_STRING_FMT));
    limitsList.append( m_limitTab->sbTo_sun->time().toString(FORMAT_STRING_FMT));

    map.insert(CLEPSYDRA_LIMIT_TIME_TO, limitsList);
}

void LimitsTabWidget::disableAccessDurationControls (bool toEnable, EnableMode mode)
{
    switch ( mode )
    {
        case SelectEveryDayConfig:
            m_limitTab->lblEveryDay->setDisabled(toEnable);
            m_limitTab->sbLimitAccessDurarationEveryDay->setDisabled(toEnable);
            break;
        case SelectPerEachDayConfig:
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
            break;
        default:
            break;
    }
}

void LimitsTabWidget::disableTimeControlCheckbox (ControlTimeCheckboxs chebox, bool newstate)
{
    switch ( chebox ) {
        case MainCheckboxes:
            m_limitTab->ckLimitAccessTimeDuration->setDisabled(newstate);
            m_limitTab->ckLimitAccessTimeFrame->setDisabled(newstate);
            break;
        case AccessDurationCheckbox:
            m_limitTab->chkLimitAccessTimeDurationEachDay->setDisabled(newstate);
            m_limitTab->ckLimitAccessDurationPerEachDay->setDisabled(newstate);
            break;
        case AccessTimeFrameCheckbox:
            m_limitTab->ckLimitAccessTimeFrameEachDay->setDisabled(newstate);
            m_limitTab->chLimitAccessTimeFramePerDay->setDisabled(newstate);
            break;
    }
}

void LimitsTabWidget::disableAccessTimeFrameControls (bool toEnable, EnableMode mode)
{
    switch ( mode ) {
        case SelectEveryDayConfig:
            m_limitTab->sbEveryFrom->setDisabled(toEnable);
            m_limitTab->sbEveryTo->setDisabled(toEnable);
            m_limitTab->lblAccessTF_everyday->setDisabled(toEnable);
            break;
        case SelectPerEachDayConfig:
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
            break;
        default:
            break;
    }
}

void LimitsTabWidget::disableCorrectControlsBasedOnCheckbox ()
{
    m_allowSignalChange = false;

    m_limitTab->ckLimitAccessTimeFrame->setDisabled(false);
    m_limitTab->ckLimitAccessTimeDuration->setDisabled(false);

    if (m_limitTab->ckLimitAccessTimeDuration->checkState()==Qt::Checked){
        // Verify that a) time frame side has been disabled and
        // correct controls in duration side has been enabled or disabled.
        disableAccessTimeFrameControls (true, SelectEveryDayConfig);
        disableAccessTimeFrameControls (true, SelectPerEachDayConfig);

        m_limitTab->chkLimitAccessTimeDurationEachDay->setDisabled(false);
        m_limitTab->ckLimitAccessDurationPerEachDay->setDisabled(false);

        m_limitTab->ckLimitAccessTimeFrameEachDay->setDisabled(true);
        m_limitTab->chLimitAccessTimeFramePerDay->setDisabled(true);
    } else {
        disableAccessDurationControls (true, SelectEveryDayConfig);
        disableAccessDurationControls (true, SelectPerEachDayConfig);

        m_limitTab->chkLimitAccessTimeDurationEachDay->setDisabled(true);
        m_limitTab->ckLimitAccessDurationPerEachDay->setDisabled(true);

        m_limitTab->chLimitAccessTimeFramePerDay->setDisabled(false);
        m_limitTab->ckLimitAccessTimeFrameEachDay->setDisabled(false);
    }
    m_allowSignalChange = true;
}

// Set all controls to disabled but not hide them.
// Useful selected user is admin.
void LimitsTabWidget::disableControls(bool toDisable)
{    
    if (toDisable)  {
        // Easy, disable all controls.
        disableAccessDurationControls (toDisable, SelectEveryDayConfig);
        disableAccessDurationControls (toDisable, SelectPerEachDayConfig);

        disableAccessTimeFrameControls(toDisable, SelectEveryDayConfig);
        disableAccessTimeFrameControls (toDisable, SelectPerEachDayConfig);

        disableTimeControlCheckbox(MainCheckboxes, toDisable);
        disableTimeControlCheckbox (AccessDurationCheckbox, toDisable);
        disableTimeControlCheckbox (AccessTimeFrameCheckbox, toDisable);

    } else {
        disableCorrectControlsBasedOnCheckbox ();
    }
}

void LimitsTabWidget::ckLimitAccessTimeDurationChanged (int state)
{
    if (!m_allowSignalChange)
        return;

    if (state == Qt::Checked && m_limitTab->ckLimitAccessTimeFrame->checkState()==Qt::Checked) {
        m_limitTab->ckLimitAccessTimeFrame->setCheckState(Qt::Unchecked);
        disableAccessTimeFrameControls (true, SelectEveryDayConfig);
        disableAccessTimeFrameControls (true, SelectPerEachDayConfig);

        if (m_limitTab->chkLimitAccessTimeDurationEachDay->isChecked ()) {
            disableAccessDurationControls (false, SelectEveryDayConfig);
            disableAccessDurationControls (true, SelectPerEachDayConfig);
        } else {
            disableAccessDurationControls (true, SelectEveryDayConfig);
            disableAccessDurationControls (false, SelectPerEachDayConfig);
        }

        disableTimeControlCheckbox(AccessDurationCheckbox, false);
        disableTimeControlCheckbox(AccessTimeFrameCheckbox, true);

    } else {
        m_limitTab->ckLimitAccessTimeFrame->setCheckState(Qt::Checked);
    }
}

// Nofied when state of ckLimitAccessTimeFrame-state has changed
void LimitsTabWidget::ckLimitAccessTimeFrameChanged(int state)
{
    if (!m_allowSignalChange)
        return;
    if (state == Qt::Checked && m_limitTab->ckLimitAccessTimeDuration->checkState()==Qt::Checked) {
        m_limitTab->ckLimitAccessTimeDuration->setCheckState(Qt::Unchecked);
        if (m_limitTab->ckLimitAccessTimeFrameEachDay->isChecked()) {
            disableAccessTimeFrameControls (false, SelectEveryDayConfig);
            disableAccessTimeFrameControls (true, SelectPerEachDayConfig);
        } else {
            disableAccessTimeFrameControls (true, SelectEveryDayConfig);
            disableAccessTimeFrameControls (false, SelectPerEachDayConfig);
        }
        disableAccessDurationControls (true, SelectEveryDayConfig);
        disableAccessDurationControls (true, SelectPerEachDayConfig);

        disableTimeControlCheckbox(AccessDurationCheckbox, true);
        disableTimeControlCheckbox(AccessTimeFrameCheckbox, false);

    } else {
        m_limitTab->ckLimitAccessTimeDuration->setCheckState(Qt::Checked);
    }
}

void LimitsTabWidget::chkLimitAccessTimeDurationEachDayChanged(int state)
{
    if (!m_allowSignalChange)
        return;
    if (state == Qt::Checked && m_limitTab->ckLimitAccessDurationPerEachDay->checkState()==Qt::Checked)  {
        m_limitTab->ckLimitAccessDurationPerEachDay->setCheckState(Qt::Unchecked);
        disableAccessDurationControls (false, SelectEveryDayConfig);
        disableAccessDurationControls (true, SelectPerEachDayConfig);
    } else {
        m_limitTab->ckLimitAccessDurationPerEachDay->setCheckState(Qt::Checked);
    }
}

void LimitsTabWidget::ckLimitAccessDurationPerEachDayChanged (int state)
{
    if (!m_allowSignalChange)
        return;
    if (state == Qt::Checked && m_limitTab->chkLimitAccessTimeDurationEachDay->checkState()==Qt::Checked)  {
        m_limitTab->chkLimitAccessTimeDurationEachDay->setCheckState(Qt::Unchecked);
        disableAccessDurationControls (true, SelectEveryDayConfig);
        disableAccessDurationControls (false, SelectPerEachDayConfig);
    } else {
        m_limitTab->chkLimitAccessTimeDurationEachDay->setCheckState(Qt::Checked);
    }
}

void LimitsTabWidget::ckLimitAccessTimeFrameEachDayChanged (int state)
{
    if (!m_allowSignalChange)
        return;
    if (state == Qt::Checked && m_limitTab->chLimitAccessTimeFramePerDay->checkState()==Qt::Checked)  {
        m_limitTab->chLimitAccessTimeFramePerDay->setCheckState(Qt::Unchecked);
        disableAccessTimeFrameControls(false, SelectEveryDayConfig);
        disableAccessTimeFrameControls (true, SelectPerEachDayConfig);
    } else {
        m_limitTab->chLimitAccessTimeFramePerDay->setCheckState(Qt::Checked);
    }
}

void LimitsTabWidget::chLimitAccessTimeFramePerDayChanged (int state)
{
    if (!m_allowSignalChange)
        return;
    if (state == Qt::Checked && m_limitTab->ckLimitAccessTimeFrameEachDay->checkState()==Qt::Checked)  {
        m_limitTab->ckLimitAccessTimeFrameEachDay->setCheckState(Qt::Unchecked);
        disableAccessTimeFrameControls(true, SelectEveryDayConfig);
        disableAccessTimeFrameControls (false, SelectPerEachDayConfig);
    } else {
        m_limitTab->ckLimitAccessTimeFrameEachDay->setCheckState(Qt::Checked);
    }
}

void LimitsTabWidget::setLimitTbCbs ()
{
    connect(m_limitTab->ckLimitAccessTimeDuration, SIGNAL(stateChanged (int)), this,
            SLOT(ckLimitAccessTimeDurationChanged(int)));
    connect(m_limitTab->ckLimitAccessTimeFrame, SIGNAL(stateChanged (int)), this ,
            SLOT(ckLimitAccessTimeFrameChanged(int)));

    connect(m_limitTab->chkLimitAccessTimeDurationEachDay, SIGNAL(stateChanged (int)), this,
            SLOT(chkLimitAccessTimeDurationEachDayChanged(int)));
    connect(m_limitTab->ckLimitAccessDurationPerEachDay, SIGNAL(stateChanged (int)), this,
            SLOT(ckLimitAccessDurationPerEachDayChanged(int)));

    connect(m_limitTab->ckLimitAccessTimeFrameEachDay, SIGNAL(stateChanged (int)), this,
            SLOT(ckLimitAccessTimeFrameEachDayChanged(int)));
    connect(m_limitTab->chLimitAccessTimeFramePerDay,  SIGNAL(stateChanged (int)), this,
            SLOT(chLimitAccessTimeFramePerDayChanged(int)));
}
