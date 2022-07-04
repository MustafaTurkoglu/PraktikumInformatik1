#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>

namespace Ui {
class dialogAddStreet;
}

class dialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAddStreet(QWidget *parent = nullptr);
    ~dialogAddStreet();
    QString getName1();
    QString getName2();

private:
    Ui::dialogAddStreet *ui;
    QString nameCity_1;
    QString nameCity_2;


};

#endif // DIALOGADDSTREET_H
