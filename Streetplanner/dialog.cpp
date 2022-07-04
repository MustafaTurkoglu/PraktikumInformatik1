#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::newCity()
{
    nameofCity = ui->nameDerStadt->text();
    qDebug() << nameofCity;
    bool ok;


    x = ui->XKoor->text().toInt(&ok);

    if (ok == false)
    {

        qDebug() << "Bitte geben Sie eine ganze Zahl ein!";
        setResult(2);
       // QMessageBox::about(this,"Fehler!","Bitte geben Sie nur ganze Zahlen ein! ");

    }
    else
    {
        qDebug() << y;
    }

    y = ui->YKoor->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine ganze Zahl ein!";
        setResult(2);

       // QMessageBox::about(this,"Fehler!","Bitte geben Sie nur ganze Zahlen ein! ");

    }
    else
    {
        qDebug() << y;
    }

    return  new City(nameofCity, x, y);
}



