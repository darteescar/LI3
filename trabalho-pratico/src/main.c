#include "parser.h"
#include "general_manager.h"
#include "utilidades.h"
#include "Queries/querie_1.h"
#include "Queries/querie_2.h"
#include "Queries/querie_3.h"
#include "Queries/querie_4.h"
#include "Queries/querie_5.h"
#include "Queries/querie_6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char **argv) {

    if (argc < 3){
        fprintf(stderr, "Missing arguments\n");
        return 1;
    }

    //Inicialização do Gestor
    Gestor* gestor = init_GP();

    //CSVs
    parser_csv(argv[1], gestor);

    //QUERIES
    parser_queries(argv[2], gestor);
    
    //FREE
    free_GP (gestor);

    return 0;
}