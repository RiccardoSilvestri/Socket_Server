#include <stdlib.h>
#include <stdio.h>

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#else
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#endif

#ifdef WIN32
int ServerInWindows();  // Dichiarazione della funzione per Windows
#else
int ServerInUnix();  // Dichiarazione della funzione per Unix
#endif

int main(int argc, char const* argv[]) {
#ifdef WIN32
    ServerInWindows();  // Chiamata alla funzione per Windows
#else
    ServerInUnix();  // Chiamata alla funzione per Unix
#endif

    return 0;
}

#ifdef WIN32
int ServerInWindows() {
    // Includi solo le dichiarazioni specifiche di Windows
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock.\n");
        return 1;
    }

    SOCKET servSockD = socket(AF_INET, SOCK_STREAM, 0);

    if (servSockD == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    char serMsg[255] = "Message from the server to the client 'Hello Client' ";

    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5555);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
        printf("Socket binding failed.\n");
        closesocket(servSockD);
        WSACleanup();
        return 1;
    }

    if (listen(servSockD, 1) == SOCKET_ERROR) {
        printf("Socket listening failed.\n");
        closesocket(servSockD);
        WSACleanup();
        return 1;
    }

    SOCKET clientSocket = accept(servSockD, NULL, NULL);

    send(clientSocket, serMsg, sizeof(serMsg), 0);

    closesocket(clientSocket);
    closesocket(servSockD);
    WSACleanup();

    return 0;
}
#endif

#ifdef __unix__
int ServerInUnix() {
    // Codice specifico di Unix...
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);

    char serMsg[255] = "Message from the server to the client 'Hello Client' ";

    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5555);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr));

    listen(servSockD, 1);

    int clientSocket = accept(servSockD, NULL, NULL);

    send(clientSocket, serMsg, sizeof(serMsg), 0);

    return 0;
}
#endif
