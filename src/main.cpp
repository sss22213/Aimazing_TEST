#include <iostream>
#include "sniffing.hpp"

int main(int argc, char **argv)
{
    /* Check number of parameters */
    if(argc < 2) {
        printf("Parameter too few\n");
        return -1;
    }

    sniffing new_sniffing(argv[1]);

    new_sniffing.get_tcp_package();

    return 0;
}
