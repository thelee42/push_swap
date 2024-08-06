/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:28 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 20:49:29 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_pile *pile)
{
	int	a;
	int	b;
	int	c;

	a = pile->data[(pile->front + 1) % pile->size];
	b = pile->data[(pile->front + 2) % pile->size];
	c = pile->data[pile->rear];
	if (a < b && b > c && a < c)
	{
		swap(pile, 'a');
		rotate(pile, 'a');
	}
	else if (a > b && b < c && a < c)
		swap(pile, 'a');
	else if (a > b && b > c)
	{
		swap(pile, 'a');
		rrotate(pile, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(pile, 'a');
	else if (a < b && b > c && a > c)
		rrotate(pile, 'a');
}

void	sort_3_b(t_pile *pile)
{
	int	a;
	int	b;
	int	c;

	a = pile->data[(pile->front + 1) % pile->size];
	b = pile->data[(pile->front + 2) % pile->size];
	c = pile->data[pile->rear];
	if (a > b && b < c && a > c)
	{
		swap(pile, 'b');
		rotate(pile, 'b');
	}
	else if (a < b && b > c && a > c)
		swap(pile, 'b');
	else if (a < b && b < c)
	{
		swap(pile, 'b');
		rrotate(pile, 'b');
	}
	else if (a < b && b > c && a < c)
		rotate(pile, 'b');
	else if (a > b && b < c && a < c)
		rrotate(pile, 'b');
}

void	sort_4(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	front;

	i = 0;
	while (i < 4)
	{
		front = get_front(pile_a);
		if ((front == 0 || front == 3))
		{
			push(pile_a, pile_b, 'b');
			break ;
		}
		else
			rotate(pile_a, 'a');
		i++;
	}
	sort_3(pile_a);
	if (get_front(pile_b) == 3)
	{
		push(pile_b, pile_a, 'a');
		rotate(pile_a, 'a');
	}
	else
		push(pile_b, pile_a, 'a');
}

void	sort_5(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	remain;
	int	front;

	i = 0;
	remain = 0;
	while (i < 5 && remain < 2)
	{
		front = get_front(pile_a);
		if ((front == 0 || front == 1))
		{
			push(pile_a, pile_b, 'b');
			remain++;
		}
		else
			rotate(pile_a, 'a');
		i++;
	}
	sort_3(pile_a);
	if (get_front(pile_b) == 0)
		swap(pile_b, 'b');
	push(pile_b, pile_a, 'a');
	push(pile_b, pile_a, 'a');
}

void	sort_6(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	remain;
	int	front;

	i = 0;
	remain = 0;
	while (i < 6 && remain < 3)
	{
		front = get_front(pile_a);
		if ((front < 3))
		{
			push(pile_a, pile_b, 'b');
			remain++;
		}
		else
			rotate(pile_a, 'a');
		i++;
	}
	sort_3(pile_a);
	sort_3_b(pile_b);
	push(pile_b, pile_a, 'a');
	push(pile_b, pile_a, 'a');
	push(pile_b, pile_a, 'a');
}
