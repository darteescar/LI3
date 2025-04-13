#include "parser.h"

History* parser_line_H(char* line, char *platform){
    History* h = init_history();

    char *token;
    int field = 0;  // Contador para controlar qual campo estamos a preencher

    // Separar a linha em tokens usando strsep
    while ((token = strsep(&line, ";")) != NULL) {
        // Remover aspas que estão nas strings, caso existam
        if (token[0] == '\"' && token[strlen(token) - 1] == '\"') {
            token[strlen(token) - 1] = '\0';  // Remove a última aspa
            token++;  // Remove a primeira aspa
        }
        // Atribuir os tokens aos campos apropriados da struct history
        switch (field) {
            case 0:
                set_history_id(h, token);
                break;
            case 1:
                set_user_id_history(h, token);
                break;
            case 2:
                set_music_id_history(h, token);
                break;
            case 3:
                char* data = strsep(&token, " ");
                char* hora = token;
                if (data == "timestamp" || token == NULL) {break;} // lazy fix
                set_hora_history(h, hora);
                set_data_history(h ,data);
                break;
            case 4:
                set_duration_history(h, token);
                break;
            case 5:
                strcpy(platform, token);
                break;
            default:
                break;
        }
        field++;
    }
    return h;
}

Album* parse_line_Al(char *line, int *flag) {
    Album *a = init_album();

    char *token;
    int field = 0;  // Contador para controlar qual campo estamos a preencher

    // Separar a linha em tokens usando strsep
    while ((token = strsep(&line, ";")) != NULL) {
        // Remover aspas que estão nas strings, caso existam
        if (token[0] == '\"' && token[strlen(token) - 1] == '\"') {
            token[strlen(token) - 1] = '\0';  // Remove a última aspa
            token++;  // Remove a primeira aspa
        }
        
        // Atribuir os tokens aos campos apropriados da struct album
        switch (field) {
            case 0:
                set_album_id(a, token);
                break;
            case 1:
                set_album_title(a, token);
                break;
            case 2:
            if (valida_listas(token) == 0) {
                    *flag = 1;
                }
                // Remover os parêntesis retos
                if (token[0] == '[' && token[strlen(token) - 1] == ']') {
                    token[strlen(token) - 1] = '\0';  // Remove o último ']'
                    token++;  // Remove o primeiro '['
                }
                // Verificar se a lista está vazia
                if (strlen(token) == 0) {
                    set_album_artists_id(a, NULL);
                    set_album_n_artists(a, 0);
                } else {
                    // Processar a lista de constituintes entre aspas simples e separados por vírgulas
                    char *token2;
                    int n_artists = 0;
                    char **artists_id = malloc(sizeof(char*));  // Inicializa o array

                    while ((token2 = strsep(&token, ",")) != NULL) {
                        // Remover espaços em branco e aspas simples
                        while (*token2 == ' ' || *token2 == '\'') token2++;  // Avança o ponteiro para ignorar espaços e aspas simples

                        // Remover a aspa simples no final, se presente
                        if (token2[strlen(token2) - 1] == '\'') {
                            token2[strlen(token2) - 1] = '\0';  // Remove a última aspa simples
                        }

                        artists_id = realloc(artists_id, (n_artists + 1) * sizeof(char*));
                        artists_id[n_artists] = strdup(token2);  // Aloca memória para cada ID e copia
                        n_artists++;
                    }
                    set_album_n_artists(a, n_artists);
                    set_album_artists_id(a, artists_id);                
                }
                break;
            case 3:
                int year = atoi(token);
                set_album_year(a, year);
                break;
            case 4:
                // Remover os parêntesis retos
                if (token[0] == '[' && token[strlen(token) - 1] == ']') {
                    token[strlen(token) - 1] = '\0';  // Remove o último ']'
                    token++;  // Remove o primeiro '['
                }

                // Verificar se a lista está vazia
                if (strlen(token) == 0) {
                    set_album_producers(a, NULL);
                    set_album_n_producers(a, 0);
                } else {
                    // Processar a lista de constituintes entre aspas simples e separados por vírgulas
                    char *token2;
                    int n_producers = 0;
                    char **producers = malloc(sizeof(char*));  // Inicializa o array

                    while ((token2 = strsep(&token, ",")) != NULL) {
                        // Remover espaços em branco e aspas simples
                        while (*token2 == ' ' || *token2 == '\'') token2++;  // Avança o ponteiro para ignorar espaços e aspas simples

                        // Remover a aspa simples no final, se presente
                        if (token2[strlen(token2) - 1] == '\'') {
                            token2[strlen(token2) - 1] = '\0';  // Remove a última aspa simples
                        }

                        producers = realloc(producers, (n_producers + 1) * sizeof(char*));
                        producers[n_producers] = strdup(token2);  // Aloca memória para cada ID e copia
                        n_producers++;
                    }
                    set_album_producers(a, producers);
                    set_album_n_producers(a, n_producers);
                }
                break;
            default:
                break;
        }
        field++;
    }
    return a;
}

