write the c code for practical for my daa assignement 

15.Network packet analysis using tools like Wireshark, tcpdump, etc.
 Here's sample C code for analyzing network packets using tcpdump:

```
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  printf("Packet captured with length: %d\n", header->len);
}

int main(int argc, char *argv[]) {
  char *device, errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;

  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    return(2);
  }

  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
    return(2);
  }

  pcap_loop(handle, -1, packet_handler, NULL);

  pcap_close(handle);
  return(0);
}
```
