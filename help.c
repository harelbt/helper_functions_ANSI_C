/*
 Created by Harel Bentabou on 07/06/2020.
 Update  08/06/2020: new funcs: 1)translate_to_binary 2)int_to_str 3)invert_long_arr(private / static).
*/
#include "help.h"
static void invert_long_arr(long*, int);

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
/*translates strings and numbers to binary base
 * returns the result in a long array
 * for char, int and long, every number is stored in a different cell (2 = |1|0|)
 * for strings, every char's translation is stored in a different cell ("12" = |1|10|)*/
long* translate_to_binary(const char* data_type,...) {
    va_list argp;
    va_start(argp, data_type);
    /*_____________________________________________________________*/
    if (!strcmp(data_type, "char") || !strcmp(data_type, "int") || !strcmp(data_type, "Int")
            || !strcmp(data_type, "long")) {/*for int, long and char*/
        long *translation = allocate_arr_memory(2, "long");/*minimum required size*/
        long to_translate;
        long reminder;
        long curr_index = 0;
        /*gets value from the arguments*/
        if (!strcmp(data_type, "long"))/*data_type == "long"*/
            to_translate = va_arg(argp, long);
        else /*data_type == "int" || "char"*/
            to_translate = va_arg(argp, int);

        while (to_translate != 0) {/*every iteration finds the next 0 or 1*/
            reminder = to_translate % 2;
            to_translate /= 2;
            translation[curr_index] = reminder;
            curr_index++;
            /*redetermines size according to curr_index*/
            translation = realloc_arr_memory(translation, curr_index + 1, "long");
        }
        /*-1 in the last cell*/
        translation[curr_index] = -1;
        /*array needs to be inverted*/
        invert_long_arr(translation, curr_index + 1);
        /*_____________________________________________________________*/
        return translation;
    }

    if ((!strcmp(data_type,"string") )|| (!strcmp(data_type,"String")) || (!strcmp(data_type,"char*"))
    || (!strcmp(data_type,"const char*")) || (!strcmp(data_type,"Char*")) || (!strcmp(data_type,"Const char*"))) {/*for int, long and char*/
        long *translation = allocate_arr_memory(1, "long");/*minimum required size*/
        /*gets value from the arguments*/
        const char *string = va_arg(argp, char*);
        long binary = 0;
        long reminder;
        long i = 1;
        long j = 0;

        while (string[j] != '\0') {
            /*copying char*/
            translation[j] = (long) string[j];
            /*translating char*/
            while (translation[j] != 0) {
                reminder = translation[j] % 2;
                translation[j] /= 2;
                binary += reminder * i;
                i *= 10;
            }
            /*copying translation to the array*/
            translation[j] = binary;
            /*recalibrate variables*/
            binary = 0;
            i = 1;
            j++;
            /*redetermines size according to the index*/
            translation = realloc_arr_memory(translation, j + 1, "long");
        }
        /*puts -1 in the end*/
        translation[j] = -1;

        return translation;
    }
    /*returns NULL if data type hasn't been recognised*/
    return NULL;
}
/*returns an int as a string (char*)*/
char* int_to_str(int number) {
    int number_copy = number;
    int count = 0;
    int negative = 0;
    char *str;
    if (number < 0)
        negative = 1;
    /*counts "length"*/
    while (number_copy != 0) {
        count++;
        number_copy /= 10;
    }
    /*allocating the necessary memory*/
    if (negative == 1) {
        /*saves place for a '-'*/
        str = allocate_arr_memory(count + 2, "char");
        str[count+1] = '\0';
        count++;/*starts ahead to save place for '-'*/
    } else {
        str = allocate_arr_memory(count + 1, "char");
        str[count] = '\0';
    }
    /*enters values to the string*/
    while (count != 0) {
        /*gets last number*/
        number_copy = number % 10;
        number /= 10;
        /*updates the index*/
        count--;
        /*if the number is negative, adds a '-' to the start (cell pre saved)*/
        if (negative == 1 && count == 0) {
            str[count] = '-';
            break;
        }
        /*inserts accordingly*/
        switch (abs(number_copy)) {
            case 0: {
                str[count] = '0';
                break;
            }
            case 1: {
                str[count] = '1';
                break;
            }
            case 2: {
                str[count] = '2';
                break;
            }
            case 3: {
                str[count] = '3';
                break;
            }
            case 4: {
                str[count] = '4';
                break;
            }
            case 5: {
                str[count] = '5';
                break;
            }
            case 6: {
                str[count] = '6';
                break;
            }
            case 7: {
                str[count] = '7';
                break;
            }
            case 8: {
                str[count] = '8';
                break;
            }
            case 9: {
                str[count] = '9';
                break;
            }
        }
    }
    return str;
}

/*(private) inverting long arrays, ignores last cell*/
static void invert_long_arr(long* array, int length){
    long i = 0;
    long j = length - 2;
    long swap;
    while (i < j){
        swap = array[i];
        array[i] = array[j];
        array[j] = swap;
        i++;
        j--;
    }
}
