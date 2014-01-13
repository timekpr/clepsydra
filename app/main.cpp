#include <QApplication>

#include "user.h"
#include "accounts.h"

#include "ui_main.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     QWidget *widget = new QWidget;
     Ui::Form ui;
     ui.setupUi(widget);

     Accounts *accounts = new Accounts();
     accounts->getUsers();

     widget->show();

     delete accounts;

     return app.exec();
 }

