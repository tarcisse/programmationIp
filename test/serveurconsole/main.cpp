

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serveur.h"



int main(void)
{
serveur Serv;

Serv.connexion(5000,htonl(INADDR_ANY));
while(true)
{
Serv.ecoute();
Serv.recevoir();
Serv.envoyer("bonjour tarcisse !!!");
}
  printf("ok");

    return EXIT_SUCCESS;
}
