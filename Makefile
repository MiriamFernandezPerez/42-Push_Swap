NAME =		push_swap

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror -g

RM =		rm -f

HEADER =	push_swap.h

SRCS =		push_swap.c check_args.c utils.c manage_arr.c manage_stacks.c swap.c push.c rotate.c reverse_rotate.c sort_stacks.c stack_props.c stack_movs.c

OBJS =		$(SRCS:.c=.o)

%.o:%.c		$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all


