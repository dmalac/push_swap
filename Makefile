NAME = push_swap

BONUS_NAME = checker

CC = gcc

CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address	#delete before submitting

SRC = main.c initialisations.c input_processing.c input_checks.c list_creation.c \
list_operations.c small_stack.c sorting_small.c sorting_large.c actions.c large_stack.c \
tranche_limits.c stack_operations.c 

BONUS_SRC = main_bonus.c input_processing_bonus.c input_checks.c \
actions.c list_creation.c list_operations.c line_checks_bonus.c line_processing_bonus.c

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

clean:
	@rm -Rf $(OBJDIR)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(BONUS_NAME)

re: fclean
	@make

.PHONY: clean fclean re all

# individual dependencies:		TO BE CHECKED BEFORE SUBMISSION
$(OBJDIR)/actions.o: actions.c main.h list_structure.h

$(OBJDIR)/initialisations.o: initialisations.c main.h list_structure.h

$(OBJDIR)/input_checks.o: input_checks.c main.h list_structure.h

$(OBJDIR)/input_processing.o: input_processing.c main.h list_structure.h

$(OBJDIR)/list_creation.o: list_creation.c main.h list_structure.h libft/libft.h

$(OBJDIR)/list_operations.o: list_operations.c main.h list_structure.h libft/libft.h

$(OBJDIR)/large_stack.o: large_stack.c main.h list_structure.h

$(OBJDIR)/main.o: main.c main.h list_structure.h libft/libft.h

$(OBJDIR)/small_stack.o: small_stack.c main.h list_structure.h

$(OBJDIR)/sorting_large.o: sorting_large.c main.h list_structure.h

$(OBJDIR)/sorting_small.o: sorting_small.c main.h list_structure.h

$(OBJDIR)/stack_operations.o: stack_operations.c main.h list_structure.h

$(OBJDIR)/tranche_limits.o: tranche_limits.c main.h list_structure.h
