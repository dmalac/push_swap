NAME = push_swap

BONUS_NAME = checker

SRCDIR = src

OBJDIR = obj

INCLDIR = include

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c initialisations.c input_processing.c input_checks.c list_creation.c \
list_operations.c small_stack.c sorting_small.c sorting_large.c actions.c \
large_stack.c tranche_limits.c stack_operations.c 

BONUS_SRC_FILES = main_bonus.c input_processing_bonus.c input_checks.c \
actions.c list_creation.c list_operations.c line_checks_bonus.c line_processing_bonus.c

SRC = $(addprefix $(SRCDIR)/,$(SRC_FILES))

BONUS_SRC = $(addprefix $(SRCDIR)/,$(BONUS_SRC_FILES))

OBJ = $(addprefix $(OBJDIR)/,$(SRC_FILES:.c=.o))

BONUS_OBJ = $(addprefix $(OBJDIR)/,$(BONUS_SRC_FILES:.c=.o))

LIBFT = libft/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CCFLAGS) $^ -o $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(CCFLAGS) $^ -o $(BONUS_NAME)

$(BONUS_OBJ): | $(OBJDIR)

clean:
	@rm -Rf $(OBJDIR)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(BONUS_NAME)

re: fclean
	@make

.PHONY: clean fclean re all bonus


# Individual dependencies:
$(OBJDIR)/actions.o: $(SRCDIR)/actions.c $(INCLDIR)/prototypes_shared.h

$(OBJDIR)/initialisations.o: $(SRCDIR)/initialisations.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h libft/libft.h

$(OBJDIR)/input_checks.o: $(SRCDIR)/input_checks.c $(INCLDIR)/list_structure.h libft/libft.h

$(OBJDIR)/input_processing_bonus.o: $(SRCDIR)/input_processing_bonus.c $(INCLDIR)/main_bonus.h \
$(INCLDIR)/prototypes_shared.h libft/libft.h

$(OBJDIR)/input_processing.o: $(SRCDIR)/input_processing.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h libft/libft.h

$(OBJDIR)/large_stack.o: $(SRCDIR)/large_stack.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h

$(OBJDIR)/line_checks_bonus.o: $(SRCDIR)/line_checks_bonus.c $(INCLDIR)/main_bonus.h

$(OBJDIR)/line_processing_bonus.o: $(SRCDIR)/line_processing_bonus.c $(INCLDIR)/main_bonus.h $(INCLDIR)/prototypes_shared.h \
libft/libft.h

$(OBJDIR)/list_creation.o: $(SRCDIR)/list_creation.c $(INCLDIR)/prototypes_shared.h libft/libft.h

$(OBJDIR)/list_operations.o: $(SRCDIR)/list_operations.c $(INCLDIR)/list_structure.h libft/libft.h

$(OBJDIR)/main_bonus.o: $(SRCDIR)/main_bonus.c $(INCLDIR)/main_bonus.h $(INCLDIR)/prototypes_shared.h libft/libft.h \
libft/get_next_line.h

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h

$(OBJDIR)/small_stack.o: $(SRCDIR)/small_stack.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h

$(OBJDIR)/sorting_large.o: $(SRCDIR)/sorting_large.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h

$(OBJDIR)/sorting_small.o: $(SRCDIR)/sorting_small.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h

$(OBJDIR)/stack_operations.o: $(SRCDIR)/stack_operations.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h libft/ft_printf.h

$(OBJDIR)/tranche_limits.o: $(SRCDIR)/tranche_limits.c $(INCLDIR)/main.h $(INCLDIR)/prototypes_shared.h
