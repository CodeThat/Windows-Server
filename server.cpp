#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

struct SOCKADDR_IN
{
    short sin_family;
    u_short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

int main()
{
    WSAData wsa;
    WORD Version = MAKEWORD(2, 1);

    WSAStartup(Version, &wsa);

    SOCKET Listen = socket(AF_INET,SOCK_STREAM,NULL);
    SOCKET Connect = socket(AF_INET,SOCK_STREAM,NULL);

    SOCKADDR_IN Server;

    Server.sin_addr.s_addr = inet_addr("127.0.0.1");
    Server.sin_family = AF_INET;
    Server.sin_port = htons(80);

    bind(Listen, (SOCKADDR*)&Server, sizeof(Server));

    listen(Listen, 1);

    int size = sizeof(Server);

    std::cout << "Listening for connection...";

    for(;;)
    {
        if(Connect = accept(Listen, (SOCKADDR*)&Server, &size))
            std::cout << "Connection found\n";
        break;
    }

    WSACleanup();
    std::cin.get();
    return 0;
}
