void connect(char **args) {
    // call memora_connect(const char *address, uint16_t port);
}

void close(char **args) {
    // call memora_close(void *handle);
}

void create(char **args) {
    // call memora_create(void *handle, const char *key, const char *value);  
}

void read(char **args) {
    // call char* memora_read(void *handle, const char *key);
}

void update(char **args) {
    // call memora_update(void *handle, const char *key, const char *value);
}

void delete(char **args) {
    // call memora_delete(void *handle, const char *key);
}

void upsert(char **args) {
    // call memora_upsert(void *handle, const char *key, const char *value);
}