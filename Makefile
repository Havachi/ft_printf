MODE = 1

NAME = libftprintf.a
LIBFILES = ft_printf ft_parse ft_converter ft_check 
INCL = -I$(INCLDIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifeq ($(MODE), 1)
CFLAGS += -g2 -pipe
else
CFLAGS += -D_FORTIFY_SOURCE=2 -O2
endif
AR = ar qcs

LFTDIR = libft
LFT = $(LFTDIR)/libft.a
LFTH = $(LFTDIR)/libft.h

SRCSDIR = src
OBJSDIR = objects
INCLDIR = includes
LIBSRCS = $(addprefix $(SRCSDIR)/, $(addsuffix .c, $(LIBFILES)))
LIBOBJS = $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(LIBFILES)))

all: $(NAME)

$(NAME) : $(LIBOBJS) $(LFT)
	cp $(LFTH) $(INCLDIR)
	cp $(LFT) $(NAME)
	$(AR) $(NAME) $(LIBOBJS)
	@echo "$(NAME) : Tip-Top!"

$(LIBOBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	@echo "Compiling $@"
	$(CC) -c $(CFLAGS) $< -o $@ $(INCL)

$(LFT):
	@echo "Preparing Libft"
	make -C $(LFTDIR)
clean:
	@rm -rf $(OBJSDIR)
fclean: clean
	@rm -f $(NAME)
	@rm -f 
re: fclean all

init:
	git -C $(LFTDIR) pull
	make -C $(LFTDIR)
.PHONY: all clean fclean re
