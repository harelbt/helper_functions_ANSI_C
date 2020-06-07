/*
 Created by Harel Bentabou on 07/06/2020.
*/

#ifndef HELP_H
#define HELP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT 10
#define OUTPUT 11
#define MEMORY 12
#define OTHER 13
#define FOPEN 14
#define POINTER_CHECK if (p == NULL) stop(MEMORY,"");
/**
 *  returns the first character after the white characters
 *  if starts at a non white character, returns the next character
 *  @param file the file to read from
 * @return the first character after the white characters
 */
int skip_white_chars(FILE* file);
/**
 *  returns the first character after the spaces
 *  if starts at a non space character, returns the next character
 * @param file the file to read from
 * @return the first character after the spaces
 */
int skip_spaces(FILE* file);
/**
 * stops with exit code, optional - custom massage, if a massage isn't provided, ""(empty string) is required instead:
 * 1)with pre defined codes(below) and "" string (pre made massage to stderr).
 * 2)"EXIT_SUCCESS/FAILURE" and "" string(no massage to stderr).
 * "EXIT_SUCCESS/FAILURE" and a massage to stderr.
 * codes were defined as macros:
 * INPUT, OUTPUT, MEMORY, OTHER, FOPEN, EXIT_SUCCESS, EXIT_FAILURE.
 * @param exit_type
 * @param massage
 */
void stop(int exit_type, const char* massage);
/**
 * like fopen, but if the opening failed gives a proper massage and exit the program
 * @param file_name to open
 * @param mode open mode, as in fopen
 * @return a FILE pointer to the file (FILE*)
 */
FILE* open_file(const char* file_name, const char* mode);
/**
 * like malloc, but in case of a failure, gives a proper massage and exit the program, and does the casting
 * and all the hard work, and works with all of the data types
 * @param size to allocate
 * @param arr_type
 * @return a pointer to the new array
 */
void* allocate_arr_memory (int size, const char* arr_type);
/**
 * like realloc, but in case of a failure, gives a proper massage and exit the program, and does the casting
 * and all the hard work, and works with all of the data types
 * @param ptr pointer to the array to reallocate
 * @param size to allocate
 * @param arr_type
 * @return a pointer to reallocated new array
 */
void* realloc_arr_memory (void* ptr, int size, const char* arr_type);
/**
 * returns a string until a white character.
 * if starts in a white character, returns empty string
 * @param file to read from
 * @return a string until a white space
 */
char* get_until_white_char(FILE* file);
/**
 * returns a line and deletes the spaces
 * @param file to read from
 * @return a line without spaces
 */
char* get_line_no_spaces(FILE* file);
/**
 * returns the next word that appears after any number of spaces and enter characters, from it's first word to the last
 * @param file to read from
 * @return the next word
 */
char* get_next_word(FILE* file);
#endif /*HELP_H*/
