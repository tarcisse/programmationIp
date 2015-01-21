
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"



int main(void)
{


client Client;
Client.connection(5000,"127.0.0.1");
Client.envoyer("ce que j' envoie");
Client.recevoir();

    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    printf("ok");

    return EXIT_SUCCESS;
}
