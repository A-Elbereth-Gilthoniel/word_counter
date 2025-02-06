#include "libr.h"
#include "parser.h"
#include "dictionary.h"

void parsing(parser* pars, dictionary* dict);

int main(int argc, char *argv[])
{
    char file_name[100] = FILE_REPOSITORY;
    strcat(file_name, argv[1]);

    parser* new_parser = parser_create(file_name);
    dictionary* new_dict = dictionary_create(MIN_DICT_CAPACITY);

    parsing(new_parser, new_dict);

    dictionary_print(new_dict);
}

//======================================================================

void parsing(parser* pars, dictionary* dict)
{
    char* buffer = (char*) calloc((WORD_MAX_SIZE + 1), sizeof(char));
    char* start = buffer;
    char cur_symb;

    for (int i = 0; i < pars->size + 1; i++)
    {
        cur_symb = pars->text[i];
        if (cur_symb >= 'A' && cur_symb <= 'Z')
        {
            *buffer = cur_symb + 32;
            buffer += sizeof(char);
            continue;
        }
        else if (cur_symb >= 'a' && cur_symb <= 'z')
        {
            *buffer = cur_symb;
            buffer += sizeof(char);
            continue;
        }
        else if (buffer == start)
        {
            continue;
        }
        else
        {
            *(buffer) = '\0';
            dictionary_push(dict, start);
            buffer = start;
        }
    }
}
