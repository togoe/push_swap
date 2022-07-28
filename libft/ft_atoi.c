/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:13:44 by ctogoe            #+#    #+#             */
/*   Updated: 2022/07/16 10:43:09 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	convert;
	int				sign;

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
		convert = convert * 10 + str[i] - '0';
		i++;
		if (convert > 2147483647 && sign == 1)
			return (ft_err("Error"));
		if (convert > 2147483648 && sign == -1)
			return (ft_err("Error"));
	}
	return (convert * sign);
}
