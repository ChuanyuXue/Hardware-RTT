#include "utils.h"

int main(int argc, char *argv[])
{
    const char *address = "192.168.0.22";
    const int port = 54321;

    int fd_in = socket(AF_INET, SOCK_DGRAM, 0);
    int fd_out = socket(AF_INET, SOCK_DGRAM, 0);

    setup_adapter(fd_in, "eth0");
    setup_adapter(fd_out, "eth0");

    setup_sender(fd_out);
    setup_receiver(fd_in, port);

    int count = 0;
    while (1)
    {
        printf("[ ---- Iter-%5d ----------------------------- ]\n", count++);
        recv_single(fd_in);
        usleep(10000);
        send_single(fd_out, (char *)address, port);
    }
}