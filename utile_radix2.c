/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_radix2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:43 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:04:06 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bits_first_ba(t_pile *pile_b, t_pile *pile_a, int i)
{
	int	j;
	int	bits;

	j = 0;
	while (j < pile_b->size)
	{
		bits = (get_front(pile_b) >> i) & 3;
		if (bits > 1)
			push(pile_b, pile_a, 'a');
		else
			rotate(pile_b, 'b');
		j++;
	}
}

void	bits_second_1a(t_pile *pile_b, t_pile *pile_a, int i)
{
	int	j;
	int	bits;

	j = countpile(pile_a);
	while (j > 0)
	{
		bits = (get_front(pile_a) >> i) & 3;
		if (bits == 2)
			push(pile_a, pile_b, 'b');
		else if (bits == 3)
			rotate(pile_a, 'a');
		j--;
	}
	while (((get_front(pile_b) >> i) & 3) > 1)
		push(pile_b, pile_a, 'a');
}

void	bits_second_2b(t_pile *pile_b, t_pile *pile_a, int i)
{
	int	j;
	int	bits;

	j = countpile(pile_b);
	while (j > 0)
	{
		bits = (get_front(pile_b) >> i) & 3;
		if (bits == 1)
			push(pile_b, pile_a, 'a');
		else
			rotate(pile_b, 'b');
		j--;
	}
	while (pile_b->front != pile_b->rear)
		push(pile_b, pile_a, 'a');
}
