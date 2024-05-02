#ifndef ETHERNET_H
#define ETHERNET_H

#include <stdint.h>

//便利な定義
#define ETHER_TYPE_IPV4         0x0800
#define ETHER_TYPE_IPV6         0x86dd
#define ETHER_TYPE_ARP          0x0806

#define MAC_LEN 6

#define ETHER_HDR_LEN_WITH_NOVLAN 14
#define ETHER_HDR_LEN_WITH_VLAN 18

typedef struct{
    uint8_t dst[MAC_LEN];
    uint8_t src[MAC_LEN];
    uint16_t type;
}ether_hdr;

uint8_t *GenEtherHdr(ether_hdr *hdr);

#endif