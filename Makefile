# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 12:33:46 by pguillie          #+#    #+#              #
#    Updated: 2017/03/10 18:02:01 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I./includes
LINK		= -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
LIBPATH		= ../libft/
LIB			= $(LIBPATH)libft.a

SOURCES	= \
		  color.c\
		  events.c\
		  ft_calibrate.c\
		  ft_center.c\
		  ft_cursor.c\
		  ft_display.c\
		  ft_disp_col.c\
		  ft_disp_cur.c\
		  ft_disp_exit.c\
		  ft_disp_info.c\
		  ft_disp_move.c\
		  ft_disp_pos.c\
		  ft_disp_rot.c\
		  ft_disp_zoom.c\
		  ft_error.c\
		  ft_fdf_valid_tab.c\
		  ft_filename.c\
		  ft_fill_image.c\
		  ft_find_color.c\
		  ft_get_coord.c\
		  ft_max.c\
		  key_input.c\
		  mouse_input.c\
		  main.c\

OBJECTS	= $(SOURCES:.c=.o)

RED		= \033[31;01m
GREEN	= \033[32;01m
BLUE	= \033[34;01m
WHITE	= \033[37;01m
EOC		= \033[0m

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ make -C $(LIBPATH)
	@ $(CC) $(FLAGS) -o $@ $^ $(LIB) -lm $(LINK)
	@ echo "\n$(GREEN)$@ successfully created !$(EOC)\n"

%.o : %.c
	@ $(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	@ echo "$(BLUE)• $(WHITE)$(notdir $(basename $@))$(GREEN) √$(EOC)"

clean :
	@ make -C $(LIBPATH) clean
	@ rm -rf $(OBJECTS)
	@ echo "$(RED)$(NAME) object files deleted$(EOC)\n"

fclean : clean
	@ rm -rf $(LIBPATH)libft.a
	@ echo "$(RED)libft.a deleted$(EOC)\n"
	@ rm -rf $(NAME)
	@ echo "$(RED)$(NAME) deleted$(EOC)\n"

re : fclean all
