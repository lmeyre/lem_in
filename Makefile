NAME = lem-in

FLAGS = -Wall -Werror -Wextra

VPATH = $(SRCS_DIR) $(SRCS_DIR)/algorythm

SRCS = main.c config_room.c init_parsing.c room_parsing.c error.c	\
	   initialize.c ft_deltab.c	check_parsing.c	ft_checkint_positive.c	\
	   link_parsing.c lm_visual.c lm_launch_visual.c bonus.c	\
	   find_path.c send_ant.c width_scan.c split_path.c reset_lst.c	choose_ant_path.c check_scan.c\
	   util_algo.c lm_putpath.c lm_findlink.c

SRCS_DIR = srcs

BIN = $(SRCS:.c=.o)

HEADER = includes/lem_in.h

HEADER_DIR = includes

LIB = libft/libft.a

LIBDIR = libft

MAKE = Makefile

DEBUG = -g -fsanitize=address

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN)  $(LIB) $(HEADER) $(MAKE)
		gcc $(FLAGS) -o $(NAME) $(BIN) -I $(LIBDIR) -I $(HEADER_DIR) $(LIB)

%.o: %.c
		@gcc $(FLAGS) -o $@ -c $< -I $(HEADER_DIR)

$(LIB):
		@make -C $(LIBDIR)

debug:	$(BIN)  $(LIB) $(HEADER) $(MAKE)
		@gcc $(FLAGS) $(DEBUG) -o $(NAME) $(BIN) -I $(LIBDIR) -I $(HEADER_DIR) $(LIB)
		@echo "Compiling debuging mode..."
		

clean:
		@rm -f $(BIN)
		@make clean -C $(LIBDIR)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBDIR)

re: fclean all
