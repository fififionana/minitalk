# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frushiti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:10:58 by frushiti          #+#    #+#              #
#    Updated: 2023/05/22 15:11:13 by frushiti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), server.c client.c)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
LIBFT_DIR = libft/

.PHONY: all clean fclean re libft

all: libft server client

libft:
	$(MAKE) -C $(LIBFT_DIR)

server: $(SRC_DIR)server.o $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_DIR)server.o $(LIBFT) -o server

client: $(SRC_DIR)client.o $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_DIR)client.o $(LIBFT) -o client

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f server client

re: fclean all
