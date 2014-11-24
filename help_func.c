/*
 * help_func.c
 *
 *  Created on: Nov 23, 2014
 *      Author: ivan
 */
#include <string.h>
#include "help_func.h"

void print_info(FILE * stream,int exit_c){
	fprintf(stream,"Use: http_client options [input file]  URL\n");
	fprintf(stream,"  -h   --help       	Display info\n"
				   "  -o   --output_file    Name output file\n"
				   "  -v   --verbose        Print in verbose mode\n");
	exit(exit_c);
}

void format_url(char *url,char *get){
	//если пользователь ввел *://*
	char *ptr=strstr(url,"://");
	if(ptr!=NULL){
		strcpy(url,ptr+3);
	}
	//поиск строки для get запроса. Найти первый /
	ptr=(char*)memchr(url,'/',strlen(url));
	if(ptr!=NULL){
		strcpy(get,ptr);
		url[ptr-url]='\0';
	}
	else
		strcpy(get,"/");
}

