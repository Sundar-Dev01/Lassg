#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t process_id = fork();

    if (process_id == 0)
    {
        printf("Child process created.\n");
    }
    else if (process_id > 0)
    {
        printf("Parent process running.\n");
    }
    else
    {
        perror("fork");
        return 1;
    }

    return 0;
}
