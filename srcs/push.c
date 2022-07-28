/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:08:42 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/09 21:45:13 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_list **list, t_list **list_b)
{
	t_list	*tmp;

	if (*list_b == NULL)
		return ;
	tmp = *list;
	*list = *list_b;
	*list_b = (*list_b)->next;
	(*list)->next = tmp;
	tmp = NULL;
	write(1, "pa\n", 3);
}

void	push_b(t_list **list, t_list **list_b)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	tmp = *list_b;
	*list_b = *list;
	*list = (*list)->next;
	(*list_b)->next = tmp;
	tmp = NULL;
	write(1, "pb\n", 3);
}
