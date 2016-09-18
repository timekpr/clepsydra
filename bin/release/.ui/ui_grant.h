/********************************************************************************
** Form generated from reading UI file 'grant.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRANT_H
#define UI_GRANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grantForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *lbAddTime;
    QSpinBox *sbAddTime;
    QSpacerItem *verticalSpacer;
    QPushButton *btnClearAllRestriction;
    QPushButton *btnBypass;
    QPushButton *btnClearBypass;
    QPushButton *btnLockAccount;
    QPushButton *btnUnlockAccount;
    QPushButton *btnAddTime;
    QPushButton *btnResetTime;

    void setupUi(QWidget *grantForm)
    {
        if (grantForm->objectName().isEmpty())
            grantForm->setObjectName(QStringLiteral("grantForm"));
        grantForm->resize(385, 249);
        gridLayout = new QGridLayout(grantForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(grantForm);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 2);

        verticalSpacer_4 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 2);

        verticalSpacer_6 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 4, 1, 1, 2);

        label_2 = new QLabel(grantForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 6, 1, 1, 2);

        label_5 = new QLabel(grantForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbAddTime = new QLabel(grantForm);
        lbAddTime->setObjectName(QStringLiteral("lbAddTime"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbAddTime->sizePolicy().hasHeightForWidth());
        lbAddTime->setSizePolicy(sizePolicy);
        lbAddTime->setLayoutDirection(Qt::RightToLeft);
        lbAddTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lbAddTime);

        sbAddTime = new QSpinBox(grantForm);
        sbAddTime->setObjectName(QStringLiteral("sbAddTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbAddTime->sizePolicy().hasHeightForWidth());
        sbAddTime->setSizePolicy(sizePolicy1);
        sbAddTime->setMinimum(0);
        sbAddTime->setMaximum(1440);

        horizontalLayout->addWidget(sbAddTime);


        gridLayout->addLayout(horizontalLayout, 7, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 2);

        btnClearAllRestriction = new QPushButton(grantForm);
        btnClearAllRestriction->setObjectName(QStringLiteral("btnClearAllRestriction"));

        gridLayout->addWidget(btnClearAllRestriction, 1, 1, 1, 2);

        btnBypass = new QPushButton(grantForm);
        btnBypass->setObjectName(QStringLiteral("btnBypass"));

        gridLayout->addWidget(btnBypass, 3, 1, 1, 1);

        btnClearBypass = new QPushButton(grantForm);
        btnClearBypass->setObjectName(QStringLiteral("btnClearBypass"));

        gridLayout->addWidget(btnClearBypass, 3, 2, 1, 1);

        btnLockAccount = new QPushButton(grantForm);
        btnLockAccount->setObjectName(QStringLiteral("btnLockAccount"));

        gridLayout->addWidget(btnLockAccount, 5, 1, 1, 1);

        btnUnlockAccount = new QPushButton(grantForm);
        btnUnlockAccount->setObjectName(QStringLiteral("btnUnlockAccount"));

        gridLayout->addWidget(btnUnlockAccount, 5, 2, 1, 1);

        btnAddTime = new QPushButton(grantForm);
        btnAddTime->setObjectName(QStringLiteral("btnAddTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnAddTime->sizePolicy().hasHeightForWidth());
        btnAddTime->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(btnAddTime, 7, 1, 1, 1);

        btnResetTime = new QPushButton(grantForm);
        btnResetTime->setObjectName(QStringLiteral("btnResetTime"));
        sizePolicy2.setHeightForWidth(btnResetTime->sizePolicy().hasHeightForWidth());
        btnResetTime->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(btnResetTime, 8, 1, 1, 1);


        retranslateUi(grantForm);

        QMetaObject::connectSlotsByName(grantForm);
    } // setupUi

    void retranslateUi(QWidget *grantForm)
    {
        grantForm->setWindowTitle(QApplication::translate("grantForm", "Form", 0));
        label->setText(QApplication::translate("grantForm", "All restrictions:", 0));
        label_2->setText(QApplication::translate("grantForm", "Account lock:", 0));
        label_5->setText(QApplication::translate("grantForm", "Today access time:", 0));
        lbAddTime->setText(QApplication::translate("grantForm", "minutes:", 0));
        btnClearAllRestriction->setText(QApplication::translate("grantForm", "Clear", 0));
        btnBypass->setText(QApplication::translate("grantForm", "Bypass", 0));
        btnClearBypass->setText(QApplication::translate("grantForm", "Unbypass", 0));
        btnLockAccount->setText(QApplication::translate("grantForm", "Lock", 0));
        btnUnlockAccount->setText(QApplication::translate("grantForm", "Unlock", 0));
        btnAddTime->setText(QApplication::translate("grantForm", "Add", 0));
        btnResetTime->setText(QApplication::translate("grantForm", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class grantForm: public Ui_grantForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRANT_H
