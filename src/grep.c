#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int process_file(bool mul_files, char* pattern, char* filename) {
    FILE* fptr;
    if ((fptr= fopen(filename, "r")) == NULL) {
        perror("Error in opening file.");
        return 1;
    }

    char buff[1024];
    while(fgets(buff, sizeof(buff), fptr)) {
        char* pattern_ptr = strstr(buff, pattern);
        if (pattern_ptr != NULL) {
            if (mul_files) {
                fputs(filename, stdout);
                fputs(": ", stdout);
            }
            size_t len = strlen(buff);
            fputs(buff, stdout);
            if (!(buff[len - 1] == '\n')) {
                fputs("\n", stdout);
            }
        }
    }
        if (fclose(fptr) != 0) {
            perror("Error in closing file");
            return 1;
        }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "argc %d is invalid.\nUsage: <%s> <pattern> <file>\n", argc, argv[0]);
        return 1;
    }

    bool multiple_files_mode = true;
    if (argc == 3) {
        multiple_files_mode = false;
    }

    int i;
    for (i = 2; i < argc; i++) { 
        bool file_error_flag = false;
        if (process_file(multiple_files_mode, argv[1],argv[i]) == 1) {
            file_error_flag = true;
            if (file_error_flag) {
                return 1;
            }
        }
    }
    return 0;
}
