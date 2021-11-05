#ifndef FUNCMYCP_H
#define FUNCMYCP_H

size_t get_file_size(FILE *f_namein);
void file_copy(FILE *f_namein, FILE *f_nameout, size_t file_size);


#endif