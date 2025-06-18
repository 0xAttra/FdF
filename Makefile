# variables
CC = cc
CFLAGS = -Wall -Werror -Wextra
MINILIBX = -L/usr/lib -lXext -lX11 -lm -lz
NAME = fdf
BONUS_NAME = fdf_bonus

INC_DIR = inc/
LIBFT_INC_DIR = libft/inc/
MLX = minilibx-linux/
MLX_NAME = minilibx-linux/libmlx.a

SRCS_DIR = srcs/
SRCS_FILES = draw.c env.c free.c maths.c minilib.c utils.c

PARS_DIR = parsing/
PARS_SRCS = parsing_color.c parsing_map.c
PARS_FILES = $(addprefix ${PARS_DIR}, ${PARS_SRCS})

HOOK_DIR = hooks/
HOOK_SRCS = hooks.c hooks_utils.c
HOOK_FILES = $(addprefix ${HOOK_DIR}, ${HOOK_SRCS})

SRCS = fdf.c $(addprefix ${SRCS_DIR}, ${SRCS_FILES}) $(addprefix ${SRCS_DIR}, ${PARS_FILES}) $(addprefix ${SRCS_DIR}, ${HOOK_FILES})
OBJS = ${SRCS:.c=.o}

BONUS_DIR = srcs/bonus/
BONUS_OTHER_SRCS = maths.c minilib.c free.c utils.c env.c parsing/parsing_color.c parsing/parsing_map.c
BONUS_SRCS = $(addprefix ${BONUS_DIR}, colors_bonus.c draw_bonus.c fdf_bonus.c hooks_bonus.c hooks_utils_bonus.c)
BONUS_SRCS += $(addprefix srcs/, ${BONUS_OTHER_SRCS})
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT_AR = $(addprefix ${LIBFT_DIR}, ${LIBFT_NAME})

# style
BOLD = \033[1m
RED = \033[1;31m
GREEN = \033[1;32m
LIGHT_BLUE = \033[1;34m
NC = \033[0m

# phony
.PHONY = all clean fclean re bonus rew withoutflags

# rules
all: ${NAME}

%.o: %.c
	@ ${CC} ${CFLAGS} -I${INC_DIR} -I${LIBFT_INC_DIR} -I${MLX} -c $< -o $@
	@ echo -e '${BOLD}${LIGHT_BLUE}[COMPILING]${NC}${LIGHT_BLUE} $@ ${NC}'

${NAME}: ${LIBFT_AR} print ${MLX_NAME} ${OBJS}
	@ ${CC} ${CFLAGS} ${OBJS} ${MINILIBX} ${MLX_NAME} ${LIBFT_AR} -o ${NAME}
	@ echo "${GREEN} --------------------------------------------${NC}"
	@ echo "\t${BOLD}${GREEN}[EXECUTABLE] './${NAME}' ready.${NC}"
	@ echo "${GREEN} --------------------------------------------${NC}"

${MLX_NAME}:
	@ $(MAKE) -j -C ${MLX}

bonus: ${BONUS_NAME}

print:
	@ echo -e '\n'
	@ echo -e ' ${GREEN}███████ ██████  ███████ ${NC}'
	@ echo -e ' ${GREEN}██      ██   ██ ██      ${NC}'
	@ echo -e ' ${GREEN}█████   ██   ██ █████   ${NC}'
	@ echo -e ' ${GREEN}██      ██   ██ ██      ${NC}'
	@ echo -e ' ${GREEN}██      ██████  ██      ${NC}'
	@ echo -e '\n'

${BONUS_NAME}: ${LIBFT_AR} print_bonus ${MLX_NAME} ${BONUS_OBJS}
	@ ${CC} ${CFLAGS} ${BONUS_OBJS} ${MINILIBX} ${MLX_NAME} ${LIBFT_AR} -o ${BONUS_NAME}
	@ echo "${GREEN} ----------------------------------------------${NC}"
	@ echo "\t${BOLD}${GREEN}[EXECUTABLE] './${BONUS_NAME}' ready.${NC}"
	@ echo "${GREEN} ----------------------------------------------${NC}"

print_bonus:
	@ echo -e '\n'
	@ echo -e ' ${GREEN}███████ ██████  ███████     ██████   ██████  ███    ██ ██    ██ ███████ ${NC}'
	@ echo -e ' ${GREEN}██      ██   ██ ██          ██   ██ ██    ██ ████   ██ ██    ██ ██      ${NC}'
	@ echo -e ' ${GREEN}█████   ██   ██ █████       ██████  ██    ██ ██ ██  ██ ██    ██ ███████ ${NC}'
	@ echo -e ' ${GREEN}██      ██   ██ ██          ██   ██ ██    ██ ██  ██ ██ ██    ██      ██ ${NC}'
	@ echo -e ' ${GREEN}██      ██████  ██          ██████   ██████  ██   ████  ██████  ███████ ${NC}'
	@ echo -e '\n'

withoutflags: ${LIBFT_AR}
	${CC} ${SRCS} -I${INC_DIR} -I${LIBFT_INC_DIR} ${MINILIBX} -o ${NAME} ${LIBFT_AR}

${LIBFT_AR}:
	@ $(MAKE) -j -C ${LIBFT_DIR}

clean:
	@ $(MAKE) clean -C ${LIBFT_DIR}
	@ rm -f ${OBJS}
	@ rm -f ${BONUS_OBJS}
	@ echo "${BOLD}${RED}[DELETION] All objects have been deleted.${NC}"
	@ $(MAKE) clean -C ${MLX}

fclean: clean
	@ $(MAKE) fclean -C ${LIBFT_DIR}
	@ rm -f fdf
	@ rm -f fdf_bonus
	@ echo "${BOLD}${RED}[DELETION] Executable(s) have been deleted.${NC}"

re: fclean all

rew: fclean withoutflags
