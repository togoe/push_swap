/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:09:24 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/09 21:46:40 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		len;
	int		i;

	i = -1;
	len = ft_lstsize(*list);
	tmp1 = *list;
	tmp2 = *list;
	while (tmp1 && ++i < len - 1)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	*list = (*list)->next;
	tmp2->next = NULL;
	tmp1 = NULL;
	tmp2 = NULL;
}

void	rotate_a(t_list **list)
{
	ft_rotate(list);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **list)
{
	ft_rotate(list);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_list **list_a, t_list **list_b)
{
	if (*list_a && *list_b)
	{
		ft_rotate(list_a);
		ft_rotate(list_b);
	}
	write(1, "rr\n", 3);
}
