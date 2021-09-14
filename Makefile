
NAME	= scop

CC      = gcc

PWD = \"$(shell pwd)\"


SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
INCLUDESDIR = incs

LIBGLMATHDIR = libglmath
LIBGLMATH_INCLUDEDIR = inc
LIBGLMATH = $(LIBGLMATHDIR)/libglmath.a
LIBVECTORDIR = libvector
LIBVECTOR_INCLUDEDIR = inc
LIBVECTOR = $(LIBVECTORDIR)/libvector.a
LIBFTDIR = libft
LIBFT_INCLUDEDIR = inc
LIBFT = $(LIBFTDIR)/libft.a
LIBGLEWDIR = ~/.brew/Cellar/glew/2.2.0_1
LIBGLEW_INCLUDEDIR = include
LIBGLEW = $(LIBGLEWDIR)/lib/libGLEW.a
LIBGLFWDIR = ~/.brew/Cellar/glfw/3.3.4
LIBGLFW_INCLUDEDIR = include
LIBGLFW = $(LIBGLFWDIR)/lib/

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX = input.c main.c opengl.c run.c shader_tools.c shader_utils.c\
					shader.c utils.c camera.c call_backs.c load1.c load_obj_utils.c\
					load_obj_tools.c defaults.c

INCLUDES_NO_PREFIX = scop.h utils.h structs.h defines.h

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR) -I $(LIBGLMATHDIR)/$(LIBGLMATH_INCLUDEDIR)\
		-I $(LIBVECTORDIR)/$(LIBVECTOR_INCLUDEDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDEDIR)\
		-I $(LIBGLFWDIR)/$(LIBGLFW_INCLUDEDIR) -I $(LIBGLEWDIR)/$(LIBGLEW_INCLUDEDIR)

CFLAGS = -DPATH=$(PWD) -Wall -Wextra -Werror $(INC)
LFLAGS = -L $(LIBGLMATHDIR) -L $(LIBVECTORDIR) -L $(LIBFTDIR)\
		 -L $(LIBGLEWDIR)/lib -L $(LIBGLFWDIR)/lib -lglmath -lvector -lft\
		 -lm -lGLEW -lglfw -framework OPENGL

all:
	@make -C $(LIBGLMATHDIR) all
	@make -C $(LIBVECTORDIR) all
	@make -C $(LIBFTDIR) all
	@make $(BINDIR)/$(NAME)

$(LIBGLMATH):
	@make -C $(LIBGLMATHDIR) all

$(LIBVECTOR):
	@make -C $(LIBVECTORDIR) all

$(LIBFT):
	@make -C $(LIBFTDIR) all

$(BINDIR)/$(NAME): $(OBJECTS) $(LIBGLMATH) $(LIBVECTOR) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS) 

clean:
	@make clean -C $(LIBGLMATHDIR)
	@make clean -C $(LIBVECTORDIR)
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJECTS)
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBGLMATHDIR)
	@make fclean -C $(LIBVECTORDIR)
	@make fclean -C $(LIBFTDIR)
	@rm -f $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
