#include "utilidades.h"

//----------------------------------------------------------------------------------
//                           FUNÇÕES AUXILIARES PARA I/O
//----------------------------------------------------------------------------------

void store_invalid_line(const char *filename, const char *line) {
    //usar como filename "resultados/musics_errors.csv" por exemplo, para a fopen criar esse arquivo
    FILE *error_file = fopen(filename, "a"); //abrir no modo 'a' que cria o arquivo se ele não existir e escreve no final do arquivo se ele existir

    if (error_file == NULL) {
        perror("Falha ao abrir ou criar o arquivo de erros");
        return;
    }

    fprintf(error_file, "%s", line);
    fclose(error_file);
}

char *get_file_path(const char *folder, const char *file_name){
    char *file_path = malloc(strlen(folder) + strlen(file_name) + 2);

    if (file_path == NULL) {
        exit(EXIT_FAILURE);
    }
    sprintf(file_path, "%s/%s", folder, file_name);
    return file_path;
}

//----------------------------------------------------------------------------------
//                           FUNÇÕES AUXILIARES PARA VALIDAÇÃO
//----------------------------------------------------------------------------------

int valida_numero(char *num) {
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] < '0' || num[i] > '9') return 0;
    }
    return 1; // Número válido
}

int valida_data(char *date) {
    if (strlen(date) != 10 || date[4] != '/' || date[7] != '/') return 0;  

    char year[5], month[3], day[3];
    strncpy(year, date, 4);
    year[4] = '\0';
    strncpy(month, date + 5, 2);
    month[2] = '\0';
    strncpy(day, date + 8, 2);
    day[2] = '\0';

    if (!valida_numero(year) || !valida_numero(month) || !valida_numero(day)) return 0;

    int year_num = atoi(year);
    int month_num = atoi(month);
    int day_num = atoi(day);

    if (month_num < 1 || month_num > 12) return 0;
    if (day_num < 1 || day_num > 31) return 0;
    if (month_num==2 && day_num>29) return 0;

    if (year_num > 2024 || (year_num == 2024 && month_num > 9) || (year_num == 2024 && month_num == 9 && day_num > 9)) {
        return 0;
    }

    return 1;  // Data válida
}

int valida_duration(char *duration) {
    int hours, minutes, seconds;
    if (sscanf(duration, "%d:%d:%d", &hours, &minutes, &seconds) != 3) return 0;

    // Verificar se h, m, s estão em [0,9]
    if (hours < 0 || hours > 99) return 0;
    if (minutes < 0 || minutes > 59) return 0;
    if (seconds < 0 || seconds > 59) return 0;

    return 1;  // Duração válida
}

int valida_email(char *email) {
    // Procurar pelo caractere '@'
    char *at_sign = strchr(email, '@');
    if (at_sign == NULL) return 0;

    // O '@' não pode estar no início ou no fim
    if (at_sign == email || *(at_sign + 1) == '\0') return 0;

    // Verificar se o domínio contém um ponto '.'
    char *at_point = strchr(at_sign + 1, '.');
    if (at_point == NULL || *(at_point + 1) == '\0') return 0;

    // Verificar se todos os caracteres antes do '@' são válidos (a-z, 0-9)
    for (char *aux = email; aux < at_sign; aux++) {
        if (!isalnum(*aux)) return 0;
    }

    // Verificar se o domínio e a extensão têm caracteres válidos e estão no tamanho correto
    int tamanho = 0;
    for (char *aux = at_sign + 1; aux < at_point; aux++) {
        if (!isalpha(*aux)) return 0;
        tamanho++;
    }

    if (tamanho<1) return 0;

    tamanho = 0;
    for (char *aux = at_point + 1; *aux != '\0'; aux++) {
        if (!isalpha(*aux)) return 0;
        tamanho++;
    }

    if (tamanho < 2 || tamanho > 3) return 0;

    return 1;  // Email válido
}

int valida_subscription_type (const char *subscription_type){
    if (strcmp(subscription_type, "normal") == 0 || strcmp(subscription_type, "premium") == 0) return 1;
    return 0;
}

int verifica_type_individual(const char* type){
    return strcasecmp(type, "individual") == 0;
}

int verifica_type_group(const char* type){
    return strcasecmp(type, "group") == 0;
}

int valida_artist_type(const char* type){
    if (verifica_type_individual(type)==1 || verifica_type_group(type)==1) return 1;
    return 0;
}

