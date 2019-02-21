#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 17:49:49 by svovchyn          #+#    #+#              #
#    Updated: 2018/10/27 13:34:16 by svovchyn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC = *.c
OBJ = $(SRC:.c=.o)
DEL = rm -f
FLAG = -Wall -Wextra -Werror
TRSH = *~

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "     __...--~~~~~-.__  _.-~~~~~--...__        "
	@echo "    //     libft      V   is           \\     "
	@echo "   //                 |     created     \\    "
	@echo "  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\   "
	@echo " //__.....----~~~~._\ | /_.~~~~----.....__\\  "
	@echo "====================\\|//==================== "
	@echo "                     ---                      "

clean:
	@$(DEL) $(OBJ)
	@echo "--_-_-_-_---      "
	@echo "   -_-_-_         "
	@echo "    -_-_-         "
	@echo "     -__-  all    "
	@echo "    _-_     the   "
	@echo "   _-  *.o files  "
	@echo "   -_  destroyed  "
	@echo "    _-_           "

cashdel:
	@$(DEL) $(TRSH)
	@echo "---------------"
	@echo "|   succes!   |"
	@echo "| scum's out! |"
	@echo "---------------"

fclean: clean
	@$(DEL) $(NAME)
	@echo "--_-_-_-_---      "
	@echo "   -_-_-_         "
	@echo "    -_-_-         "
	@echo "     -__- libft   "
	@echo "    _-_   is      "
	@echo "   _-     deleted "
	@echo "   -_             "
	@echo "    _-_           "

re: fclean all