#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int process_file(bool print_linenumber, bool multiple_files, const char* pattern, const char* filename) {
    FILE* fptr;
    if ((fptr= fopen(filename, "r")) == NULL) {
        perror("Error in opening file");
        return 1;
    }

    char buff[1024];
    int line_counter = 1;
    while(fgets(buff, sizeof(buff), fptr)) {
        char* pattern_ptr = strstr(buff, pattern);
        if (pattern_ptr != NULL) {
            if (multiple_files) {
                fputs(filename, stdout);
                fputs(": ", stdout);
            }
            if (print_linenumber) {
                printf("line %d: ", line_counter);
            }
            size_t len = strlen(buff);
            fputs(buff, stdout);
            if (!(buff[len - 1] == '\n')) {
                fputs("\n", stdout);
            }
        }
        line_counter ++;
    }
        if (fclose(fptr) != 0) {
            perror("Error in closing file");
            return 1;
        }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "argc %d is invalid.\nUsage: <%s> <-n (optional)> <pattern> <file>\n", argc, argv[0]);
        return 1;
    }

    int argv_pattern_index = 1;
    int argv_first_file_index = 2;
    bool print_linenumber_active = false;
    if (strcmp(argv[1], "-n") == 0 && argc >= 4) {
        print_linenumber_active = true;
        argv_pattern_index ++;
        argv_first_file_index ++;
    }

    bool multiple_files_mode = false;
    if (argc - argv_first_file_index > 1) {
        multiple_files_mode = true;
    }

    bool file_error_flag = false;
    int i;
    for (i = argv_first_file_index; i < argc; i++) { 
        if (process_file(print_linenumber_active, multiple_files_mode, argv[argv_pattern_index], argv[i]) == 1) {
            file_error_flag = true;
        }
    }
    if (file_error_flag) {
        return 1;
    }
    return 0;
}

