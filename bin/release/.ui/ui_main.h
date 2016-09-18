/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_1;
    QSpacerItem *horizontalSpacer;
    QLabel *lbActiveUser;
    QComboBox *cbActiveUser;
    QFrame *frStatus;
    QVBoxLayout *lyStatus;
    QLabel *lbStatus;
    QTabWidget *tab;
    QWidget *tbGrant;
    QWidget *tbLimitBound;
    QWidget *tbStatus;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(553, 245);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer);

        lbActiveUser = new QLabel(Form);
        lbActiveUser->setObjectName(QStringLiteral("lbActiveUser"));

        horizontalLayout_1->addWidget(lbActiveUser);

        cbActiveUser = new QComboBox(Form);
        cbActiveUser->setObjectName(QStringLiteral("cbActiveUser"));
        cbActiveUser->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_1->addWidget(cbActiveUser);


        gridLayout->addLayout(horizontalLayout_1, 0, 0, 1, 2);

        frStatus = new QFrame(Form);
        frStatus->setObjectName(QStringLiteral("frStatus"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frStatus->sizePolicy().hasHeightForWidth());
        frStatus->setSizePolicy(sizePolicy);
        frStatus->setMinimumSize(QSize(0, 0));
        frStatus->setFrameShape(QFrame::StyledPanel);
        frStatus->setFrameShadow(QFrame::Raised);
        lyStatus = new QVBoxLayout(frStatus);
        lyStatus->setObjectName(QStringLiteral("lyStatus"));
        lbStatus = new QLabel(frStatus);
        lbStatus->setObjectName(QStringLiteral("lbStatus"));
        lbStatus->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbStatus->sizePolicy().hasHeightForWidth());
        lbStatus->setSizePolicy(sizePolicy1);
        lbStatus->setTextFormat(Qt::AutoText);
        lbStatus->setAlignment(Qt::AlignCenter);

        lyStatus->addWidget(lbStatus);


        gridLayout->addWidget(frStatus, 1, 0, 1, 1);

        tab = new QTabWidget(Form);
        tab->setObjectName(QStringLiteral("tab"));
        tbGrant = new QWidget();
        tbGrant->setObjectName(QStringLiteral("tbGrant"));
        tab->addTab(tbGrant, QString());
        tbLimitBound = new QWidget();
        tbLimitBound->setObjectName(QStringLiteral("tbLimitBound"));
        tab->addTab(tbLimitBound, QString());
        tbStatus = new QWidget();
        tbStatus->setObjectName(QStringLiteral("tbStatus"));
        tbStatus->setFocusPolicy(Qt::NoFocus);
        tab->addTab(tbStatus, QString());

        gridLayout->addWidget(tab, 1, 1, 1, 1);


        retranslateUi(Form);

        tab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Clepsydra", 0));
        lbActiveUser->setText(QApplication::translate("Form", "Current user:", 0));
        lbStatus->setText(QApplication::translate("Form", "<b>Status</b>", 0));
        tab->setTabText(tab->indexOf(tbGrant), QApplication::translate("Form", "Grant", 0));
        tab->setTabText(tab->indexOf(tbLimitBound), QApplication::translate("Form", "Limits and Bounds", 0));
        tab->setTabText(tab->indexOf(tbStatus), QApplication::translate("Form", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
