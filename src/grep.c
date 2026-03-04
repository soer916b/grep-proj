#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "argc %d is invalid.\nUsage: <%s> <file> <pattern>\n", argc, argv[0]);
        return 1;
    }
    
    FILE* file;
    if ((file= fopen(argv[1], "r")) == NULL) {
        perror("Error in opening file");
        return 1;
    }
    printf("file <%s> openened succesfully!\n", argv[1]);

    // TO-DO: do something with file here.

        if (fclose(file) != 0) {
            perror("Error in closing file");
            return 1;
        }
        printf("file <%s> closed succesfully!\n", argv[1]);

    return 0;
}
