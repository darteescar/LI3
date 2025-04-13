#include "Iteratividade/iteratividade.h"

int main(int argc, char **argv){
    //Inicialização do Gestor
    Gestor* gestor = init_GP();

    //início do programa iterativo
    iterativo(gestor);

    //FREE
    free_GP (gestor);

    return 0;
}