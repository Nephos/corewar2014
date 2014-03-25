##
## Makefile for Corewar in /home/chapui_s/travaux/Corewar/VM
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Thu Mar 20 16:53:03 2014 chapui_s
## Last update Tue Mar 25 18:52:44 2014 
##

NAME		= corewar

UTIL_DIR	= utils

GUI_DIR		= gui

EXEC_DIR	= exec_instructions

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
	  	  $(UTIL_DIR)/my_strlen.c \
	  	  $(UTIL_DIR)/check_args.c \
	  	  $(UTIL_DIR)/get_info_champions.c \
		  $(GUI_DIR)/my_gui.c \
		  $(GUI_DIR)/hex_to_str.c \
		  $(GUI_DIR)/get_color.c \
		  $(EXEC_DIR)/exec_instructions.c \
		  $(EXEC_DIR)/get_instruction.c \
		  ../op/op.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

RM		= rm -rf

CFLAGS		= -lSDL -lSDL_ttf -Wall -Wextra -ggdb

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
