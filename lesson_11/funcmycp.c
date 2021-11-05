#include <stdio.h>
#include <stdlib.h>
#include "funcmycp.h"

#define BUFSIZE 4096


size_t get_file_size(FILE *f_namein)
{
    size_t file_size = 0;

    fseek(f_namein, 0, SEEK_END);    //перемещаем каретку в конец файл
    file_size = ftell(f_namein);     //получаем количество байтов от начала файла
    rewind(f_namein);                //возвращаемся в начало

    return file_size;  
}

void file_copy(FILE *f_namein, FILE *f_nameout, size_t file_size)
{

    unsigned char buffer[BUFSIZE];
    
    for(size_t i = 0; i < file_size / BUFSIZE; ++i) {
        if(fread(buffer, sizeof(unsigned char), BUFSIZE, f_namein) != BUFSIZE) {
            fprintf(stderr, "Ошибка чтения\n");
            exit(EXIT_FAILURE);
        }
        if(fwrite(buffer, sizeof(unsigned char), BUFSIZE, f_nameout) != BUFSIZE) {
            fprintf(stderr, "Ошибка записи\n");
            exit(EXIT_FAILURE);
        }
    }
    
    if((file_size %= BUFSIZE)) {
        if(fread(buffer, sizeof(unsigned char), file_size, f_namein) != file_size) {
            fprintf(stderr, "Ошибка чтения\n");
            exit(EXIT_FAILURE);
        }
        if(fwrite(buffer, sizeof(unsigned char), file_size, f_nameout) != file_size) {
            fprintf(stderr, "Ошибка записи\n");
            exit(EXIT_FAILURE);
        }
    }
}