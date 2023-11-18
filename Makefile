NAME = push_swap
SRC_FILES = main.c \
			count_and_error.c \
			parser.c \
			create_and_sort_stack.c \
			utils.c \
			push_swap.c \
			simple_sort.c \
			radix.c \
			sort_three.c \
			sort_five.c \

OBJ_FILES = $(SRC_FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@cc $(OBJ_FILES) $(FLAGS) -o $(NAME)

clean :
	@rm -f $(OBJ_FILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re