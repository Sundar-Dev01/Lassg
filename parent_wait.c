#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t process_id = fork();

    if (process_id == 0)
    {
        printf("Child process executing.\n");
    }
    else if (process_id > 0)
    {
        if (wait(NULL) == -1)
        {
            perror("wait");
            return 1;
        }

        printf("Parent resumed after child termination.\n");
    }
    else
    {
        perror("fork");
        return 1;
    }

    return 0;
}
