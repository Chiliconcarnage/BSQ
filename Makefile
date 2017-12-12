##
## Makefile for makefile in /home/oem/home/CPE_2015_BSQ
## 
## Made by OEM Configuration (temporary user)
## Login   <oem@epitech.net>
## 
## Started on  Sun Dec 20 18:04:00 2015 OEM Configuration (temporary user)
## Last update Tue Dec 12 18:11:23 2017 maxence.lauque
##

CC	= cc

SRC	= src/bsq.c \
	  src/bsq2.c \
	  src/my_putchar.c \
	  src/my_putstr.c \
	  src/my_getnbr.c \
	  src/my_put_nbr.c \
	  src/my_strlen.c

RM	= rm -f

DIR_LIB = -L./

NAME	= bsq

OBJ	= $(SRC:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(DIR_LIB)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY : all clean fclean re
