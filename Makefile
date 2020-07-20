#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 22:55:24 by mbiliaie          #+#    #+#              #
#    Updated: 2018/10/17 22:55:31 by mbiliaie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 		= mbiliaie.filler
HDR_FOLDER 	= includes/
CC 			= clang
CFLAGS 		= -Wall -Werror -Wextra
SRCS_PATH 	= src/
LIB_FOLDER 	= libft/
OUT_PATH  	= obj/

SRCS 		= validate_and_run.c \
			  objects_handler.c \
			  start_loop.c \
			  prepare_spot.c \
			  reveal_point.c \
			  position.c \
			  nearest_spot.c

OBJECTS 	= $(addprefix $(OUT_PATH), $(SRCS:.c=.o))
SOURCES 	= $(addprefix $(SRCS_PATH), $(SRCS))

all: 		$(NAME)
$(NAME): 	$(OBJECTS)
	@make -C $(LIB_FOLDER)
	@$(CC) $(CFLAGS) $(OBJECTS) -I $(HDR_FOLDER) -L $(LIB_FOLDER) -lft -o $(NAME)
	@echo "$(NAME) is ready"
	
$(OUT_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(CFLAGS) -I $(HDR_FOLDER) $< -o $@

clean:
	@make -C $(LIB_FOLDER) fclean
	@rm -rf $(OUT_PATH)
	@rm -rf filler.trace
	@echo "o-files were deleted"

fclean: clean
	@rm -f $(NAME)

re:  fclean $(NAME)
.PHONY: all, clean, fclean, re