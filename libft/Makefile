NAME = libft.a

SRC = ft_printf.c ft_printf_converters.c ft_printf_flags.c \
ft_printf_printers.c ft_power.c ft_itoa.c ft_putchar_int.c \
ft_putstr_int.c ft_substr.c ft_uitoa.c ft_strlen.c

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC = gcc

CCFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $?

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJDIR)/ft_printf*.o: ft_printf*.c ft_printf.h libft.h

$(OBJDIR)/ft_substr.o: ft_substr.c libft.h

clean:
	rm -R $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all