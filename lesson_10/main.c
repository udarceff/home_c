#include <stdio.h>
#include "gettemp.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int main(void)
{
    srand(time(NULL));
    struct templist d = { 0 };
    FILE *data_temp;
    data_temp = fopen("data_list.txt", "w");
    
    for(int i = 0; i < 10; i++) {
        
        d.month = get_month();
        d.year = generate_year();
        d.day = get_day(d.month, d.year);
        d.temper = get_temp(d.month);

        fprintf(data_temp, "%d.%d.%d Температура: %d\n", d.day, d.month, d.year, d.temper);


       
    }

    fclose(data_temp);

    return 0;
}