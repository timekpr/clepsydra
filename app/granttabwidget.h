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

#ifndef GRANTUIWIDGET_H
#define GRANTUIWIDGET_H

#include "ui_grant.h"
#include <QWidget>

class GrantTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GrantTabWidget(QWidget *parent = 0);

public slots:
    // if true all controls are disable,
    void disableControls(bool);
    void enableLockButton (bool);

public:
    //
    void setGrantTbCbs ();

private:
    Ui_grantForm *m_grantTab;
    bool m_controlsDisabled;

};

#endif // GRANTUIWIDGET_H
