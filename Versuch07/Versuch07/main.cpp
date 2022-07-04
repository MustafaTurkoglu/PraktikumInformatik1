/** @mainpage
 *
 * Praktikum Informatik 1 MMXXII <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <algorithm>
#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    std::vector <Student>::iterator it;
    //std::vector <Student>::reverse_iterator revIt;

    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wuellnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement hinten entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank rueckwaerts ausgeben" << std::endl
                  << "(5): Element loeschen " << std::endl
                  << "(6): Datenelement hinzufuegen" << std::endl
                  << "(7): Datenelement vorne loeschen" << std::endl
                  << "(8): Datenbank aus einer Datei einlesen" << std::endl
                  << "(9): Datenbank in einer Datei speichern" << std::endl

                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement hinten entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.back();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout << student;
                        studentenListe.pop_back();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!"<< std::endl;
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(Student student : studentenListe)
                        std::cout << student;
                                    }
                else
                {
                    std::cout << "Die Liste ist leer!\n";
                }
                break;

            // Datenbank rueckwerts ausgeben

            case '4':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                    for( auto revIt=studentenListe.rbegin();revIt!=studentenListe.rend();revIt++){
                        std::cout <<(*revIt);
;
                    }
                    
                }
                else
                {
                    std::cout << "Die Liste ist leer!"<< std::endl;
                }
                break;
            // Element Loeschen
            case '5':{
                int matrNr = 0;
                if(!studentenListe.empty())
                {
                    std::cout << "Geben Sie die studentNr, die Sie loeschen moechten:" << std::endl;
                    std::cin >> matrNr;
                    it = find(studentenListe.begin(), studentenListe.end(), Student (matrNr, "", "", ""));

                    if(it != studentenListe.end())
                    {
                        std::cout << "Student(in) wurde in studenenListe gefunden: " << *it << std::endl;
                        studentenListe.erase(it);



                    }
                    else
                    {
                        std::cout << "Student(in) wurde in studenenListe nicht gefunden:\n";
                    }
                    
                }
                
                else
                {
                    std::cout << "Die Liste ist leer!"<< std::endl;;
                }
                }
                break;
                
                // Datenelement an irgeneiner Stelle hinzufuegen
            case '6':{
                unsigned int matNr = 0;
                int insertNummer = 0;
                if(!studentenListe.empty())
                {
                    std::cout << "An welche Stelle möchten Sie neues Element hinzufuegen?:" << std::endl;
                    std::cin >> insertNummer;
                    std::cin.ignore(10, '\n');
                    int index = insertNummer - 1;

                    
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\n Name: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag); //zeile einlesen

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    Student studentN(matNr, name, geburtstag, adresse);

                    studentenListe.insert(studentenListe.begin() + index, studentN);
                }
                else
                {
                    std::cout << "Die Liste ist Leer!\n\n";
                }
            }break;
                // Datenelement vorne loeschen
            case '7':{
                if(!studentenListe.empty())
                {
                    std::cout << "Erstes Element wird geloescht..." << std::endl;
                    studentenListe.erase(studentenListe.begin());
                }
                
                else
                {
                    std::cout << "Die Liste ist Leer!\n";
                }
            }break;
                //Daten aus einer Datei lesen
            case '8':{
                std::string dateiName = "";
                std::cout << "Geben Sie den Namen von Datei ein: ";
                std::cin >> dateiName;
                std::cin.ignore(10, '\n');

                std::ifstream eingabe(dateiName);//input modus
                studentenListe.clear();// clear bevor Datei lesen
                
                if (!eingabe)
                    std::cout<<"WTF"<<std::endl;
                
                if (eingabe) {
                    
                
                    std::string s=" ";
                    getline(eingabe, s);

                    do// loop um die ganze datei einzulesen
                    {
                    
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";
                    
                   
                    matNr=std::stoi(s);// str to int
                    getline(eingabe, s);
                        
                    name=s;
                    name.pop_back();
                    getline(eingabe, s);
                    geburtstag=s;
                    geburtstag.pop_back();
                            
                    getline(eingabe, s);
                    adresse=s;
                    adresse.pop_back();
                    //s="";
                    Student student(matNr, name, geburtstag, adresse);
                    
                    studentenListe.push_back(student);
                    getline(eingabe, s);

                }while(s!="");
                    eingabe.close();}
            }break;
                //Daten in einer Datei sichern
                case '9':
                  {
                      std::string dateiName = "";
                      std::cout << "Geben Sie den Namen von Datei ein: ";
                      std::cin >> dateiName;
                      std::cin.ignore(10, '\n');

                      std::ofstream ausgabe(dateiName);// output Modus


                      for(it = studentenListe.begin(); it != studentenListe.end(); it++)
                      {
                          ausgabe << it->getMatNr() << std::endl;
                          ausgabe << it->getName() << std::endl;
                          ausgabe << it->getGeburtstag() << std::endl;
                          ausgabe << it->getAdresse() << std::endl ;
                      }
                      ausgabe.close();
                  }
                  break;
           case 'a':
              {
                  if(!studentenListe.empty())
                  {
                      
                      std::sort(studentenListe.begin(), studentenListe.end());

                      
                      std::cout << "Die Liste wurde gesorted" << std::endl;
                      for(Student student : studentenListe)
                          std::cout << student;
                                      }
                  else
                  {
                      std::cout << "Die Liste ist leer!\n";
                  }
              }
              break;
            
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    //Beenden
    while (abfrage != '0');

    return 0;
}

