#include "CA.h"

CA::CA(CA_cert& ca_cert): ca(*ca_cert.cert, *ca_cert.private_key, "SHA-256", ca_cert.rng), certs_store("certs"){
    //nothing to do more
}

Botan::X509_Certificate CA::create_cert(std::string request_file){
    Botan::PKCS10_Request request(request_file);

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    Botan::X509_Time start_time(now);
    Botan::X509_Time end_time(end);//need to be editted

    Botan::X509_Certificate new_cert = ca.sign_request(request, rng, start_time, end_time);


    std::string cert_file;
    std::cin >> cert_file;

    std::ofstream cert("certs/" + cert_file);
    cert << new_cert.PEM_encode();

    certs_store.add_certificate(new_cert);

    return new_cert;
}