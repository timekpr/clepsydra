/********************************************************************************
** Form generated from reading UI file 'limits.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIMITS_H
#define UI_LIMITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_limitForm
{
public:
    QGridLayout *gridLayout_4;
    QCheckBox *chkLimitAccessTimeDurationEachDay;
    QCheckBox *ckLimitAccessTimeFrame;
    QCheckBox *ckLimitAccessTimeDuration;
    QWidget *wgBoundConf;
    QGridLayout *gridLayout_3;
    QCheckBox *ckLimitAccessTimeFrameEachDay;
    QHBoxLayout *accConfEveryDay;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblEveryDay;
    QTimeEdit *sbLimitAccessDurarationEveryDay;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_13;
    QLabel *lblAccessTF_everyday;
    QTimeEdit *sbEveryFrom;
    QTimeEdit *sbEveryTo;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layAccess_mon;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lblAccessMon;
    QTimeEdit *sbLimit_mon;
    QHBoxLayout *layAccess_tue;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lblAccessTue;
    QTimeEdit *sbLimit_tue;
    QHBoxLayout *layAccess_wed;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lblAccessWed;
    QTimeEdit *sbLimit_wed;
    QHBoxLayout *layAccess_thu;
    QSpacerItem *horizontalSpacer_9;
    QLabel *lblAccessThu;
    QTimeEdit *sbLimit_thu;
    QHBoxLayout *layAccess_fri;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lblAccessFri;
    QTimeEdit *sbLimit_fri;
    QHBoxLayout *layAccess_sat;
    QSpacerItem *horizontalSpacer_11;
    QLabel *lblAccessSat;
    QTimeEdit *sbLimit_sat;
    QHBoxLayout *layAccess_sun;
    QSpacerItem *horizontalSpacer_12;
    QLabel *lblAccessSun;
    QTimeEdit *sbLimit_sun;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QCheckBox *ckLimitAccessDurationPerEachDay;
    QCheckBox *chLimitAccessTimeFramePerDay;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *lblAccessTF_mon;
    QTimeEdit *sbFrom_mon;
    QTimeEdit *sbTo_mon;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lblAccessTF_tue;
    QTimeEdit *sbFrom_tue;
    QTimeEdit *sbTo_tue;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_14;
    QLabel *lblAccessTF_wed;
    QTimeEdit *sbFrom_wed;
    QTimeEdit *sbTo_wed;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_15;
    QLabel *lblAccessTF_thu;
    QTimeEdit *sbFrom_thu;
    QTimeEdit *sbTo_thu;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_16;
    QLabel *lblAccessTF_fri;
    QTimeEdit *sbFrom_fri;
    QTimeEdit *sbTo_fri;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_17;
    QLabel *lblAccessTF_sat;
    QTimeEdit *sbFrom_sat;
    QTimeEdit *sbTo_sat;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_18;
    QLabel *lblAccessTF_sun;
    QTimeEdit *sbFrom_sun;
    QTimeEdit *sbTo_sun;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *limitForm)
    {
        if (limitForm->objectName().isEmpty())
            limitForm->setObjectName(QStringLiteral("limitForm"));
        limitForm->resize(684, 443);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(limitForm->sizePolicy().hasHeightForWidth());
        limitForm->setSizePolicy(sizePolicy);
        limitForm->setMinimumSize(QSize(0, 0));
        gridLayout_4 = new QGridLayout(limitForm);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        chkLimitAccessTimeDurationEachDay = new QCheckBox(limitForm);
        chkLimitAccessTimeDurationEachDay->setObjectName(QStringLiteral("chkLimitAccessTimeDurationEachDay"));

        gridLayout_4->addWidget(chkLimitAccessTimeDurationEachDay, 1, 0, 1, 1);

        ckLimitAccessTimeFrame = new QCheckBox(limitForm);
        ckLimitAccessTimeFrame->setObjectName(QStringLiteral("ckLimitAccessTimeFrame"));
        ckLimitAccessTimeFrame->setEnabled(true);
        ckLimitAccessTimeFrame->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(ckLimitAccessTimeFrame, 0, 3, 1, 1);

        ckLimitAccessTimeDuration = new QCheckBox(limitForm);
        ckLimitAccessTimeDuration->setObjectName(QStringLiteral("ckLimitAccessTimeDuration"));
        ckLimitAccessTimeDuration->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(ckLimitAccessTimeDuration, 0, 0, 1, 1);

        wgBoundConf = new QWidget(limitForm);
        wgBoundConf->setObjectName(QStringLiteral("wgBoundConf"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wgBoundConf->sizePolicy().hasHeightForWidth());
        wgBoundConf->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(wgBoundConf);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);

        gridLayout_4->addWidget(wgBoundConf, 6, 4, 1, 1);

        ckLimitAccessTimeFrameEachDay = new QCheckBox(limitForm);
        ckLimitAccessTimeFrameEachDay->setObjectName(QStringLiteral("ckLimitAccessTimeFrameEachDay"));
        ckLimitAccessTimeFrameEachDay->setEnabled(true);
        ckLimitAccessTimeFrameEachDay->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(ckLimitAccessTimeFrameEachDay, 1, 3, 1, 1);

        accConfEveryDay = new QHBoxLayout();
        accConfEveryDay->setObjectName(QStringLiteral("accConfEveryDay"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accConfEveryDay->addItem(horizontalSpacer_2);

        lblEveryDay = new QLabel(limitForm);
        lblEveryDay->setObjectName(QStringLiteral("lblEveryDay"));

        accConfEveryDay->addWidget(lblEveryDay);

        sbLimitAccessDurarationEveryDay = new QTimeEdit(limitForm);
        sbLimitAccessDurarationEveryDay->setObjectName(QStringLiteral("sbLimitAccessDurarationEveryDay"));

        accConfEveryDay->addWidget(sbLimitAccessDurarationEveryDay);


        gridLayout_4->addLayout(accConfEveryDay, 2, 0, 2, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 6, 5, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        lblAccessTF_everyday = new QLabel(limitForm);
        lblAccessTF_everyday->setObjectName(QStringLiteral("lblAccessTF_everyday"));
        lblAccessTF_everyday->setMinimumSize(QSize(0, 23));
        lblAccessTF_everyday->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAccessTF_everyday->setMargin(0);
        lblAccessTF_everyday->setIndent(4);

        horizontalLayout_3->addWidget(lblAccessTF_everyday);

        sbEveryFrom = new QTimeEdit(limitForm);
        sbEveryFrom->setObjectName(QStringLiteral("sbEveryFrom"));
        sbEveryFrom->setEnabled(true);
        sbEveryFrom->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(sbEveryFrom);

        sbEveryTo = new QTimeEdit(limitForm);
        sbEveryTo->setObjectName(QStringLiteral("sbEveryTo"));
        sbEveryTo->setEnabled(true);
        sbEveryTo->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(sbEveryTo);


        gridLayout_4->addLayout(horizontalLayout_3, 2, 3, 2, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layAccess_mon = new QHBoxLayout();
        layAccess_mon->setObjectName(QStringLiteral("layAccess_mon"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_mon->addItem(horizontalSpacer_6);

        lblAccessMon = new QLabel(limitForm);
        lblAccessMon->setObjectName(QStringLiteral("lblAccessMon"));

        layAccess_mon->addWidget(lblAccessMon);

        sbLimit_mon = new QTimeEdit(limitForm);
        sbLimit_mon->setObjectName(QStringLiteral("sbLimit_mon"));

        layAccess_mon->addWidget(sbLimit_mon);


        verticalLayout->addLayout(layAccess_mon);

        layAccess_tue = new QHBoxLayout();
        layAccess_tue->setObjectName(QStringLiteral("layAccess_tue"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_tue->addItem(horizontalSpacer_3);

        lblAccessTue = new QLabel(limitForm);
        lblAccessTue->setObjectName(QStringLiteral("lblAccessTue"));

        layAccess_tue->addWidget(lblAccessTue);

        sbLimit_tue = new QTimeEdit(limitForm);
        sbLimit_tue->setObjectName(QStringLiteral("sbLimit_tue"));

        layAccess_tue->addWidget(sbLimit_tue);


        verticalLayout->addLayout(layAccess_tue);

        layAccess_wed = new QHBoxLayout();
        layAccess_wed->setObjectName(QStringLiteral("layAccess_wed"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_wed->addItem(horizontalSpacer_8);

        lblAccessWed = new QLabel(limitForm);
        lblAccessWed->setObjectName(QStringLiteral("lblAccessWed"));

        layAccess_wed->addWidget(lblAccessWed);

        sbLimit_wed = new QTimeEdit(limitForm);
        sbLimit_wed->setObjectName(QStringLiteral("sbLimit_wed"));

        layAccess_wed->addWidget(sbLimit_wed);


        verticalLayout->addLayout(layAccess_wed);

        layAccess_thu = new QHBoxLayout();
        layAccess_thu->setObjectName(QStringLiteral("layAccess_thu"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_thu->addItem(horizontalSpacer_9);

        lblAccessThu = new QLabel(limitForm);
        lblAccessThu->setObjectName(QStringLiteral("lblAccessThu"));

        layAccess_thu->addWidget(lblAccessThu);

        sbLimit_thu = new QTimeEdit(limitForm);
        sbLimit_thu->setObjectName(QStringLiteral("sbLimit_thu"));

        layAccess_thu->addWidget(sbLimit_thu);


        verticalLayout->addLayout(layAccess_thu);

        layAccess_fri = new QHBoxLayout();
        layAccess_fri->setObjectName(QStringLiteral("layAccess_fri"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_fri->addItem(horizontalSpacer_10);

        lblAccessFri = new QLabel(limitForm);
        lblAccessFri->setObjectName(QStringLiteral("lblAccessFri"));

        layAccess_fri->addWidget(lblAccessFri);

        sbLimit_fri = new QTimeEdit(limitForm);
        sbLimit_fri->setObjectName(QStringLiteral("sbLimit_fri"));

        layAccess_fri->addWidget(sbLimit_fri);


        verticalLayout->addLayout(layAccess_fri);

        layAccess_sat = new QHBoxLayout();
        layAccess_sat->setObjectName(QStringLiteral("layAccess_sat"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_sat->addItem(horizontalSpacer_11);

        lblAccessSat = new QLabel(limitForm);
        lblAccessSat->setObjectName(QStringLiteral("lblAccessSat"));

        layAccess_sat->addWidget(lblAccessSat);

        sbLimit_sat = new QTimeEdit(limitForm);
        sbLimit_sat->setObjectName(QStringLiteral("sbLimit_sat"));

        layAccess_sat->addWidget(sbLimit_sat);


        verticalLayout->addLayout(layAccess_sat);

        layAccess_sun = new QHBoxLayout();
        layAccess_sun->setObjectName(QStringLiteral("layAccess_sun"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layAccess_sun->addItem(horizontalSpacer_12);

        lblAccessSun = new QLabel(limitForm);
        lblAccessSun->setObjectName(QStringLiteral("lblAccessSun"));

        layAccess_sun->addWidget(lblAccessSun);

        sbLimit_sun = new QTimeEdit(limitForm);
        sbLimit_sun->setObjectName(QStringLiteral("sbLimit_sun"));

        layAccess_sun->addWidget(sbLimit_sun);


        verticalLayout->addLayout(layAccess_sun);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_4->addLayout(verticalLayout, 5, 0, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 163, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 6, 1, 1, 1);

        line = new QFrame(limitForm);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 0, 2, 8, 1);

        ckLimitAccessDurationPerEachDay = new QCheckBox(limitForm);
        ckLimitAccessDurationPerEachDay->setObjectName(QStringLiteral("ckLimitAccessDurationPerEachDay"));

        gridLayout_4->addWidget(ckLimitAccessDurationPerEachDay, 4, 0, 1, 1);

        chLimitAccessTimeFramePerDay = new QCheckBox(limitForm);
        chLimitAccessTimeFramePerDay->setObjectName(QStringLiteral("chLimitAccessTimeFramePerDay"));

        gridLayout_4->addWidget(chLimitAccessTimeFramePerDay, 4, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lblAccessTF_mon = new QLabel(limitForm);
        lblAccessTF_mon->setObjectName(QStringLiteral("lblAccessTF_mon"));
        lblAccessTF_mon->setMinimumSize(QSize(0, 23));
        lblAccessTF_mon->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAccessTF_mon->setMargin(0);
        lblAccessTF_mon->setIndent(4);

        horizontalLayout->addWidget(lblAccessTF_mon);

        sbFrom_mon = new QTimeEdit(limitForm);
        sbFrom_mon->setObjectName(QStringLiteral("sbFrom_mon"));
        sbFrom_mon->setEnabled(true);
        sbFrom_mon->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(sbFrom_mon);

        sbTo_mon = new QTimeEdit(limitForm);
        sbTo_mon->setObjectName(QStringLiteral("sbTo_mon"));
        sbTo_mon->setEnabled(true);
        sbTo_mon->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(sbTo_mon);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        lblAccessTF_tue = new QLabel(limitForm);
        lblAccessTF_tue->setObjectName(QStringLiteral("lblAccessTF_tue"));
        lblAccessTF_tue->setMinimumSize(QSize(0, 23));
        lblAccessTF_tue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAccessTF_tue->setMargin(0);
        lblAccessTF_tue->setIndent(4);

        horizontalLayout_6->addWidget(lblAccessTF_tue);

        sbFrom_tue = new QTimeEdit(limitForm);
        sbFrom_tue->setObjectName(QStringLiteral("sbFrom_tue"));
        sbFrom_tue->setEnabled(true);
        sbFrom_tue->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(sbFrom_tue);

        sbTo_tue = new QTimeEdit(limitForm);
        sbTo_tue->setObjectName(QStringLiteral("sbTo_tue"));
        sbTo_tue->setEnabled(true);
        sbTo_tue->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(sbTo_tue);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_14);

        lblAccessTF_wed = new QLabel(limitForm);
        lblAccessTF_wed->setObjectName(QStringLiteral("lblAccessTF_wed"));
        lblAccessTF_wed->setMinimumSize(QSize(0, 23));
        lblAccessTF_wed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAccessTF_wed->setMargin(0);
        lblAccessTF_wed->setIndent(4);

        horizontalLayout_7->addWidget(lblAccessTF_wed);

        sbFrom_wed = new QTimeEdit(limitForm);
        sbFrom_wed->setObjectName(QStringLiteral("sbFrom_wed"));
        sbFrom_wed->setEnabled(true);
        sbFrom_wed->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(sbFrom_wed);

        sbTo_wed = new QTimeEdit(limitForm);
        sbTo_wed->setObjectName(QStringLiteral("sbTo_wed"));
        sbTo_wed->setEnabled(true);
        sbTo_wed->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(sbTo_wed);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_15);

        lblAccessTF_thu = new QLabel(limitForm);
        lblAccessTF_thu->setObjectName(QStringLiteral("lblAccessTF_thu"));
        lblAccessTF_thu->setMinimumSize(QSize(0, 23));
        lblAccessTF_thu->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAccessTF_thu->setMargin(0);
        lblAccessTF_thu->setIndent(4);

        horizontalLayout_9->addWidget(lblAccessTF_thu);

        sbFrom_thu = new QTimeEdit(limitForm);
        sbFrom_thu->setObjectName(QStringLiteral("sbFrom_thu"));
        sbFrom_thu->setEnabled(true);
        sbFrom_thu->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(sbFrom_thu);

        sbTo_thu = new QTimeEdit(limitForm);
        sbTo_thu->setObjectName(QStringLiteral("sbTo_thu"));
        sbTo_thu->setEnabled(true);
        sbTo_thu->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(sbTo_thu);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        lblAccessTF_fri = new QLabel(limitForm);
        lblAccessTF_fri->setObjectName(QStringLiteral("lblAccessTF_fri"));
        lblAccessTF_fri->setMinimumSize(QSize(0, 23));
        lblAccessTF_fri->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblAccessTF_fri->setMargin(0);
        lblAccessTF_fri->setIndent(4);

        horizontalLayout_10->addWidget(lblAccessTF_fri);

        sbFrom_fri = new QTimeEdit(limitForm);
        sbFrom_fri->setObjectName(QStringLiteral("sbFrom_fri"));
        sbFrom_fri->setEnabled(true);
        sbFrom_fri->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(sbFrom_fri);

        sbTo_fri = new QTimeEdit(limitForm);
        sbTo_fri->setObjectName(QStringLiteral("sbTo_fri"));
        sbTo_fri->setEnabled(true);
        sbTo_fri->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(sbTo_fri);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_17);

        lblAccessTF_sat = new QLabel(limitForm);
        lblAccessTF_sat->setObjectName(QStringLiteral("lblAccessTF_sat"));

        horizontalLayout_11->addWidget(lblAccessTF_sat);

        sbFrom_sat = new QTimeEdit(limitForm);
        sbFrom_sat->setObjectName(QStringLiteral("sbFrom_sat"));

        horizontalLayout_11->addWidget(sbFrom_sat);

        sbTo_sat = new QTimeEdit(limitForm);
        sbTo_sat->setObjectName(QStringLiteral("sbTo_sat"));

        horizontalLayout_11->addWidget(sbTo_sat);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_18);

        lblAccessTF_sun = new QLabel(limitForm);
        lblAccessTF_sun->setObjectName(QStringLiteral("lblAccessTF_sun"));

        horizontalLayout_12->addWidget(lblAccessTF_sun);

        sbFrom_sun = new QTimeEdit(limitForm);
        sbFrom_sun->setObjectName(QStringLiteral("sbFrom_sun"));

        horizontalLayout_12->addWidget(sbFrom_sun);

        sbTo_sun = new QTimeEdit(limitForm);
        sbTo_sun->setObjectName(QStringLiteral("sbTo_sun"));

        horizontalLayout_12->addWidget(sbTo_sun);


        verticalLayout_3->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout_4->addLayout(verticalLayout_3, 5, 3, 2, 2);


        retranslateUi(limitForm);

        QMetaObject::connectSlotsByName(limitForm);
    } // setupUi

    void retranslateUi(QWidget *limitForm)
    {
        limitForm->setWindowTitle(QApplication::translate("limitForm", "Form", 0));
        chkLimitAccessTimeDurationEachDay->setText(QApplication::translate("limitForm", "Configure every day", 0));
        ckLimitAccessTimeFrame->setText(QApplication::translate("limitForm", "Limit access on time frame", 0));
        ckLimitAccessTimeDuration->setText(QApplication::translate("limitForm", "Limit access on duration", 0));
        ckLimitAccessTimeFrameEachDay->setText(QApplication::translate("limitForm", "Configure every day", 0));
        lblEveryDay->setText(QApplication::translate("limitForm", "Every day:", 0));
        sbLimitAccessDurarationEveryDay->setDisplayFormat(QApplication::translate("limitForm", "HH:mm", 0));
        lblAccessTF_everyday->setText(QApplication::translate("limitForm", "Every day:", 0));
        sbEveryFrom->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbEveryTo->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessMon->setText(QApplication::translate("limitForm", "Monday", 0));
        sbLimit_mon->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTue->setText(QApplication::translate("limitForm", "Tuesday", 0));
        sbLimit_tue->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessWed->setText(QApplication::translate("limitForm", "Wednesday", 0));
        sbLimit_wed->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessThu->setText(QApplication::translate("limitForm", "Thursday", 0));
        sbLimit_thu->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessFri->setText(QApplication::translate("limitForm", "Friday", 0));
        sbLimit_fri->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessSat->setText(QApplication::translate("limitForm", "Saturday", 0));
        sbLimit_sat->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessSun->setText(QApplication::translate("limitForm", "Sunday", 0));
        sbLimit_sun->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        ckLimitAccessDurationPerEachDay->setText(QApplication::translate("limitForm", "Per each day:", 0));
        chLimitAccessTimeFramePerDay->setText(QApplication::translate("limitForm", "Per each day :", 0));
        lblAccessTF_mon->setText(QApplication::translate("limitForm", "Monday:", 0));
        sbFrom_mon->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_mon->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTF_tue->setText(QApplication::translate("limitForm", "Tuesday:", 0));
        sbFrom_tue->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_tue->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTF_wed->setText(QApplication::translate("limitForm", "Wednesday:", 0));
        sbFrom_wed->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_wed->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTF_thu->setText(QApplication::translate("limitForm", "Thursday", 0));
        sbFrom_thu->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_thu->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTF_fri->setText(QApplication::translate("limitForm", "Friday:", 0));
        sbFrom_fri->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_fri->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTF_sat->setText(QApplication::translate("limitForm", "Saturday", 0));
        sbFrom_sat->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_sat->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        lblAccessTF_sun->setText(QApplication::translate("limitForm", "Sunday", 0));
        sbFrom_sun->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
        sbTo_sun->setDisplayFormat(QApplication::translate("limitForm", "hh:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class limitForm: public Ui_limitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIMITS_H
