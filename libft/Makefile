NAME = libft.a
CC = gcc
LINKER = ar rcs
C_FLAGS = -Wall -Wextra -Werror -I$(HEADERS_L)
SRCS = ft_atoi	ft_bzero	ft_calloc \
	  ft_isalnum	ft_isalpha	ft_isascii \
	  ft_isdigit	ft_isprint	ft_itoa \
          ft_memccpy	ft_memchr	ft_memcmp \
          ft_memcpy	ft_memmove	ft_memset \
          ft_putchar_fd	ft_putendl_fd	ft_putnbr_fd \
          ft_putstr_fd	ft_split	ft_strchr \
          ft_strdup	ft_strjoin	ft_strlcat \
          ft_strlcpy	ft_strlen	ft_strmapi \
          ft_strncmp	ft_strnstr	ft_strrchr \
          ft_strtrim	ft_substr	ft_tolower \
          ft_toupper
B_SRCS = ft_lstnew	ft_lstadd_front	ft_lstsize \
	 ft_lstlast	ft_lstadd_back	ft_lstdelone \
	 ft_lstclear	ft_lstiter	ft_lstmap
HEADERS_L = .
OBJ_FILE_L = $(addsuffix .o, $(SRCS))
SRC_FILE = $(addsuffix .c, $(SRCS))
B_OBJ_FILE_L = $(addsuffix .o, $(B_SRCS))

all: $(NAME)

$(NAME): $(OBJ_FILE_L)
	$(LINKER) $(NAME) $?

%.o: %.c libft.h
	$(CC) -c $(C_FLAGS) $< -o $@

bonus:
	@$(MAKE) OBJ_FILE_L="$(OBJ_FILE_L) $(B_OBJ_FILE_L)" $(NAME)

clean:
	rm -f $(OBJ_FILE_L) $(B_OBJ_FILE_L)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
