/*
** EPITECH PROJECT, 2021
** police map inside
** File description:
** inside_police_station.c
*/

#include "../../../include/func_name.h"

void police_texture_map(rpg_t *rpg)
{
    sfTexture *in_police = sfTexture_createFromFile
    ("assets/maps/real/police_int.png", NULL);
    sfTexture *in_police_col = sfTexture_createFromFile
    ("assets/maps/colisions/police_int.png", NULL);
    sfTexture *out_police_col = sfTexture_createFromFile
    ("assets/maps/colisions/police_ext.png", NULL);
    sfTexture *out_police = sfTexture_createFromFile
    ("assets/maps/real/police_ext.png", NULL);

    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_INSIDE_POLICE],
    in_police, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_OUTSIDE_POLICE],
    out_police, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->map->collisions[MAP_INSIDE_POLICE],
    in_police_col, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->map->collisions[MAP_OUTSIDE_POLICE],
    out_police_col, sfTrue);
}

void give_police_pos_map(rpg_t *rpg)
{
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE] =
    put_in_vector2f(-1300, -300);
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE] =
    put_in_vector2f(500, 500);
    sfSprite_setPosition(rpg->game->in_game->map->maps[MAP_INSIDE_POLICE],
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE]);
    sfSprite_setPosition(rpg->game->in_game->map->collisions[MAP_INSIDE_POLICE],
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE]);
    sfSprite_setPosition(rpg->game->in_game->map->maps[MAP_OUTSIDE_POLICE],
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE]);
    sfSprite_setPosition
    (rpg->game->in_game->map->collisions[MAP_OUTSIDE_POLICE],
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE]);
}

int create_police_map(rpg_t *rpg)
{
    int map_nbr = 3;

    if ((rpg->game->in_game->map->maps = malloc(sizeof(sfSprite *) * map_nbr))
    == NULL || (rpg->game->in_game->map->collisions = malloc(sizeof(sfSprite *)
    * map_nbr)) == NULL || (rpg->game->in_game->map->pos_map =
    malloc(sizeof(sfVector2f) * map_nbr)) == NULL)
        return (MALLOC_ERROR);
    for (int i = MAP_INSIDE_POLICE; i != NO_MAP; i++) {
        rpg->game->in_game->map->maps[i] = sfSprite_create();
        rpg->game->in_game->map->collisions[i] = sfSprite_create();
    }
    police_texture_map(rpg);
    give_police_pos_map(rpg);
    return (0);
}