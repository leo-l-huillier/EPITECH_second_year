/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** druid.c
*/
#include <pthread.h>
#include <stdio.h>

#include "../include/struct.h"
#include "../include/end.h"

void *create_druid(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
    return NULL;
}

void *no_more_refill(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}

//ici changer villager pour pano
void *druid(void *arg)
{
    villager_t *villager = (villager_t *)arg;
    while (villager->pano->refill_left > 0 ||
        is_finished(villager->pano, villager)) {
        sem_wait(&villager->pano->sem_druid);
        if (is_finished(villager->pano, villager))
            break;
        pthread_mutex_lock(&villager->mutex->mutex_druid);
        if (villager->pano->serving_left == 0) {
            printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware");
            printf(" I can only make %i more refills after this one.\n",
                villager->pano->refill_left - 1);
            villager->pano->serving_left = villager->pano->pot_size;
            villager->pano->refill_left--;
        }
        pthread_mutex_unlock(&villager->mutex->mutex_druid);
        sem_post(&villager->pano->sem_villager);
    }
    if (villager->pano->refill_left <= 0)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
