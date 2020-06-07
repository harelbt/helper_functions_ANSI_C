/*
 Created by Harel Bentabou on 07/06/2020.
*/
#include "help.h"
/*returns the first char after the white chars*/
int skip_white_chars(FILE* file){
    int ch;
    /*_____________________________________________________________*/
    while ((ch = fgetc(file)) == '\n' || ch == ' ');/*skipping engine*/
    /*_____________________________________________________________*/
    return ch;
}
/*returns the first char after the spaces. return value may be a new line character, consider using the skip_white_chars
  function.*/
int skip_spaces(FILE* file){
    int ch;
    /*_____________________________________________________________*/
    while ((ch = fgetc(file)) == ' ');/*skipping engine*/
    /*_____________________________________________________________*/
    return ch;
}
/*stops with exit code.
 * 1)with pre defined codes and "" string (pre made massage to stderr).
 * 2)"EXIT_SUCCESS/FAILURE" and "" string(no massage to stderr).
 * "EXIT_SUCCESS/FAILURE" and a massage to stderr.
 * codes were defined as macros*/
void stop(int exit_type, const char* to_print) {
    /*custom exit with a given string*/
    if (strcmp(to_print,"") != 0 && (exit_type == EXIT_FAILURE || exit_type == EXIT_SUCCESS)) {
        fputs(to_print,stderr);
        exit(exit_type);
    } else/*exit with exit code and "" (empty) string*/
        switch (exit_type) {
            case INPUT: {
                fputs("Can't open input file. Terminating program\n", stderr);
                exit(EXIT_FAILURE);
            }
            case OUTPUT: {
                fputs("Can't open output file. Terminating program\n", stderr);
                exit(EXIT_FAILURE);
            }
            case MEMORY: {
                fputs("Not enough memory\nTerminating program\n", stderr);
                exit(EXIT_FAILURE);
            }
            case FOPEN:{
                fputs("Can't open file. Terminating program\n", stderr);
                exit(EXIT_FAILURE);
            }
            case OTHER: {
                fputs("Something went wrong\nTerminating program\n", stderr);
                exit(EXIT_FAILURE);
            }
            case EXIT_SUCCESS: {
                exit(EXIT_SUCCESS);
            }
            case EXIT_FAILURE: {
                exit(EXIT_FAILURE);
            }
            default: exit(EXIT_FAILURE);
        }
}
/*opens file safely and exits program in case of failure with a proper massage to stderr*/
FILE* open_file(const char* file_name, const char* open_type){
    FILE* file_pointer;
    file_pointer = fopen(file_name, open_type);/*the opening*/
    /*_____________________________________________________________*/
    if (file_pointer == NULL) {/*fail check*/
        stop(FOPEN,"");
    }
    /*_____________________________________________________________*/
    return file_pointer;
}
/*allocates memory for array of any type safely and exits program in case of failure with a proper massage to stderr
 * returns the address*/
