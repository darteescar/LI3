#include "History_Manager/HT_LUS.h"

GHashTable *init_HT_LUS () {
    return g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify) g_hash_table_destroy);
}

GHashTable *init_HT_history () {
    return g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify) free_history);
}

void free_HT_history (GHashTable *table) {
    g_hash_table_destroy(table);
}

void free_HT_LUS (GHashTable *table) {
    g_hash_table_destroy(table);
}

void add_HT_LUS (GHashTable *table, History *h) {
    char *user_id = get_user_id_history(h);
    GHashTable *tabela_do_user = g_hash_table_lookup(table, user_id);
    if (tabela_do_user == NULL) {
        tabela_do_user = init_HT_history();
        g_hash_table_insert(tabela_do_user, get_history_id(h), h);
        g_hash_table_insert(table, strdup(user_id), tabela_do_user);
    }
    else {
        g_hash_table_insert(tabela_do_user, get_history_id(h), h);
    }
    free(user_id);
}

GHashTable *search_HT_LUS (GHashTable *table, char *user_id) {
    return g_hash_table_lookup(table, user_id);
}

GHashTable *encapsula_LUS (GHashTable *table, char *user_id) {
    GHashTable *tabela_do_user = g_hash_table_lookup(table, user_id);
    if (tabela_do_user == NULL) {
        return NULL;
    }
    return copy_LUS(tabela_do_user);
}

GHashTable *copy_LUS (GHashTable *table) {
    GHashTable *new_table = init_HT_history();
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, table);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        History *h = (History *) value;
        g_hash_table_insert(new_table, strdup(key), copy_history(value));
    }
    return new_table;
}