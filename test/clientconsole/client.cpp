#include "client.h"

#if defined (WIN32)
      WSADATA WSAData;
      int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
  #else
      int erreur = 0;
  #endif

  SOCKET sock;
  SOCKADDR_IN sin;
  char buffer1[32] = "";
  char buffer2[32] = "";
  int sock_err;

client::client()
{

    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {

    }
}

client::connection(int port,char add[]){

    /* Création de la socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    /* Configuration de la connexion */
    sin.sin_addr.s_addr = inet_addr(add);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    /* Si l'on a réussi à se connecter */
    if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
    {
        printf("Connection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
    }
    /* sinon, on affiche "Impossible de se connecter" */
    else
    {
        printf("Impossible de se connecter\n");
    }


}

client::envoyer(char buffer[]){
    /////ajouter/////
   sock_err=send(sock, buffer, 32, 0);
     if(sock_err != SOCKET_ERROR)
            printf("Chaine envoyee : %s\n", buffer);
        else
            printf("Erreur de transmission\n");
}
client::recevoir(){

    /* Si l'on reçoit des informations : on les affiche à l'écran */
    if(recv(sock, buffer2, 32, 0) != SOCKET_ERROR)
        printf("Recu : %s\n", buffer2);

}

client::~client()
{
    /* On ferme la socket */
    closesocket(sock);

    #if defined (WIN32)
        WSACleanup();
    #endif
}

