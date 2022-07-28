/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:07:46 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/19 20:20:01 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(t_list **lst)
{
	t_list	*stack_a;

	while (*lst)
	{
		stack_a = (*lst);
		(*lst) = (stack_a)->next;
		free(stack_a);
	}
	stack_a = NULL;
}

int	find_doubble_and_position(t_list *lst)
{
	t_list	*tmp;
	int		number;

	while (lst)
	{
		tmp = lst;
		number = tmp->content;
		while (tmp)
		{
			tmp = tmp->next;
			if (tmp && number == tmp->content)
				return (1);
			if (tmp && tmp->content > number)
				tmp->position += 1;
			else if (tmp && tmp->content < number)
				lst->position += 1;
		}
		lst = lst->next;
	}
	return (0);
}

void	ft_push_swap(t_list **lst)
{
	t_list	*stack_a;

	stack_a = *lst;
	if (ft_lstsize(stack_a) == 2)
		ft_two(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		ft_three(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		ft_four(&stack_a);
	else if (ft_lstsize(stack_a) == 5)
		ft_five(&stack_a);
	else
		radix_x(&stack_a);
	ft_free(&stack_a);
}

int	ft_fill_nb(int ac, char **av, t_list **stack_a)
{
	int		i;
	t_list	*list;

	i = 1;
	(*stack_a) = ft_lstnew(ft_atoi(av[1]));
	if (!(*stack_a))
		return (ft_error("Error"));
	(*stack_a)->position = 0;
	list = *stack_a;
	while (++i < ac)
	{
		list = ft_lstnew(ft_atoi(av[i]));
		if (!list)
		{
			ft_free(stack_a);
			return (ft_error("Error"));
		}
		list->position = 0;
		ft_lstadd_back(stack_a, list);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_list	*stack_a;

	stack_a = NULL;
	ft_check_pars(ac, av);
	ft_fill_nb(ac, av, &stack_a);
	if (find_doubble_and_position(stack_a))
	{
		ft_free(&stack_a);
		return (ft_error("Error"));
	}
	list = stack_a;
	if (!ft_check_order(list))
	{
		ft_free(&list);
		exit(EXIT_SUCCESS);
	}
	if (ft_check_order(list))
		ft_push_swap(&stack_a);
	return (0);
}
