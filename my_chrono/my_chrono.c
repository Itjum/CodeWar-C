#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int stop = 1;

void handler(int signum)
{
    if (signum == SIGALRM)
    {
        printf("End of chrono!\n");
        stop = 0;
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    if (sigemptyset(&sa.sa_mask) == -1)
    {
        return 1;
    }
    if (sigaction(SIGALRM, &sa, NULL) == -1)
    {
        return 1;
    }
    if (argc != 2)
    {
        printf("Usage: ./my_chrono <time>\n");
        return 1;
    }
    else if (argv[1][0] == '0')
    {
        stop = 0;
    }
    int timer = atoi(argv[1]);
    alarm(timer);
    while (stop)
        continue;
    return 0;
}
