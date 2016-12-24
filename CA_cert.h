#ifndef CA_HOMETASK_CA_CERT_H
#define CA_HOMETASK_CA_CERT_H

#include <iostream>
#include <fstream>
#include <memory>

#include <botan/botan.h>
#include <botan/x509_ca.h>
#include <botan/pkcs8.h>
#include <botan/rsa.h>

#include "CA.h"


class CA_cert{
private:
    Botan::AutoSeeded_RNG rng; // вряд ли здесь нужен rng
    std::unique_ptr<Botan::X509_Certificate> cert;
    std::unique_ptr<Botan::RSA_PrivateKey> private_key;
    size_t RSA_KEY_SIZE = 1024; // нас сломают
public:
    friend  class CA;
    CA_cert(std::string cert_file, std::string private_key_file);
};


#endif //CA_HOMETASK_CA_CERT_H
