#	MAKEFILE FOR LIBFT	#

# Output Colors
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

# Global Config
NAME 	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c ft_atoi_base.c \
			  ft_calloc.c ft_memchr.c ft_memcpy.c ft_memcmp.c \
			  ft_memmove.c ft_memset.c ft_putchar_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_putstr_fd.c ft_strchr.c ft_strdup.c \
			  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			  ft_strmapi.c ft_strncmp.c ft_split.c \
			  ft_strnstr.c ft_strrchr.c ft_striteri.c \
			  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			  ft_itoa.c ft_printf/ft_printf.c ft_printf/print_cs.c \
			  ft_printf/print_diu.c ft_printf/print_xp.c \
			  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BONUS_SRC	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			  ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			  ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
			  ft_lstsize_bonus.c
HEADER		= libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(NAME) $(BONUS_OBJS)
	ar rs $(NAME) $(BONUS_OBJS)
	@echo "${GREEN}bonus added successfully ✓${CLR_RMV}"

$(NAME): $(OBJS)
	ar rs $(NAME) $(OBJS)
	@echo "${GREEN}$(NAME) created successfully ✓${CLR_RMV}"

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme: fclean
	@norminette $(SRC) $(HEADER)

.PHONY: clean fclean all re
