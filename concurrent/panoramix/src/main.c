/*
** EPITECH PROJECT, 2023
** base_cpp_project
** File description:
** main.c
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/struct.h"
#include "../include/panoramix.h"

static void help(void)
{
    printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> ");
    printf("<nb_refills>\nValues must be >0\n");
}

static int error_handling(int argc, char **argv)
{
    if (argc != 5 || atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 ||
        atoi(argv[3]) <= 0 || atoi(argv[4]) <= 0) {
        help();
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == EXIT_ERROR)
        return EXIT_ERROR;
    villager_t *villager = init_struct_villager(argv);
    panoramix(villager);
    return 0;
}
