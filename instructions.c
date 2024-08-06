/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:38:38 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:58:46 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile, char ab)
{
	int	temp;

	temp = pile->data[(pile->front + 1) % pile->size];
	pile->data[(pile->front + 1) % pile->size] = pile->data[(pile->front + 2)
		% pile->size];
	pile->data[(pile->front + 2) % pile->size] = temp;
	if (ab == 'a')
		write(1, "sa\n", 3);
	if (ab == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_pile *pile, char ab)
{
	int	temp;

	temp = get_front(pile);
	pile->front = (pile->front + 1) % pile->size;
	add_rear(pile, temp);
	if (ab == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrotate(t_pile *pile, char ab)
{
	int	temp;

	temp = get_rear(pile);
	pile->rear = (pile->rear - 1 + pile->size) % pile->size;
	add_front(pile, temp);
	if (ab == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push(t_pile *pile_from, t_pile *pile_to, char ab)
{
	int	temp;

	temp = get_front(pile_from);
	add_front(pile_to, temp);
	delete_front(pile_from);
	if (ab == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

int	countpile(t_pile *pile)
{
	if (get_front(pile) && (pile->front == pile->rear))
		return (pile->size);
	else
	{
		if (pile->front < pile->rear)
			return (pile->rear - pile->front);
		else
			return (pile->size - pile->front + pile->rear);
	}
}
