#define HELP "help"
#define NEW_CERTS "create_new_certs"
#define REVOKE_CERT "revoke_cert"
#define EXIT "exit"

#include <iostream>

#include <fstream>
#include <string>
#include <botan/botan.h>

#include "CA.h"

void help(void);


int main(){
    try{
        help();
        // хардкод подходит для прототипа
        std::ifstream fCert("ca/cert.pem");
        std::ifstream fKey("ca/key.pem");
        fCert.close();
        fKey.close();

        CA_cert ca_cert("ca/cert.pem", "ca/key.pem");
        CA ca(ca_cert);

        std::string command;
        do{
            std::cout << std::endl
                      << "$ Enter command. If you need help, enter 'help\n>>>'" << std::endl;
            std::cin >> command;

            if (command == HELP){
                help();
            }
            else if(command == NEW_CERTS){
                //automatic processing will be added
                std::string pkcs10_req;
                std::cout << "$ Enter request name:"
                          << std::endl;
                std::cin >> pkcs10_req;
                pkcs10_req = "requests/" + pkcs10_req;
                std::cout << "$ Creating new certificates..."
                          << std::endl;
                if (ca.create_cert(pkcs10_req) == nullptr){
                    std::cout << "$ File can't be opened. Please, check if your input was correct"
                              << std::endl;
                }
                std::cout << "$ Success. Certificates was created and added to a store"
                          << std::endl;
                // как пользователь получает этот сертификат?
            }
            else if(command == REVOKE_CERT){
                //there is no processing function for it now
                std::cout << "$ Revoking the certificate..." << std::endl;
                std::cout << "$ Isn't available in this version" << std::endl;
            } else {
                std::cout << "$ Sorry, your command is incorrect" << std::endl;
                help();
            }



        } while (command != EXIT);
        return 0;
    }
    catch(std::ios_base::failure& e){ // const, почему не std::exception?
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...){
        std::cout << "$ Uknown error. Maybe CA key or CA cert doesn't exist\n$ Exit program" << std::endl;
        return 2;
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