/*
 * help_func.h
 *
 *  Created on: Nov 23, 2014
 *      Author: ivan
 */
//полезные функции
#ifndef HELP_FUNC_H_
#define HELP_FUNC_H_



#include <stdio.h>
#include <stdlib.h>
//выводит help для пользователя флаги -h или--help
void print_info(FILE * stream,int exit_c);
//преобразование пользовательских данных для get запроса
void format_url(char *url,char *get);

#endif /* HELP_FUNC_H_ */
