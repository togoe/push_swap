/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:08:51 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/09 21:46:19 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_rotate(t_list **list)
{
	t_list	*tmp1;
	int		len;
	int		i;

	i = -1;
	len = ft_lstsize(*list);
	tmp1 = *list;
	while (tmp1 && ++i < len - 1)
		tmp1 = tmp1->next;
	tmp1->next = *list;
	*list = tmp1;
	i = -1;
	while (tmp1 && ++i < len - 1)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	tmp1 = NULL;
}

void	reverse_rotate_a(t_list **list)
{
	ft_reverse_rotate(list);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **list)
{
	ft_reverse_rotate(list);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_list **list_a, t_list **list_b)
{
	if (*list_a && *list_b)
	{
		ft_reverse_rotate(list_a);
		ft_reverse_rotate(list_b);
	}
	write(1, "rrr\n", 4);
}
