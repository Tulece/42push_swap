NAME	=	push_swap
CC		=	cc
FLAGS 	=	-g -Wall -Werror -Werror
LIBFT_PATH = libft/
LIBFT_FILE = libft/libft.a

SRC 	=	$(wildcard src/*.c)
OBJ 	=	$(patsubst %.c,%.o,$(SRC))
RM 		=	rm -f

.SUFFIXES: .c .o

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_FILE) -o $(NAME) -I includes/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I includes/

all: $(NAME)

clean:
	echo "Deleting Obj file in $(LIBFT_PATH)...\n"
	make clean -sC $(LIBFT_PATH)
	@echo "Done\n"
	@echo "Deleting Push Swap object...\n"
	rm -f $(OBJ)
	@echo "Done\n"

fclean: clean
	@echo "Deleting Push_Swap executable..."
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	@echo "Done\n"

re: fclean all

.PHONY: all clean fclean re
