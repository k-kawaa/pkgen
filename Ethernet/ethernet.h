#ifndef ETHERNET_H
#define ETHERNET_H

#include <stdint.h>

//便利な定義
#define ETHER_TYPE_IPV4         0x0800
#define ETHER_TYPE_IPV6         0x86dd
#define ETHER_TYPE_ARP          0x0806

#define TPID                    0x8100

#define MAC_LEN 6

#define ETHER_HDR_LEN_WITH_NOVLAN 14
#define ETHER_HDR_LEN_WITH_VLAN 18

typedef struct{
    uint8_t dst[MAC_LEN];
    uint8_t src[MAC_LEN];
    uint16_t type;
}ether_hdr;

typedef struct{
    uint8_t dst[MAC_LEN];
    uint8_t src[MAC_LEN];
    uint8_t pcp;            //フレーム優先度（3bit）
    uint8_t dei;            //輻輳時設定 0/1（1bit）
    uint16_t vid;            //VLAN ID（12bit）
    uint16_t type;
}ether_hdr_v;

uint8_t *GenEtherHdr(ether_hdr *hdr);
uint8_t *GenEtherHdrWithVLAN(ether_hdr_v *hdr);

#endif