User* parse_line_U(char *line) {
    User *u = init_user();

    char *token;
    int field = 0;  // Contador para controlar qual campo estamos a preencher

    // Separar a linha em tokens usando strsep
    while ((token = strsep(&line, ";")) != NULL) {
        // Remover aspas que estão nas strings, caso existam
        if (token[0] == '\"' && token[strlen(token) - 1] == '\"') {
            token[strlen(token) - 1] = '\0';  // Remove a última aspa
            token++;  // Remove a primeira aspa
        }
        // Atribuir os tokens aos campos apropriados da struct user
        switch (field) {
            case 0:
                set_username(u, token);  
                break;
            case 1:
                set_email(u, token);
                break;
            case 2:
                set_first_name(u, token);  
                break;
            case 3:
                set_last_name(u, token); 
                break;
            case 4:
                set_birth_date(u, token);
                break;
            case 5:
                set_country(u, token); 
                break;
            case 6:
                set_subscription_type(u, token);
                
                break;
            case 7:
                
                // Remover os parêntesis retos
                if (token[0] == '[' && token[strlen(token) - 1] == ']') {
                    token[strlen(token) - 1] = '\0';  // Remove o último ']'
                    token++;  // Remove o primeiro '['
                }

                // Processar a lista de liked musics entre aspas simples e separados por vírgulas
                char *token2;
                int n_liked_musics = 0;
                char **liked_musics_id = malloc(sizeof(char*));  // Inicializa o array

                while ((token2 = strsep(&token, ",")) != NULL) {
                    // Remover espaços em branco e aspas simples
                    while (*token2 == ' ' || *token2 == '\'') token2++;  // Avança o ponteiro para ignorar espaços e aspas simples

                    // Remover a aspa simples no final, se presente
                    if (token2[strlen(token2) - 1] == '\'') {
                        token2[strlen(token2) - 1] = '\0';  // Remove a última aspa simples
                    }

                    liked_musics_id = realloc(liked_musics_id, (n_liked_musics + 1) * sizeof(char*));
                    liked_musics_id[n_liked_musics] = strdup(token2);  // Aloca memória para cada ID e copia
                    n_liked_musics++;

                }
                set_liked_musics_id(u, liked_musics_id);
                set_n_liked_musics(u, n_liked_musics);
                break;
            default:
                break;
        }
        field++;
    }
    return u;
}

