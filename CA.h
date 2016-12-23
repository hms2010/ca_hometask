#ifndef CA_HOMETASK_CA_H
#define CA_HOMETASK_CA_H

#define CERT_LIFETIME 365*24*60*60
#include <memory>
#include <chrono>

#include <botan/botan.h>
#include <botan/x509_ca.h>
#include <botan/x509cert.h>
#include <botan/certstor.h>

#include "CA_cert.h"

class CA_cert;


class CA{
private:
    Botan::Certificate_Store_In_Memory certs_store;
    Botan::AutoSeeded_RNG rng;
public:
    Botan::X509_CA ca;
    CA(void) = delete;
    CA(CA_cert& ca_cert);
    Botan::X509_Certificate create_cert(std::string request_file);


};


#endif //CA_HOMETASK_CA_H
