#include "CA_cert.h"

CA_cert::CA_cert(std::string cert_file, std::string private_key_file): cert(nullptr), private_key(nullptr){

    cert.reset(new Botan::X509_Certificate(cert_file));

    // нужно разделять модель и интерфейс
    std::string passphrase;
    std::cout  << "Please, enter passphrase to decrypt key:";
    std::cin >> passphrase;


    private_key.reset(dynamic_cast<Botan::RSA_PrivateKey*>(Botan::PKCS8::load_key(
            private_key_file, rng, passphrase)));
}