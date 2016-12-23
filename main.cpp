#define HELP "help"
#define NEW_CERT "create_new_cert"
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

        CA_cert ca_cert("ca/cert.pem", "ca/key.pem");
        CA ca(ca_cert);

        std::string command;
        do{
            std::cout << "##- Enter command. If you need help, enter 'help'" << std::endl;
            std::cin >> command;

            if (command == HELP){
                help();
            }
            else if(command == NEW_CERT){
                //automatic processing will be added
                std::string pkcs10_req;
                ca.create_cert(pkcs10_req);
            }
            else if(command == REVOKE_CERT){
                //there is no processing function for it now
            }



        } while (command != EXIT);
        return 0;
    }
    catch(std::ios_base::failure& e){
        std::cerr << e.what() << '\n';
        return  1;
    }
    catch(...){
        std::cout << "##- Uknown error. Exit program" << std::endl;
        return  333;
    }


}

void help(void){
    std::cout << "Command list:" << std::endl;
    std::cout << " _____________________ __________________ ___________________________________________ " << std::endl;
    std::cout << "|--------name---------|------params------|-----------------description---------------|" << std::endl;
    std::cout << "|0. help              |no params         |prints command info                        |" << std::endl;
    std::cout << "|1. create_new_cert   |pkcs10_request    |creates new certificate from pkcs10 request|" << std::endl;
    std::cout << "|2. revoke_cert       |certificate reason|revokes certificate                        |" << std::endl;
    std::cout << "|3. exit              |no params         |exit from program                          |" << std::endl;
    std::cout << "|_____________________|__________________|___________________________________________|" << std::endl;

}