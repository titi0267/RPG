/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** audios
*/

#include "../../../include/func_name.h"

void create_boom(menu_t *menu)
{
    menu->intro->intro_snd->create_start =
    sfSoundBuffer_createFromFile("assets/audios/start.ogg");
    menu->intro->intro_snd->start = sfSound_create();
    sfSound_setBuffer(menu->intro->intro_snd->start, menu->intro->intro_snd->create_start);
    menu->menu_snd->create_a_menu =
    sfSoundBuffer_createFromFile("assets/audios/menu.ogg");
    menu->menu_snd->a_menu = sfSound_create();
    sfSound_setBuffer(menu->menu_snd->a_menu, menu->menu_snd->create_a_menu);
    sfSound_setLoop(menu->menu_snd->a_menu, sfTrue);
}