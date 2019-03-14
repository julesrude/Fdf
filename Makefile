NAME = fdf
SOURCES = main.c    get_color.c    read_file.c    validate_file.c    draw.c \
	calculate_img.c actions.c      rotations.c    projection.c		color_grade.c
HEADER = includes/
OBJECTS = $(SOURCES:.c=.o)


LIBFT = libft/libft.a
LIBFT_FOLDER = libft
LIBFT_HEAD = libft/includes/

LIBX = minilibx/libmlx.a
LIBX_FOLDER = minilibx/

all: $(NAME)

$(NAME): $(LIBFT) $(LIBX) $(OBJECTS)
	@gcc $(OBJECTS) -I $(LIBFT_HEAD) $(LIBFT) -I $(HEADER) -L minilibx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "[ $(NAME) created ]"

$(LIBX):
	@make -C $(LIBX_FOLDER)
	@echo "[ $(LIBX) created ]"

$(LIBFT):
	@make -C libft
	@echo "[ $(LIBFT) created ]"

%.o:%.c $(HEADER)
	@gcc -I $(LIBFT_HEAD) -I $(HEADER) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@make -C libft clean
	@echo "[ objects cleaned ]"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "[ $(NAME) and $(LIBFT) cleaned ]"

re: fclean all