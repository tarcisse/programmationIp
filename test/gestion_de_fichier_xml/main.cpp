#include <QCoreApplication>
#include <QtXml>
#include <QtDebug>
#include "traiter_xml.h";


int main(int argc, char *argv[])
{
    char Monfichier[100][6];
traiter_xml fichier;
//fichier.ListFichier();
 /*Monfichier=*/ fichier.ListeFichier_detail();

    return 0;
}
