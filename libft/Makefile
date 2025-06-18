# compil
COMPIL = cc
CFLAGS = -Wall -Werror -Wextra

# variables
NAME = libft.a

DIR = src/

FT_IS_DIR = ft_is/
FT_IS_SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
FT_IS_OBJ = ${addprefix ${FT_IS_DIR}, ${FT_IS_SRC:.c=.o}}

FT_LST_DIR = ft_lst/
FT_LST_SRC = ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
FT_LST_OBJ = ${addprefix ${FT_LST_DIR}, ${FT_LST_SRC:.c=.o}}

FT_MEM_DIR = ft_mem/
FT_MEM_SRC = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
FT_MEM_OBJ = ${addprefix ${FT_MEM_DIR}, ${FT_MEM_SRC:.c=.o}}

FT_PRINTF_DIR = ft_printf/
FT_PRINTF_SRC = ft_dispatcher.c ft_handler_c.c ft_handler_d_i.c ft_handler_p.c ft_handler_s.c ft_handler_u.c ft_handler_x.c \
				ft_print_until_format.c ft_printf.c is_a_formatter.c
FT_PRINTF_OBJ = ${addprefix ${FT_PRINTF_DIR}, ${FT_PRINTF_SRC:.c=.o}}

FT_PUT_DIR = ft_put/
FT_PUT_SRC = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
FT_PUT_OBJ = ${addprefix ${FT_PUT_DIR}, ${FT_PUT_SRC:.c=.o}}

FT_STR_DIR = ft_str/
FT_STR_SRC = ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			 ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
FT_STR_OBJ = ${addprefix ${FT_STR_DIR}, ${FT_STR_SRC:.c=.o}}

FT_TO_DIR = ft_to/
FT_TO_SRC = ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c ft_uitoa.c ft_uitoa_base.c ft_ulitoa_base.c ft_atoli.c ft_atossize_t_base.c
FT_TO_OBJ = ${addprefix ${FT_TO_DIR}, ${FT_TO_SRC:.c=.o}}

GNL_SRC = get_next_line.c
GNL_OBJ = ${GNL_SRC:.c=.o}

OBJS = $(addprefix ${DIR}, ${FT_IS_OBJ} ${FT_LST_OBJ} ${FT_MEM_OBJ} ${FT_PRINTF_OBJ} ${FT_PUT_OBJ} ${FT_STR_OBJ} ${FT_TO_OBJ} ${GNL_OBJ})

BOLD = \033[1m
RED = \033[1;31m
GREEN = \033[1;32m
NC = \033[0m

# style
BOLD = \033[1m
RED = \033[1;31m
GREEN = \033[1;32m
LIGHT_BLUE = \033[1;34m
NC = \033[0m

# phony
.PHONY = all clean fclean re print

# rules
all: print ${NAME}

%.o: %.c
	@ ${COMPIL} ${CFLAGS} -Iinc/ -c $< -o $@
	@ echo -e '${BOLD}${LIGHT_BLUE}[COMPILING]${NC}${LIGHT_BLUE} $@ ${NC}'

${NAME}: ${OBJS}
	@ ar rcs -o ${NAME} ${OBJS}

print:
	@ echo -e '\n'
	@ echo -e ' ${GREEN}██      ██ ██████  ███████ ████████ ${NC}'
	@ echo -e ' ${GREEN}██      ██ ██   ██ ██         ██    ${NC}'
	@ echo -e ' ${GREEN}██      ██ ██████  █████      ██    ${NC}'
	@ echo -e ' ${GREEN}██      ██ ██   ██ ██         ██    ${NC}'
	@ echo -e ' ${GREEN}███████ ██ ██████  ██         ██    ${NC}'
	@ echo -e '\n'

clean:
	@ rm -f ${OBJS}

fclean: clean
	@ rm -f ${NAME}

re: fclean all
