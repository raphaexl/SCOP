
NAME	= libft.a

CC      = gcc

SRCDIR   = src
OBJDIR   = obj
BINDIR   = .
INCLUDESDIR = inc



OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX =	ft_atoi.c ft_atof.c ft_ftoa.c ft_isalnum.c ft_isascii.c ft_isalpha.c\
					ft_isdigit.c ft_isprint.c ft_bzero.c ft_lstnew.c ft_lstadd.c ft_lstadd2.c\
					 ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstdup.c ft_lstjoin.c\
					 ft_lstlen.c ft_lstmap.c ft_memalloc.c ft_memcpy.c ft_memchr.c ft_memccpy.c\
					 ft_memdel.c ft_memcmp.c ft_memset.c ft_memmove.c ft_power.c ft_tab_len.c \
					 ft_tab_free.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
					 ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strclr.c ft_strcat.c\
					 ft_strcpy.c ft_strchr.c ft_strcmp.c ft_strdel.c ft_strdup.c ft_striter.c ft_strequ.c\
					 ft_striteri.c ft_strlen.c ft_strlcat.c ft_strmap.c ft_strjoin.c ft_strmapi.c ft_strncat.c\
					 ft_strncpy.c ft_strncmp.c ft_strnequ.c ft_strns.c ft_strncat.c ft_strnstr.c ft_strnew.c ft_newstr.c\
					 ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strsub.c ft_strsplit.c\
					 ft_strtrim.c ft_itoa.c ft_itoa_base.c ft_get_next_line.c ft_realloc.c
	
					
INCLUDES_NO_PREFIX = color.h libft.h

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
	@rm -rf $(OBJDIR)
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(BINDIR)/$(NAME)

re: fclean

.PHONY: all clean fclean re
