#include "traiter_xml.h"
#include <QCoreApplication>
#include <QtXml>
#include <QtDebug>
#include <string.h>

QDomDocument document;

QDomNodeList items;
QDomNode itemnode;
QDomElement itemele;
QDomElement root;

QDomNodeList books;
QDomNode booknode;
QDomElement book;
String Monfichier[100][6];
string Monfichier1[6];
char *Monfichier2[6];
char t6;
int

traiter_xml::traiter_xml()
{
    document;
   QFile file("fichier.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "impossible de lire l fichier";
        //return -1;
    }
    else{

        if(!document.setContent(&file))
        {
            qDebug() << "impossible de charger le document";
            //return -1;
        }
        file.close();
    }
    //get the root element
     root=document.firstChildElement();
}



char* traiter_xml::ListElements (QDomElement root,QString tagname, QString attribute){

items=root.elementsByTagName(tagname);
qDebug() << "nombre d' item chargé: " << items.count();

for(int i=0;i<items.count();i++)
{
 itemnode=items.at(i);

//convert to element
if(itemnode.isElement())
{
    itemele=itemnode.toElement();
    qDebug()  << itemele.attribute(attribute);
   //Monfichier1[i]= "jjj";//itemele.attribute(attribute);
   strcpy( Monfichier1[i], "j");
}
}
return Monfichier1;
}

void traiter_xml::ListFichier()
{
    //lister les documents
       ListElements(root,"fichier","Nom");
}

char traiter_xml::ListeFichier_detail()
{


     qDebug() << "\r\n voir plus \r\n";
      books=root.elementsByTagName("fichier");

     for(int i=0;i<books.count();i++)
     {
     booknode=books.at(i);
 //convert to element
 if( booknode.isElement())
 {
      book= booknode.toElement();
      qDebug() <<"Details du fichier " << book.attribute("Nom");
       Monfichier2=ListElements(book,"infos","Nom");
       Monfichier[i][0]= Monfichier2[0];
        Monfichier[i][1]= Monfichier2[1];
         Monfichier[i][2]= Monfichier2[2];
          Monfichier[i][3]= Monfichier2[3];
           Monfichier[i][4]= Monfichier2[4];
            Monfichier[i][5]= Monfichier2[5];
return Monfichier;


 }
     }
}

traiter_xml::~traiter_xml()
{

}

