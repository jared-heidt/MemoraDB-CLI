#include <stdio.h>

// stores the current connection
void *current_handler;

void db_connect(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "usage: connect address port\n");
        return;
    }

    void* handle;
    // handle =  memora_connect(const char *address, uint16_t port);
    current_handler = handle;
}

void db_close(char **args) {
    int result;
    // result = memora_close(void *handle);
    if (result != 0) {
        fprintf(stderr, "failed to close memora connection\n");
        return;
    }
}

void create_kv(char **args) {
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

void read_kv(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "usage: read key\n");
        return;
    } 

    char* result;
    // result = char* memora_read(void *handle, const char *key);

    printf("%s\n", result);
}

void update_kv(char **args) {
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

void delete_kv(char **args) {
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

void upsert_kv(char **args) {
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

void exit_cli(char **args) {
    exit(0);
}

void help(char **args) {
    char* help = 
    "MemoraDB CLI - manage key-value pairs in connected MemoraDB\n"
    "Commands:"
    "   connect: connect to MemoraDB\n"
    "   close: close current MemoraDB connection\n"
    "   exit: exit the cli\n"
    "   create: create one-key value pair\n"
    "   read: read one key-value pair\n"
    "   update: close current MemoraDB connection\n"
    "   delete: close current MemoraDB connection\n"
    "   upsert: if key exists perform update, otherwise perform create\n";
    printf("%s", help);
}

struct command {
    char *name;
    void (*function)(char **args);
};

struct command builtin_commands[] = {
    {"connect", db_connect},
    {"close", db_close},
    {"create", create_kv},
    {"read", read_kv},
    {"update", update_kv},
    {"delete", delete_kv},
    {"upsert", upsert_kv},
    {"exit", exit_cli},
    {"help", help}
};

// Returns the number of registered commands.
int num_builtin_commands() {
    return sizeof(builtin_commands) / sizeof(struct command);
}

