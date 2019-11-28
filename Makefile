HDRS = checker.h
GNLDIR = ../gnl
LIBFTDIR = $(GNLDIR)/libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS = main.c $(GNLDIR)/get_next_line.c get_options.c check_stdin.c options.c \
	   check_huge.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I$(GNLDIR)
NAME = test_gnl

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc -I$(GNLDIR) -L$(LIBFTDIR) $(OBJS) -lft -o $(NAME)

%.o: %.c $(HDRS)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)
