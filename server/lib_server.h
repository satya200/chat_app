#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include "lib_server_err.h"

typedef short int uint_16;

typedef enum socket_type
{
    TCP = 0,
    UDP
}socket_type_t;

typedef enum socket_domain
{
    IPV4 = 0,
    IPV6,
    LOCAL
}socket_domain_t;

int iCreate_socket(socket_type_t type, socket_domain_t domain);
int iBind_socket(int sock_fd, uint_16 port, socket_domain_t domain);
int iListen_socket(int sock_fd, int no);
int iAccept_socket(int sock_fd, char *ip, uint_16 *port);
