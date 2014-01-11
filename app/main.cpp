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

     Users *user = new Accounts();
     user->getStandardUsers();

     widget->show();

     return app.exec();
 }

