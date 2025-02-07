#include "libr.h"
#include "parser.h"
#include "dictionary.h"

//=======================================================================

int main(int argc, char *argv[])
{
    char file_name[100] = FILE_REPOSITORY;
    strcat(file_name, argv[1]);

    parser* new_parser = parser_create(file_name);
    dictionary* new_dict = dictionary_create(MIN_DICT_CAPACITY);

    char* buffer;

    while (buffer = parsing(new_parser))
    {
        dictionary_push(new_dict, buffer);
        free(buffer);
    }

    dictionary_print(new_dict);

    dictionary_destroy(new_dict);
    parser_destroy(new_parser);
}

//======================================================================
