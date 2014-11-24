/*
 * data_exchange.h
 *
 *  Created on: Nov 23, 2014
 *      Author: ivan
 */

#ifndef DATA_EXCHANGE_H_
#define DATA_EXCHANGE_H_

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
//порт обращения
#define PORT 80
void data_exchange(char *url,const char * out_file,int verbose);

#endif /* DATA_EXCHANGE_H_ */
