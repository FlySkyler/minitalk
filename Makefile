.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

NAME = minitalk

OBJ_DIR = obj/
SRC = minitalk.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_DIR)ressource/libft.h $(LIBFT_DIR)libft/*c
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all
