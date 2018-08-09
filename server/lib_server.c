#include "lib_server.h"

int iCreate_socket(socket_type_t type, socket_domain_t domain)
{
    int iret = -1;

    socket_type_t eSock_type;
    socket_domain_t eSock_domain;

    if (type == TCP) {
        eSock_type = SOCK_STREAM;
    } else if (type == UDP) {
        eSock_type = SOCK_DGRAM;
    } else {
        printf("liberr:invalid socket type\n");
        return EINVALID_SOCK;
    }

    if (domain == IPV4) {
        eSock_domain = AF_INET;
        printf("Domain :ipv4\n");
    } else if (domain == IPV6) {
        eSock_domain = AF_INET6;
    } else if (domain == LOCAL) {
        eSock_domain = AF_UNIX;
    }else {
        printf("liberr:invalid socket domain\n");
        return EINVALID_DOMAIN;
    }
    iret = socket(eSock_domain, eSock_type, 0);
    perror("lib socket");
    if (iret <= 0) {
        perror("socket");
    } else {
        printf("lib:socket create success:%d\n",iret);
        return iret;
    }
    return iret;
}

int iBind_socket(int sock_fd, uint_16 port, socket_domain_t domain)
{
    int iret = -1;
    socket_domain_t eSock_domain;
    socklen_t len;
    struct sockaddr_in serv_addr;

    if (sock_fd <= 0 || port <= 1024) {
        printf("liberr:Invalid argument\n");
        return EINVALID_ARG_BIND;
    }

    if (domain == IPV4) {
        eSock_domain = AF_INET;
        printf("Domain1 :ipv4\n");
    } else if (domain == IPV6) {
        eSock_domain = AF_INET6;
    } else if (domain == LOCAL) {
        eSock_domain = AF_UNIX;
    }else {
        printf("liberr:invalid bind socket domain\n");
        return EINVALID_DOMAIN;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = eSock_domain;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    len = sizeof(serv_addr);
    iret = bind(sock_fd, (const struct sockaddr *)&serv_addr, len);
    if (iret < 0) {
        perror("liberr:bind");
        printf("sock_fd:%d\n",sock_fd);
        return iret;
    } else {
        printf("lib:bind success\n");
    }
    return iret;
}

int iListen_socket(int sock_fd, int no)
{
    int iret = -1;

    if (sock_fd <= 0 || no <= 0) {
        printf("liberr:Invalid listen argument");
        return EINVALID_ARG_LISTEN;
    }

    iret = listen(sock_fd, no);
    if (iret < 0) {
        perror("lib_listen");
        return iret;
    } else {
        printf("lib:listen success\n");
    }
    return iret;
}

int iAccept_socket(int sock_fd, char *ip, uint_16 *port)
{
    int iret = -1;
    socklen_t len;
    struct sockaddr_in serv_addr;

    if (sock_fd <= 0 || ip == NULL || port == NULL) {
        printf("liberr:Invalid argument\n");
        return EINVALID_ARG_ACCEPT;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    len = sizeof(serv_addr);
    iret = accept(sock_fd, (struct sockaddr *)&serv_addr, &len);
    if (iret < 0) {
        perror("liberr:accept");
        printf("after accept sock_fd:%d:%d\n",sock_fd,iret);
        return iret;
    } else {
        printf("lib:accept success\n");
    }
    return iret;
}
