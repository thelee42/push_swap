/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:48 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 22:07:25 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_pile(t_pile *pile)
{
	free(pile->data);
	free(pile);
}

void	dup_check(int *array, t_pile *pile)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile->size)
	{
		j = i + 1;
		while (j < pile->size)
		{
			if (array[i] == array[j])
			{
				free(array);
				free_pile(pile);
				print_error();
			}
			j++;
		}
		i++;
	}
}

int	ft_atoi(char const *str)
{
	int			sign;
	int			i;
	long long	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return ((int)(nb * sign));
}

int	atoi_check(char *str)
{
	long long	nb;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if ((sign == 1 && nb > 2147483647)
			|| (sign == -1 && nb > 2147483648))
			return (1);
	}
	return (str[i] != '\0');
}
