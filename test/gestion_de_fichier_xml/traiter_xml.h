
#include <QCoreApplication>
#include <QtXml>
#include <QtDebug>
#ifndef TRAITER_XML_H
#define TRAITER_XML_H


class traiter_xml
{

public:
    traiter_xml();
   char *ListElements(QDomElement root,QString tagname, QString attribute);
   void ListFichier();
  char ListeFichier_detail();
    ~traiter_xml();
};

#endif // TRAITER_XML_H
