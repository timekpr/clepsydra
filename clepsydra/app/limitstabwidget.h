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

#ifndef LIMITSTABWIDGET_H
#define LIMITSTABWIDGET_H

#include <QMap>
#include <QWidget>
#include "ui_limits.h"


class LimitsTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LimitsTabWidget(QWidget *parent = 0);

    void setLimitTbCbs();

    void setLimits (const QVariantMap&);
    void getLimits (QVariantMap&);
public:
    enum EnableMode {
        SelectEveryDayConfig,  // Enable every day time and disable per each day time controls
        SelectPerEachDayConfig // Enable per each day time controls and disable every day time control
     };

    enum ControlTimeCheckboxs {
        MainCheckboxes,
        AccessDurationCheckbox,
        AccessTimeFrameCheckbox
    };

private :
    //
    // This will be enable or disable controls based on state of checkbox.
    // designed to use when user changed.
    void disableCorrectControlsBasedOnCheckbox ();
    //
    void disableAccessDurationControls (bool, EnableMode);
    //
    void disableAccessTimeFrameControls(bool, EnableMode);
    // Disable or enable based on control checkboxs
    void disableTimeControlCheckbox (ControlTimeCheckboxs, bool);

public slots:
    // If true all controls are going to disable,
    // most when admin (sudoer) user has been selected.
    void disableControls(bool); // Disables all controls.

    // ckLimitAccessTimeDuration
    void ckLimitAccessTimeDurationChanged (int);
    // ckLimitAccessTimeFrame
    void ckLimitAccessTimeFrameChanged (int);

    // duration based checkbox's
    void chkLimitAccessTimeDurationEachDayChanged (int);
    void ckLimitAccessDurationPerEachDayChanged (int);

    // Timeframe checkbox's
    void ckLimitAccessTimeFrameEachDayChanged (int);
    void chLimitAccessTimeFramePerDayChanged (int);

private:

    void hideTimeDurationControls ();
    void hideTimeFrameControls ();

private:
    Ui_limitForm *m_limitTab;
    bool m_allowSignalChange;
    QVariantMap m_usedMap;
};

#endif // LIMITSTABWIDGET_H
