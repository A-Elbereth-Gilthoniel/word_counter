#ifndef LIBR_H
#define LIBR_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define FILE_REPOSITORY "."
#define WORD_MAX_SIZE 30
#define MIN_DICT_CAPACITY 20
#define MAX_FILE_NAME 100

size_t find_file_size(FILE* fp);

#endif      // LIBR_H
