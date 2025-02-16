.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
SRC_DIR = srcs/
OBJ_DIR = obj/

NAME = minitalk
SERVER = $(SRC_DIR)server.c
CLIENT = $(SRC_DIR)client.c

SERVER_OBJ = $(SERVER:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
CLIENT_OBJ = $(CLIENT:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): client server

$(LIBFT): $(LIBFT_DIR)ressource/libft.h $(LIBFT_DIR)libft/*c
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

server: $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

client: $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	rm -f $(NAME) client server
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all
