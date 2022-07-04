#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <city.h>
#include <map.h>
#include <QDebug>
#include <QGraphicsScene>
#include <QMessageBox>
#include <dialog.h>
#include <dialogaddstreet.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug()<<"testen";
}




void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();

}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"About","Streetplanner crated by musti");
}


void MainWindow::on_drawCity_clicked()
{
    City city1("Istanbul",100,500);
    City city2("Aachen",100,500);

    city1.draw(scene);
    city2.draw(scene);

}



void MainWindow::on_drawMap_clicked()
{
        City c1("city c1", 20,50);
        map.addCity(&c1);
        map.draw(scene);
}


void MainWindow::on_testStreet_clicked()
{
    City newCityy1("noobCity1", 0, 20);
    City newCityy2("noobCity2", 100, 200);
    Street newStreet(&newCityy1, &newCityy2);
    map.addCity(&newCityy1);
    map.addCity(&newCityy2);
    newCityy1.draw(scene);
    newCityy2.draw(scene);
    newStreet.draw(scene);
}


void MainWindow::on_testModus_clicked()
{
    if (ui->testModus->isChecked()==true)
            {
                ui->testStreet->hide();
                ui->drawMap->hide();
                ui->drawCity->hide();
            }

            else if(ui->testModus->isChecked()==false)
            {
                ui->testStreet->show();
                ui->drawMap->show();
                ui->drawCity->show();
            }
}

void MainWindow::on_addCity_clicked()
{
    Dialog dialog;
a:
        int i = dialog.exec();
        qDebug() << "Der Rückgabewert: " << i;

        if (i == 1)
        {
            City* city = dialog.newCity();
            if(dialog.result()==2){

                QMessageBox::warning(this,"Fehler!","Bitte geben Sie nur ganze Zahlen ein! ");

                goto a;

            }
            else{
                map.addCity(city);
                city->draw(scene);
            }
        }

        else
        {
            qDebug() << "Keine neue Stadt wurde hinzugefuegt.";
        }
}


void MainWindow::on_fillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
}


void MainWindow::on_testAbstractMap_clicked()
{

        Map testMap;
        City *a = new City("a", 0, 0);
        City *b = new City("b", 0, 100);
        City *c = new City("c", 100, 300);
        Street *s = new Street(a, b);
        Street *s2 = new Street(b, c);


        qDebug() << "MapTest: Start Test of the Map";
        {
            qDebug() << "MapTest: adding wrong street";
            bool t1 = testMap.addStreet(s);
            if (t1) {
                qDebug() << "-Error: Street should not bee added, if cities have not been added.";
            }
        }

        {
            qDebug() << "MapTest: adding correct street";
            testMap.addCity(a);
            testMap.addCity(b);
            bool t1 = testMap.addStreet(s);
            if (!t1) {
                qDebug() << "-Error: It should be possible to add this street.";
            }
        }

        {
            qDebug() << "MapTest: findCity";
            City* city = testMap.findCity("a");
            if (city != a)
                qDebug() << "-Error: City a could not be found.";

            city = testMap.findCity("b");
            if (city != b)
                qDebug() << "-Error: City b could not be found.";

            city = testMap.findCity("c");
            if (city != nullptr)
                qDebug() << "-Error: If city could not be found 0 should be returned.";
        }

        testMap.addCity(c);
        testMap.addStreet(s2);

        {
            qDebug() << "MapTest: getOppositeCity";
            const City *city = testMap.getOppositeCity(s, a);
            if (city != b)
                qDebug() << "-Error: Opposite city should be b.";

            city = map.getOppositeCity(s, c);
            if (city != nullptr)
                qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
        }

        {
            qDebug() << "MapTest: streetLength";
            double l = testMap.getLength(s2);
            double expectedLength = 223.6;
            // compare doubles with 5% tolerance
            if (l < expectedLength * 0.95 || l > expectedLength *1.05)
                qDebug() << "-Error: Street Length is not equal to the expected.";

        }

        {
            qDebug() << "MapTest: getStreetList";
            QVector<Street*> streetList1 = testMap.getStreetList(a);
            QVector<Street*> streetList2 = testMap.getStreetList(b);
            if (streetList1.size() != 1) {
                qDebug() << "-Error: One street should be found for city a.";
            }
            else if (*streetList1.begin() != s) {
                    qDebug() << "-Error: The wrong street has been found for city a.";
            }

            if (streetList2.size() != 2)
                qDebug() << "-Error: Two streets should be found for city b.";
        }

        qDebug() << "MapTest: End Test of the Map.";


}


void MainWindow::on_testDijkstra_clicked()
{
    Map testMap;
       City a("a", 0, 0);
       City b("b", 100, 0);
       City c("c", 0, 100);
       City d("d", 100, 200);

       testMap.addCity(&a);
       testMap.addCity(&b);
       testMap.addCity(&c);
       testMap.addCity(&d);

       Street s1(&a, &b);
       Street s2(&b, &c);
       Street s3(&a, &c);
       Street s4(&c, &d);
       testMap.addStreet(&s1);
       testMap.addStreet(&s2);
       testMap.addStreet(&s3);
       testMap.addStreet(&s4);

       testMap.draw(scene);

       QVector<Street*> kuerzesterWeg = Dijkstra::search(testMap, a.getName(), d.getName());

       for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
       {
           (*it)->drawRed(scene);
       }
}


void MainWindow::on_addStreet_clicked()
{
    dialogAddStreet dialog;
        int i = dialog.exec();
        qDebug() << "Der Rückgabewert: " << i;


        if (i == 1)
        {
            QString Name1 = dialog.getName1();
            QString Name2 = dialog.getName2();

            if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
            {
                qDebug() << "Geben Sie richtige Stadt ein!";
                return;
            }

            City* city1 = map.findCity(Name1);
            City* city2 = map.findCity(Name2);

            Street* strasse = new Street(city1, city2);
            if(map.addStreet(strasse))
            {
                strasse->draw(scene);
            }
        }

        else
        {
            qDebug() << "Keine neue Strasse war hinzugefuegt!";
        }
}

