/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** struct.c
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/struct.h"
#include "../include/druid.h"

static pano_t *init_struct_pano(char **argv)
{
    pano_t *pano = malloc(sizeof(pano_t));
    pano->nb_villager = atoi(argv[1]);
    pano->pot_size = atoi(argv[2]);
    pano->serving_left = atoi(argv[2]);
    pano->nb_fight = atoi(argv[3]);
    pano->refill_left = atoi(argv[4]);
    pano->nb_fight_left = malloc(sizeof(int *) * pano->nb_villager);
    for (int i = 0; i != pano->nb_villager; i++) {
        pano->nb_fight_left[i] = pano->nb_fight;
    }
    pano->thread_villager = malloc(sizeof(pthread_t) * pano->nb_villager);
    sem_init(&pano->sem_druid, 0, 0);
    sem_init(&pano->sem_villager, 0, 0);
    return pano;
}

// y a un truc plus propre que le exit 84?
villager_t *init_struct_villager(char **argv)
{
    pano_t *pano = init_struct_pano(argv);
    mutex_t *mutex = malloc(sizeof(mutex_t));
    if (pthread_mutex_init(&mutex->mutex_druid, NULL) != 0) {
        printf("\n mutex init has failed\n");
        exit(EXIT_ERROR);
    }
    if (pthread_mutex_init(&mutex->mutex_villager, NULL) != 0) {
        printf("\n mutex init has failed\n");
        exit(EXIT_ERROR);
    }
    villager_t *villager = malloc(sizeof(villager_t) * pano->nb_villager);
    for (int i = 0; i < pano->nb_villager; i++) {
        villager[i].mutex = mutex;
        villager[i].pano = pano;
        villager[i].id = i;
        villager[i].sleeping = false;
    }
    return villager;
}

void free_struct(villager_t *villager)
{
    pthread_mutex_destroy(&villager[0].mutex->mutex_druid);
    pthread_mutex_destroy(&villager[0].mutex->mutex_villager);
    for (int i = 0; i != villager->pano->nb_villager; i++) {
        pthread_detach(villager->pano->thread_villager[i]);
    }
    pthread_detach(villager->pano->thread_druid);
    free(villager[0].mutex);
    free(villager[0].pano->thread_villager);
    free(villager[0].pano->nb_fight_left);
    free(villager[0].pano);
    free(villager);
}
