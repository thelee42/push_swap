/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:36 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:02:13 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rear(t_pile *pile, int data)
{
	pile->rear = (pile->rear + 1) % pile->size;
	pile->data[pile->rear] = data;
}

int	get_front(t_pile *pile)
{
	return (pile->data[(pile->front + 1) % pile->size]);
}

int	get_rear(t_pile *pile)
{
	return (pile->data[pile->rear]);
}

void	add_front(t_pile *pile, int data)
{
	pile->data[pile->front] = data;
	pile->front = (pile->front - 1 + pile->size) % pile->size;
}

void	delete_front(t_pile *pile)
{
	pile->front = (pile->front + 1) % pile->size;
}
