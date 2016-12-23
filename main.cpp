#define HELP "help"
#define NEW_CERTS "create_new_certs"
#define REVOKE_CERT "revoke_cert"
#define EXIT "exit"

void help(void);

#include <iostream>
#include <fstream>
#include <string>

#include <botan/botan.h>

#include "CA.h"


int main(){
    try{
        help();
        std::ifstream fCert("ca/cert.pem");
        std::ifstream fKey("ca/key.pem");
        fCert.close();
        fKey.close();

//        CA_cert ca_cert("ca/cert.pem", "ca/key.pem");
//        CA ca(ca_cert);

        std::string command;
        do{
            std::cout << std::endl
                      << "$ Enter command. If you need help, enter 'help'" << std::endl;
            std::cin >> command;

            if (command == HELP){
                help();
            }
            else if(command == NEW_CERTS){
                //automatic processing will be added
                std::cout << "$ Creating new certificates..."
                          << std::endl;
                std::string pkcs10_req;
//                ca.create_cert(pkcs10_req);
                std::cout << "$ Success. Certificates was created and added to a store"
                          << std::endl;
            }
            else if(command == REVOKE_CERT){
                //there is no processing function for it now
                std::cout << "$ Revoking the certificate..." << std::endl;
            }



        } while (command != EXIT);
        return 0;
    }
    catch(std::ios_base::failure& e){
        std::cerr << e.what() << '\n';
        return  1;
    }
    catch(...){
        std::cout << "$ Uknown error.\n$ Exit program" << std::endl;
        return  333;
    }


}

void help(void){
    std::cout << "Command list:" << std::endl;
    std::cout << " _____________________ __________________ ___________________________________________ " << std::endl;
    std::cout << "|--------name---------|------params------|-----------------description---------------|" << std::endl;
    std::cout << "|0. help              |no params         |prints commands info                       |" << std::endl;
    std::cout << "|1. create_new_certs  |no params         |creates new certificate from pkcs10 request|" << std::endl;
    std::cout << "|2. revoke_cert       |certificate reason|revokes certificate                        |" << std::endl;
    std::cout << "|3. exit              |no params         |exit the program                           |" << std::endl;
    std::cout << "|_____________________|__________________|___________________________________________|" << std::endl;

}