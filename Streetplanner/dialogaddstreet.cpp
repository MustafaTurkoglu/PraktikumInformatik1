#include "dialogaddstreet.h"
#include "ui_dialogaddstreet.h"

dialogAddStreet::dialogAddStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAddStreet)
{
    ui->setupUi(this);
}

dialogAddStreet::~dialogAddStreet()
{
    delete ui;
}

QString dialogAddStreet::getName1()
{
    nameCity_1 = ui->City_1->text();

    return nameCity_1;
}

QString dialogAddStreet::getName2()
{
    nameCity_2 = ui->City_2->text();

    return nameCity_2;
}
