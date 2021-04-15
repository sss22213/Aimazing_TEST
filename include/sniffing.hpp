#ifndef __SNIFFING_HPP__
#define __SNIFFING_HPP__

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <net/if.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h> /* the L2 protocols */
#include <sys/ioctl.h>
#include <net/if.h>

using namespace std;

/* Network sniffing over socker */
class sniffing
{
    private:
        uint8_t *buffer;

    public:
        /* Initialize and open socket */
        sniffing(char*);
        
        /* Close socket */
        ~sniffing(void);

        /* Get tcp package*/
        void get_tcp_package();
};

#endif