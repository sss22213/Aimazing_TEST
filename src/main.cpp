#include <iostream>
#include <tins/tins.h>
#include <vector>
#include <stdint.h>

using namespace Tins;
using namespace std;

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
        cout << (uint8_t)payload[idx];
    }
    cout << endl;
    return true;
}

int main(int argc, char **argv) 
{
    Sniffer(argv[1]).sniff_loop(callback);
    return 0;
}