##
## Makefile for  in /home/poulet_a/projets/corewar
## 
## Made by poulet_a
## Login   <poulet_a@epitech.net>
## 
## Started on  Tue Mar 11 08:22:15 2014 poulet_a
## Last update Thu Mar 13 20:40:34 2014 poulet_a
##

CC	=	cc

RM	=	rm -f

CFLAGS	+=	-W -Wall -pedantic

LFLAGS	+=	-I../op/

NAME	=	AsmX

SRCS	=	../op/op.c \
		main.c \
		arguments.c \
		files.c \
		get_next_line.c \
		my_match.c \
		my_strlen.c \
		my_strdup.c \
		my_strsplit.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean all re
