/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:32 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:01:53 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->size == 2)
		swap(pile_a, 'a');
	if (pile_a->size == 3)
		sort_3(pile_a);
	else if (pile_a->size == 4)
		sort_4(pile_a, pile_b);
	else if (pile_a->size == 5)
		sort_5(pile_a, pile_b);
	else if (pile_a->size == 6)
		sort_6(pile_a, pile_b);
	else if (pile_a->size > 6)
	{
		radix_2_ab(pile_a, pile_b, 0);
		radix_1_b(pile_b, pile_a, 2);
	}
}

void	sort_big(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	max;

	max = 0;
	while (((pile_a->size - 1) >> max) != 0)
		max++;
	radix_4(pile_a, pile_b, 0);
	i = 4;
	radix_sort(pile_a, pile_b, i, max);
}

void	radix_sort(t_pile *pile_a, t_pile *pile_b, int i, int max)
{
	while ((i + 4) <= max)
	{
		radix_2_ab(pile_a, pile_b, i);
		radix_2_ba(pile_b, pile_a, i + 2);
		i += 4;
	}
	if (max % 4 == 1)
		radix_1(pile_a, pile_b, i);
	if (max % 4 == 2)
	{
		radix_1(pile_a, pile_b, i);
		radix_1(pile_a, pile_b, i + 1);
	}
	if (max % 4 == 3)
	{
		radix_2_ab(pile_a, pile_b, i);
		radix_1_b(pile_b, pile_a, i + 2);
	}
}

int	is_sorted(t_pile *pile)
{
	int	i;

	i = (pile->front + 1) % pile->size;
	while (i != pile->rear)
	{
		if (pile->data[i] > pile->data[(i + 1) % pile->size])
			return (0);
		i = (i + 1) % pile->size;
	}
	return (1);
}
