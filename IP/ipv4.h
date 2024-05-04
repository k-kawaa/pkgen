#ifndef ipv4_h
#define ipv4_h

#include <stdint.h>

typedef struct{
    uint8_t version;
    uint8_t ihl;
    uint8_t tos;
    uint16_t total_length;
    uint16_t idf;
    uint8_t flags;
    uint16_t fo;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
}ipv4_hdr;


uint8_t *GenIPv4Header(ipv4_hdr *hdr);

#endif