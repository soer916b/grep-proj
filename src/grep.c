#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "argc %d is invalid.\nUsage: <%s> <file> <pattern>\n", argc, argv[0]);
        return 1;
    }
    
    FILE* fptr;
    if ((fptr= fopen(argv[1], "r")) == NULL) {
        perror("Error in opening file");
        return 1;
    }
    printf("file <%s> openened succesfully!\n", argv[1]);
    char buff[1024];
    while(fgets(buff, sizeof(buff), fptr)) {
        char* pattern_ptr = strstr(buff, argv[2]);
        if (pattern_ptr != NULL) {
            fputs(buff, stdout);
        }
    }
    printf("\n");

        if (fclose(fptr) != 0) {
            perror("Error in closing file");
            return 1;
        }
        printf("file <%s> closed succesfully!\n", argv[1]);

    return 0;
}
