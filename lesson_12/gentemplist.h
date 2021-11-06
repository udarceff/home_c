#ifndef GENTEMPLIST_H
#define GENTEMPLIST_H

int generate_year();
int get_month();
int get_day(int arg, int arg2);
int get_temp(int arg);
int get_array_digit(char *str1);
void writefile(int day, int month, int year, int temper, FILE *data);
void print_help(const char *message);

struct templist {
    int day;
    int month;
    int year;
    int temper;
};


#endif