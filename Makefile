NAME = push_swap

CC = gcc

CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address	#delete before submitting

SRC = main.c input_processing.c list_operations.c small_stack.c \
sorting_small.c sorting_large.c actions.c large_stack.c tranches.c

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

LIBFT = libft/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $(NAME)

$(LIBFT):
	make -C libft

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -Rf $(OBJDIR)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean
	make

.PHONY: clean fclean re all

# individual dependencies:		TO BE CHECKED BEFORE SUBMISSION
$(OBJDIR)/actions.o: actions.c list_operations.h actions.h sorting.h main.h

$(OBJDIR)/input_processing.o: input_processing.c main.h

$(OBJDIR)/list_operations.o: list_operations.c main.h list_operations.h

$(OBJDIR)/large_stack.o: large_stack.c list_operations.h sorting.h main.h actions.h

$(OBJDIR)/main.o: main.c main.h libft/libft.h actions.h

$(OBJDIR)/small_stack.o: small_stack.c list_operations.h sorting.h actions.h main.h

$(OBJDIR)/sorting_small.o: sorting_small.c list_operations.h actions.h main.h

$(OBJDIR)/tranches.o: tranches.c list_operations.h main.h

