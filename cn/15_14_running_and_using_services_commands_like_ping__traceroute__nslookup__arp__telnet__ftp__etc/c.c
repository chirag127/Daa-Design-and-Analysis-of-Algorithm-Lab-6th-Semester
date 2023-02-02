write the c code for practical for my daa assignement 

14. Running and using services/commands like ping, traceroute, nslookup, arp, telnet, ftp, etc.
 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char command[100];

  if (argc != 2)
  {
    printf("Usage: %s <command>\n", argv[0]);
    return 1;
  }

  strcpy(command, argv[1]);

  if (system(command) == -1)
  {
    perror("system");
    return 1;
  }

  return 0;
}
```
This code takes a command as an argument and runs it using the system function. This code can be used to run various network commands like ping, traceroute, nslookup, arp, telnet, ftp, etc.
