/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_radix1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:39 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:03:19 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bits_first_ab(t_pile *pile_a, t_pile *pile_b, int i)
{
	int	j;
	int	bits;

	j = 0;
	while (j < pile_a->size)
	{
		bits = (get_front(pile_a) >> i) & 3;
		if (bits < 2)
			push(pile_a, pile_b, 'b');
		else
			rotate(pile_a, 'a');
		j++;
	}
}

void	bits_second_1b(t_pile *pile_a, t_pile *pile_b, int i)
{
	int	j;
	int	bits;

	j = countpile(pile_b);
	while (j > 0)
	{
		bits = (get_front(pile_b) >> i) & 3;
		if (bits == 1)
			push(pile_b, pile_a, 'a');
		else if (bits == 0)
			rotate(pile_b, 'b');
		j--;
	}
	while (((get_front(pile_a) >> i) & 3) == 1)
		push(pile_a, pile_b, 'b');
}

void	bits_second_2a(t_pile *pile_a, t_pile *pile_b, int i)
{
	int	j;
	int	bits;

	j = countpile(pile_a);
	while (j > 0)
	{
		bits = (get_front(pile_a) >> i) & 3;
		if (bits == 2)
			push(pile_a, pile_b, 'b');
		else
			rotate(pile_a, 'a');
		j--;
	}
	while (pile_a->front != pile_a->rear)
		push(pile_a, pile_b, 'b');
}

void	bits_first_4(t_pile *pile_a, t_pile *pile_b, int i)
{
	int	j;
	int	bits;

	j = 0;
	while (j < pile_a->size)
	{
		bits = (get_front(pile_a) >> i) & 3;
		if (bits == 0)
		{
			push(pile_a, pile_b, 'b');
			if (countpile(pile_b) > 1)
				rotate(pile_b, 'b');
		}
		else if (bits == 1)
			push(pile_a, pile_b, 'b');
		else
			rotate(pile_a, 'a');
		j++;
	}
}
