#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t process_id = fork();

    if (process_id == 0)
    {
        printf("Child fork return value: %ld\n", (long)process_id);
    }
    else if (process_id > 0)
    {
        printf("Parent fork return value: %ld\n", (long)process_id);
    }
    else
    {
        perror("fork");
        return 1;
    }

    return 0;
}
