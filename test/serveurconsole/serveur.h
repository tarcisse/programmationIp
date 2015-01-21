#if defined (WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#elif defined (linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif

#ifndef SERVEUR_H
#define SERVEUR_H
#include <stdio.h>
#define PORT 23
#include <string.h>

class serveur
{
#if defined (WIN32)
    WSADATA WSAData;
    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
    int erreur = 0;
#endif


public:

    serveur();
    ~serveur();
    connexion(int port, char ipadresse);
    ecoute();
    envoyer(char buffer[]);
    recevoir();

};

#endif // SERVEUR_H
