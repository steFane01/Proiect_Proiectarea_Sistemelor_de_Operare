#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verifică numărul de argumente
    if (argc != 2) {
        printf("Utilizare: %s nume_fisier\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Eroare la deschiderea fișierului.");
        return 1;
    }

    const char *data = "Acesta este conținutul fișierului.\n";
    size_t dataSize = strlen(data);

    // Scrie datele în fișier
    size_t bytesWritten = fwrite(data, 1, dataSize, file);

    if (bytesWritten != dataSize) {
        perror("Eroare la scrierea în fișier.");
        fclose(file);
        return 1;
    }

    printf("S-a scris %zd bytes în fișierul %s.\n", bytesWritten, filename);

    fclose(file);

    return 0;
}
