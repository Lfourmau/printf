NAME = libftprintf.a

SRCS = print.c ft_printf.c struct_manip.c parsing.c conversions.c ft_isit.c comp.c\
		itoa_base.c itoa_base_p.c conversions_utils.c displ_utils.c

GCCF = gcc -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

_END = \033[0m
_DIM = \033[2m
_YELLOW = \033[33m
_GREEN = \033[92m
_RED = \033[91m
_ROSE = \033[95m
_CYAN = \033[96m




%o : %.c ft_printf.h
	${GCCF} -c $< -o $@

$(NAME) : ${OBJS}
	$(MAKE) -C libft/
	cp libft/libft.a $(NAME)
	ar -rc ${NAME} $?

all : ${NAME}

clean :
	rm -f ${OBJS}
	cd libft/ && make clean

fclean : clean
	rm -f ${NAME}
	cd libft/ && make fclean

re : fclean all


.PHONY : all clean fclean re
