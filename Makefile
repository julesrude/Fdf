NAME = fdf
SOURCES = main.c    read_file.c    validate_file.c    draw.c \
	calculate_img.c actions.c      rotations.c    projection.c		color.c \
	bresenham.c
HEADER = includes/
OBJECTS = $(SOURCES:.c=.o)


LIBFT = libft/libft.a
LIBFT_FOLDER = libft
LIBFT_HEAD = libft/includes/

LIBX = minilibx/libmlx.a
LIBX_FOLDER = minilibx/

all: $(NAME)

$(NAME): $(LIBFT) $(LIBX) $(OBJECTS)
	@gcc $(OBJECTS) -I $(LIBFT_HEAD) $(LIBFT) -I $(HEADER) -I $(LIBX_FOLDER) -L minilibx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "[ $(NAME) created ]"

$(LIBX):
	@make -C minilibx
	@echo "[ $(LIBX) created ]"

$(LIBFT):
	@make -C libft
	@echo "[ $(LIBFT) created ]"

%.o:%.c $(HEADER)
	@gcc -I $(LIBFT_HEAD) -I $(HEADER) -I $(LIBX_FOLDER) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@make -C libft clean
	@echo "[ objects cleaned ]"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "[ $(NAME) and $(LIBFT) cleaned ]"

re: fclean all