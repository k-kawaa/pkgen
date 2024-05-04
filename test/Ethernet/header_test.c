#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <netdb.h>

#include "header_test.h"
#include "../../Ethernet/ethernet.h"

//srcとdstが同じインチキヘッダーダンププログラム
void Header_Dump(){
    uint8_t *buff;
    uint16_t type = ETHER_TYPE_IPV4;
    ether_hdr hdr;
    struct ifreq s;

    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    memset(&hdr,0,sizeof(hdr));
    strcpy(s.ifr_name, "eth0");
    if (0 == ioctl(fd, SIOCGIFHWADDR, &s)) {
        int i;
        for (i = 0; i < 6; ++i){
            memcpy(&(hdr.dst[i]),&(s.ifr_addr.sa_data[i]),1);
        }
        for (i = 0; i < 6; ++i){
            memcpy(&(hdr.src[i]),&(s.ifr_addr.sa_data[i]),1);
        }

        memcpy(&(hdr.type),&type,2);
    }
    buff = GenEtherHdr(&hdr);
    int a;
    for(a=0;a<14;a++){
        printf(" %02x", buff[a]);
    }

}

//vlan test
void Header_Dump_V(){
    uint8_t *buff;
    uint16_t type = ETHER_TYPE_IPV4;
    uint8_t pcp = 0;
    uint8_t dei = 1;
    uint16_t vid = 2000;
    ether_hdr_v hdr;
    struct ifreq s;

    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    memset(&hdr,0,sizeof(hdr));
    strcpy(s.ifr_name, "eth0");
    if (0 == ioctl(fd, SIOCGIFHWADDR, &s)) {
        int i;
        for (i = 0; i < 6; ++i){
            memcpy(&(hdr.dst[i]),&(s.ifr_addr.sa_data[i]),1);
        }
        for (i = 0; i < 6; ++i){
            memcpy(&(hdr.src[i]),&(s.ifr_addr.sa_data[i]),1);
        }

        memcpy(&(hdr.type),&type,2);
        memcpy(&(hdr.pcp),&pcp,1);
        memcpy(&(hdr.dei),&dei,1);
        memcpy(&(hdr.vid),&vid,2);
    }
    buff = GenEtherHdrWithVLAN(&hdr);
    int a;
    for(a=0;a<18;a++){
        printf(" %02x", buff[a]);
    }
    printf("\n");

}