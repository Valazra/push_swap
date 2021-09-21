NAME = push_swap
LIBFT = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)/includes
LFLAGS = -L $(LIBFT_DIR) -lft

SRCS_DIR = srcs
INC_DIR = includes
OBJS_DIR = objs
LIBFT_DIR = libft

INC = push_swap.h
SRCS = chunks.c errors.c five_or_less_sort.c five_or_less_sort2.c free_piles.c initialize.c \
	more_than_five_numbers.c more_than_five_numbers2.c count_moves.c operations_a.c \
	operations_b.c operations_ab.c parsing.c print.c sort.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
vpath	%.c $(shell find $(SRCS_DIR) -type d)

$(OBJS_DIR)/%.o: %.c
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: init $(NAME)

init:
	$(shell mkdir -p $(OBJS_DIR))

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(IFLAGS) push_swap.c -o $@ $^ $(LFLAGS)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR) 

re: fclean all

.PHONY: all clean fclean re make init
