SRC			=		./main.c       \
					./srcs/dda.c    \
					./utils/error.c  \
					./utils/talloc.c  \
					./srcs/mini_map.c  \
					./srcs/draw_line.c  \
					./srcs/key_hooks.c   \
					./srcs/utilities.c    \
					./srcs/collisions.c    \
					./srcs/mouse_hooks.c    \
					./srcs/render_column.c     \
					./utils/putendl_fd.c      \
					./srcs/update_frame.c      \
					./srcs/ray_processing.c     \
					./srcs/window_handling.c \
					./srcs/doors.c \
					./srcs/sprites.c \
					./parse/init.c \
					./parse/list_op.c\
					./parse/parse_header.c\
					./parse/fill_data.c\
					./parse/parse_map.c\
					./parse/bools.c\
					./parse/parse.c\
					./gnl/get_next_line.c\
					./gnl/get_next_line_utils.c\
					./parse/mini_libft/ft_atoi.c\
					./parse/mini_libft/ft_strjoin.c\
					./parse/mini_libft/ft_strrchr.c\
					./parse/mini_libft/ft_split.c\
					./parse/mini_libft/ft_strlen.c\
					./parse/mini_libft/ft_strtrim.c\
					./parse/mini_libft/ft_strchr.c\
					./parse/mini_libft/ft_strncmp.c\
					./parse/mini_libft/ft_substr.c\
					./parse/mini_libft/ft_strdup.c\

CC			=	cc
NAME		=	cub3D
HEADER		=	include/cub3d.h include/struct.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L./MLX -l mlx -framework OpenGL -framework AppKit


all: $(NAME)
	
$(NAME): $(OBJ)
	@$(CC) -g $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS_L) $(MLXFLAGS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
