# ca_hometask

## Requirements
1. Botan-1.11 - https://botan.randombit.net/manual/building.html
2. g++ and make

## To install
1. $git clone https://github.com/hms2010/ca_hometask.git
2. Change path to Botan library in Makefile
3. $make

## To use
1. $./create_path.sh
2. Move CA RSA private key ("key.pem") and CA certificate to path/ca_hometask/ca directory.

 You can generate it by yourself
 
 Example:
 $openssl genrsa -'enc_algo' -passout 'your_pass' -out key.pem 1024
 
2. Create dir your_path/ca_hometask/certs

