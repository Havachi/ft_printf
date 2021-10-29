NAME = ft_printf.a
LIBFILES = ft_printf format
INCL = ./inc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./src/
OBJSDIR = ./bin/
LIBSRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(LIBFILES)))
LIBOBJS = $(addprefix $(OBJSDIR), $(addsuffix .o, $(LIBFILES)))

$(NAME) : $(LIBOBJS) 
	@echo "Making $(NAME)"
	@ar r $(NAME) $(LIBOBJS)
	@echo "$(NAME) : Tip-Top!"


$(LIBOBJS) : $(LIBSRCS) 
	@mkdir -p $(OBJSDIR)
	@echo "Compiling $@"
	@gcc -c $(CFLAGS) $< -o $@ -I$(INCL)
	
all: $(NAME) 

clean:
	@rm -rf $(OBJSDIR)
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

