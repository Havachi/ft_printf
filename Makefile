NAME = libftprintf.a
LIBFILES = ft_parse ftprintf ft_converter 
INCL = includes -Ilibft
CC = clang
CFLAGS = -Wall -Wextra -Werror 

AR = /usr/bin/ar rcs

LFTDIR = libft
LFT = $(LFTDIR)/libft.a

SRCSDIR = src
OBJSDIR = objects
LIBSRCS = $(addprefix $(SRCSDIR)/, $(addsuffix .c, $(LIBFILES)))
LIBOBJS = $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(LIBFILES)))

all: $(NAME)

$(NAME) : $(LIBOBJS) $(LFT)
	cp $(LFT) $(NAME)
	$(AR) $(NAME) $(LIBOBJS)
	@echo "$(NAME) : Tip-Top!"


$(LIBOBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	@echo "Compiling $@"
	$(CC) -c $(CFLAGS) $< -o $@ 

$(LFT):
	make -C $(LFTDIR)
clean:
	@rm -rf $(OBJSDIR)
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