void* allocate_arr_memory (int size, const char* type){
    /*allocation*/
    if (!strcmp(type,"char")) {
        char* p = (char *) malloc(sizeof(char) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned char")) {
        unsigned char* p = (unsigned char *) malloc(sizeof( char) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed char")) {
        signed char* p = (signed char *) malloc(sizeof(char) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "short")) {
        short* p = (short*) malloc(sizeof(short) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "short int")) {
        short int* p = (short int*) malloc(sizeof(short int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed short")) {
        signed short* p = (signed short*) malloc(sizeof(signed short) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed short int")) {
        signed short int* p = (signed short int*) malloc(sizeof(signed short int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned short")) {
        unsigned short* p = (unsigned short*) malloc(sizeof(unsigned short) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned short int")) {
        unsigned short int* p = (unsigned short int*) malloc(sizeof(unsigned short int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "int")) {
        int* p = (int*) malloc(sizeof(int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed")) {
        signed * p = (signed*) malloc(sizeof(signed) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed int")) {
        signed int* p = (signed int*) malloc(sizeof(signed int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned")) {
        unsigned * p = (unsigned*) malloc(sizeof(unsigned) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned int")) {
        unsigned int* p = (unsigned int*) malloc(sizeof(unsigned int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "long")) {
        long* p = (long*) malloc(sizeof(long) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "long int")) {
        long int* p = (long int*) malloc(sizeof(long int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed long")) {
        signed long* p = (signed long*) malloc(sizeof(signed long) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed long int")) {
        signed long int* p = (signed long int*) malloc(sizeof(signed long int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned long")) {
        unsigned long* p = (unsigned long*) malloc(sizeof(unsigned long) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned long int")) {
        unsigned long int* p = (unsigned long int*) malloc(sizeof(unsigned long int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "float")) {
        float* p = (float*) malloc(sizeof(float) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "double")) {
        double* p = (double*) malloc(sizeof(double) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "long double")) {
        long double* p = (long double*) malloc(sizeof(long double) * size);
        POINTER_CHECK
        return p;
    }
    /*_____________________________________________________________*/
    return NULL;
}
/*reallocates memory for array of any type safely and exits program in case of failure with a proper massage to stderr
 * returns the address*/
void* realloc_arr_memory (void* ptr, int size, const char* type){
    /*reallocation*/
    if (!strcmp(type,"char")) {
        char* p = (char *) realloc(ptr, sizeof(char) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned char")) {
        unsigned char* p = (unsigned char *) realloc(ptr, sizeof( char) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed char")) {
        signed char* p = (signed char *) realloc(ptr, sizeof(char) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "short")) {
        short* p = (short*) realloc(ptr, sizeof(short) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "short int")) {
        short int* p = (short int*) realloc(ptr, sizeof(short int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed short")) {
        signed short* p = (signed short*) realloc(ptr, sizeof(signed short) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed short int")) {
        signed short int* p = (signed short int*) realloc(ptr, sizeof(signed short int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned short")) {
        unsigned short* p = (unsigned short*) realloc(ptr, sizeof(unsigned short) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned short int")) {
        unsigned short int* p = (unsigned short int*) realloc(ptr, sizeof(unsigned short int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "int")) {
        int* p = (int*) realloc(ptr, sizeof(int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed")) {
        signed * p = (signed*) realloc(ptr, sizeof(signed) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed int")) {
        signed int* p = (signed int*) realloc(ptr, sizeof(signed int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned")) {
        unsigned * p = (unsigned*) realloc(ptr, sizeof(unsigned) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned int")) {
        unsigned int* p = (unsigned int*) realloc(ptr, sizeof(unsigned int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "long")) {
        long* p = (long*) realloc(ptr, sizeof(long) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "long int")) {
        long int* p = (long int*) realloc(ptr, sizeof(long int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed long")) {
        signed long* p = (signed long*) realloc(ptr, sizeof(signed long) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "signed long int")) {
        signed long int* p = (signed long int*) realloc(ptr, sizeof(signed long int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned long")) {
        unsigned long* p = (unsigned long*) realloc(ptr, sizeof(unsigned long) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "unsigned long int")) {
        unsigned long int* p = (unsigned long int*) realloc(ptr, sizeof(unsigned long int) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "float")) {
        float* p = (float*) realloc(ptr, sizeof(float) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "double")) {
        double* p = (double*) realloc(ptr, sizeof(double) * size);
        POINTER_CHECK
        return p;
    }
    if (!strcmp(type, "long double")) {
        long double *p = (long double *) realloc(ptr, sizeof(long double) * size);
        POINTER_CHECK
        return p;
    }
    /*_____________________________________________________________*/
    return NULL;
}
/*returns a string from the file pointer until a white char(dynamic memory allocation)
 * if the file pointer points at a white char, returns "" (empty string)*/
char* get_until_white_char(FILE* file) {
    char* string = allocate_arr_memory(1, "char");/*initial allocation*/
    char* p = string;
    int i = 0;
    int ch;
    /*_____________________________________________________________*/
    while ((ch = fgetc(file)) != '\n' && ch != ' ' && ch != EOF){/*gets characters*/
        *(p+i) = (char) ch;
        i++;
        string = realloc_arr_memory(string,(i + 1),"char");/*expanding string*/
    }
    /*_____________________________________________________________*/
    return string;
}
char* get_line_no_spaces(FILE* file){
    char* string = allocate_arr_memory(1, "char");/*initial allocation*/
    char* p = string;
    int i = 0;
    int ch;
    /*_____________________________________________________________*/
    while ((ch = fgetc(file)) != '\n' && ch != EOF){/*gets characters*/
        if (ch != ' ') {
            *(p + i) = (char) ch;
            i++;
            string = realloc_arr_memory(string, (i + 1), "char");/*expanding string*/
        }
    }
    /*_____________________________________________________________*/
    return string;
}
char* get_next_word(FILE* file){
    char* string = allocate_arr_memory(2, "char");/*initial allocation*/
    char* p = string;
    int ch = skip_white_chars(file);/*gets first char after white characters*/
    int i =0;
    /*_____________________________________________________________*/
    if (ch == EOF){/*no word found*/
        return "";
    }
    *p = (char) ch;/*enters first non white character*/
    i++;/*gets ready for the next character*/
    string = realloc_arr_memory(string,(i + 1),"char");/*expanding string*/
    while ((ch = fgetc(file)) != '\n' && ch != ' ' && ch != EOF){/*gets characters*/
        *(p+i) = (char) ch;
        i++;
        string = realloc_arr_memory(string,(i + 1),"char");/*expanding string*/
    }
    /*_____________________________________________________________*/
    return string;
}