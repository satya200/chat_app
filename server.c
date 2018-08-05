#include "server.h"

SERVER_PACK file_pack;

int main(int argc, char **argv)
{
    int sock_fd = 0,
        ret     = 0,
        client_fd = 0;
    
    char wrbuff[10] = "Hello\n";

    socklen_t len;

    if (argc < 2) {
        printf("In sufficient argument.Ex:- a.out <port no>\n");
        return -1;
    }
    struct sockaddr_in server_addr,client_addr;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(-1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    
    len = sizeof(server_addr);
    ret = bind(sock_fd, (const struct sockaddr *)&server_addr, len);
    if (ret < 0) {
        perror("bind");
        close(sock_fd);
        exit(-1);
    }

    ret = listen(sock_fd, 5);
    if (ret < 0) {
        perror("listen");
        close(sock_fd);
        exit(-1);
    }
    
    printf("Waiting for client request ....\n");
    len = sizeof(client_addr);
    client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &len);
    if (client_fd < 0) {
        perror("accept");
        close(sock_fd);
        exit(-1);
    } else {
        printf("client req accepted\n");
        send(client_fd, wrbuff, strlen(wrbuff), 0);
        perror("send");
        bzero(wrbuff, sizeof(wrbuff));
        recv(client_fd, wrbuff, sizeof(wrbuff), 0);
        perror("recv");
        printf("reading from client:%s\n",wrbuff);
    }

    close(client_fd);
    close(sock_fd);
    return 0;
}
