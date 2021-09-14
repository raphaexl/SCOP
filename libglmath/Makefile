
NAME	= libglmath.a

CC      = gcc

SRCDIR   = src
OBJDIR   = obj
BINDIR   = .
INCLUDESDIR = inc



OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX =	mat4.c  mat4_op1.c  mat4_op2.c  mat4_op3.c\
					mat3.c vec3.c vec3_op1.c vec3_op2.c\
					vec4.c versor_op1.c versor_op2.c mat4_op1.c
					
INCLUDES_NO_PREFIX = defs.h mat3.h mat4.h vec2.h vec3.h vec4.h versor.h

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR)

CFLAGS = -DPATH=$(PWD) -Wall -Wextra -Werror $(INC)
LFLAGS = -lm

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
