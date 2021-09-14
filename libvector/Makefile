
NAME	= libvector.a

CC      = gcc

SRCDIR   = src
OBJDIR   = obj
BINDIR   = .
INCLUDESDIR = inc



OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX =	vector1.c vector2.c
					
INCLUDES_NO_PREFIX = vector.h

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR)

CFLAGS = -DPATH=$(PWD) -Wall -Wextra -Werror $(INC)
LFLAGS = 

all:
	@make $(BINDIR)/$(NAME)

$(BINDIR)/$(NAME): $(OBJECTS)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	@$(CC) -c $< -o $@ $(CFLAGS) 

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(BINDIR)/$(NAME)

re: fclean

.PHONY: all clean fclean re
