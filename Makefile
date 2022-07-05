NAME = push_swap

BONUS_NAME = checker

CC = gcc

CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address	#delete before submitting

SRC = main.c input_processing.c input_checks.c list_creation.c list_operations.c \
small_stack.c sorting_small.c sorting_large.c actions.c large_stack.c \
tranche_limits.c tranche_operations.c stack_operations.c

BONUS_SRC = main_bonus.c

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

BONUS_OBJ = $(addprefix $(OBJDIR)/,$(BONUS_SRC:.c=.o))

LIBFT = libft/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CCFLAGS) $^ -o $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@

bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CCFLAGS) $^ -o $(BONUS_NAME)

$(BONUS_OBJ): | $(OBJDIR)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -Rf $(OBJDIR)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(BONUS_NAME)

re: fclean
	@make

.PHONY: clean fclean re all

# individual dependencies:		TO BE CHECKED BEFORE SUBMISSION
$(OBJDIR)/actions.o: actions.c list_manipulation.h actions.h sorting.h main.h

$(OBJDIR)/input_checks.o: input_checks.c main.h

$(OBJDIR)/input_processing.o: input_processing.c main.h

$(OBJDIR)/list_creation.o: list_creation.c main.h list_manipulation.h libft/libft.h

$(OBJDIR)/list_operations.o: list_operations.c main.h list_manipulation.h libft/libft.h

$(OBJDIR)/large_stack.o: large_stack.c list_manipulation.h sorting.h main.h actions.h

$(OBJDIR)/main.o: main.c main.h libft/libft.h actions.h

$(OBJDIR)/small_stack.o: small_stack.c list_manipulation.h sorting.h actions.h main.h

$(OBJDIR)/stack_operations.o: stack_operations.c list_manipulation.h sorting.h actions.h main.h

$(OBJDIR)/sorting_small.o: sorting_small.c list_manipulation.h actions.h main.h

$(OBJDIR)/tranche_limits.o: tranche_limits.c list_manipulation.h main.h

$(OBJDIR)/tranche_operations.o: #tranche_operations.c list_manipulation.h main.h
