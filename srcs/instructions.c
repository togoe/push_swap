/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:08:15 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/19 22:52:55 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_two(t_list **lst)
{
	if ((*lst)->position > (*lst)->next->position)
		swap_a(lst);
	else
		return ;
}

void	ft_three(t_list **lst)
{
	if ((*lst)->position < (*lst)->next->position
		&& (*lst)->next->position > (*lst)->next->next->position)
	{
		reverse_rotate_a(lst);
		if (((*lst)->position > (*lst)->next->position
				&& (*lst)->position < (*lst)->next->next->position
				&& (*lst)->next->position < (*lst)->next->next->position))
			swap_a(lst);
	}
	else if (((*lst)->position > (*lst)->next->position
			&& (*lst)->position < (*lst)->next->next->position)
		&& (*lst)->next->position < (*lst)->next->next->position)
		swap_a(lst);
	else if ((*lst)->position > (*lst)->next->position
		&& (*lst)->position > (*lst)->next->next->position)
	{
		rotate_a(lst);
		if (((*lst)->position > (*lst)->next->position
				&& (*lst)->position < (*lst)->next->next->position)
			&& (*lst)->next->position < (*lst)->next->next->position)
			swap_a(lst);
	}
	else
		return ;
}

void	ft_four(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3 && ft_check_order(*stack_a))
	{
		if ((*stack_a)->position == 0 && ft_check_order(*stack_a))
			push_b(stack_a, &stack_b);
		else if (ft_check_order(*stack_a))
			rotate_a(stack_a);
	}
	if (ft_lstsize(*stack_a) == 3)
		ft_three(stack_a);
	if (ft_lstsize(stack_b) > 0)
		push_a(stack_a, &stack_b);
}

void	ft_five(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3)
	{
		if (((*stack_a)->position == 0) || ((*stack_a)->position == 1))
			push_b(stack_a, &stack_b);
		else if (((*stack_a)->position != 0) || ((*stack_a)->position != 1))
			rotate_a(stack_a);
	}
	if ((stack_b)->next && ((stack_b)->position < (stack_b)->next->position))
		swap_b(&stack_b);
	ft_three(stack_a);
	while (ft_lstsize(stack_b) > 0)
		push_a(stack_a, &stack_b);
}

void	radix_x(t_list **stack_a)
{
	t_list	*stack_b;
	int		len;
	int		i;
	int		j;

	stack_b = NULL;
	len = ft_lstsize(*stack_a);
	i = 0;
	while (i < len && ft_check_order(*stack_a))
	{
		j = 0;
		while (j < len)
		{
			if (((((*stack_a)->position) >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, &stack_b);
			j++;
		}
		while (ft_lstsize(stack_b) > 0)
			push_a(stack_a, &stack_b);
		i++;
	}
}
