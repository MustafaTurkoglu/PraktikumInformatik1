#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <city.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    City* newCity();
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
  //  void on_textBrowser_anchorClicked(const QUrl &arg1);

private:
    Ui::Dialog *ui;
    QString nameofCity;
    //QString strasse;
    //QString nameCity1;
    //QString nameCity2;
    int x;
    int y;
};

#endif // DIALOG_H
