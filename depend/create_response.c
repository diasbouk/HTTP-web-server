#include "../include/http.h"
#include "../include/strings.h"

char *create_response(request_t *req) {
	char *response, *status, *content, *header, fname[30] = {0};
	int size;

	if (!strcmp(req->route, "/"))
		strcpy(fname, "data/index.html");
	else {
		strcpy(fname, "data");
		strcat(fname, req->route);
	}
	content = file_read(fname);
	if (!content) {
		header = "HTTP/1.1 404 NOT FOUND\r\n";
		content = file_read("data/not-found.html");
	}
	else
		header = "HTTP/1.1 200 OK\r\n";
	status = "Content-Type: text/html\r\n\r\n";
	size = ft_strlen(header) + ft_strlen(status) + ft_strlen(content);
	response = malloc(sizeof(char) * (size + 1));
	if (!response)
		return (NULL);
	ft_bzero(response, size);
	strcpy(response, header);
	strcat(response, status);
	strcat(response, content);
	free(content);
	return (response);
}
