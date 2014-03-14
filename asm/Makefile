##
## Makefile for  in /home/poulet_a/projets/corewar
## 
## Made by poulet_a
## Login   <poulet_a@epitech.net>
## 
## Started on  Tue Mar 11 08:22:15 2014 poulet_a
## Last update Fri Mar 14 12:17:07 2014 poulet_a
##

CC	=	cc

RM	=	rm -f

CFLAGS	+=	-W -Wall -pedantic
CFLAGS	+=	-I../op -I. -Imy

NAME	=	asm

SRCS	=	../op/op.c \
		main.c \
		arguments.c \
		register.c \
		files.c \
		my/get_next_line.c \
		my/my_match.c \
		my/my_strlen.c \
		my/my_strdup.c \
		my/my_strsplit.c \
		my/my_getnbr.c


OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean all re
