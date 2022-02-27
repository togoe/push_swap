# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int             content;
	struct s_list	*next;
} t_list;

int		ft_atoi(const char *str)
{
	int			i;
	long int	convert;
	int			sign;

	i = 0;
	convert = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (convert > 2147483647 && sign == 1)
			return (-1);
		if (convert > 2147483648 && sign == -1)
			return (0);
		convert = convert * 10 + str[i] - '0';
		i++;
	}
	return (convert * sign);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = *alst;
	last = ft_lstlast(*alst);
	last->next = new;
}
int main(int ac, char **av)
{
    t_list *list = NULL;
	t_list *head_list = NULL;
	int i = 1;

	head_list = list;
	head_list = ft_lstnew(ft_atoi(av[1]));
	printf("%d maillon\n", i);
	while (++i < ac)
	{
		list = ft_lstnew(ft_atoi(av[i]));
		if (!list)
			return(printf("A revoir l'algo"));
		ft_lstadd_back(&head_list, list);
		printf("%d maillon\n", list->content);
	}
	//ft_lstiter(list, ft_atoi(av[++i]));
}