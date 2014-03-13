##
## Makefile for  in /home/poulet_a/projets/corewar
## 
## Made by poulet_a
## Login   <poulet_a@epitech.net>
## 
## Started on  Tue Mar 11 08:22:15 2014 poulet_a
## Last update Thu Mar 13 19:43:33 2014 poulet_a
##

CC	=	cc

RM	=	rm -f

CFLAGS	+=	-W -Wall -pedantic

LFLAGS	+=	-I../op

NAME	=	AsmX

SRCS	=	../op/op.c \
		main.c \
		match.c
		arguments.c \
		files.c \
		get_next_line.c

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
