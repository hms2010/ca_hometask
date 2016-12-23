#include <iostream>

#include <botan/botan.h>

#include "CA.h"


int main(){
    CA_cert ca_cert("ca/cert.pem", "ca/key.pem");
    CA ca(ca_cert);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}