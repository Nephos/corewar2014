##
## Makefile for Corewar in /home/chapui_s/travaux/Corewar/VM
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Thu Mar 20 16:53:03 2014 chapui_s
## Last update Fri Mar 21 20:54:51 2014 chapui_s
##

NAME		= corewar

UTIL_DIR	= utils

SRC		= main.c \
		  arguments.c \
		  list_champions.c \
		  load_arena.c \
		  load_champions_in_arena.c \
		  $(UTIL_DIR)/init_arena.c \
	  	  $(UTIL_DIR)/usage.c \
	  	  $(UTIL_DIR)/my_strcmp.c \
	  	  $(UTIL_DIR)/my_puts.c \
	  	  $(UTIL_DIR)/my_atoi.c \
	  	  $(UTIL_DIR)/my_showmem.c \
	  	  $(UTIL_DIR)/attribute_prog_number.c \
	  	  $(UTIL_DIR)/attribute_address.c \
	  	  $(UTIL_DIR)/check_args.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

RM		= rm -rf

CFLAGS		= -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
