HDRS = ../checker.h
GNLDIR = ../gnl
LIBFTDIR = $(GNLDIR)/libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS = huge_sender.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I$(GNLDIR) -I..
NAME = huge_sender

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc -I$(GNLDIR) -I.. -L$(LIBFTDIR) $(OBJS) -lft -o $(NAME)

%.o: %.c $(HDRS)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)
