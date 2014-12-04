/*
 * data_exchange.c
 *
 *  Created on: Nov 23, 2014
 *      Author: ivan
 */

#include "data_exchange.h"
#include "help_func.h"
void data_exchange(char *url,const char* out_file,int verbose){
	//выделения памяти для url и для get строки
	char *aloc_url=(char *)malloc(strlen(url)+1);
	char *get=(char *)malloc(strlen(url)+1);

	strcpy(aloc_url,url);
	format_url(aloc_url,get);
	//буферр для сетевого обмена
	char request[1024];
	//структура инфома об сервере
	struct hostent *server;
	struct sockaddr_in serveraddr;
	FILE *pfile;
	if(out_file==NULL)
		pfile=fopen("out","w");
	else
		pfile=fopen(out_file,"w");
	//открытие сокета
	int Socket = socket(AF_INET, SOCK_STREAM, 0);

	if (Socket < 0){
	     perror("Error opening socket\n");
	     goto clear;}
//получения ip сервера
	server = gethostbyname(aloc_url);

	if (server == NULL)
	  {
	   perror("gethostbyname() failed\n");
	   goto clear;
	  }
	//заполения струтуры сервера
	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;

	bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);

	serveraddr.sin_port = htons(PORT);
	//коннескт к серверу
	if (connect(Socket, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0){
	     perror("Error Connecting\n");
		 goto clear;}
//запрос на получения контента.
	sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", get, aloc_url);
	if(verbose)
	  printf("\n%s", request);
	//отправка запроса на сервер
	if (send(Socket, request, strlen(request), 0) < 0){
	    perror("Error with send()");
	    goto clear;}

	 bzero(request, 1024);
	 int c;
	 //получения данных от сервера
	 while((c=recv(Socket, request, 1023, 0))>0){
		 fwrite(request,sizeof(char),c,pfile);
		 }
	 clear:
	 //закрытие сокета
	 close(Socket);
	 //закрытие файла
	 fclose(pfile);
	 //освобождения хипа
	 free(get);
	 free(aloc_url);
}

