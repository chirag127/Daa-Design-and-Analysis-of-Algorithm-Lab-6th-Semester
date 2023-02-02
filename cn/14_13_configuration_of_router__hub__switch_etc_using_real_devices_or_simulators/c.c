write the c code for practical for my daa assignement 

13. Configuration of router, hub, switch etc. (using real devices or simulators)
 Here is a basic C code for configuring a router, hub, or switch:

```
#include <stdio.h>
#include <string.h>

int main() {
  char device[10];
  printf("Enter the device type (router, hub, switch): ");
  scanf("%s", device);

  if (strcmp(device, "router") == 0) {
    printf("Configuring router...\n");
    // code to configure router
  } else if (strcmp(device, "hub") == 0) {
    printf("Configuring hub...\n");
    // code to configure hub
  } else if (strcmp(device, "switch") == 0) {
    printf("Configuring switch...\n");
    // code to configure switch
  } else {
    printf("Invalid device type\n");
  }

  return 0;
}
```
