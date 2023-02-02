write the c code for practical for my daa assignement 

17.Socket programming using UDP and TCP (e.g., simple DNS, data & time client/server, echo client/server, iterative & concurrent servers)
 Here's a simple example for a UDP echo server in C:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddrlen;
    char buf[BUFSIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9876);

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        cliaddrlen = sizeof(cliaddr);
        if (recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &cliaddr, &cliaddrlen) < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        if (sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &cliaddr, cliaddrlen) < 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
```
