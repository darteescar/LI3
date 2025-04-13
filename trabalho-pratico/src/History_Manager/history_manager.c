#include "History_Manager/history_manager.h"


/*----------------Estrutura------------------*/

struct history_Manager {
    GHashTable *LUS;
};

/*----------------Funções do Gestor de Histórico------------------*/

History_Manager *init_GH() {
    History_Manager *hm = malloc(sizeof(History_Manager));
    if (hm != NULL) {
        hm->LUS = init_HT_LUS();
    }
    return hm;
}

void free_GH(History_Manager *hm) {
    free_HT_LUS(hm->LUS);
    free(hm);
}

void add_GH_H(History_Manager *hm, History *h) {
    add_HT_LUS(hm->LUS, h);
}

GHashTable *encapsula_LUS_GH(History_Manager *hm, char *id) {
    return encapsula_LUS (hm->LUS, id);
}