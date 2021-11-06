#include <stdio.h>
#include "gentemplist.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

extern char *optarg;
extern int optind, opterr, optopt;

#ifdef DEBUG
#define DBG(x) printf("%s функция: %s:%d\n", x, __func__, __LINE__)
#else
#define DBG(x)
#endif



int main(int argc, char **argv)
{
    char *mode = "w";
    int n = 0;
    int ret;
    const char *filename;
    opterr = 0;
    bool v = false;


    while ((ret = getopt(argc, argv, "vfnah")) != -1) {
        switch(ret) {
             case 'v' : {
                v = true;
                break;
            }
            case 'f' : {
                filename = argv[optind];
                break;
            }
            case 'n' : {
                n = get_array_digit(argv[optind]);
                break;
            }
            case 'a' : {
                mode = "a";
                break;
            }
             case 'h' : {
                print_help(argv[0]);
                return 0;
                break;
            }
            case '?' : {
                printf("Неизвестная опция\n");
                break;
            }
        }
    }

    if(!filename || !n) {
        print_help(argv[0]);
        return -1;
    }

    srand(time(NULL));
    struct templist d = { 0 };
    FILE *data_temp;

    if((data_temp = fopen(filename, mode)) == NULL) {
        if(v) {
            DBG("Ошибка открытия файла");
        }
        return -1;
    } else {
        if(v) {
            DBG("Файл успешно открыт");
        }
    }
    if(v) {
        DBG("Записываем сгенерированые данные в файл");
    }

    for(int i = 0; i < n; i++) {
       
        d.month = get_month();
        d.year = generate_year();
        d.day = get_day(d.month, d.year);
        d.temper = get_temp(d.month);

        writefile(d.day, d.month, d.year,  d.temper, data_temp);
        
       
    }

    if(fclose(data_temp) != 0) {
        if(v) {
            DBG("Ошибка закрытия файла");
        }
        return -1;
    } else {
        if(v) {
            DBG("Файл успешно закрыт");
        }
    }
    

    return 0;
}