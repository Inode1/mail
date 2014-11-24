/*
 * http_client.c
 *
 *  Created on: Nov 23, 2014
 *      Author: ivan
 */

#include <getopt.h>
#include "help_func.h"
#include "data_exchange.h"
int main(int argc, char **argv) {
	int next_option;
	//короткие сокращения
	const char * const short_options="ho:v";
	//опиасание набора парраметров программы
	const struct option long_options[]={
			{ "help",    0, NULL, 'h'},
			{ "output",  1, NULL, 'o'},
			{ "verbose", 0, NULL, 'v'},
			{NULL      , 0, NULL,  0 }};
	const char * output_filename=NULL;
	int verbose=0;
	//проверка введеных флагов
	do{
		next_option=getopt_long(argc,argv,short_options,
								long_options, NULL);
		switch(next_option){
		case 'h':
			print_info(stdout,0);
		case 'o':
			output_filename=optarg;
			break;
		case 'v':
			verbose=1;
			break;
		case '?':
			print_info(stderr,1);
		case -1:
			break;
		default:
			abort();
	    }
	 }
	while(next_option!=-1);
	int c=optind;
	//проверка факта ввова пользователя URL
    if(argv[c]==NULL){
    	fprintf(stderr,"NEED ENTER URL\n");
    	print_info(stderr,1);
    }
    //вызов функции обращения к http серверу
    data_exchange(argv[c],output_filename,verbose);
    exit(EXIT_SUCCESS);
}

