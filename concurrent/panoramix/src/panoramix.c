/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix.c
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/struct.h"
#include "../include/druid.h"
#include "../include/villager.h"
#include "../include/end.h"

static void create_druid_and_villager(villager_t *villager)
{
    for (int i = 0; i != villager[0].pano->nb_villager; i++) {
        pthread_create(&villager[0].pano->thread_villager[i], NULL,
            &create_villager, &i);
        pthread_join(villager[0].pano->thread_villager[i], NULL);
    }
}

static void attack_loop(villager_t *villager)
{
    for (int i = 0; i < villager[0].pano->nb_villager; i++)
        if (villager[i].sleeping == false) {
            pthread_create(&villager[0].pano->thread_villager[i],
                NULL, &attack, &villager[i]);
            pthread_join(villager[0].pano->thread_villager[i], NULL);
            continue;
        }
}

void panoramix(villager_t *villager)
{
    pthread_create(&villager[0].pano->thread_druid, NULL,
        &create_druid, &villager[0]);
    pthread_join(villager[0].pano->thread_druid, NULL);
    pthread_create(&villager[0].pano->thread_druid, NULL,
        &druid, &villager[0]);
    for (int i = 0; i < villager[0].pano->nb_villager; i++) {
        pthread_create(&villager[0].pano->thread_villager[i],
            NULL, &create_villager, &villager[i]);
    }
    for (int i = 0; i < villager[0].pano->nb_villager; i++)
        pthread_join(villager[0].pano->thread_villager[i], NULL);
    for (int i = 0; i < villager[0].pano->nb_villager; i++)
        pthread_create(&villager[0].pano->thread_villager[i],
            NULL, &attack, &villager[i]);
    pthread_join(villager[0].pano->thread_druid, NULL);
    for (int i = 0; i < villager[0].pano->nb_villager; i++)
        pthread_join(villager[0].pano->thread_villager[i], NULL);
    make_them_sleep(villager);
}
