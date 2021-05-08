/*
** EPITECH PROJECT, 2021
** chose map
** File description:
** map_status.c
*/

#include "../../../include/func_name.h"

void destroy_enemies(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    for (; rpg->game->in_game->nmi_list != NULL;
    rpg->game->in_game->nmi_list = rpg->game->in_game->nmi_list->next) {
        sfSprite_destroy(rpg->game->in_game->nmi_list->yellow_man);
        free(rpg->game->in_game->nmi_list->nmi_rect);
        free(rpg->game->in_game->nmi_list->offset_nmi);
        free(rpg->game->in_game->nmi_list);
    }
    *(rpg->game->in_game->nmi) = NULL;
}

void print_map(rpg_t *rpg, int on_map)
{
    int map_status = rpg->game->in_game->map->status;

    if (rpg->menu->status == ON_GAME &&
    !on_cine(rpg)) {
        player_run(rpg);
        move_left_map(rpg, on_map, rpg->game->in_game->objects,
        rpg->game->in_game->map);
    }
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    if (rpg->game->in_game->map->status != MAP_INSIDE_POLICE &&
    rpg->game->in_game->map->status != MAP_INSIDE_CDC)
        move_enemies(rpg);
    if (map_status != rpg->game->in_game->map->status &&
    rpg->game->in_game->map->status != MAP_INSIDE_POLICE &&
    map_status != MAP_INSIDE_POLICE)
        destroy_enemies(rpg);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->car->car, NULL);
    printf("Draw car\n");
    print_player_move(rpg);
    collision_enemy_bullet(rpg);
}

void chose_map(rpg_t *rpg)
{
    print_map(rpg, rpg->game->in_game->map->status);
    if (rpg->game->in_game->map->status == MAP_INSIDE_POLICE) {
        sfSprite_setPosition(rpg->game->in_game->objects->policemen,
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x
        + 2457, rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y + 1347));
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->objects->policemen, NULL);
    }
    if (rpg->game->in_game->map->status == MAP_WARREN) {
        sfSprite_setPosition(rpg->game->in_game->objects->warren,
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_WARREN].x
        + 1315, rpg->game->in_game->map->pos_map[MAP_WARREN].y + 3210));
        sfSprite_setTextureRect(rpg->game->in_game->objects->warren,
        rpg->game->in_game->objects->rect_warren);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->objects->warren, NULL);
    }
}