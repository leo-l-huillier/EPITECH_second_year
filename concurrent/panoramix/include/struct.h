/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** struct.h
*/
#ifndef PANORAMIX_STRUCT_H
    #define PANORAMIX_STRUCT_H

    #include <pthread.h>
    #include <stdbool.h>
    #include <semaphore.h>

    #define EXIT_SUCCESS 0
    #define EXIT_ERROR 84

typedef struct panoramix_s {
    int nb_villager;
    int pot_size;
    int serving_left;
    int nb_fight;
    int *nb_fight_left;
    int refill_left;
    pthread_t thread_druid;
    pthread_t *thread_villager;
    sem_t sem_druid;
    sem_t sem_villager;
} pano_t;

typedef struct mutex_s {        /* Country mutex structure */
    pthread_mutex_t mutex_druid;
    pthread_mutex_t mutex_villager;
} mutex_t;

typedef struct villager_s {
    int id;
    pano_t *pano;
    mutex_t *mutex;
    bool sleeping;
} villager_t;

villager_t *init_struct_villager(char **argv);
void free_struct(villager_t *villager);

#endif
