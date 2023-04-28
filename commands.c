#include <stdio.h>

struct command {
    char *name;
    void (*function)(char **args);
};

struct command builtin_commands[] = {
    {"connect", connect},
    {"close", close},
    {"create", create},
    {"read", read},
    {"update", update},
    {"delete", delete},
    {"upsert", upsert},
    {"exit", exit},
};

// Returns the number of registered commands.
int num_builtin_commands() {
    return sizeof(builtin_commands) / sizeof(struct command);
}

void connect(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "missing address\n");
    } 
    if (args[2] == NULL) {
        fprintf(stderr, "missing port\n");
    } 

    void* handle;
    // handle =  memora_connect(const char *address, uint16_t port);
}

void close(char **args) {
    int result;
    // result = memora_close(void *handle);
    if (result != 0) {
        fprintf(stderr, "failed to close memora connection\n");
    }
}

void create(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "missing key\n");
    } 
    if (args[2] == NULL) {
        fprintf(stderr, "missing value\n");
    } 

    int result;
    // result = memora_create(void *handle, const char *key, const char *value);  

    if (result != 0) {
        fprintf(stderr, "%d: could not create key-value pair\n", result);
    }
}

void read(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "missing key\n");
    } 

    char* result;
    // result = char* memora_read(void *handle, const char *key);

    printf("%c\n", result);
}

void update(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "missing key\n");
    } 
    if (args[2] == NULL) {
        fprintf(stderr, "missing value\n");
    } 
    int result;
    // int = memora_update(void *handle, const char *key, const char *value);

    if (result != 0) {
        fprintf(stderr, "%d: failed to update", result);
    }
}

void delete(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "missing key\n");
    } 
    int result;
    // result =  memora_delete(void *handle, const char *key);
    if (result != 0) {
        fprintf(stderr, "%d: failed to delete", result);
    }
}

void upsert(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "missing key\n");
    } 
    if (args[2] == NULL) {
        fprintf(stderr, "missing value\n");
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