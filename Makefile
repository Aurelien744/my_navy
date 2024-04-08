##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Write a Makefile that compiles my libm
##

SRC	=	src/main.c \
		src/help.c	\
		src/navy.c	\
		src/player_one.c	\
		src/player_two.c	\
		src/my_put_nbr.c	\
		src/my_getnbr.c	\
		src/empty_tab.c	\
		src/my_putstr.c	\
		src/display_maps.c	\
		src/pars_file.c	\
		src/str_to_word_array.c	\
		src/par_fil.c	\
		src/fill_map.c	\
		src/horizontal_pos.c	\
		src/vertical_pos.c	\
		src/game_loop.c	\
		src/my_attack.c	\
		src/my_defense.c	\
		src/get_signal.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_navy

CFLAGS += -g

all: $(NAME)

$(NAME): 	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAG) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
