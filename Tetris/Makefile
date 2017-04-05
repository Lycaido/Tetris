##
## Makefile for bootstrap in /home/Rev/CSFML/bootstrap
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Thu Nov	10 12:12:07 2016 Roméo Nahon
## Last update	Thu Nov	10 12:12:07 2016 Roméo Nahon
##

SRC = 		get_tetri.c 			\
		get_tetri_next.c		\
		tetri_list.c			\
		tetri_error.c			\
		aff_list.c			\
		main.c				\
		help.c				\
		key.c				\
		parsing.c			\
		basic_opt_parsing.c		\
		opt_parsing.c			\
		tri_tetrimino.c			\
		rotation.c			\
		my_str_to_wordtab.c		\
		blink.c				\
		color.c				\
		draw_tetris_name.c		\
		joystick.c			\
		main_jeu.c			\
		manage_box.c			\
		tetri_in_game.c			\
		tetri_in_game_next.c		\
		tetri_move.c			\
		press.c				\
		destroy_line.c			\
		next_tetri.c			\
		get_next_line.c			\
		recup_score.c			\
		redimension_tetris.c		\
		blink_next.c			\
		special_key.c			\
		timer.c				\
		tetri_in_game_two.c		\
		moove_tetri.c			\
		tetri_error_two.c		\
		get_score.c			\
		get_tetri_two.c			\
		menu.c				\
		menu_next.c			\
		menu_next_2.c			\
		end_game.c			\
		high_score.c

OBJ = $(SRC:.c=.o)

NAME = tetris

CFLAGS += -W -Wall -Wimplicit -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) -lncurses -Lmy_lib -lmy

val:
	@gcc -g3 $(SRC) -lncurses -Lmy_lib -lmy -o $(NAME)
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f *#

re: fclean all

.PHONY: $(NAME) all clean
