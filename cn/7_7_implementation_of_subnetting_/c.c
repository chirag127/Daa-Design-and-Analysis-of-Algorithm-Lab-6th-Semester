write the c code for practical for my daa assignement 

7. Implementation of Subnetting .
 
```
#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, n, m, p, q, r, s, t, u, v, w, x, y, z;
    unsigned int ip, subnet_mask, network_address, host_min, host_max, broadcast_address;
    printf("Enter IP address in decimal notation: ");
    scanf("%u", &ip);
    printf("Enter subnet mask in decimal notation: ");
    scanf("%u", &subnet_mask);
    n = ip & subnet_mask;
    network_address = n;
    m = pow(2, 32 - __builtin_popcount(subnet_mask));
    host_min = network_address + 1;
    host_max = network_address + m - 2;
    broadcast_address = network_address + m - 1;
    printf("\nNetwork address is: %u", network_address);
    printf("\nBroadcast address is: %u", broadcast_address);
    printf("\nHost range is: %u - %u", host_min, host_max);
    return 0;
}
```
