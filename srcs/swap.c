/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:09:32 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/09 21:46:51 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*tmp1;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
	tmp1 = (*list)->next;
	(*list)->next = tmp1->next;
	tmp1->next = *list;
	*list = tmp1;
	tmp1 = NULL;
}

void	swap_a(t_list **list)
{
	ft_swap(list);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **list)
{
	ft_swap(list);
	write(1, "sb\n", 3);
}

void	swap_a_b(t_list **list_a, t_list **list_b)
{
	if (*list_a && *list_b)
	{
		ft_swap(list_a);
		ft_swap(list_b);
	}
	write(1, "ss\n", 3);
}
