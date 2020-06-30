#include "words.h"
#include "helpfunctions.h"
#include "assembler data.h"
int main (int argc, char* argv[]){
    initialize_all();
    first_pass();
    second_pass();
}