//#include "push_swap.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int             *content;
	struct s_list	*next;
} t_list;
void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
int main(int ac, char **av)
{
    t_list  *list;
    int     i;

    i = -1;
    if (ac < 3)
        ft_error("The format must be similar as: ./push_swap 2 1 3 6 5 8");
    //list = malloc((ac - 1) * sizeof(*list));
    while (++i < 5)
        list = malloc(sizeof(*list));
}