write the c code for practical for my daa assignement 

6. Write a program to implement RPC (Remote Procedure Call)

```
#include <stdio.h>
#include <rpc/rpc.h>

int main(int argc, char *argv[]) {
  CLIENT *cl;
  char *server;
  char *result;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s hostname\n", argv[0]);
    exit(1);
  }

  server = argv[1];
  cl = clnt_create(server, PROGRAM, VERSION, "tcp");
  if (cl == NULL) {
    clnt_pcreateerror(server);
    exit(1);
  }

  result = remote_procedure_call(cl, ...);
  if (result == NULL) {
    clnt_perror(cl, server);
    exit(1);
  }

  printf("Result: %s\n", result);
  clnt_destroy(cl);
  return 0;
}
```
