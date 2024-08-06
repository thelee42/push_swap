/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:21 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:00:52 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_1(t_pile *pile_a, t_pile *pile_b, int i)
{
	int	j;

	j = 0;
	while (j < pile_a->size)
	{
		if ((get_front(pile_a) >> i) & 1)
			rotate(pile_a, 'a');
		else
			push(pile_a, pile_b, 'b');
		j++;
	}
	while (pile_b->front != pile_b->rear)
		push(pile_b, pile_a, 'a');
}

void	radix_1_b(t_pile *pile_b, t_pile *pile_a, int i)
{
	int	j;

	j = 0;
	while (j < pile_b->size)
	{
		if ((get_front(pile_b) >> i) & 1)
			push(pile_b, pile_a, 'a');
		else
			rotate(pile_b, 'b');
		j++;
	}
	while (pile_b->front != pile_b->rear)
		push(pile_b, pile_a, 'a');
}

void	radix_2_ab(t_pile *pile_a, t_pile *pile_b, int i)
{
	bits_first_ab(pile_a, pile_b, i);
	bits_second_1b(pile_a, pile_b, i);
	bits_second_2a(pile_a, pile_b, i);
}

void	radix_2_ba(t_pile *pile_b, t_pile *pile_a, int i)
{
	bits_first_ba(pile_b, pile_a, i);
	bits_second_1a(pile_b, pile_a, i);
	bits_second_2b(pile_b, pile_a, i);
}

void	radix_4(t_pile *pile_a, t_pile *pile_b, int i)
{
	bits_first_4(pile_a, pile_b, i);
	bits_second_2a(pile_a, pile_b, i);
	radix_2_ba(pile_b, pile_a, i + 2);
}
