NAME = push_swap

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

CCFLAGS_DEBUG = -Wall -Wextra -Werror -g -fsanitize=address		#delete

SRC = main.c input_processing.c

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS_DEBUG) $^ -o $(NAME)

$(LIBFT):
	make -C libft

# include dependencies for .o files (like .h files) ?

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CCFLAGS_DEBUG) -c $< -o $@

$(OBJDIR)/main.o: main.c main.h libft/libft.h

$(OBJDIR)/input_processing.o: input_processing.c main.h

clean:
	rm -R $(OBJDIR)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: clean fclean re all