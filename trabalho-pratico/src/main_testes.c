#include "testes.h"

int main(int argc, char **argv){

    if (argc < 4){
        fprintf(stderr, "Missing arguments\n");
        return 1;
    }
    
    //Início do programa de testes
    testes(argv[1], argv[2], argv[3]);

    return 0;

}