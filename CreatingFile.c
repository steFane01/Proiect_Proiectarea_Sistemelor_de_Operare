#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilizare: %s nume_fisier\n", argv[0]);
        return 1;
    }

    const char *partitionPath = "/dev/sda4";
    const char *filename = argv[1]; 

    int partition = open(partitionPath, O_CREAT | O_WRONLY, 0666);

    if (partition == -1) {
        perror("Eroare la deschiderea partiției.");
        return 1;
    }

    const char *data = "Acesta este conținutul fișierului.\n";
    size_t dataSize = strlen(data);

    ssize_t bytesWritten = write(partition, data, dataSize);

    if (bytesWritten == -1) {
        perror("Eroare la scrierea în partiție.");
        close(partition);
        return 1;
    }

    printf("S-a scris %zd bytes în partiție.\n", bytesWritten);

    close(partition);

    return 0;
}
