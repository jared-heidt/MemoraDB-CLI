#include <stdio.h>

void* connect(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "usage: connect address port\n");
        return;
    }

    void* handle;
    // handle =  memora_connect(const char *address, uint16_t port);
}

void close(char **args) {
    int result;
    // result = memora_close(void *handle);
    if (result != 0) {
        fprintf(stderr, "failed to close memora connection\n");
        return;
    }
}

void create(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "usage: create key value\n");
        return;
    }

    int result;
    // result = memora_create(void *handle, const char *key, const char *value);  

    if (result != 0) {
        fprintf(stderr, "%d: could not create key-value pair\n", result);
    }
}

void read(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "usage: read key\n");
        return;
    } 

    char* result;
    // result = char* memora_read(void *handle, const char *key);

    printf("%c\n", result);
}

void update(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "usage: update key value\n");
        return;
    }

    int result;
    // int = memora_update(void *handle, const char *key, const char *value);

    if (result != 0) {
        fprintf(stderr, "%d: failed to update", result);
    }
}

void delete(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "usage: delete key\n");
        return;
    }

    int result;
    // result =  memora_delete(void *handle, const char *key);
    if (result != 0) {
        fprintf(stderr, "%d: failed to delete", result);
    }
}

void upsert(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "usage: upsert key value\n");
        return;
    }

    int result;
    // result = memora_upsert(void *handle, const char *key, const char *value);
    if (result != 0) {
        fprintf(stderr, "%d: failed to upsert", result);
    }
}

void exit(char **args) {
    exit(0);
}