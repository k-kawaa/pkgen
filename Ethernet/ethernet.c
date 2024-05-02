#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ethernet.h"
#include "../Quokka/memory.h"

uint8_t *GenEtherHdr(ether_hdr *hdr, int vlan) {
    uint8_t *ptr;
    if(vlan == 0){
        //ptr = malloc(ETHER_HDR_LEN_WITH_NOVLAN);
        ptr = malloc(14);
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
}