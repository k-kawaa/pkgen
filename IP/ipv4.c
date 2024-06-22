#include <stdint.h>
#include <stdlib.h>

#include "ipv4.h"

/*

    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |Version|  IHL  |Type of Service|          Total Length         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |         Identification        |Flags|      Fragment Offset    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Time to Live |    Protocol   |         Header Checksum       |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                       Source Address                          |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Destination Address                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Options                    |    Padding    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

1 octet is 8 bit!
*/

//no option!!
uint8_t *GenIPv4Header(ipv4_hdr *hdr){
    uint8_t *ptr;
    ptr = malloc(IP_HDR_WITH_NO_OPTION);
    if (ptr == NULL){
        printf("[Memory]can't allocate memory");
        return NULL;
    }
    ptr[0] = (hdr->version & 0xFF) << 0 | hdr->ihl << 5;
    ptr[1] = hdr->tos;
    ptr[2] = hdr->total_length >> 8;
    ptr[3] = hdr->total_length & 0x00F;
    ptr[4] = hdr->idf >> 8;
    ptr[5] = hdr->idf & 0x0F;
    ptr[6] = hdr->flags & 0x07 | hdr->fo >> 5;
    ptr[7] = hdr->flags & 0xFF;
    ptr[8] = hdr->ttl;
    ptr[9] = hdr->protocol;
    ptr[10] = 0;
    ptr[11] = 0;
    ptr[12] = (hdr->src >> 24) & 0xFF;
    ptr[13] = (hdr->src >> 16) & 0xFF;
    ptr[14] = (hdr->src >> 8)  & 0xFF;
    ptr[15] = hdr->src & 0xFF;
    ptr[16] = (hdr->dst >> 24) & 0xFF;
    ptr[17] = (hdr->dst >> 16) & 0xFF;
    ptr[18] = (hdr->dst >> 8)  & 0xFF;
    ptr[19] = hdr->dst & 0xFF;

}