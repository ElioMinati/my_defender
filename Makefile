##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile for defender
##

SRC	=	src/main.c	\
		src/my_defender.c 	\
		src/window/window_create.c 	\
		src/window/events/analyse_events.c 	\
		src/window/events/main_menu_events.c 	\
		src/window/events/play_menu_events.c 	\
		src/window/events/info_menu_events.c 	\
		src/window/events/difficulty_menu_events.c 	\
		src/window/events/card_events.c 	\
		src/menus/main_menu.c 	\
		src/menus/play_menu.c 	\
		src/menus/info_menu.c 	\
		src/menus/difficulty_menu.c 	\
		src/object_handling/destroy_objects.c	\
		src/buttons/display_buttons.c 	\
		src/buttons/init_buttons.c	\
		src/buttons/create_button.c	\
		src/buttons/manage_buttons.c	\
		src/buttons/create_button_sprite.c	\
		src/buttons/create_case.c	\
		src/buttons/create_difficulty_buttons.c	\
		src/buttons/create_game_button.c	\
		src/buttons/create_tower_buttons.c	\
		src/game/init_game.c	\
		src/game/display_game.c	\
		src/game/game_events.c	\
		src/game/init_towers.c	\
		src/game/place_tower.c	\
		src/game/create_towers.c	\
		src/game/create_tower_prices.c	\
		src/game/price_display.c	\
		src/game/init_map.c	\
		src/game/verify_tower_placing.c 	\
		src/game/display_radius.c	\
		src/game/create_tower_rects.c 	\
		src/game/display_upgrades.c 	\
		src/game/tower_events.c	\
		src/game/display_drag_n_drop.c	\
		src/game/upgrade_handling.c	\
		src/game/display_lives.c	\
		src/game/init_balloons.c 	\
		src/game/init_advanced_balloons.c 	\
		src/game/init_game_info.c	\
		src/game/display_bloons.c	\
		src/game/detect_turns.c	\
		src/game/tower_shoot.c	\
		src/game/create_attack_sprites.c	\
		src/game/shoot_animation_handling.c	\
		src/game/round_handling.c	\
		src/game/init_boss.c 	\
		src/game/shoot.c 	\
		src/game/move_bloons.c 	\
		src/game/detect_game_end.c 	\
		src/game/display_end_menu.c 	\
		src/game/transfer_bloon_pos.c 	\
		src/game/detect_map_turns.c 	\
		src/game/init_hard_balloons.c 	\
		src/game/init_expert_balloons.c 	\
		src/game/drop.c 	\
		src/game/create_advanced_towers.c 	\
		src/game/init_advanced_towers.c 	\
		src/game/create_music.c 	\
		src/game/rounds/init_rounds.c	\
		src/game/rounds/init_five_to_ten_rounds.c	\
		src/game/rounds/init_ten_to_fifteen_rounds.c	\
		src/game/rounds/init_fifteen_to_twenty_rounds.c	\
		src/game/rounds/init_twenty_to_twenty_five_rounds.c	\
		src/game/rounds/init_freeplay_rounds.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-Llib/my/ -lmy -lm

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iinclude/

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CCRITERION	= 	--coverage -lcriterion

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY : all re clean tests_run fclean
