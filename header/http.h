#ifndef HTTP_H
#define HTTP_H
#include <arpa/inet.h>
#include <fcntl.h>
#include <limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BACK_LOG 4
#define PROTOCOL 0
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PORT 8089

/** request_t - Request structure sent by client
	 * @methode: Methode used by client
	 * @file_name: File requested by the client
*/

typedef struct request_t {
  char methode[256];
  char file_name[256];
} request_t;

/**
	 * response_t - struct for HTTP response from the server
	 * @status_code: Code returned from server to request
	 * @content_length: length of HTML file returned to client
	 * @body: Content of HTML file
*/
typedef struct response_t {
  int status_code;
  unsigned int content_length;
  char body[BUFFER_SIZE];
} response_t;

/* Prints erorrs and exits with EXIT_FAILURE */
void fetch_request(char *buffer);
int init_socket(struct sockaddr_in *address);

#endif
