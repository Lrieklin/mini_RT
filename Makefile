# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 21:10:43 by lrieklin          #+#    #+#              #
#    Updated: 2022/11/02 23:02:26 by lrieklin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_MINIRT	=	miniRT

MINIRT		=	minirt.c program_completion.c \
				parser/parser.c parser/parsing_utils.c parser/scene.c \
				parser/parsing_color.c parser/parsing_point.c \
				parser/skip_char.c parser/ambient.c parser/camera.c\
				parser/light.c parser/shapes_list.c \
				parser/sphere.c parser/plane.c parser/cylinder.c \
				vector_one.c vector_two.c vector_three.c\
				buttons.c move_buttons.c mouse.c \
				drawing.c interesect.c interesect_utils.c \
				lighting.c make_colors.c \

OBJ_MINIRT	=	$(SRC:.c=.o)

FLAG_MLX	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGC		=	-Wall -Wextra -Werror -MMD -g #-fsanitize=address -O3 -msse4 -march=native # Leaks --atExit -- ./miniRT

SRC_PATH	=	./srcs/

SRC			=	$(addprefix $(SRC_PATH), $(MINIRT))

DEP			=	$(SRC:.c=.d)

PATH_LIBFT	=	./libft/
LIBFT		=	libft.a

PATH_MLX	=	./mlx/
MLX			=	libmlx.a

all:			mlxmake libmake $(N_MINIRT)

libmake: 
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)

mlxmake:
	make -C $(PATH_MLX)
	cp $(PATH_MLX)$(MLX) $(MLX)
	
$(N_MINIRT):	$(OBJ_MINIRT)
	cc $(CFLAGS) $(FLAG_MLX) $(LIBFT) $(MLX) $(OBJ_MINIRT) -o $@

%.o:			%.c minirt.h Makefile
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_MINIRT) $(DEP) $(LIBFT) $(MLX)
	make clean -C $(PATH_LIBFT)
	make clean -C $(PATH_MLX)

fclean:			clean
	rm -rf $(N_MINIRT)
	make fclean -C $(PATH_LIBFT)
	make clean -C $(PATH_MLX)

re:				fclean all

-include $(DEP)

.PHONY:		all libmake clean fclean re	

