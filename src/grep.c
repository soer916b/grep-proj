#include <stdio.h>

// phase 1: I/O
// mål: programmet kan åbne en fil, læse den linje for linje, og printe dem igen.

int main(int argc, char* argv[]) {
    // vi skal have tre argumenter: programnavn, filnavn og pattern.
    // Vi tjekker at argc == 3:
    if (argc != 3) {
        fprintf(stderr, "argc %d is invalid.\nUsage: <%s> <file> <pattern>\n", argc, argv[0]);
        return 1;
    }
    
    FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "file <%s> does not exist.\n", argv[1]);
        return 1;
    } else {
        printf("file openened succesfully!\n");
    }
    fclose(f);

    return 0;
}
