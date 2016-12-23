#include "CA.h"

CA::CA(CA_cert& ca_cert): ca(*ca_cert.cert, *ca_cert.private_key, "SHA-256", ca_cert.rng), certs_store("certs"){
    //nothing to do more
}

bool CA::is_req_valid(Botan::PKCS10_Request request){
    return true;
}

std::unique_ptr<Botan::X509_Certificate> CA::create_cert(std::string request_file){
    Botan::PKCS10_Request request(request_file);

    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end = start + std::chrono::duration<long>(CERT_LIFETIME);

    Botan::X509_Time start_time(start);
    Botan::X509_Time end_time(end);//need to be editted

    if (!is_req_valid(request)){
        return  nullptr;
    }
    std::unique_ptr<Botan::X509_Certificate>  new_cert(new Botan::X509_Certificate(ca.sign_request(request, rng, start_time, end_time)));


    std::string cert_file;
    std::cin >> cert_file;

    std::ofstream cert("certs/" + cert_file);
    cert << new_cert->PEM_encode();

    certs_store.add_certificate(*new_cert);

    return new_cert;
}