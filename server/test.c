#include "lib_server.h"

int main()
{
    int ret = -1;
    int sock_fd = -1;
    uint_16 port = 2001;
    char ip[16] = {0};
    fd_set rdset;

    sock_fd = iCreate_socket(TCP, IPV4);
    if (sock_fd <= 0) {
        printf("Err: in create_socket\n");
        return sock_fd;
    } else {
        printf("Socket create success:%d\n",sock_fd);
    }
    ret = iBind_socket(sock_fd, port, IPV4);
    if (ret < 0) {
        printf("Bind error\n");
        close(sock_fd);
        return 0;
    } else {
        printf("Bind success\n");
    }

    ret = iListen_socket(sock_fd, 5);
    if (ret < 0) {
        printf("listen error\n");
        return ret;
    } else {
        printf("listen success\n");
    }

    FD_ZERO(&rd_set);
    FD_SET(sock_fd, rd_set);
    //select();
    port = 0;
    ret = iAccept_socket(sock_fd, ip, &port);
    if (ret < 0) {
        printf("iaccept err\n");
        close(sock_fd);
        return 0;
    } else {
        printf("accept success:client_fd:%d\n",ret);
    }
    return 0;
}
