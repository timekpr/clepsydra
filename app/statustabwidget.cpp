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
#include "statustabwidget.h"
#include "config.h"

StatusTabWidget::StatusTabWidget(QWidget *parent) :
    QWidget(parent), m_statusTab(new Ui::statusForm)
{
    m_statusTab->setupUi(this);
}

void StatusTabWidget::setStatus (const QVariantMap& map)
{
    if (map.count())  {
        bool locked = map.value(CLEPSYDRA_LOCKED).toBool();
        if (locked) {
            m_statusTab->lbAccountlocked->setText(tr("Yes"));
        } else {
            m_statusTab->lbAccountlocked->setText(tr("No"));
        }

        bool limited = map.value(CLEPSYDRA_LIMITED).toBool();
        if (limited)  {
            m_statusTab->lbLimitedByAccessDuration->setText(tr("Yes"));
        } else {
            m_statusTab->lbLimitedByAccessDuration->setText(tr("No"));
        }

        bool limitedTf = map.value(CLEPSYDRA_LIMIT_LIMITSBYDAY).toBool();
        if (limitedTf)  {
            m_statusTab->lbLimitedByTimeFrame->setText(tr("Yes"));
        } else {
            m_statusTab->lbLimitedByTimeFrame->setText(tr("No"));
        }
    }
}

void StatusTabWidget::disableControls(bool /*toDisable*/)
{

}
