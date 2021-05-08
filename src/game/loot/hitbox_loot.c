/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** hitbox_loot
*/

#include "../../../include/func_name.h"

void weapon_hitbox(rpg_t *rpg)
{
    printf("%f || %f\n", rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x,
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y);
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x <=
    -784 && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x >= -860
    && rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y <= -2844 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y >= -2920) {
        rpg->game->in_game->stuff->stuff_status[GUN] = TRUE;
    }
    if (rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x <=
    -1105 && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x >= -1181
    && rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y <= -1475 &&
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y >= -1551) {
        rpg->game->in_game->stuff->stuff_status[KNIFE] = TRUE;
    }
}

void vest_hitbox(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_WARREN].x <=
    -1105 && rpg->game->in_game->map->pos_map[MAP_WARREN].x >= -1181
    && rpg->game->in_game->map->pos_map[MAP_WARREN].y <= -1475 &&
    rpg->game->in_game->map->pos_map[MAP_WARREN].y >= -1551) {
        rpg->game->in_game->stuff->stuff_status[BPVEST] = TRUE;
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[BPVEST],
        rpg->game->in_game->inventory->pos_weapon[BPVEST]);
    }
}