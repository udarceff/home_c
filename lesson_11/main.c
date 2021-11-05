#include <stdio.h>
#include <stdlib.h>
#include "funcmycp.h"

#define BUFSIZE 4096
 
int main(int argc, char **argv)
{
 
    unsigned char buffer[BUFSIZE];
 
    char *file_name_in = argv[1];
    char *file_name_out = argv[2];

    FILE *fin, *fout;

    if((fin = fopen(file_name_in, "rb")) == NULL) {
        fprintf(stderr, "Не удалось открыть файл\n");
        exit(EXIT_FAILURE);
    }
    
    if((fout = fopen(file_name_out, "wb")) == NULL) {
        fprintf(stderr, "Не удалось открыть файл\n");
        exit(EXIT_FAILURE);
    }
    
    size_t file_size = get_file_size(fin);
    file_copy(fin, fout, file_size);
    
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}

