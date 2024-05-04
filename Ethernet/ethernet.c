#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ethernet.h"
#include "../Quokka/memory.h"

//VLANなし
uint8_t *GenEtherHdr(ether_hdr *hdr) {
    uint8_t *ptr;
    ptr = malloc(ETHER_HDR_LEN_WITH_NOVLAN);

    if(ptr == NULL){
        printf("[Memory]can't allocate memory");
    }

    int a;
    for(a=0;a<6;++a){
        ptr[a] = hdr->dst[a];
    }
    for(a=0;a<6;++a){
        ptr[a+6] = hdr->src[a];
    }
    ptr[12] = (uint8_t)((hdr->type >> 8) & 0xFF);
    ptr[13] = (uint8_t)(hdr->type & 0xFF);
    return ptr;
}

uint8_t *GenEtherHdrWithVLAN(ether_hdr_v *hdr){
    uint8_t *ptr;
    uint16_t tci = 0;
    ptr = malloc(ETHER_HDR_LEN_WITH_VLAN);

    if(ptr == NULL){
        printf("[Memory]can't allocate memory");
        return NULL;
    }

    int a;
    for(a=0;a<6;++a){
        ptr[a] = hdr->dst[a];
    }
    for(a=0;a<6;++a){
        ptr[a+6] = hdr->src[a];
    }
    tci = ((hdr->pcp & 0x07) << 13 )| ((hdr->dei & 0x01) << 12) | ((hdr->vid & 0xFFF));
    ptr[12] = (uint8_t)((TPID >> 8) & 0xFF);
    ptr[13] = (uint8_t)((TPID & 0xFF));
    ptr[14] = (uint8_t)((tci >> 8) & 0xFF);
    ptr[15] = (uint8_t)(tci & 0xFF);
    ptr[16] = (uint8_t)((hdr->type >> 8) & 0xFF);
    ptr[17] = (uint8_t)(hdr->type & 0xFF);
    return ptr;
}