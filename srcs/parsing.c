/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:28:03 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/19 23:59:09 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_ifelse(int c)
{
	if (!(c == '-' || c == '+'))
		return (0);
	return (1);
}

int	ft_check_string(char *av)
{
	int	i;

	if (!ft_ifelse(av[0]) && !ft_isdigit(av[0]))
		return (0);
	if (ft_ifelse(av[0]) && !av[1])
		return (0);
	i = 1;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_pars(int ac, char **av)
{
	int	j;

	j = 1;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac == 2 && (ft_strlen(av[1]) == 0 || ft_strlen(av[j]) >= 12))
		ft_error("Error");
	if (ac >= 2 && ft_check_string(av[1]))
		ft_atoi(av[1]);
	while (av[j])
	{
		ft_atoi(av[j]);
		if (ac >= 2 && !ft_check_string(av[j]))
			return (ft_error("Error"));
		if (ft_strlen(av[j]) == 0 || ft_strlen(av[j]) >= 12)
			ft_error("Error");
		j++;
	}
	return (0);
}
