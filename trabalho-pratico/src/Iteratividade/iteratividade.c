#include "Iteratividade/iteratividade.h"

//----------------------------------------------------------------------------------
//                         FUNÇÃO AUXILIAR PARA ITERATIVIDADE
//----------------------------------------------------------------------------------

int is_more_recent(char* data1, char* data2){
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    sscanf(data1, "%d/%d/%d", &ano1, &mes1, &dia1);
    sscanf(data2, "%d/%d/%d", &ano2, &mes2, &dia2);

    if (ano1<ano2){
        return 1;
    } else if (ano1==ano2){
        if (mes1<mes2){
            return 1;
        } else if (mes1==mes2){
            if (dia1<dia2){
                return 1;
            }
        }
    }

    return 0;
}

void iterativo(Gestor* gestor){
    //INICIO DO PROGRAMA ITERATIVO
    printf("\n");
    printf("Introduza o caminho dos ficheiros de dados: ");

    char* path = malloc(100);

    scanf("%s", path);
    printf("Dataset a carregar...\n");

    //INICIALIZAÇÃO DE VARIÁVEIS
    char* Q = malloc(100);

    //1
    char* id = malloc(100);
    
    //2
    int nA;
    char* aux1 = malloc(100);
    
    //3
    int min;
    int max;

    //4
    char* data1 = malloc(100);
    char* data2 = malloc(100);
    char* aux3 = malloc(100);

    //5
    char* username = malloc(100);
    int recomendacoes;

    //6
    char* userID = malloc(100);
    int year;
    char* aux2 = malloc(100);
    int nArtistas;

    //CSVs e ESTRUTURAS
    parser_csv(path, gestor);//CSVs
    preenche_GP_TOP(gestor);//Q2
    preenche_GP_ALL_TOP_10s(gestor);//Q4
    printf("Carregado com sucesso!\n");
    printf("\n");

    printf("////Digite -1 para terminar!\n");

    while (1){

    printf("Que query deseja executar? ");
    scanf("%s", Q);
    printf("\n");

    if (Q[0]=='1' && Q[1]=='\0'){//first_querie////////////////////////////////////
        printf("Introduza o id: ");
        scanf("%s", id);

        if(id[0]=='A' && search_GP_HT_A(gestor, id)==NULL){
            printf("\n");
            printf("Artista não encontrado!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        } else if (id[0]=='U' && search_GP_HT_U(gestor, id)==NULL){
            printf("\n");
            printf("Utilizador não encontrado!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        } else if (id[0]!='A' && id[0]!='U'){
            printf("\n");
            printf("ID inválido!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }
        printf(".\n");
        printf("..\n");
        printf("...\n");

        first_querie_iter(gestor, id);


    } else if (Q[0]=='2' && Q[1]=='\0'){//second_querie/////////////////////////////
        char* country = malloc(100);

        printf("Quantos artistas deseja ver? ");
        scanf("%d", &nA);

        if (nA==0){
            printf("\n");
            printf("------------------------------\n");
            printf("\n");
            continue;
        } else if (nA<0){
            printf("\n");
            printf("Número inválido!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }

        printf("\n");
        printf("////Se não quiser restringir a um determinado país, digite '0'!\n");
        printf("Introduza o país da pesquisa: ");
        scanf("%s", country);

        if (country[0]=='0' && country[1]=='\0'){
            free(country);
            country = NULL;
        }
        printf(".\n");
        printf("..\n");
        printf("...\n");

        second_querie_iter(country, nA, gestor);

        if (country!=NULL) {free(country);}


    } else if (Q[0]=='3' && Q[1]=='\0'){//third_querie/////////////////////////////////
        printf("Introduza o limite mínimo: ");
        scanf("%d", &min);

        if (min<0){
            printf("\n");
            printf("Idade inválida\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }

        printf("Introduza o limite máximo: ");
        scanf("%d", &max);

        if (max<min){
            printf("\n");
            printf("Idade inválida!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }
        printf(".\n");
        printf("..\n");
        printf("...\n");

        third_querie_iter(min, max, gestor);

    } else if (Q[0]=='4' && Q[1]=='\0'){//fourth_querie/////////////////////////////////

        printf("Considerar um intervalo específico de datas?(S/N) ");
        scanf("%s", aux3);

        if ((aux3[0] == 'S' || aux3[0] == 's') && aux3[1]=='\0'){
            printf("Introduza a data inicial: ");
            scanf("%s", data1);

            if (valida_data(data1) == 0){
                printf("\n");
                printf("Data inválida!\n");
                printf("Tente novamente!\n");
                printf("\n");
                continue;
            }

            printf("Introduza a data final: ");
            scanf("%s", data2);

            if (valida_data(data2) == 0){
                printf("\n");
                printf("Data inválida!\n");
                printf("Tente novamente!\n");
                printf("\n");
                continue;
            }

            if (is_more_recent(data1, data2)==0){
                printf("\n");
                printf("Data final mais recente que a data inicial!\n");
                printf("Tente novamente!\n");
                printf("\n");
                continue;
            }

        } else if ((aux3[0] == 'N' || aux3[0] == 'n') && aux3[1]=='\0'){
            sprintf(data1, "2018/06/01");
            sprintf(data2, "2024/08/31");
        } else {
            printf("\n");
            printf("Opção inválida!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }
        printf(".\n");
        printf("..\n");
        printf("...\n");

        fourth_querie_iter(data1, data2, gestor);

    } else if (Q[0]=='5' && Q[1]=='\0'){//fifth_querie//////////////////////////////////
        printf("Introduza o username: ");
        scanf("%s", username);

        if (username[0]!='U'){
            printf("\n");
            printf("Username inválido!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        } else if (search_GP_HT_U(gestor, username)==NULL){
            printf("\n");
            printf("Utilizador não encontrado!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }

        printf("Introduza o número de utilizadores a recomendar: ");
        scanf("%d", &recomendacoes);
        
        if (recomendacoes==0){
            printf("\n");
            printf("------------------------------------\n");
            printf("\n");
            continue;
        } else if (recomendacoes<0){
            printf("\n");
            printf("Número inválido!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }
        printf(".\n");
        printf("..\n");
        printf("...\n");

        int **matriz = NULL;
        char **array = NULL;
        int tamanho_atual = 0;
        faz_matriz_array_aux(gestor, &matriz, &array, &tamanho_atual);

        fifth_querie_iter(username, recomendacoes, gestor, &matriz, &array, &tamanho_atual);

        free_matriz_array( matriz, array, tamanho_atual);

    } else if (Q[0]=='6' && Q[1]=='\0'){//sixth_querie/////////////////////////////////
        char* line = malloc(100);

        printf("Introduza o userID: ");
        scanf("%s", userID);

        if (search_GP_HT_U(gestor, userID)==NULL){
            printf("\n");
            printf("Utilizador não encontrado!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }

        printf("Introduza o ano: ");
        scanf("%d", &year);

        if (year>2024 || year<0){
            printf("\n");
            printf("Ano inválido!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }

        printf("Deseja saber os N artistas mais ouvidos?(S/N) ");
        scanf("%s", aux2);
        if ((aux2[0] == 'S' || aux2[0] == 's') && aux2[1]=='\0'){
            printf("Introduza o número de artistas: ");
            scanf("%d", &nArtistas);

            if (nArtistas<0){
                printf("\n");
                printf("Número inválido!\n");
                printf("Tente novamente!\n");
                printf("\n");
                continue;
            }
            
        } else if ((aux2[0] == 'N' || aux2[0] == 'n') && aux2[1]=='\0'){
            nArtistas = 0;
        } else {
            printf("\n");
            printf("Opção inválida!\n");
            printf("Tente novamente!\n");
            printf("\n");
            continue;
        }

        if (nArtistas==0){
            sprintf(line, "6 %s %d", userID, year);
        } else {
            sprintf(line, "6 %s %d %d", userID, year, nArtistas);
        }
        printf(".\n");
        printf("..\n");
        printf("...\n");

        sixth_querie_iter(line, gestor);
        free(line);

    } else if (Q[0]=='-' && Q[1]=='1' && Q[2]=='\0'){
        printf("\n");
        break;

    } else {
        printf("Query inválida!\n");
        printf("Tente novamente!\n");
        printf("\n");
        continue;
    }
    printf("\n");
    }

    //FIM DO PROGRAMA ITERATIVO
    printf("...Programa encerrado\n");

    //FREE
    free(path);
    free(Q);
    free(id);
    free(data1);
    free(data2);
    free(username);
    free(userID);
    free(aux1);
    free(aux2);
    free(aux3);
    //FREE Q2
    free_GP_TOP(gestor);
    //FREE Q3
    free_GP_HT_GC(gestor);
    //FREE Q4
    free_GP_tabela_principal(gestor);
    free_GP_ALL_TOP_10s(gestor);
}

