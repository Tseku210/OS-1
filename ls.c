#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void _ls(const char *dir)
{
    struct dirent *d;
    DIR *dh = opendir(dir);
    if (!dh)
    {
        if (errno == ENOENT)
        {
            perror("Directory baihgui");
        }
        else
        {
            perror("Directory unshigdahgui");
        }
        exit(EXIT_FAILURE);
    }
    while ((d = readdir(dh)) != NULL)
    {
        if (d->d_name[0] == '.')
            continue;
        printf("%s\n", d->d_name);
    }
    printf("\n");
}

void _create(const char file[])
{
    FILE *fp;
    fp = fopen(file, "a+");
    fclose(fp);
}

void _write(char file_name[], char input[])
{
    FILE *fp;
    fp = fopen(file_name, "a+");
    fputs(input, fp);
    fclose(fp);
}

int main(int argc, const char *argv[])
{
    char cmd[20];
    // fgets(cmd, 10, stdin);
    int running = 1;
    while (running)
    {
        printf("\nCommand: ");
        scanf("%s", cmd);
        if (strcmp(cmd, "dir") == 0)
        {
            _ls(".");
        }
        else if (strcmp(cmd, "create") == 0)
        {
            char file_name[20];
            printf("\nGive file name: ");
            scanf("%s", file_name);
            _create(file_name);
        }
        else if (strcmp(cmd, "input") == 0)
        {
            char file_name[20], input[100];
            printf("\nSelect which file to change: ");
            scanf("%s", file_name);
            printf("\nGive input: ");
            // fgets(input, 100, stdin);
            scanf(" %50[^\n]", input);
            printf("%s", input);
            _write(file_name, input);
        }
        else if (strcmp(cmd, "rename") == 0)
        {
            char new_name[20], old_name[20];
            printf("\nWhich file to rename: ");
            scanf("%s", old_name);
            printf("\nInput new name: ");
            scanf("%s", new_name);
            int result = rename(old_name, new_name);
            if (result == 0)
            {
                printf("\nAmjilttai");
            }
            else
            {
                printf("\nAmjiltgui");
            }
        }
        else if (strcmp(cmd, "del") == 0)
        {
            char file_name[20];
            printf("\nWhich file to delete: ");
            scanf("%s", file_name);
            if (remove(file_name) == 0)
            {
                printf("Amjilttai");
            }
            else
            {
                printf("Amjiltgui");
            }
        }
        else if (strcmp(cmd, "cd") == 0)
        {
            char directory[20], s[100];
            printf("\nWhich directory: ");
            scanf("%s", directory);
            chdir(directory);
            printf("%s\n", getcwd(s, 100));
        }
        else if (strcmp(cmd, "exit") == 0)
        {
            return 0;
        }
        else
        {
            printf("Aldaatai");
        }
    }
    return 0;
}