Artist* parse_line_A(char *line, int *flag) {
    Artist* a = init_artist();

    char *token;
    int field = 0;  // Contador para controlar qual campo estamos a preencher

    // Separar a linha em tokens usando strsep
    while ((token = strsep(&line, ";")) != NULL) {
        // Remover aspas que estão nas strings, caso existam
        if (token[0] == '\"' && token[strlen(token) - 1] == '\"') {
            token[strlen(token) - 1] = '\0';  // Remove a última aspa
            token++;  // Remove a primeira aspa
        }
        
        // Atribuir os tokens aos campos apropriados da struct artista
        switch (field) {
            case 0:
                set_artist_id(a, token); 
                break;
            case 1:
                set_artist_name(a, token);
                break;
            case 2:
                //set_artist_description(a, token);
                break;
            case 3:
                set_artist_recipe_per_stream(a, atof(token));
                break;
            case 4:
                if (valida_listas(token) == 0) {
                    *flag = 1;
                }

                // Remover os parêntesis retos
                if (token[0] == '[' && token[strlen(token) - 1] == ']') {
                    token[strlen(token) - 1] = '\0';  // Remove o último ']'
                    token++;  // Remove o primeiro '['
                }

                // Verificar se a lista está vazia
                if (strlen(token) == 0) {
                    set_artist_id_constituent(a, NULL);
                    set_artist_n_constituent(a, 0);
                } else {
                    // Processar a lista de constituintes entre aspas simples e separados por vírgulas
                    char *token2;
                    int n_constituent = 0;
                    char **id_constituent = malloc(sizeof(char*));  // Inicializa o array

                    while ((token2 = strsep(&token, ",")) != NULL) {
                        // Remover espaços em branco e aspas simples
                        while (*token2 == ' ' || *token2 == '\'') token2++;  // Avança o ponteiro para ignorar espaços e aspas simples

                        // Remover a aspa simples no final, se presente
                        if (token2[strlen(token2) - 1] == '\'') {
                            token2[strlen(token2) - 1] = '\0';  // Remove a última aspa simples
                        }

                        id_constituent = realloc(id_constituent, (n_constituent + 1) * sizeof(char*));
                        id_constituent[n_constituent] = strdup(token2);  // Aloca memória para cada ID e copia
                        n_constituent++;
                    }
                    set_artist_id_constituent(a, id_constituent);
                    set_artist_n_constituent(a, n_constituent);
                }
                break;
            case 5:
                set_artist_country(a, token); 
                break;
            case 6:
                token++;
                token[strlen(token) - 2] = '\0';  // Remove a última aspa
                set_artist_type(a, token);
                break;
            default:
                break;
        }
        field++;
    }
    return a;
}

Music* parse_line_M(char *line, int *flag) {
    Music *m = init_music();

    char *token;
    int field = 0;  // Contador para controlar qual campo estamos a preencher

    // Separar a linha em tokens usando strsep
    while ((token = strsep(&line, ";")) != NULL) {
        // Remover aspas duplas nas strings
        if (token[0] == '\"' && token[strlen(token) - 1] == '\"') {
            token[strlen(token) - 1] = '\0';  // Remove a última aspa
            token++;  // Remove a primeira aspa
        }

        // Atribuir os tokens aos campos apropriados da struct music
        switch (field) {
            case 0:
                set_music_id(m, token);
                break;
            case 1:
                //set_music_title(m, token);
                break;
            case 2: {
                if (valida_listas(token) == 0) {
                    *flag = 1;
                }
                // Remover os parêntesis retos
                if (token[0] == '[' && token[strlen(token) - 1] == ']') {
                    token[strlen(token) - 1] = '\0';  // Remove o último ']'
                    token++;  // Remove o primeiro '['
                }

                // Processar a lista de IDs de artistas entre aspas simples e separados por vírgulas
                char *token2;
                int n_artists = 0;
                char **artist_id = malloc(sizeof(char*));  // Inicializa o array

                while ((token2 = strsep(&token, ",")) != NULL) {
                    // Remover espaços em branco e aspas simples
                    while (*token2 == ' ' || *token2 == '\'') token2++;  // Avança o ponteiro para ignorar espaços e aspas simples

                    // Remover a aspa simples no final, se presente
                    if (token2[strlen(token2) - 1] == '\'') {
                        token2[strlen(token2) - 1] = '\0';  // Remove a última aspa simples
                    }

                    artist_id = realloc(artist_id, (n_artists + 1) * sizeof(char*));
                    artist_id[n_artists] = strdup(token2);  // Aloca memória para cada ID e copia
                    n_artists++;
                }
                set_music_artist_id(m, artist_id);
                set_music_n_artists(m, n_artists);
                break;
            }
            case 3:
                set_music_album_id(m, token);
                break;
            case 4:
                set_music_duration(m, token);              
                break;
            case 5:
                set_music_genre(m, token);
                break;
            case 6:
                set_music_year(m, atoi(token));
                break;
            case 7:
                //set_music_lyrics(m, token);
                break;
            default:
                break;
        }
        field++;
    }
    return m;
}

