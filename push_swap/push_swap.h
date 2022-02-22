#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

void	ft_error(char *str);
int     main(int ac, char **av);

#endif