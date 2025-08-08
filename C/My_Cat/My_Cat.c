#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[100]; //Buffer Overflow vulnerability :)
    size_t bytes_read;

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Unable to open file: %s\n", argv[i]);
            continue;
        }

        while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            fwrite(buffer, 1, bytes_read, stdout);
        }

        fclose(file);
        
    }

    return 0;
}

int main();
