#include <stdint.h>
#include <stdlib.h>

#include "ipv4.h"


//no option!!
uint8_t *GenIPv4Header(ipv4_hdr *hdr){
    uint8_t *ptr;
    ptr = malloc(IP_HDR_WITH_NO_OPTION);
    if (ptr == NULL){
        printf("[Memory]can't allocate memory");
        return NULL;
    }
    ptr[0] = (hdr->version & 0xFF) << 0 | hdr->ihl << 5;
    ptr[1] = (hdr->ihl & 0xFF) << 0;
}