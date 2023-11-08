#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char* partitionPath = "/dev/sda4";
    int partition = open(partitionPath, O_CREAT | O_WRONLY, 0666);

    if (partition == -1) {
        perror("Eroare la deschiderea partiției.");
        exit(1);
    }

    const char* data = "Acesta este conținutul fișierului pe partiția raw.\n";
    size_t dataSize = strlen(data);

    ssize_t bytesWritten = write(partition, data, dataSize);

    if (bytesWritten == -1) {
        perror("Eroare la scrierea în partiție.");
        close(partition);
        exit(1);
    }

    printf("S-a scris %zd bytes în partiție.\n", bytesWritten);

    close(partition);

    return 0;
}
