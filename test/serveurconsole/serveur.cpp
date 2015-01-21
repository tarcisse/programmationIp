#include "serveur.h"
SOCKET sock; //creation de la socket serveur
SOCKADDR_IN sin; //stricture qui permet de gerer l' addressage et le numero de port
SOCKET csock; //creation de la socket qui se chargera de la communication avec le client
SOCKADDR_IN csin; //strucure des information du client
char buffer1[32] = "Bonjour !";  //envoi
char buffer2[32] = "Bonjour !";  //reception
socklen_t recsize = sizeof(csin); //????
int sock_err;

serveur::serveur()
{

    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

}
serveur::connexion(int port,char ipadresse){
    /* Si la socket est valide */
    if(sock != INVALID_SOCKET)
    {
        printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);

        /* Configuration */
        sin.sin_addr.s_addr    = ipadresse/*htonl(INADDR_ANY)*/;   /* Adresse IP automatique */
        sin.sin_family         = AF_INET;             /* Protocole familial (IP) */
        sin.sin_port           = htons(port);         /* Listage du port */
        sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));
     //on vient de lancer la socket

        /* Si la socket fonctionne */
        if(sock_err != SOCKET_ERROR)
        {
            /* D�marrage du listage (mode server) */
            sock_err = listen(sock, 5);
            printf("Listage du port %d...\n", htons(sin.sin_port));
            /* Si la socket fonctionne */

        }

          else
            return -2;
    }
    else
        return -1;

}
serveur::ecoute(){
    if(sock_err != SOCKET_ERROR)
    {

        /* Attente pendant laquelle le client se connecte */
        printf("Patientez pendant que le client se connecte sur le port %d...\n", htons(sin.sin_port));

        csock = accept(sock, (SOCKADDR*)&csin, &recsize);
        printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));

     }
    else
        return -3;
}

serveur::recevoir(){

    if(recv(csock, buffer2, 32, 0) != SOCKET_ERROR)
                   printf("Recu : %s\n", buffer2);
    else
        printf("\n rien.......\n ");
}

serveur::envoyer(char buffer[]){

strcpy(buffer1, buffer);

        sock_err = send(csock, buffer1, 32, 0);

        if(sock_err != SOCKET_ERROR)
            printf("Chaine envoyée : %s\n", buffer1);
        else
            printf("Erreur de transmission\n");
}


serveur::~serveur()
{
    /* Il ne faut pas oublier de fermer la connexion (ferm�e dans les deux sens) */
    shutdown(csock, 2);
    /* Fermeture de la socket */
    printf("Fermeture de la socket...\n");
    closesocket(sock);
    printf("Fermeture du serveur terminee\n");

#if defined (WIN32)
    WSACleanup();
#endif
}