int valida_artist_n_constituent(const char *type, int n_constituent) {
    if (verifica_type_individual(type)==1) {
        // Artistas individuais devem ter 0 constituintes
        if (n_constituent != 0) {
            return 0;  // Inválido, deveria ser 0 constituintes
        }
    } else if (verifica_type_group(type)==1) {
        // Artistas do tipo "grupo" devem ter pelo menos 1 constituinte
        if (n_constituent < 1) {
            return 0;  // Inválido, grupos devem ter pelo menos 1 constituinte
        }
    }

    return 1;  // O campo está válido
}

int valida_listas (char* lista){
    int length = strlen(lista);

    if (length < 2 || lista[0] != '[' || lista[length - 1] != ']') {
        return 0;  
    }

    return 1;  // Válido
}

int valida_listas_User (char* lista){
    int length = strlen(lista);

    if (length < 2 || lista[1] != '[' || lista[length - 3] != ']') {
        return 0;  
    }

    return 1;  // Válido
}

int esta_na_HT_ids_M (char* id, Gestor *gestor){
    return (musica_existe_GP(gestor, id));
}

int valida_listas_music_ids(char** lista, int n_listas, Gestor *gestor) {
    int i = 0;
    while (i < n_listas) {
        char temp_id[9];
        if (i == 0) {
            strncpy(temp_id, lista[i] + 3, 8);
            temp_id[8] = '\0';

            if (esta_na_HT_ids_M(temp_id, gestor) == 0) {
                return 0;
            }
        } else if (i == n_listas - 1) {
            strncpy(temp_id, lista[i], 8);
            temp_id[8] = '\0';
            if (esta_na_HT_ids_M(temp_id, gestor) == 0) {
                return 0;
            }
        } else {
            if (esta_na_HT_ids_M(lista[i], gestor) == 0) {
                return 0;
            }
        }
        i++;
    }

    return 1;  // Válido
}

int esta_na_HT_ids_A (char* id, Gestor *gestor){
    Artist *a = search_GP_HT_A(gestor, id);
    if (a == NULL) {
        free_artist(a);
        return 0;
    }
    free_artist(a);
    return 1;
}

int valida_listas_artist_ids(char** lista, int n_listas, Gestor *gestor) {
    int i = 0;
    while (i < n_listas) {
        if (esta_na_HT_ids_A(lista[i], gestor) == 0) {
            return 0;
        }
        i++;
    }

    return 1;  // Válido
}

int verifica_type_mobile(const char* type) {
    if((type[1]=='m'||type[1]=='M')&&(type[2]=='o'||type[2]=='O')&&(type[3]=='b'||type[3]=='B')&&(type[4]=='i'||type[4]=='I')&&(type[5]=='l'||type[5]=='L')&&(type[6]=='e'||type[6]=='E')) 
    {return 1;}
    return 0;
}

int verifica_type_desktop(const char* type) {
    if((type[1]=='d'||type[1]=='D')&&(type[2]=='e'||type[2]=='E')&&(type[3]=='s'||type[3]=='S')
      &&(type[4]=='k'||type[4]=='K')&&(type[5]=='t'||type[5]=='T')&&(type[6]=='o'||type[6]=='O')
      &&(type[7]=='p'||type[7]=='P')) {return 1;}
    return 0;
}

int valida_plataform(const char* type){
    if (verifica_type_mobile(type)==1 || verifica_type_desktop(type)==1) return 1;
    return 0;
}

int valida_album_id(Gestor* g, char* id){ // falta copiar isto
    if (search_GP_Al(g, id) == NULL) {
        return 0;
    }
    return 1; //válido
}

int valida_user (User *u, Gestor *gestor){
    char *email = get_email(u);
    if (valida_email(email) == 0) {
        free(email);
        return 0;
    }
    char *birth_date = get_birth_date(u);
    if (valida_data(birth_date) == 0) {
        free(email);
        free(birth_date);
        return 0;
    }
    char *subscription_type = get_subscription_type(u);
    if (valida_subscription_type(subscription_type) == 0) {
        free(email);
        free(birth_date);
        free(subscription_type);
        return 0;
    }
    char **liked_musics_id = get_liked_musics_id(u);
    int n_liked_musics = get_n_liked_musics(u);
    if (valida_listas_music_ids(liked_musics_id,n_liked_musics,gestor) == 0) {
        free(subscription_type);
        free(birth_date);
        free(email);
        for (int i = 0; i < n_liked_musics; i++) {
            free(liked_musics_id[i]);
        }
        free(liked_musics_id);
        return 0;
    }
    for (int i = 0; i < n_liked_musics; i++) {
        free(liked_musics_id[i]);
    }
    free(liked_musics_id);
    free(subscription_type);
    free(birth_date);
    free(email);
    return 1;  // Válido
}

