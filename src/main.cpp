#include <iostream>
#include <cstdio>
#include <tins/tins.h>
#include <vector>
#include <stdint.h>

using namespace Tins;
using namespace std;

FILE *fp;

bool callback(const PDU &pdu) 
{
    /* Find tcp layer */
    const TCP &tcp = pdu.rfind_pdu<TCP>(); 
    /* Find protocol data unit */
    const RawPDU& raw = tcp.rfind_pdu<RawPDU>();
    /* Find payload */
    const RawPDU::payload_type& payload = raw.payload();
    /* Print payload */
    for(long unsigned int idx = 0; idx < payload.size(); idx++) {
        fprintf(fp, "%c", (uint8_t)payload[idx]);
        fflush(fp);
    }
    return true;
}

int main(int argc, char **argv) 
{
    /* Check number of parameters */
    if(argc < 3) {
        fprintf(stderr, "Parameter too few\n");
        return -1;
    }

    /* Create log file*/
    fp = NULL;
    fp = fopen(argv[2], "w+");
    if (fp == NULL) {
        perror("Open file fail\n");
        return -1;
    }
    
    Sniffer(argv[1]).sniff_loop(callback);

    fclose(fp);

    return 0;
}