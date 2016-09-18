/********************************************************************************
** Form generated from reading UI file 'status.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUS_H
#define UI_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statusForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbAllDayLogin;
    QLabel *lbLock;
    QLabel *lbBound;
    QLabel *lbLimit;
    QLabel *lbTimeLeft;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QLabel *lbLimitedByAccessDuration;
    QLabel *lbAccountlocked;
    QLabel *lbAbleToLoginAllDayToday;
    QLabel *lbLimitedByTimeFrame;
    QLabel *lbTimeLeftStatus;

    void setupUi(QWidget *statusForm)
    {
        if (statusForm->objectName().isEmpty())
            statusForm->setObjectName(QStringLiteral("statusForm"));
        statusForm->resize(315, 252);
        gridLayout = new QGridLayout(statusForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(10, 14, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        lbAllDayLogin = new QLabel(statusForm);
        lbAllDayLogin->setObjectName(QStringLiteral("lbAllDayLogin"));
        lbAllDayLogin->setMinimumSize(QSize(0, 24));
        lbAllDayLogin->setLayoutDirection(Qt::RightToLeft);
        lbAllDayLogin->setFrameShape(QFrame::NoFrame);
        lbAllDayLogin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbAllDayLogin, 1, 0, 1, 1);

        lbLock = new QLabel(statusForm);
        lbLock->setObjectName(QStringLiteral("lbLock"));
        lbLock->setMinimumSize(QSize(0, 24));
        lbLock->setLayoutDirection(Qt::RightToLeft);
        lbLock->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbLock, 4, 0, 1, 1);

        lbBound = new QLabel(statusForm);
        lbBound->setObjectName(QStringLiteral("lbBound"));
        lbBound->setMinimumSize(QSize(0, 24));
        lbBound->setLayoutDirection(Qt::RightToLeft);
        lbBound->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbBound, 6, 0, 1, 1);

        lbLimit = new QLabel(statusForm);
        lbLimit->setObjectName(QStringLiteral("lbLimit"));
        lbLimit->setMinimumSize(QSize(0, 24));
        lbLimit->setLayoutDirection(Qt::RightToLeft);
        lbLimit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbLimit, 8, 0, 1, 1);

        lbTimeLeft = new QLabel(statusForm);
        lbTimeLeft->setObjectName(QStringLiteral("lbTimeLeft"));
        lbTimeLeft->setMinimumSize(QSize(0, 24));
        lbTimeLeft->setLayoutDirection(Qt::RightToLeft);
        lbTimeLeft->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbTimeLeft, 10, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(206, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 3);

        verticalSpacer_4 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 7, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 9, 0, 1, 1);

        lbLimitedByAccessDuration = new QLabel(statusForm);
        lbLimitedByAccessDuration->setObjectName(QStringLiteral("lbLimitedByAccessDuration"));
        lbLimitedByAccessDuration->setTextFormat(Qt::PlainText);
        lbLimitedByAccessDuration->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbLimitedByAccessDuration, 6, 1, 1, 1);

        lbAccountlocked = new QLabel(statusForm);
        lbAccountlocked->setObjectName(QStringLiteral("lbAccountlocked"));
        lbAccountlocked->setTextFormat(Qt::PlainText);
        lbAccountlocked->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbAccountlocked, 4, 1, 1, 1);

        lbAbleToLoginAllDayToday = new QLabel(statusForm);
        lbAbleToLoginAllDayToday->setObjectName(QStringLiteral("lbAbleToLoginAllDayToday"));
        lbAbleToLoginAllDayToday->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(lbAbleToLoginAllDayToday, 1, 1, 1, 1);

        lbLimitedByTimeFrame = new QLabel(statusForm);
        lbLimitedByTimeFrame->setObjectName(QStringLiteral("lbLimitedByTimeFrame"));
        lbLimitedByTimeFrame->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(lbLimitedByTimeFrame, 8, 1, 1, 1);

        lbTimeLeftStatus = new QLabel(statusForm);
        lbTimeLeftStatus->setObjectName(QStringLiteral("lbTimeLeftStatus"));
        lbTimeLeftStatus->setMinimumSize(QSize(100, 0));
        lbTimeLeftStatus->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(lbTimeLeftStatus, 10, 1, 1, 1);


        retranslateUi(statusForm);

        QMetaObject::connectSlotsByName(statusForm);
    } // setupUi

    void retranslateUi(QWidget *statusForm)
    {
        statusForm->setWindowTitle(QApplication::translate("statusForm", "Form", 0));
        lbAllDayLogin->setText(QApplication::translate("statusForm", "Able to login all day today:", 0));
        lbLock->setText(QApplication::translate("statusForm", "Account locked:", 0));
        lbBound->setText(QApplication::translate("statusForm", "Limited by access duration:", 0));
        lbLimit->setText(QApplication::translate("statusForm", "Limited by time frame:", 0));
        lbTimeLeft->setText(QApplication::translate("statusForm", "Usage time left:", 0));
        lbLimitedByAccessDuration->setText(QApplication::translate("statusForm", "No", 0));
        lbAccountlocked->setText(QApplication::translate("statusForm", "No", 0));
        lbAbleToLoginAllDayToday->setText(QApplication::translate("statusForm", "Yes", 0));
        lbLimitedByTimeFrame->setText(QApplication::translate("statusForm", "No", 0));
        lbTimeLeftStatus->setText(QApplication::translate("statusForm", "No limit", 0));
    } // retranslateUi

};

namespace Ui {
    class statusForm: public Ui_statusForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUS_H
