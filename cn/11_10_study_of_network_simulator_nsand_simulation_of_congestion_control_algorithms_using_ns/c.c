write the c code for practical for my daa assignement 

10. Study of Network simulator (NS).and Simulation of Congestion Control Algorithms using NS
 Here's a sample code in C for simulating congestion control algorithms using NS-2:
```
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include "ns2.h"

#define MAX_PACKET_SIZE 1500
#define MAX_QUEUE_SIZE 100
#define MAX_SIMULATION_TIME 10000

struct packet {
  int size;
  int arrival_time;
};

int main() {
  std::queue<packet> q;
  std::vector<double> delay;
  int current_time = 0;
  int packet_loss = 0;
  int total_packets = 0;

  while (current_time < MAX_SIMULATION_TIME) {
    if (q.size() < MAX_QUEUE_SIZE) {
      packet p;
      p.size = rand() % MAX_PACKET_SIZE + 1;
      p.arrival_time = current_time;
      q.push(p);
      total_packets++;
    } else {
      packet_loss++;
    }

    if (q.size() > 0) {
      packet p = q.front();
      q.pop();
      delay.push_back(current_time - p.arrival_time);
    }

    current_time++;
  }

  double avg_delay = 0;
  for (int i = 0; i < delay.size(); i++) {
    avg_delay += delay[i];
  }
  avg_delay /= delay.size();

  printf("Average delay: %f\n", avg_delay);
  printf("Packet loss rate: %f\n", (double) packet_loss / total_packets);

  return 0;
}
```
