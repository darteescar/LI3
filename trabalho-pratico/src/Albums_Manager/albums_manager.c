#include "Albums_Manager/albums_manager.h"

/*------------------------------------------Estrutura---------------------------------------------*/

struct albums_Manager {
    GHashTable *albums;
};

/*-------------------------------------Funções do Gestor dos Albums-------------------------------*/

// Inicializa o Gestor de Albums
Albums_Manager *init_GAl() {
    Albums_Manager *am = malloc(sizeof(Albums_Manager));
    am->albums = init_HT_Al();
    return am;
}

// Liberta a memória alocada para o Gestor de Albums
void free_GAl(Albums_Manager *am) {
    free_HT_Al(am->albums);
    free(am);
}

// Função que adiciona um album ao gestor de albums
void add_GAl_Al(Albums_Manager *am, Album *album) {
    add_HT_Al_Al(album, am->albums);
}

Album *search_GAl_Al (Albums_Manager *am, char *id) {
    return search_HT_Al(am->albums, id);
}