void parser_csv(char *path, Gestor* gestor){
    //CONCATENAÇÃO DOS CAMINHOS DOS FICHEIROS
    char* music_path = get_file_path(path, "musics.csv");
    char* user_path = get_file_path(path, "users.csv");
    char* artists_path = get_file_path(path, "artists.csv");
    char* albums_path = get_file_path(path, "albums.csv");
    char* history_path = get_file_path(path, "history.csv");

    //ABERTURA DOS FICHEIROS 
    FILE* music_file = fopen(music_path, "r");
    if(music_file == NULL){
        perror("Error opening music_file");
        return;
    }

    FILE* user_file = fopen(user_path, "r");
    if(user_file == NULL){
        perror("Error opening user_file");
        return;
    }

    FILE* artists_file = fopen(artists_path, "r");
    if(artists_file == NULL){
        perror("Error opening artists_file");
        return;
    }

    FILE* albums_file = fopen(albums_path, "r");
    if(albums_file == NULL){
        perror("Error opening albums_file");
        return;
    }

    FILE* history_file = fopen(history_path, "r");
    if(history_file == NULL){
        perror("Error opening history_file");
        return;
    }

    //LEITURA DOS FICHEIROS
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

//----------------------------------------------------------------------------------
//                                     Artistas
//----------------------------------------------------------------------------------

    while ((read = getline(&line, &len, artists_file)) != -1) {
        char copia [strlen(line)+1];
        strcpy(copia, line);
        int *flag = malloc(sizeof(int));
        *flag = 0;
        Artist* a = parse_line_A(line, flag);

        if (*flag == 1){
            store_invalid_line("resultados/artists_errors.csv", copia);
            free_artist (a);
        }
        else {
            if (valida_artist(a) == 1) {
                add_GP_A(gestor, a);
            }
            else {
                store_invalid_line("resultados/artists_errors.csv", copia);
                free_artist (a);
            }
        }
        free(flag);
    }
    free(line);
    line = NULL;
    len = 0;

//----------------------------------------------------------------------------------
//                                     Albums
//----------------------------------------------------------------------------------

    while ((read = getline(&line, &len, albums_file)) != -1) {
        char copia [strlen(line)+1];
        strcpy(copia, line);
        int *flag = malloc(sizeof(int));
        *flag = 0;
        Album* a = parse_line_Al(line, flag);//aqui

        if (*flag == 1){
            store_invalid_line("resultados/albums_errors.csv", copia);
            free_album (a);
        }
        else {
            add_GP_Al(gestor, a);
        }
        free(flag);
    }
    free(line);
    line = NULL;
    len = 0;
//----------------------------------------------------------------------------------
//                                      Músicas
//----------------------------------------------------------------------------------

    while ((read = getline(&line, &len, music_file)) != -1) {
        char copia [strlen(line)+1]; 
        strcpy(copia, line);
        int *flag = malloc(sizeof(int));
        *flag = 0;
        Music* m = parse_line_M(line, flag);

        if (*flag == 1){
            store_invalid_line("resultados/musics_errors.csv", copia);
            free_music(m);
        }
        else {
            if (valida_music(m,gestor) == 1) {
                add_GP_M(gestor, m);
            }
            else {
                store_invalid_line("resultados/musics_errors.csv", copia);
                free_music(m);
            }
        }
        free(flag);
        }

    free(line);
    line = NULL;
    len = 0;

//----------------------------------------------------------------------------------
//                                     Histórico
//----------------------------------------------------------------------------------
    int j = 0;
    while ((read = getline(&line, &len, history_file)) != -1) {
        char copia [strlen(line)+1];
        strcpy(copia, line);
        char *platform = malloc(sizeof(char)*15);
        History* h = parser_line_H(line, platform);
        if (valida_history(platform) == 1) {
            add_GP_H(gestor, h);
        }
        else {
            store_invalid_line("resultados/history_errors.csv", copia);
            free_history (h);
        }
    }
    free(line);
    line = NULL;
    len = 0;

//----------------------------------------------------------------------------------
//                                    Utilizadores
//----------------------------------------------------------------------------------

    while ((read = getline(&line, &len, user_file)) != -1) {
        char copia [strlen(line)+1];
        strcpy(copia, line);
        User* u = parse_line_U(line);

        if (valida_user(u,gestor) == 1) {
            add_GP_U(gestor, u);
        }
        else {
            store_invalid_line("resultados/users_errors.csv", copia);
            free_user(u);
        }
    }
    
    //print_GP(gestor);

    //FECHAR OS FICHEIROS
    fclose(music_file);
    fclose(user_file);
    fclose(artists_file);
    fclose(albums_file);
    fclose(history_file);
    free(music_path);
    free(user_path);
    free(artists_path);
    free(albums_path);
    free(history_path);
    free(line);

}

