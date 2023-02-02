write the c code for practical for my daa assignement 

a. Echo client and echo server b. Chat c. File Transfer


a. Echo client and echo server:
```
// Echo server
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // bind the socket to a specific IP and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    char server_message[256] = "You have reached the server!";
    send(client_socket, server_message, sizeof(server_message), 0);

    char client_response[256];
    recv(client_socket, &client_response, sizeof(client_response), 0);
    printf("The client said: %s\n", client_response);

    close(server_socket);
    return 0;
}

// Echo client
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // connect to the server
    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(9002);
    client_address.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (struct sockaddr*) &client_address, sizeof(client_address));

    char client_message[256];
    fgets(client_message, sizeof(client_message), stdin);
    send(client_socket, client_message, sizeof(client_message), 0);

    char server_response[256];
    recv(client_socket, &server_response, sizeof(server_response), 0);
    printf("The server said: %s\n", server_response);

    close(client_socket);
    return 0;
}
```
b. Chat:
```
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9003);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    while (1) {
        char server_message[256];
        fgets(server_message, sizeof(server_message), stdin);
        send(client_socket, server_message, sizeof(server_message), 0);

        char client_response[256];
        recv(client_socket, &client_response, sizeof(client_response), 0);
        printf("Client: %s\n", client_response);
    }

    close(server_socket);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(9003);
    client_address.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (struct sockaddr*) &client_address, sizeof(client_address));

    while (1) {
        char client_message[256];
        fgets(client_message, sizeof(client_message), stdin);
        send(client_socket, client_message, sizeof(client_message), 0);

        char server_response[256];
        recv(client_socket, &server_response, sizeof(server_response), 0);
        printf("Server: %s\n", server_response);
    }

    close(client_socket);
    return 0;
}
```
c. File Transfer:
```
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9004);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    char file_name[256];
    recv(client_socket, file_name, sizeof(file_name), 0);

    FILE *fp;
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (1) {
        unsigned char buffer[256];
        int bytes_read = fread(buffer, 1, 256, fp);
        if (bytes_read == 0) break;

        send(client_socket, buffer, bytes_read, 0);
    }

    fclose(fp);
    close(server_socket);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(9004);
    client_address.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (struct sockaddr*) &client_address, sizeof(client_address));

    char file_name[256];
    printf("Enter the file name: ");
    scanf("%s", file_name);
    send(client_socket, file_name, sizeof(file_name), 0);

    FILE *fp;
    fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    while (1) {
        unsigned char buffer[256];
        int bytes_received = recv(client_socket, buffer, 256, 0);
        if (bytes_received == 0) break;

        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
    close(client_socket);
    return 0;
}
```
