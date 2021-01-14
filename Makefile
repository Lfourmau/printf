LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		print.c \
		itoa_base.c \
		itoa_base_p.c \
		conversions.c \
		conversions_utils.c \
		displ_utils.c \
		parsing.c \
		ft_isit.c \
		comp.c \
		struct_manip.c \

GCCF = gcc -c -Wall -Wextra -Werror

INCLUDE = ft_printf.h

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
	$(GCCF) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(GCCF) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft 
	rm -f *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f *.o
	rm -f ${NAME}

re : fclean all

.PHONY: clean fclean re all