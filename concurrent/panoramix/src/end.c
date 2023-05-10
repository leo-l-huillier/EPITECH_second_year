/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** end.c
*/
#include <stdbool.h>
#include <stdio.h>

#include "../include/struct.h"

static bool is_evryone_sleeping(villager_t *villager)
{
    for (int i = 0; i < villager[0].pano->nb_villager; i++)
        if (!villager[i].sleeping)
            return false;
    return true;
}

bool is_finished(pano_t *pano, villager_t *villager)
{
    if (is_evryone_sleeping(villager))
        return true;
    for (int i = 0; i != pano->nb_villager; i++) {
        if (pano->nb_fight_left[i] > 0)
            return false;
    }
    return true;
}

void make_them_sleep(villager_t *villager)
{
    for (int i = 0; i != villager->pano->nb_villager; i++)
        printf("Villager %i: I’m going to sleep now.\n", villager[i].id);
}
