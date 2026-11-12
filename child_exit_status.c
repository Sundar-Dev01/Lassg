#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t process_id;
    int status;

    process_id = fork();

    if (process_id == 0)
    {
        printf("Child process executing.\n");
        exit(5);
    }
    else if (process_id > 0)
    {
        if (wait(&status) == -1)
        {
            perror("wait");
            return 1;
        }

        if (WIFEXITED(status))
        {
            printf("Child terminated normally.\n");
            printf("Child exit status: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Child terminated abnormally.\n");
        }
    }
    else
    {
        perror("fork");
        return 1;
    }

    return 0;
}
