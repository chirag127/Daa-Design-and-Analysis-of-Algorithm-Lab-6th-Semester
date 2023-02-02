write the c code for practical for my daa assignement 

11. Perform a case study about the different routing algorithms to select the network path with its optimum and economical during data transfer. i. Link State routing ii. Flooding iii. Distance vector
 Here is a sample C code for a case study of the three routing algorithms:

```
#include <stdio.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 500

// Structure to store network information
struct Network {
  int nodes;
  int links;
  int cost[MAX_NODES][MAX_NODES];
};

// Link State Routing Algorithm
void linkStateRouting(struct Network network) {
  // Code for Link State Routing Algorithm
}

// Flooding Routing Algorithm
void floodingRouting(struct Network network) {
  // Code for Flooding Routing Algorithm
}

// Distance Vector Routing Algorithm
void distanceVectorRouting(struct Network network) {
  // Code for Distance Vector Routing Algorithm
}

int main() {
  struct Network network;

  // Initialize network information
  memset(network.cost, 0, sizeof(network.cost));
  network.nodes = MAX_NODES;
  network.links = MAX_LINKS;

  // Call Link State Routing Algorithm
  linkStateRouting(network);

  // Call Flooding Routing Algorithm
  floodingRouting(network);

  // Call Distance Vector Routing Algorithm
  distanceVectorRouting(network);

  return 0;
}
```
