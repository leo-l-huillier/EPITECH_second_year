/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** villager.c
*/
#include <pthread.h>
#include <stdio.h>

#include "../include/struct.h"
#include "../include/druid.h"
#include "../include/end.h"

void *create_villager(void *arg)
{
    int villager_id = *(int *)arg;
    printf("Villager %d: Going into battle!\n", villager_id);
    return NULL;
}

static void *roman_scum(villager_t *villager)
{
    printf("Villager %i: Take that roman scum! Only %i left.\n",
        villager->id, villager->pano->nb_fight_left[villager->id] - 1);
    villager->pano->nb_fight_left[villager->id]--;
    villager->pano->serving_left--;
    if (villager->pano->nb_fight_left[villager->id] == 0)
        villager->sleeping = true;
    pthread_mutex_unlock(&villager->mutex->mutex_villager);
    return NULL;
}

static bool is_going_to_sleep(villager_t *villager)
{
    if (villager->pano->serving_left <= 0 &&
        villager->pano->refill_left <= 0) {
        villager->sleeping = true;
        return true;
    }
    return false;
}

void *attack(void *arg)
{
    villager_t *villager = (villager_t *)arg;
    while (villager->sleeping == false) {
        pthread_mutex_lock(&villager->mutex->mutex_villager);
        printf("Villager %d: I need a drink... I see %d servings left.\n",
            villager->id, villager->pano->serving_left);
        if (villager->pano->serving_left <= 0) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
                villager->id);
            sem_post(&villager->pano->sem_druid);
            sem_wait(&villager->pano->sem_villager);
        }
        if (is_going_to_sleep(villager))
            return NULL;
        roman_scum(villager);
    }
    if (is_finished(villager->pano, villager) == true)
        sem_post(&villager->pano->sem_druid);
    return NULL;
}
