#ifndef CA_HOMETASK_CA_H
#define CA_HOMETASK_CA_H

#include <memory>

#include <botan/botan.h>
#include <botan/x509_ca.h>
#include <botan/x509cert.h>

#include "CA_cert.h"

class CA_cert;

class CA{
public:
    Botan::X509_CA ca;
    CA(void) = delete;
    CA(CA_cert& ca_cert);

};


#endif //CA_HOMETASK_CA_H
