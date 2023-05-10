/*
** EPITECH PROJECT, 2021
** palindrome
** File description:
** tester.c
*/
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define RED "\x1B[1;31m"
#define GREEN "\x1b[1;32m"
#define RESET "\x1b[0m"

char *open_and_read(char const *filepath)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);
    int ret = stat(filepath, &sb);
    int buff_size = sb.st_size;
    char *buff = malloc(sizeof(char *) * buff_size);;

    if (ret == -1)
        return (NULL);
    read(fd, buff, buff_size);
    buff[buff_size - 1] = '\0';
    close(fd);
    return (buff);
}

int main(int argc, char **argv)
{
    char *str1 = open_and_read(argv[1]);
    char *str2 = open_and_read(argv[2]);
    if (strcmp(str1, str2) == 0) {
        printf(GREEN "test :    %s         succeed\n", argv[3]);
        printf(RESET);
        return 0;
    }
    printf(RED "test :    %s          failed\n", argv[3]);
    printf(RESET);
    printf("expected : \n%s\n", str2);
    printf("but got : \n%s\n", str1);
    return 1;
}