#include <stdlib.h>
#include <stdio.h>
#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#else
#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#endif

int main(int argc, char const* argv[]) {
#ifdef WIN32
    int ServerInWindows();
    ServerInWindows();
#else
    int ServerInUnix();
    ServerInUnix();

#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ServerInWindows(){
// Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Failed to initialize Winsock.\n");
        return 1;
    }

    // Create server socket similar to what was done in the client program
    SOCKET servSockD = socket(AF_INET, SOCK_STREAM, 0);

    // Check for socket creation failure
    if (servSockD == INVALID_SOCKET)
    {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    // String to store data to send to the client
    char serMsg[255] = "Message from the server to the client 'Hello Client' ";

    // Define server address
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to the specified IP and port
    if (bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        printf("Socket binding failed.\n");
        closesocket(servSockD);
        WSACleanup();
        return 1;
    }

    // Listen for connections
    if (listen(servSockD, 1) == SOCKET_ERROR)
    {
        printf("Socket listening failed.\n");
        closesocket(servSockD);
        WSACleanup();
        return 1;
    }

    // Integer to hold client socket
    SOCKET clientSocket = accept(servSockD, NULL, NULL);

    // Send messages to client socket
    send(clientSocket, serMsg, sizeof(serMsg), 0);

    // Cleanup
    closesocket(clientSocket);
    closesocket(servSockD);
    WSACleanup();

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ServerInUnix() {
    // create server socket similar to what was done in
    // client program
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);

    // string store data to send to client
    char serMsg[255] = "Message from the server to the "
                       "client \'Hello Client\' ";
    // define server address
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to the specified IP and port
    bind(servSockD, (struct sockaddr*)&servAddr,
         sizeof(servAddr));

    // listen for connections
    listen(servSockD, 1);

    // integer to hold client socket.
    int clientSocket = accept(servSockD, NULL, NULL);

    // send's messages to client socket
    send(clientSocket, serMsg, sizeof(serMsg), 0);
    return 0;
}

