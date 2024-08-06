/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:27:28 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:27:39 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_pile(t_pile *pile, int argc, char **argv)
{
	pile->front = 0;
	pile->rear = 0;
	if (argc > 2)
	{
		pile->size = argc - 1;
		pile->data = (int *)malloc(sizeof(int) * pile->size);
		index_data(pile, args_array(argc, argv));
	}
	else if (argc == 2)
	{
		pile->size = countword(argv[1], ' ');
		pile->data = (int *)malloc(sizeof(int) * pile->size);
		index_data(pile, str_array(argv[1], pile->size));
	}
}

void	init_pile_b(t_pile *pile, int size)
{
	pile->front = 0;
	pile->rear = 0;
	pile->size = size;
	pile->data = (int *)malloc(sizeof(int) * size);
}

int	*str_array(char *str, int size)
{
	int		i;
	char	**strarray;
	int		*array;

	strarray = ft_split(str, ' ');
	if (!strarray)
		return (NULL);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (free_split(strarray, size), NULL);
	i = -1;
	while (strarray[++i])
	{
		if (atoi_check(strarray[i]))
		{
			free_split(strarray, size);
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(strarray[i]);
	}
	free_split(strarray, size);
	return (array);
}

int	*args_array(int argc, char **argv)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		if (atoi_check(argv[i + 1]))
		{
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (array);
}

void	index_data(t_pile *pile, int *array)
{
	int	i;
	int	j;
	int	index_data;

	i = 0;
	if (!array)
	{
		free_pile(pile);
		print_error();
	}
	dup_check(array, pile);
	while (i < pile->size)
	{
		j = 0;
		index_data = 0;
		while (j < pile->size)
		{
			if (array[j] < array[i])
				index_data++;
			j++;
		}
		add_rear(pile, index_data);
		i++;
	}
	free(array);
}
