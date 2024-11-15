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
#include <unistd.h>
#endif

#ifdef WIN32
int ServerInWindows();
#elif defined(__unix__) || defined(__APPLE__)
int ServerInUnix();
#endif

int main(int argc, char const* argv[]) {
#ifdef WIN32
    ServerInWindows();
#elif defined(__unix__) || defined(__APPLE__)
    ServerInUnix();
#endif

    return 0;
}

#ifdef WIN32
int ServerInWindows() {
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

    printf("Server is waiting for a connection...\n");
    SOCKET clientSocket = accept(servSockD, NULL, NULL);

    if (clientSocket == INVALID_SOCKET) {
        printf("Failed to accept connection.\n");
        closesocket(servSockD);
        WSACleanup();
        return 1;
    }

    char buffer[255];
    char serMsg[255] = "Message from the server to the client 'Hello Client' ";

    while (1) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

        if (bytesReceived <= 0) {
            printf("Connection closed by client or error.\n");
            break;
        }

        buffer[bytesReceived] = '\0';
        printf("%s\n", buffer);

        send(clientSocket, serMsg, sizeof(serMsg), 0);
    }

    closesocket(clientSocket);
    closesocket(servSockD);
    WSACleanup();

    return 0;
}
#endif

#if defined(__unix__) || defined(__APPLE__)
int ServerInUnix() {
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);
    if (servSockD == -1) {
        perror("Socket creation failed");
        return 1;
    }

    char serMsg[255] = "Message from the server to the client 'Hello Client' ";

    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5555);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
        perror("Socket binding failed");
        close(servSockD);
        return 1;
    }

    if (listen(servSockD, 1) == -1) {
        perror("Socket listening failed");
        close(servSockD);
        return 1;
    }

    int clientSocket = accept(servSockD, NULL, NULL);
    if (clientSocket == -1) {
        perror("Socket accepting failed");
        close(servSockD);
        return 1;
    }

    send(clientSocket, serMsg, sizeof(serMsg), 0);

    close(clientSocket);
    close(servSockD);

    return 0;
}
#endif
