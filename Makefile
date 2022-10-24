NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCNAME		= \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isspace \
			ft_isprint \
			ft_strlen \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_strlcpy \
			ft_strlcat \
			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_memchr \
			ft_memcmp \
			ft_strnstr \
			ft_atoi \
			ft_atoi_if_valid \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_split_by_chars \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_str_utils \
			ft_numlen \
			ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap \
			ft_free_strarr \
			get_next_line \
			get_next_line_utils \
			get_next_line_utils2 \
			ft_printf \
			ft_printf_t_conv \
			ft_printf_parse_format \
			ft_printf_parse_format_utils \
			ft_printf_create_str \
			ft_printf_create_str_utils \
			ft_printf_fwrite_chr \
			ft_printf_fwrite_num \
			ft_printf_fwrite_ptr \
			ft_printf_fwrite_utils

SRC			= $(addprefix src/, $(addsuffix .c, $(SRCNAME)))
OBJ			= $(addprefix src/, $(addsuffix .o, $(SRCNAME)))

all: ${NAME}

objs :
	make -j 4 $(OBJ)

${NAME} : objs
	ar -rcus ${NAME} ${OBJ}

.c.o :
	${CC} ${CFLAGS} -I includes -c $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re $(NAME)
