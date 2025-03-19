CC = cc -Wall -Wextra -Werror -g
SRC = push_swap.c utils.c moves.c moves2.c sorter1.c sorter2.c sorter3.c error.c
OBJ = ${SRC:.c=.o}
AR = ar rcs
RM = rm -f
PS = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LNK = -L $(LIBFT_DIR) -lft

all: $(LIBFT) $(PS)

$(PS): $(OBJ)
	$(CC) $(SRC) $(LIBFT_LNK) -o $(PS)

.c.o:
	$(CC) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT) $(PS)

re: fclean all

