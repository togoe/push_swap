/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:13:11 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/19 17:13:40 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_error(char *str);
int		ft_fill_nb(int ac, char **av, t_list **stack_a);
void	ft_free(t_list **lst);
int		ft_check_pars(int ac, char **av);
void	ft_two(t_list **lst);
void	ft_push_swap(t_list **lst);
void	ft_three_instructions(t_list **lst);
void	ft_three(t_list **lst);
void	ft_four(t_list **stack_a);
void	ft_five(t_list **stack_a);
void	radix_x(t_list **stack_a);
int		main(int ac, char **av);
int		find_doubble_and_position(t_list *lst);
int		ft_check_order(t_list *list);
void	ft_swap(t_list **list);
void	swap_a(t_list **list);
void	swap_b(t_list **list);
void	swap_a_b(t_list **list_a, t_list **list_b);
void	push_a(t_list **list, t_list **list_b);
void	push_b(t_list **list, t_list **list_b);
void	ft_reverse_rotate(t_list **list);
void	reverse_rotate_a(t_list **list);
void	reverse_rotate_b(t_list **list);
void	reverse_rotate_a_b(t_list **list_a, t_list **list_b);
void	ft_rotate(t_list **list);
void	rotate_a(t_list **list);
void	rotate_b(t_list **list);
void	rotate_a_b(t_list **list_a, t_list **list_b);
int		ft_check_string(char *av);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_ifelse(int c);

#endif