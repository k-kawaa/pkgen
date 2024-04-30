#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ethernet.h"
#include "Quokka/memory.h";

#define MAC_LEN 6

#define ETHER_HDR_LEN_WITH_NOVLAN 14
#define ETHER_HDR_LEN_WITH_VLAN 18

typedef struct{
    uint8_t dst[MAC_LEN];
    uint8_t src[MAC_LEN];
    uint16_t type;
}ether_hdr;

// イーサネットヘッダを生成します(vlan = 0でvlanなし、それ以外はあり)
ether_hdr *GenEtherHdr(uint8_t *dst,uint8_t *src,uint16_t *type,int *vlan){
    char *ptr;
    if(*vlan == 0){
        ptr = SMalloc(ETHER_HDR_LEN_WITH_NOVLAN);
        if(ptr == NULL)return NULL;
        memcpy(ptr,dst,6);
        *ptr += 6;
        memcpy(ptr,dst,6);
        *ptr += 6;
        memcpy(ptr,type,2);
    }else{
        ptr = SMalloc(ETHER_HDR_LEN_WITH_VLAN);
        if(ptr == NULL)return NULL;
    }

}

