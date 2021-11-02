#include <stdio.h>
#include "gettemp.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int get_day(int arg, int arg2)
{
    int day;
    int mon = arg - 1;
    int l_year[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if((arg2 % 4) == 0) {
        day = rand() % l_year[mon] + 1;
    } else {
        day = rand() % year[mon] + 1;
    }


    return day;
}
int generate_year()
{
    int r_year = rand() % 22 + 2000;

    return r_year;
}
int get_month()
{   
    int month = rand() % 12 + 1;
   


    return month;
}

int get_temp(int arg)
{
    int temper;
    int step[12] = { 58, 57, 45, 46, 39, 34, 35, 34, 31, 43, 56, 62};
    int min_temp[12] = { -48, -45, -31, -23, -11, -1, 1, 1, -3, -20, -38, -48};
    int i = arg - 1;


    temper = rand() % step[i] + min_temp[i];

    return temper;

}