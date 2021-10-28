LIBFILES = ft_printf
SRCSDIR = ./src/
OBJSDIR = ./bin/
LIBSRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(LIBFILES)))
LIBOBJS = $(addprefix $(OBJSDIR), $(addsuffix .o, $(LIBFILES)))

INCL = ./inc
CFLAGS = -Wall -Wextra -Werror
NAME = ./ft_printf.a
OUT = $(NAME)
$(LIBOBJS) : $(LIBSRCS) 
	mkdir -p $(OBJSDIR)
	@echo "Compiling $<"
	@gcc -c $(CFLAGS) $< -o $@ -I$(INCL)
	
$(NAME) : $(LIBOBJS) 
	@echo "Making $(NAME)"
	@ar r $(NAME) $(LIBOBJS)
	@echo "$(NAME) : Tip-Top!"

all: $(NAME) 

clean:
	@echo "Removing objects files"
	@rm -rf $(OBJSDIR)
fclean: clean
	@echo "Removing ftlib"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

