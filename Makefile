CXX = g++
CXXFLAGS = -std=c++11 -I/usr/local/include/botan-1.11/
LDFLAGS = -lbotan-1.11 -L/usr/local/lib/botan-1.11/

all: main.o CA.o CA_cert.o
	g++ -o awful_ca $^  $(LDFLAGS)


