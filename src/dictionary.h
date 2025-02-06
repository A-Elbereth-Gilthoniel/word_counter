#include "libr.h"

//====================================================================================

typedef struct {
    char** word_list;
    size_t* onset_number;
    size_t dict_size;
    size_t dict_capacity;
} dictionary;

//====================================================================================

dictionary* dictionary_create(size_t start_capacity);
void dictionary_push(dictionary* dict, char* word);
void dictionary_realloc(dictionary* dict, int new_capacity);
void dictionary_print(dictionary* dict);

//=====================================================================================

dictionary* dictionary_create(size_t start_capacity)
{
    dictionary* new_dict = (dictionary*) malloc(sizeof(dictionary));
    new_dict->dict_capacity = start_capacity;
    new_dict->dict_size = 0;
    new_dict->word_list = (char**) malloc(new_dict->dict_capacity * sizeof(char*));

    new_dict->onset_number = (size_t*) malloc(new_dict->dict_capacity * sizeof(size_t));

    return new_dict;
}

//=====================================================================================

void dictionary_push(dictionary* dict, char* word)
{
    for (int i = 0; i < dict->dict_size; i++)
    {
        if (strcmp(dict->word_list[i], word) == 0)
        {
            dict->onset_number[i]++;
            return;
        }
    }
    if (dict->dict_size + 1 >= dict->dict_capacity)
    {
        dictionary_realloc(dict, dict->dict_capacity * 2);
    }
    dict->word_list[dict->dict_size] = (char*) malloc((WORD_MAX_SIZE + 1) * sizeof(char));
    strcpy(dict->word_list[dict->dict_size], word);
    dict->onset_number[dict->dict_size] = 1;
    dict->dict_size++;
}

//=====================================================================================

void dictionary_realloc(dictionary* dict, int new_capacity)
{
    dict->word_list = (char**) realloc(dict->word_list, new_capacity * sizeof(char*));
    dict->onset_number = (size_t*) realloc(dict->onset_number, new_capacity * sizeof(size_t));
    dict->dict_capacity = new_capacity;
}

//=====================================================================================

void dictionary_print(dictionary* dict)
{
    for (int i = 0; i < dict->dict_size; i++)
    {
        printf("%s\t%lu\n", dict->word_list[i], dict->onset_number[i]);
    }
    // printf("");
}
