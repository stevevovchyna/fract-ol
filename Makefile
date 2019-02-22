.PHONY: all clean fclean re lft lftclean lftfclean lftre mlx mlxclean mlxre

NAME := fractol

SRCDIR := ./src/
OBJDIR := ./obj/
INCDIR := ./inc/
LFTDIR := ./libft/
MLXDIR := ./miniLibX/
SRC := $(wildcard $(SRCDIR)*.c)
OBJ := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

INCLUDES := -I $(INCDIR) -I $(LFTDIR) -I $(MLXDIR)
LIBS := -L $(LFTDIR) -lft -L $(MLXDIR)

CC := gcc
MLXFLAGS := -lmlx -framework OpenGL -framework AppKit
CCFLAGS := -Wall -Wextra -Werror

all: lft mlx $(NAME)

lft:
		@$(MAKE) -C $(LFTDIR)

lftclean:
		@$(MAKE) -C $(LFTDIR) clean

lftfclean:
		@$(MAKE) -C $(LFTDIR) fclean

lftre:
		@$(MAKE) -C $(LFTDIR) re

mlx:
		@$(MAKE) -C $(MLXDIR)

mlxclean:
		@$(MAKE) -C $(MLXDIR) clean

mlxre:
		@$(MAKE) -C $(MLXDIR) re

$(NAME): $(OBJ)
		@echo "Your $@ is ready, sir!"
		@$(CC) $(OBJ) $(LIBS) $(MLXFLAGS) -lm -o $(NAME)

$(OBJ): | $(OBJDIR)
$(OBJDIR):
		@mkdir obj

$(OBJDIR)%.o: $(SRCDIR)%.c
		@echo "Creating $@"
		@$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
		@echo "Cleaning up..."
		@rm -rf $(OBJDIR)

fclean: clean lftfclean mlxclean
		@rm -rf $(NAME)

re: fclean all