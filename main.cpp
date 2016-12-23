#include <iostream>
#include <fstream>

#include <botan/botan.h>

#include "CA.h"


int main(){
    try{
        std::ifstream fCert("ca/cert.pem");
        std::ifstream fKey("ca/key.pem");
        fCert.close();
        fKey.close();

        CA_cert ca_cert("ca/cert.pem", "ca/key.pem");
        CA ca(ca_cert);
    }
    catch(std::ios_base::failure& e){
        std::cerr << e.what() << '\n';
        return  1;
    }

    return 0;
}