//----------------------------------------------------------------------------------
//                                LEITURA DAS  QUERIES
//----------------------------------------------------------------------------------

void inicializa_estruturas(Gestor *gestor, int num_q, int est_q){
    if(num_q == 2 && est_q == 0){
        preenche_GP_TOP(gestor);
    }
    else if(num_q == 3 && est_q == 0){
        free_GP_TOP(gestor);
    }
    else if(num_q == 4 && est_q == 0){
        free_GP_HT_GC(gestor);
        preenche_GP_ALL_TOP_10s(gestor);
        free_GP_tabela_principal(gestor);
    }
    else if(num_q == 5 && est_q == 0){
        free_GP_ALL_TOP_10s(gestor);
    }
}

void parser_queries(char* path, Gestor* gestor){
    FILE* input_file = fopen(path, "r");
    if(input_file == NULL){
        perror("Error opening inputs_exemplo_file");
        return;
    }
        
    //LEITURA DOS FICHEIROS
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int cont=1;

    //VARIAVEIS PARA A QUERIE 5
    int **matriz = NULL;
    char **array = NULL;
    int tamanho_atual = 0;
    
    int est_2 = 0;
    int est_3 = 0;
    int est_4 = 0;
    int est_5 = 0;
    int est_6 = 0;

    while ((read = getline(&line, &len, input_file)) != -1) {
        if (line[0]=='1'){
            first_querie(gestor, line, cont);
        } 
        else if (line[0]=='2'){
            inicializa_estruturas(gestor, 2, est_2);
            est_2 = 1;

            second_querie( line, cont, gestor);
        } 
        else if (line[0]=='3'){
            inicializa_estruturas(gestor, 3, est_3);
            est_3 = 1;

            third_querie( line, cont, gestor);
        } 
        else if (line[0]=='4'){
            inicializa_estruturas(gestor, 4, est_4);
            est_4 = 1;

            fourth_querie( line, cont, gestor);
        } 
        else if (line[0]=='5'){
            inicializa_estruturas(gestor, 5, est_5);
            if(est_5 == 0){
                faz_matriz_array_aux(gestor, &matriz, &array, &tamanho_atual);
            }
            est_5 = 1;

            fifth_querie( line, cont, gestor, &matriz, &array, &tamanho_atual);
        }
        else if (line[0]=='6'){
            est_6 = 1;
            sixth_querie( line, cont, gestor);
        }
        cont++;
    }

    free_matriz_array( matriz, array, tamanho_atual);

    //FECHAR OS FICHEIROS
    fclose(input_file);
    free(line);

}