#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>

namespace Ui {
class Form;
}

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    

public slots:

private:
    Ui::Form *ui;

};

#endif // MAINWINDOW_H
