write the c code for practical for my daa assignement 

3. Write a code simulating ARP /RARP protocols.
 Here's a simple example of ARP protocol simulation in C:

```
#include <stdio.h>
#include <string.h>

struct ARP_entry {
    char IP_address[16];
    char MAC_address[18];
};

struct ARP_entry ARP_table[100];
int ARP_table_size = 0;

void ARP_request(char *destination_IP) {
    int i;
    for (i = 0; i < ARP_table_size; i++) {
        if (strcmp(destination_IP, ARP_table[i].IP_address) == 0) {
            printf("Found in ARP table: %s %s\n", ARP_table[i].IP_address, ARP_table[i].MAC_address);
            return;
        }
    }
    printf("Not found in ARP table, sending ARP request...\n");
    // send ARP request
}

void ARP_response(char *sender_IP, char *sender_MAC) {
    int i;
    for (i = 0; i < ARP_table_size; i++) {
        if (strcmp(sender_IP, ARP_table[i].IP_address) == 0) {
            printf("Updating ARP table: %s %s\n", sender_IP, sender_MAC);
            strcpy(ARP_table[i].MAC_address, sender_MAC);
            return;
        }
    }
    printf("Adding to ARP table: %s %s\n", sender_IP, sender_MAC);
    strcpy(ARP_table[ARP_table_size].IP_address, sender_IP);
    strcpy(ARP_table[ARP_table_size].MAC_address, sender_MAC);
    ARP_table_size++;
}

int main() {
    ARP_request("192.168.1.1");
    ARP_response("192.168.1.1", "AA:BB:CC:DD:EE:FF");
    ARP_request("192.168.1.1");
    return 0;
}
```

And here's an example of RARP protocol simulation in C:

```
#include <stdio.h>
#include <string.h>

struct RARP_entry {
    char MAC_address[18];
    char IP_address[16];
};

struct RARP_entry RARP_table[100];
int RARP_table_size = 0;

void RARP_request(char *destination_MAC) {
    int i;
    for (i = 0; i < RARP_table_size; i++) {
        if (strcmp(destination_MAC, RARP_table[i].MAC_address) == 0) {
            printf("Found in RARP table: %s %s\n", RARP_table[i].MAC_address, RARP_table[i].IP_address);
            return;
        }
    }
    printf("Not found in RARP table, sending RARP request...\n");
    // send RARP request
}

void RARP_response(char *sender_MAC, char *sender_IP) {
    int i;
    for (i = 0; i < RARP_table_size; i++) {
        if (strcmp(sender_MAC, RARP_table[i].MAC_address) == 0) {
            printf("Updating RARP table: %s %s\n", sender_MAC, sender_IP);
            strcpy(RARP_table[i].IP_address, sender_IP);
            return;
        }
    }
    printf("Adding to RARP table: %s %s\n", sender_MAC, sender_IP);
    strcpy(RARP_table[RARP_table_size].MAC_address, sender_MAC);
    strcpy(RARP_table[RARP_table_size].IP_address, sender_IP);
    RARP_table_size++;
}

int main() {
    RARP_request("AA:BB:CC:DD:EE:FF");
    RARP_response("AA:BB:CC:DD:EE:FF", "192.168.1.1");
    RARP_request("AA:BB:CC:DD:EE:FF");
    return 0;
}
```
