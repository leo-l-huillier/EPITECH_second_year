/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** test_druid.c
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/druid.h"
#include "../../include/struct.h"
#include "tests/unit_tests/file.h"

Test(druid, create_druid_output)
{
    FILE *f = fopen("output.txt", "w");
    fflush(stdout);
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(f), fileno(stdout));

    create_druid(NULL);

    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    fclose(f);

    f = fopen("output.txt", "r");
    char expected_output[] = "Druid: I'm ready... but sleepy...\n";
    char actual_output[100];
    fgets(actual_output, 100, f);
    cr_assert_str_eq(expected_output, actual_output);

    fclose(f);
}

Test(druid, no_more_refill_output)
{
    FILE *f = fopen("output2.txt", "w");
    fflush(stdout);
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(f), fileno(stdout));

    no_more_refill(NULL);

    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    fclose(f);

    f = fopen("output2.txt", "r");
    char expected_output[] = "Druid: I'm out of viscum. I'm going back to... zZz\n";
    char actual_output[100];
    fgets(actual_output, 100, f);
    cr_assert_str_eq(expected_output, actual_output);

    fclose(f);
}

Test(druid, refill_pot_output)
{
    FILE *f = fopen("output2.txt", "w");
    fflush(stdout);
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(f), fileno(stdout));

    char **argv = create_argv();

    villager_t *villager = init_struct_villager(argv);
    //villager->mutex->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    refill_pot(villager);

    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    fclose(f);

    f = fopen("output2.txt", "r");
    char expected_output[] = "Druid: I'm out of viscum. I'm going back to... zZz\n";
    char actual_output[100];
    fgets(actual_output, 100, f);
    cr_assert_str_eq(expected_output, actual_output);

    fclose(f);
}