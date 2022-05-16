/*
** EPITECH PROJECT, 2022
** defender.h
** File description:
** header for my_defender with prototypes
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#ifndef DEFENDER_H_
    #define DEFENDER_H_

typedef enum {
    quit,
    paused,
    play,
    back,
    closed,
    help,
    card,
    tesla,
    tac_shooter,
    radius_up,
    upgrade
} btnType;

typedef enum {
    easy,
    medium,
    hard
} gamemode;

typedef enum {
    up,
    down,
    left,
    right
} direction;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *map_texture;
    sfSprite *map_sprite;
    sfVector2f pos;
    int is_hover;
    int is_pressed;
    int nb_cases;
} map_case;

typedef struct {
    btnType button_type;
    sfTexture *texture;
    sfTexture *hovered_texture;
    sfTexture *pressed_texture;
    sfSprite *sprite;
    sfSprite *hovered_sprite;
    sfSprite *pressed_sprite;
    sfText *text;
    sfVector2f pos;
    int resize;
    int is_hover;
    int is_pressed;
    int nb_buttons;
    int card_price;
    int width;
    int height;
} buttons;

typedef struct {
    int id;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *attack_texture;
    sfSprite *attack_sprite;
    sfIntRect attack_rect;
    sfVector2f pos;
    sfVector2f offset;
    buttons button;
    buttons *upgrade_buttons;
    sfClock *cooldown;
    sfClock *attack;
    float angle;
    int *upgrade_prices;
    int *radius_up_prices;
    int resize;
    int price;
    int nb_towers;
    int rad;
    int level;
    int rad_level;
    int is_shooting;
    int damage;
    float cool_time;
} tower;

typedef struct {
    sfVector2f pos;
    sfVector2f boss_pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *gb_texture;
    sfSprite *gb_sprite;
    sfTexture *blue_moab_texture;
    sfSprite *blue_moab_sprite;
    sfTexture *red_moab_texture;
    sfSprite *red_moab_sprite;
    sfIntRect rect;
    sfCircleShape *hitbox;
    sfClock *death_clock;
    int is_boss;
    int map_id;
    int nb_bloons;
    int is_pop;
    int speed;
    int life;
    direction direction;
    int nb_moves;
} bloon;

typedef struct {
    sfTexture *map_texture;
    sfSprite *map_sprite;
    sfTexture *sidebar_texture;
    sfSprite *sidebar_sprite;
    sfTexture *pause_texture;
    sfSprite *pause_sprite;
    sfTexture *gold_texture;
    sfSprite *gold_sprite;
    sfTexture *upgrade_texture;
    sfSprite *upgrade_sprite;
    sfTexture *up_gold_texture;
    sfSprite *up_gold_sprite;
    sfTexture *first_up_gold_texture;
    sfSprite *first_up_gold_sprite;
    sfTexture *heart_texture;
    sfSprite *heart_sprite;
    sfTexture *play_texture;
    sfSprite *play_sprite;
    sfTexture *win_texture;
    sfSprite *win_sprite;
    sfTexture *lose_texture;
    sfSprite *lose_sprite;
    gamemode mode;
    buttons *buttons;
    buttons *pause_buttons;
    buttons *upgrade_buttons;
    buttons *win_buttons;
    buttons *lose_buttons;
    buttons *cards;
    tower *towers;
    bloon *bloons;
    sfMusic *win;
    sfMusic *lose;
    int tower_to_upgrade;
    int card_id;
    int money;
    int map;
    int lives;
    int rounds;
    int last_round;
    int is_infinite;
    int current_round;
} game;

typedef struct {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
    sfFont *btd_font;
    sfFont *cr_font;
    buttons *menu_buttons;
    buttons *play_menu_buttons;
    buttons *dif_menu_buttons;
    map_case *map_case;
    game *game;
    sfMusic *bg_music;
    int is_play_menu;
    int is_main_menu;
    int is_info_menu;
    int map_choice;
    int is_dif_choice;
    int is_in_game;
    int is_pause;
    int is_win;
    int is_lose;
    int is_exit;
    int is_init_game;
    int is_upgrade;
    int did_game;
} defender;

void my_defender(void);

sfRenderWindow *window_create(int x, int y, int framerate);

void destroy_struct(defender *objects);

void analyse_events(defender *objects);

void display_main_menu(defender *objects);

void init_buttons(defender *objects);

void display_buttons(sfRenderWindow *win, buttons *buttons);

void create_exit_button(buttons *buttons, sfVector2f pos, float resize, int i);

void create_back_button(buttons *buttons, sfVector2f pos, float resize, int i);

void create_close_button(buttons *buttons, sfVector2f pos, float resize, int i);

void create_info_button(buttons *buttons, sfVector2f pos, float resize, int i);

void create_play_button(buttons *buttons, sfVector2f pos, float resize, int i);

int is_button_hovered(buttons button, sfRenderWindow *win,
int width, int height);

int is_button_pressed(buttons button, defender *objects,
int width, int height);

void create_sprite(buttons *buttons, int i,
sfVector2f scale, char *texture_path);

void create_hovered_sprite(buttons *buttons, int i,
sfVector2f scale, char *texture_path);

void create_pressed_sprite(buttons *buttons, int i,
sfVector2f scale, char *texture_path);

void display_play_menu(defender *objects);

void display_background(sfRenderWindow *win, char *background);

void detect_pmenu_button_hovering(defender *objects);

void detect_pmenu_button_pressing(defender *objects);

void detect_menu_button_hovering(defender *objects);

void detect_menu_button_pressing(defender *objects);

void create_case(map_case *map_case, int i, sfVector2f pos, char *map);

int is_case_hovered(map_case map_case, sfRenderWindow *win,
int width, int height);

int is_case_pressed(map_case map_case, defender *objects,
int width, int height);

void detect_pmenu_case_hovering(defender *objects);

void display_info_menu(defender *objects);

void detect_imenu_button_pressing(defender *objects);

void display_difficulty_menu(defender *objects);

void detect_cmenu_button_hovering(defender *objects);

void detect_cmenu_button_pressing(defender *objects);

void create_easy_button(buttons *buttons, sfVector2f pos, float resize, int i);

void create_inter_button(buttons *buttons, sfVector2f pos, float resize, int i);

void create_hard_button(buttons *buttons, sfVector2f pos, float resize, int i);

void detect_pmenu_case_pressing(defender *objects);

void detect_hard_dif_choice(defender *objects);

void detect_difficulty_choice(defender *objects);

void detect_difficulty_hover(defender *objects);

void make_transition(defender *objects);

void display_vgame(defender *objects);

void init_game(defender *objects);

void create_settings_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void detect_game_button_hovering(defender *objects);

void detect_game_button_pressing(defender *objects);

void create_home_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void detect_pause_button_hovering(defender *objects);

void detect_pause_button_pressing(defender *objects);

void init_cards(buttons *cards);

void create_tesla_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void detect_game_card_hovering(defender *objects);

void detect_game_card_pressing(defender *objects);

void place_tower(defender *objects);

void create_tesla(sfRenderWindow *win, game *game, int index);

void create_price(buttons *buttons, int index, int price,
sfVector2f pos);

void display_prices(defender *objects, sfFont *font);

void init_map(defender *objects);

void display_rounds(sfRenderWindow *win, game *game, defender *objects);

int verify_tower_placing_first(defender *objects);

int is_touching_illegal_item(defender *objects);

void display_radius(defender *objects, int rad);

void create_rect(game *game, int index, int width, int height);

void init_upgrade_menu(game *game);

void display_upgrade_menu(defender *objects);

void create_inv_button(buttons *button, sfVector2f pos, int width,
int height);

void detect_tower_pressing(tower *towers, defender *objects);

void display_tower_radius(defender *objects, int rad, tower tower);

void init_upgrade_button(game *game);

void detect_upgrade_button_hovering(defender *objects);

void detect_upgrade_button_pressing(defender *objects);

void init_upgrade_gold(game *game);

void display_radius_upgrade_prices(defender *objects, tower tower);

void display_radius_upgrade_text(int level, sfRenderWindow *win,
sfFont *font);

void create_tac_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void display_tesla(defender *objects);

void display_tac(defender *objects);

void create_tac(sfRenderWindow *win, game *game, int index);

void upgrade_handling(defender *objects, tower *towers, int i, int j);

void set_text(sfText *text, sfVector2f pos);

int verify_tower_placing_secondm(sfVector2i mouse);

void init_difficulty_params(game *game);

void init_heart_sprite(game *game);

void display_lives(sfRenderWindow *win, game *game, sfFont *font);

void create_red_bloon(bloon *bloons, int index, int x, int y);

void init_bloons(game *game, int size);

void create_play_round_button(buttons *buttons, sfVector2f pos,
float resize, int i);

void init_first_round(game *game);

void display_bloons(defender *objects);

void detect_first_map_turn(game *game, bloon *bloons, int index);

void create_green_bloon(bloon *bloons, int index, int x, int y);

void create_yellow_bloon(bloon *bloons, int index, int x, int y);

void create_pink_bloon(bloon *bloons, int index, int x, int y);

int is_in_tower_radius(bloon bloon, tower tower);

void tower_shoot_handling(defender *objects, bloon *bloons);

void init_tesla(game *game, int index, sfVector2f pos);

void init_tac(game *game, int index, sfVector2f pos);

void create_tesla_attack_sprite(tower *towers, int i);

void init_shoot_angle(bloon bloon, tower *towers, int i, sfVector2f v);

void move_tac_rect(sfRenderWindow *win, tower *towers, int i);

void handle_tac_shooting(defender *objects, int i, int did_shoot);

int is_round_over(game *game);

void handle_rounds(game *game);

void init_second_round(game *game);

void init_third_round(game *game);

void init_fourth_round(game *game);

void init_fifth_round(game *game);

void init_six_round(game *game);

void init_seven_round(game *game);

void init_eight_round(game *game);

void init_nine_round(game *game);

void init_ten_round(game *game);

void init_eleven_round(game *game);

void init_twelve_round(game *game);

void init_thirteen_round(game *game);

void init_fourteen_round(game *game);

void init_fifteen_round(game *game);

void init_sixteen_round(game *game);

void init_seventeen_round(game *game);

void init_eighteen_round(game *game);

void init_nineteen_round(game *game);

void init_twenty_round(game *game);

void init_twenty_o_round(game *game);

void init_twenty_to_round(game *game);

void init_twenty_te_round(game *game);

void init_twenty_fr_round(game *game);

void init_twenty_fv_round(game *game);

void create_tac_attack_sprite(tower *towers, int i);

void create_pink_bloon(bloon *bloons, int index, int x, int y);

void create_blue_bloon(bloon *bloons, int index, int x, int y);

void init_giant_balloon(bloon *bloons, int index, int x, int y);

void init_blue_moab(bloon *bloons, int index, int x, int y);

void init_red_moab(bloon *bloons, int index, int x, int y);

void move_bloons(defender *objects);

void display_money(sfRenderWindow *win, game *game, defender *objects);

void detect_game_end(defender *objects);

void init_end_menu(game *game);

void detect_lose_button_hovering(defender *objects);

void detect_lose_button_pressing(defender *objects);

void detect_win_button_hovering(defender *objects);

void detect_win_button_pressing(defender *objects);

void display_end_menu(defender *objects);

void do_shoot(defender *objects, bloon *bloons, int i, int j);

void shoot(sfRenderWindow *win, tower tower);

void detect_second_map_turn(game *game, bloon *bloons, int index);

void transfer_bloon_pos(game *game);

void detect_second_map_turn(game *game, bloon *bloons, int index);

void detect_even_more_second_map_turns(game *game,
bloon *bloons, int index);

void detect_fourth_map_turn(game *game, bloon *bloons, int index);

void create_black_bloon(bloon *bloons, int index, int x, int y);

void create_white_bloon(bloon *bloons, int index, int x, int y);

void create_purple_bloon(bloon *bloons, int index, int x, int y);

void create_zebra_bloon(bloon *bloons, int index, int x, int y);

void create_ceramic_bloon(bloon *bloons, int index, int x, int y);

void create_fortified_bloon(bloon *bloons, int index, int x, int y);

void create_sauda_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void create_sniper_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void detect_drop(defender *objects, int id, int price);

void display_sauda(defender *objects);

void display_sniper(defender *objects);

void init_tower_val(tower *towers, int index);

void init_sauda(game *game, int index, sfVector2f pos);

void init_sniper(game *game, int index, sfVector2f pos);

void create_sauda(sfRenderWindow *win, game *game, int index);

void create_sniper(sfRenderWindow *win, game *game, int index);

void create_upgrade_buttons(buttons *button);

void detect_sniper_shot(bloon *bloons, defender *objects, int j, int i);

void move_sauda_rect(tower *towers, int i);

void handle_sauda_shooting(defender *objects, int i);

void set_shoot_angle(bloon bloon, tower *towers, int i, int id);

void create_sniper_attack_sprite(tower *towers, int i);

void sniper_shoot_anim(defender *objects, tower tower);

void create_bg_music(defender *objects);

void create_freeplay_button(buttons *buttons, sfVector2f pos, float resize,
int i);

void init_freeplay_bloons(game *game, int round);

void init_effects(game *game);

void destroy_game(defender *objects);

#endif /* !DEFENDER_H_ */
