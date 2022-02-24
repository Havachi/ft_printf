NAME := libftprintf.a

#Directories
SRCS_DIR = ./
OBJS_DIR = ./objs/
INCL_DIR = ./includes/
LIB_DIR = ./lib/
LFT_DIR = ./libft/

#Compiler
CC := gcc
INCLFLAGS := -I$(INCL_DIR)
LIBSFLAGS := -L$(LIB_DIR) -lft
CFLAGS = -Wall -Wextra -Werror $(INCLFLAGS) $(LIBSFLAGS)


#Tools
RM := rm -f
CP := cp
MKDIR := mkdir

#Project files, without suffix or prefix
FILES :=\
		ft_printf\
		print_hex\
		print_pointer\
		print_uint\

#Suffix + Prefix for OBJS and SRCS
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
NAME= libftprintf.a

#Libft definition
LFT_FILE = libft
LFT_INCL = $(addprefix $(LFT_DIR), $(addsuffix .h, $(LFT_FILE)))
LFT_LIB = $(addprefix $(LFT_DIR), $(addsuffix .a, $(LFT_FILE)))
LOCAL_LFT_INCL = $(addprefix $(INCL_DIR), $(addsuffix .h, $(LFT_FILE)))
LOCAL_LFT_LIB = $(addprefix $(LIB_DIR), $(addsuffix .a, $(LFT_FILE)))
all: $(NAME)


$(OBJS): $(SRCS)
	@echo "\n---|Compiling $<|---"
	gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	@echo "\n============Archiving the library============"
	cp $(LFT_LIB) ${NAME}
	ar -rcs $(NAME) $(OBJS)
	@echo "\n============ Compilation done ✅ ============"
	@echo "You can now use ${NAME} as the library and the corresponding header file!"
	@echo "You can even us it as a submodule"

re: fclean init $(NAME)

clean:
	@echo "\n============ Removing .o files 🗑 ============"
	rm -f $(OBJS)

fclean: clean
	@echo "\n============ Removing $(NAME) 🗑 ============"
	rm -f $(NAME)

init: import_lft mk_dirs
	@echo "\n============ Project initialized for compilation ✅ ============"
init_lft:
	@echo "\n============ Pulling libft from remote repository ============"
	@cd libft
	git pull
	@cd ..
	@echo "\n============ Making libft ============"
	make -C $(LFT_DIR)
import_lft: init_lft mk_dirs
	@echo "\n============Copying libft files in project root folders ============"
	$(CP) $(LFT_INCL) $(LOCAL_LFT_INCL)
	$(CP) $(LFT_LIB) $(LOCAL_LFT_LIB)
mk_dirs:
	@echo "============Creating base folders ============"
	$(MKDIR) -p $(OBJS_DIR)
	$(MKDIR) -p $(LIB_DIR)
	$(MKDIR) -p $(INCL_DIR)
