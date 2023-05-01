#include <stdio.h>

struct HashNode {
    char* key;
    void (*function)(char** args);
    struct HashNode* next;
};

int hash(char* key, int size) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % size;
}

struct HashTable {
    int size;
    struct HashNode** table;
};

void hash_table_init(struct HashTable* ht, int size) {
    ht->size = size;
    ht->table = malloc(size * sizeof(struct HashNode*));
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
}

void hash_table_insert(struct HashTable* ht, char* key, void (*function)(char** args)) {
    int index = hash(key, ht->size);
    struct HashNode* new_node = malloc(sizeof(struct HashNode));
    new_node->key = key;
    new_node->function = function;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

void (*hash_table_lookup(struct HashTable* ht, char* key))(char** args) {
    int index = hash(key, ht->size);
    struct HashNode* node = ht->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->function;
        }
        node = node->next;
    }
    return NULL;
}

void hash_table_free(struct HashTable* table) {
    // free each linked list in the hash table
    for (int i = 0; i < table->size; i++) {
        struct HashNode* node = table->table[i];
        while (node != NULL) {
            struct HashNode* next = node->next;
            free(node);
            node = next;
        }
    }

    // free the hash table itself
    free(table);
}
