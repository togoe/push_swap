#include "push_swap.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int             content;
	struct s_list	*next;
} t_list;

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int ft_create_stack_a(int ac, char **av)
{
    t_list  *stack_a;

    stack_a = ft_lstnew(av[1]);
    
}

int main(int ac, char **av)
{
  t_list  *stack_b;
    t_list *list = NULL;
	t_list *head_list = NULL;
	int i = 1;

	head_list = list;
	list = ft_lstnew(ft_atoi(av[1]));
	printf("%d maillon\n", list->content);
	while (++i < ac)
	{
		list = ft_lstnew(ft_atoi(av[i]));
		if (!list)
			return(printf("A revoir l'algo"));
		ft_lstadd_back(&head_list, list);
		printf("%d maillon\n", list->content);
	}
}