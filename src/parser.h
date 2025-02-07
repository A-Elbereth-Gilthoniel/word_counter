#include "libr.h"

typedef struct {
    char* text;
    size_t size;
    int cur_ind;
} parser;

parser* parser_create(char* file_name);
char* parsing(parser* pars);
void parser_destroy(parser* pars);

parser* parser_create(char* file_name)
{
    parser* created = (parser*) malloc(sizeof(parser));
    FILE *fp = fopen(file_name, "rb");
    created->size = find_file_size(fp);

    created->text = (char*)calloc(created->size + 1, sizeof(char));
    fread(created->text, sizeof(char), created->size, fp);

    created->cur_ind = 0;

    return created;
}

//================================================================

char* parsing(parser* pars)
{
    char* buffer = (char*) calloc((WORD_MAX_SIZE + 1), sizeof(char));
    char* start = buffer;
    char cur_symb;

    for (int i = pars->cur_ind; i < pars->size + 1; i++)
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
            pars->cur_ind = i;
            return start;
        }
    }
    free(buffer);
    return NULL;
}

//============================================================

void parser_destroy(parser* pars)
{
    free(pars->text);
    free(pars);
}
