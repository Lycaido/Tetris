##
## Makefile for my_lib in /home/Rev/my_lib
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Sat Nov	19 12:08:02 2016 Roméo Nahon
## Last update	Sat Nov	19 12:08:02 2016 Roméo Nahon
##

SRC		=	main.c					 \
			my_realloc.c			 \
			base.c					 \
			my_ctoa.c				 \
			my_memset.c				 \
			my_str_to_wordtab.c 	 \
			my_str_to_wordtabmod.c	 \
			my_find_prime_sup.c		 \
			my_getnbr.c				 \
			my_isneg.c				 \
			my_is_prime.c			 \
			my_power_rec.c			 \
			my_putchar.c			 \
			my_put_nbr.c			 \
			my_putstr.c				 \
			my_revstr.c				 \
			my_showmem.c			 \
			my_showstr.c			 \
			my_sort_int_tab.c		 \
			my_square_root.c		 \
			my_strcapitalize.c		 \
			my_strcat.c				 \
			my_strcmp.c				 \
			my_strcpy.c				 \
			my_str_isalpha.c		 \
			my_str_islower.c		 \
			my_str_isnum.c			 \
			my_str_isprintable.c	 \
			my_str_isupper.c		 \
			my_strlen.c				 \
			my_strlowcase.c			 \
			my_strncat.c			 \
			my_strncmp.c			 \
			my_strncpy.c			 \
			my_strstr.c				 \
			my_strdup.c				 \
			my_strupcase.c			 \
			my_swap.c				 \
			my_strerror.c			 \
			my_puterror.c			 \
			my_revnb.c				 \
			my_power_it.c 			 \
			my_put_nbr_unsigned.c    \
			my_put_nbr_oct.c 	 	 \
			my_itoa.c 		 		 \
			my_intlen.c 		 	 \
			my_printf_pourcent.c 	 \
			my_printf_next.c 	 	 \
			my_printf_flag.c 	 	 \
			my_printf_display.c	 	 \
			my_printf_convert_next.c \
			my_printf_convert.c 	 \
			my_printf.c 			 \
			my_param_to_tab.c 		 \
			my_intoarg.c			 \
			get_next_line.c			 \
			my_show_wordtab.c		 \
			parse_this.c			 \

OBJ		=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	rm $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
	##rm -f *#

re:	fclean all

.PHONY:	$(NAME)	all clean
