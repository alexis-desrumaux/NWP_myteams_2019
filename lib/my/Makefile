##
## EPITECH PROJECT, 2019
## ALEXIS DESRUMAUX
## File description:
## Makefile
##

NAME	= libmy.a

RM	= rm -f

SRC_UTILITIES	= ./utilities/catch_str.c \
	  ./utilities/compteurdizaine.c \
	  ./utilities/debug.c \
	  ./utilities/float2char.c \
	  ./utilities/get_next_line.c \
	  ./utilities/int2char.c \
	  ./utilities/is_number_letter.c \
	  ./utilities/match_str.c \
	  ./utilities/my_f_puiss.c \
	  ./utilities/my_f_puiss_float.c \
	  ./utilities/my_printf.c \
	  ./utilities/my_printf_carriage.c \
	  ./utilities/my_printf_check1.c \
	  ./utilities/my_printf_check2.c \
	  ./utilities/my_printf_check3.c \
	  ./utilities/my_printf_check4.c \
	  ./utilities/my_printf_check5.c \
	  ./utilities/my_printf_check6.c \
	  ./utilities/my_printf_check7.c \
	  ./utilities/my_printf_conditions.c \
	  ./utilities/my_printf_dispflag.c \
	  ./utilities/my_putchar.c \
	  ./utilities/my_putint.c \
	  ./utilities/my_putnbr.c \
	  ./utilities/my_putnbr_long.c \
	  ./utilities/my_putnbr_short.c \
	  ./utilities/my_putstr.c \
	  ./utilities/my_strcpy.c \
	  ./utilities/my_strlen.c \
	  ./utilities/parse_str2tab.c \
	  ./utilities/tools_1.c

SRC_LINKEDLIST	= ./linkedlist/str/linkedlist_str.c \
				  ./linkedlist/str/linkedlist_str_2.c \
				  ./linkedlist/str/linkedlist_str_3.c \
				  ./linkedlist/str/linkedlist_str_4.c \
				  ./linkedlist/char/linkedlist_char.c \
				  ./linkedlist/char/linkedlist_char_2.c \
				  ./linkedlist/char/linkedlist_char_3.c \
				  ./linkedlist/char/linkedlist_char_4.c \
				  ./linkedlist/char/tools.c \
				  ./linkedlist/int/linkedlist_int.c \
				  ./linkedlist/int/linkedlist_int_2.c \
				  ./linkedlist/int/linkedlist_int_3.c \
				  ./linkedlist/mtypes/linkedlist.c \
				  ./linkedlist/mtypes/linkedlist2.c \
				  ./linkedlist/mtypes/linkedlist3.c \

OBJ_UTILITIES	= $(SRC_UTILITIES:.c=.o)

OBJ_LINKEDLIST	= $(SRC_LINKEDLIST:.c=.o)

CFLAGS = -I ../../include/lib
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ_UTILITIES) $(OBJ_LINKEDLIST)
		ar rc $(NAME) $(OBJ_UTILITIES) $(OBJ_LINKEDLIST)

clean:
	$(RM) $(OBJ_UTILITIES) $(OBJ_LINKEDLIST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
