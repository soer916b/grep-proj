#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "argc %d is invalid.\nUsage: <%s> <pattern> <file>\n", argc, argv[0]);
        return 1;
    }
    bool multiple_files = false;
    if (argc > 3) {
        multiple_files = true;
    }
    int i;
    for (i = 2; i <= argc-1; i++) {
        FILE* fptr;
        if ((fptr= fopen(argv[i], "r")) == NULL) {
            perror("Error in opening file.");
            return 1;
        }
        char buff[1024];
        while(fgets(buff, sizeof(buff), fptr)) {
            char* pattern_ptr = strstr(buff, argv[1]);
            size_t len = strlen(buff);
            if (pattern_ptr != NULL) {
                if (!multiple_files) {
                    fputs(buff, stdout);
                    if (strcmp(&buff[len-1], "\n") != 0) {
                        fputs("\n", stdout);
                    }
                } else {
                    fputs(argv[i], stdout);
                    fputs(": ", stdout);
                    fputs(buff, stdout);
                    if (strcmp(&buff[len-1], "\n") != 0) {
                        fputs("\n", stdout);
                    }
                }
            }
        }
            if (fclose(fptr) != 0) {
                perror("Error in closing file");
                return 1;
            }
    }
    printf("This is a test for WSL");
    return 0;
}
