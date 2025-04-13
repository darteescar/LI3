#define _POSIX_C_SOURCE 199309L
#define _GNU_SOURCE

#include "testes.h"

void testes (char* path_csv, char* path_querie, char* path_output){
    //INICIO DO PROGRAMA
    struct timespec start, end;
    double tempoTotal;
    clock_gettime(CLOCK_REALTIME, &start);

    //Inicialização do Gestor
    Gestor* gestor = init_GP();

    //PARSER CSVs
    parser_csv(path_csv, gestor);

    //CONCATENAÇÃO DOS CAMINHOS DOS FICHEIRO
    FILE* input_file = fopen(path_querie, "r");
    if(input_file == NULL){
        perror("Error opening inputs_exemplo_file");
        return;
    }

    //QUERIES E TEMPO DE EXECUÇÃO

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    struct timespec start1, end1;
    double tempo1, tempo2, tempo3, tempo4, tempo5, tempo6;

    //LEITURA DO FICHEIRO DE INPUT
    struct query{
        int cont;
        char* line;
    };

    struct query query1[500];
    struct query query2[500];
    struct query query3[500];
    struct query query4[500];
    struct query query5[500];
    struct query query6[500];

    int indice1=0, indice2=0, indice3=0, indice4=0, indice5=0, indice6=0;
    int cont=1;

    while((read= getline(&line, &len, input_file)) != -1){
        if(line[0]=='1'){
            query1[indice1].cont = cont;
            query1[indice1].line = malloc(200);
            strcpy(query1[indice1].line, line);
            indice1++;
        } else if(line[0]=='2'){
            query2[indice2].cont = cont;
            query2[indice2].line = malloc(200);
            strcpy(query2[indice2].line, line);
            indice2++;
        } else if(line[0]=='3'){
            query3[indice3].cont = cont;
            query3[indice3].line = malloc(200);
            strcpy(query3[indice3].line, line);
            indice3++;
        } else if(line[0]=='4'){
            query4[indice4].cont = cont;
            query4[indice4].line = malloc(200);
            strcpy(query4[indice4].line, line);
            indice4++;
        } else if(line[0]=='5'){
            query5[indice5].cont = cont;
            query5[indice5].line = malloc(200);
            strcpy(query5[indice5].line, line);
            indice5++;
        } else if(line[0]=='6'){
            query6[indice6].cont = cont;
            query6[indice6].line = malloc(200);
            strcpy(query6[indice6].line, line);
            indice6++;
        }
        cont++;
    }

    int est_2 = 0;
    int est_3 = 0;
    int est_4 = 0;
    int est_5 = 0;
    int est_6 = 0;

       //QUERY 1
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<indice1; i++){
        first_querie(gestor, query1[i].line, query1[i].cont);
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    tempo1 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;

       //QUERY 2
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<indice2; i++){
        inicializa_estruturas(gestor, 2, est_2);
        est_2 = 1;

        second_querie(query2[i].line, query2[i].cont, gestor);
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    tempo2 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;

   
       //QUERY 3
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<indice3; i++){
        inicializa_estruturas(gestor, 3, est_3);
        est_3 = 1;
        third_querie(query3[i].line, query3[i].cont, gestor);
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    tempo3 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;

   

       //QUERY 4
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<indice4; i++){
        inicializa_estruturas(gestor, 4, est_4);
        est_4 = 1;
        fourth_querie(query4[i].line, query4[i].cont, gestor);
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    tempo4 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;

       //QUERY 5
       //VARIAVEIS PARA A QUERY 5
    int **matriz = NULL;
    char **array = NULL;
    int tamanho_atual = 0;

    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<indice5; i++){
        inicializa_estruturas(gestor, 5, est_5);
            if(est_5 == 0){
                faz_matriz_array_aux(gestor, &matriz, &array, &tamanho_atual);
            }
            est_5 = 1;
        fifth_querie(query5[i].line, query5[i].cont, gestor, &matriz, &array, &tamanho_atual);
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    tempo5 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;

   
       //QUERY 6
    clock_gettime(CLOCK_REALTIME, &start1);
    for (int i=0; i<indice6; i++){
        if(est_6 == 0){
            est_6 = 1;
        }
        sixth_querie(query6[i].line, query6[i].cont, gestor);
    }
    clock_gettime(CLOCK_REALTIME, &end1);
    tempo6 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1e9;


       //IMPRIMIR TEMPO DE EXECUÇÃO
    printf("Q1 execution time: %.6f seconds\n", tempo1);
    printf("Q2 execution time: %.6f seconds\n", tempo2);
    printf("Q3 execution time: %.6f seconds\n", tempo3);
    printf("Q4 execution time: %.6f seconds\n", tempo4);
    printf("Q5 execution time: %.6f seconds\n", tempo5);
    printf("Q6 execution time: %.6f seconds\n", tempo6);
    printf("\n");
    printf("Queries total execution time: %.6f seconds\n", tempo1+tempo2+tempo3+tempo4+tempo5+tempo6);
    printf("\n");


       //LIBERTAR MEMÓRIA
    for(int i=0; i<indice1; i++){
        free(query1[i].line);
    }

    for(int i=0; i<indice2; i++){
        free(query2[i].line);
    }

    for(int i=0; i<indice3; i++){
        free(query3[i].line);
    }

    for(int i=0; i<indice4; i++){
        free(query4[i].line);
    }

    for(int i=0; i<indice5; i++){
        free(query5[i].line);
    }

    for(int i=0; i<indice6; i++){
        free(query6[i].line); 
    }

    //ANÁLISE DA DESCREPÂNCIA ENTRE OS OUTPUTS OBTIDOS E OS OUTPUTS ESPERADOS
    compare_outputs_teste(path_output, cont);
    
    //FECHAR OS FICHEIROS
    fclose(input_file);

    //FREE
    free(line);
    free_GP(gestor);
    free_matriz_array( matriz, array, tamanho_atual);

    //FIM DO PROGRAMA
    clock_gettime(CLOCK_REALTIME, &end);
    tempoTotal = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Program execution time: %.6f seconds\n", tempoTotal);
    printf("\n");

    //MEMÓRIA USADA
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
}