#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define BUFF_SIZE 64
#define DATA_BUFF_SIZE 1024

typedef struct 
{
    char name_file[BUFF_SIZE];
    unsigned int size_file;
    char data[DATA_BUFF_SIZE];
}SERVER_PACK;
