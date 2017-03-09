#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
/* Print the contents of the home page for the server’s socket.
 * Return an indication of success. */
void get_home_page (int socket_fd, char* moudle_name)
{
    char buffer[10000];
    ssize_t number_characters_read;
    /* Send the HTTP GET command for the home page. */
    sprintf (buffer, "GET /%s HTTP/1.1\n\r\n\r\n", moudle_name);
    write (socket_fd, buffer, strlen (buffer));
    /* Read from the socket. The call to read may not
     * return all the data at one time, so keep
     * trying until we run out. */
    while (1) {
        number_characters_read = read (socket_fd, buffer, sizeof(buffer));
        if (number_characters_read == 0)
            return;
        /* Write the data to standard output. */
        fwrite (buffer, sizeof (char), number_characters_read, stdout);
    }
}

int main (int argc, char* const argv[])
{
    int socket_fd;
    struct sockaddr_in name;
    struct hostent* hostinfo;
    char* address = argv[1];
    int port = atoi(argv[2]);
    char *moudle_name = argv[3];
    /* Create the socket. */
    socket_fd = socket (AF_INET, SOCK_STREAM, 0);
    /* Store the server’s name in the socket address. */
    name.sin_family = AF_INET;
    /* Convert from strings to numbers. */
    hostinfo = gethostbyname (address);
    if (hostinfo == NULL)
        return 1;
    else
        name.sin_addr = *((struct in_addr *) hostinfo->h_addr);
    /* Web servers use port 80. */
    name.sin_port = htons (port);
    /* Connect to the Web server */
    if (connect (socket_fd, (struct sockaddr *) &name, sizeof (struct sockaddr_in)) == -1) {
        perror ("connect");
        return 1;
    }
    /* Retrieve the server’s home page. */
    get_home_page (socket_fd, moudle_name);
    return 0;
}
