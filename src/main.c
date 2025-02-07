#include "libr.h"
#include "parser.h"
#include "dictionary.h"

//=======================================================================

int main(int argc, char *argv[])
{
    dictionary* new_dict = dictionary_create(MIN_DICT_CAPACITY);
    parser* new_parser;

    char* file_name= (char*) calloc(MAX_FILE_NAME, sizeof(char));
    strcat(file_name, FILE_REPOSITORY);
    char* indicator = file_name + strlen(file_name);

    for (int i = 1; i < argc; i++)
    {
        strcpy(indicator, argv[i]);

        new_parser = parser_create(file_name);
        if (!new_parser)
            continue;

        char* buffer;

        while (buffer = parsing(new_parser))
        {
            dictionary_push(new_dict, buffer);
            free(buffer);
        }

        parser_destroy(new_parser);
    }

    dictionary_print(new_dict);

    free(indicator);
    free(file_name);
    dictionary_destroy(new_dict);
}

//======================================================================