int valida_music (Music *m,Gestor* gestor){
    char *music_duration = get_music_duration(m);
    char* album_id = get_music_album_id(m);
    if (valida_album_id(gestor, album_id) == 0) {
        free(music_duration);
        free(album_id);
        return 0;
    }
    if (valida_duration(music_duration) == 0) {
        free(music_duration);
        free(album_id);
        return 0;
    }
    char **artist_id = get_music_artist_id(m);
    int n_artists = get_music_n_artists(m);
    if (valida_listas_artist_ids(artist_id,n_artists,gestor) == 0) {
        while (n_artists--) {
        free(artist_id[n_artists]);
        }
        free(artist_id);
        free(music_duration);
        free(album_id);
        return 0;
    }
    while (n_artists--) {
    free(artist_id[n_artists]);
    }
    free(artist_id);
    free(music_duration);
    free(album_id);
    return 1;  // Válido
}

int valida_artist (Artist *a){
    char *artist_type = get_artist_type(a);
    if (valida_artist_n_constituent(artist_type, get_artist_n_constituent(a)) == 0) {
        free(artist_type);
        return 0;
    }
    else if (valida_artist_type(artist_type) == 0) {
        free(artist_type);
        return 0;
    }
    free(artist_type);
    return 1;  // Válido
}

int valida_history (char *platform){
    if (valida_plataform(platform) == 0) {
        free(platform);
        return 0;
    }
    free(platform);
    return 1;  // Válido
}

//----------------------------------------------------------------------------------
//                   FUNÇÕES AUXILIARES PARA TESTES DE QUERIES
//----------------------------------------------------------------------------------

int compare_outputs(char* output_file, char* expected_output_file, int* flag){
    FILE *output = fopen(output_file, "r");
    FILE *expected_output = fopen(expected_output_file, "r");

    if(output == NULL || expected_output == NULL){
        perror("Error opening output file");
        return 0;
    }

    char* line_output = NULL;
    char* line_expected_output = NULL;
    size_t len = 0;
    size_t len2 = 0;
    ssize_t read_output;
    ssize_t read_expected_output;

    int i = 1;

    while ((read_output = getline(&line_output, &len, output)) != -1 && (read_expected_output = getline(&line_expected_output, &len2, expected_output)) != -1){
        if(strcmp(line_output, line_expected_output) != 0){
            *flag = i;
            free(line_output);
            free(line_expected_output);
            fclose(output);
            fclose(expected_output);
            return 0;
        }
        i++;
    }

    free(line_output);
    free(line_expected_output);
    fclose(output);
    fclose(expected_output);

    return 1;
}

void compare_outputs_teste (char* path_folder, int cont){
    int aux=0;
    for(int i=1; i<cont;i++){
        char* output_file = malloc(200);
        sprintf(output_file, "resultados/command%d_output.txt", i);

        char* file = malloc(200);
        sprintf(file, "command%d_output.txt", i);

        char* expected_output_file = NULL;
        expected_output_file = get_file_path(path_folder, file);

        int* flag = malloc(sizeof(int));
        *flag = 0;

        if(compare_outputs(output_file, expected_output_file, flag)==0){
            printf("--->Descrepância na querie %d, linha %d de %s\n", i, *flag, output_file);
            aux++;
        }
        free(output_file);
        free(expected_output_file);
        free(file);
        free(flag);
    }
    printf("\n");
    printf("%d de %d testes ok!\n", cont-aux-1, cont-1);
    printf("\n");
}

//----------------------------------------------------------------------------------
//                        FUNÇÕES AUXILIARES GENÉRICAS 
//----------------------------------------------------------------------------------

int duration_seg (char* duration){
    char hour[3], min[3], sec[3];
    strncpy(hour, duration, 2);
    hour[2] = '\0';
    strncpy(min, duration + 3, 2);
    min[2] = '\0';
    strncpy(sec, duration + 6, 2);
    sec[2] = '\0';

    int hour_num = atoi(hour);
    int min_num = atoi(min);
    int sec_num = atoi(sec);

    return hour_num * 3600 + min_num * 60 + sec_num;
}