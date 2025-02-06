#include "libr.h"

typedef struct {
    char* text;
    size_t size;
} parser;

parser* parser_create(char* file_name);

parser* parser_create(char* file_name)
{
    parser* created = (parser*) malloc(sizeof(parser));
    FILE *fp = fopen(file_name, "rb");
    created->size = find_file_size(fp);

    created->text = (char*)calloc(created->size + 1, sizeof(char));
    fread(created->text, sizeof(char), created->size, fp);

    return created;
}