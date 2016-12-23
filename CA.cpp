#include "CA.h"

CA::CA(CA_cert& ca_cert): ca(*ca_cert.cert, *ca_cert.private_key, "SHA-256", ca_cert.rng){
    //nothing to do more
}

Botan::X509_Certificate CA::create_cert(std::string request_file){

    Botan::X509_Certificate new_cert = ca.sign_request();
    return new_cert;
}