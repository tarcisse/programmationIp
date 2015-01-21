#include "xml_dom.h"

Xml_Dom::Xml_Dom()
{
    QDomDocument *dom = new QDomDocument("mon_xml");
        QFile xml_doc("fichier.xml");// On choisit le fichier contenant les informations XML.
        if(!xml_doc.open(QIODevice::ReadOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
        {
            QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
            return;
        }
        if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
        {
                xml_doc.close();
                QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
                return;
        }
    xml_doc.close(); // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet DOM.

    QDomElement dom_element = dom.documentElement();
        QDomNode noeud = dom_element.firstChild();
        while(!noeud.isNull())
        {
            if(!dom_element.isNull())
                QMessageBox::information(this, "Nom de la balise", "Le nom de la balise est " + dom_element.tagName());
                    noeud = noeud.nextSibling();
        }

}

Xml_Dom::~Xml_Dom()
{

}

