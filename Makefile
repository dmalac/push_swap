NAME = push_swap

CC = gcc

CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address	#delete before submitting

SRC = main.c input_processing.c list_operations.c small_stack.c \
sorting.c actions.c

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

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: clean fclean re all

# individual dependencies:		TO BE CHECKED BEFORE SUBMISSION

$(OBJDIR)/main.o: main.c main.h libft/libft.h

$(OBJDIR)/input_processing.o: input_processing.c main.h

$(OBJDIR)/list_operations.o: list_operations.c main.h

$(OBJDIR)/small_stack.o: small_stack.c list_operations.h sorting.h

$(OBJDIR)/sorting.o: sorting.c list_operations.h sorting.h

$(OBJDIR)/actions.o: actions.c list_operations.h