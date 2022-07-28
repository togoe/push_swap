NAME				=	push_swap
SRC_DIR				=	./srcs/
INC_DIR				=	./inc/
SRCS				=	main.c	instructions.c parsing.c ft_utils.c\
						swap.c push.c rotate.c reverse_rotate.c	\
                    
SRC_BASENAME    =    $(addprefix $(SRC_DIR), $(SRCS))        
OBJS            =    $(SRC_BASENAME:.c=.o)
CC              =    clang
FLAGS			=	 -Wall -Wextra -Werror -I $(INC_DIR) -I ./libft/


all				:    $(NAME)
.c.o			:
				$(CC) $(FLAGS) -c $< -o $@

$(NAME)			:    $(OBJS)
			make -C ./libft/
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L./libft/ -lft
			@echo [$(NAME)] : Created !

clean        :
			rm -rf $(OBJS)
			make fclean -C ./libft/
			@echo "[OBJS] Deleted"

fclean        :    clean
			rm -f $(NAME)
			@echo "[$(NAME)]: Deleted"

re            :    fclean all

.PHONY: all clean fclean re
