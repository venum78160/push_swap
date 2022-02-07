CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRC = swap.c \
main.c \
crea_list.c \
sort.c \
help.c \
step.c \
lst_return.c

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o : %.c
		$(CC) -o $@ -c $< $(CFLAGS)
		
$(NAME) 	:	$(OBJ)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

all : $(NAME)

clean :
		$(MAKE) clean -C ./libft
		$(RM) $(OBJ)

fclean : clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re