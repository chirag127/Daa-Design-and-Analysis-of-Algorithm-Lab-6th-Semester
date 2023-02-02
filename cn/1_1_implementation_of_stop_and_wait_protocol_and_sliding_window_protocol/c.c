write the c code for practical for my daa assignement 

1. Implementation of Stop and Wait Protocol and Sliding Window Protocol.
 Here's a sample implementation of Stop and Wait Protocol in C:

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
#define BUFSIZE 30
 
void error_handling(char *message);
 
int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUFSIZE];
    int str_len;
 
    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
 
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");
 
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");
 
    while (1)
    {
        fputs("Input message(Q to quit): ", stdout);
        fgets(message, BUFSIZE, stdin);
 
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;
 
        write(sock, message, strlen(message));
        str_len = read(sock, message, BUFSIZE - 1);
        message[str_len] = 0;
        printf("Message from server: %s", message);
    }
 
    close(sock);
    return 0;
}
 
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
```

And here's a sample implementation of Sliding Window Protocol in C:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
#define BUFSIZE 30
 
void error_handling(char *message);
 
int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
 
    char message[BUFSIZE];
 
    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
 
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");
 
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
 
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");
 
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");
 
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept() error");
 
    while (1)
    {
        int str_len = read(clnt_sock, message, BUFSIZE - 1);
        if (str_len == 0)
            break;
 
        message[str_len] = 0;
        printf("Received message: %s", message);
        write(clnt_sock, message, str_len);
    }
 
    close(clnt_sock);
    close(serv_sock);
    return 0;
}
 
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
```
