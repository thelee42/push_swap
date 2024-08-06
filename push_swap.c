/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:39:25 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 20:50:12 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 1)
		return (1);
	pile_a = (t_pile *)malloc(sizeof(t_pile));
	if (!pile_a)
		return (1);
	init_pile(pile_a, argc, argv);
	if (is_sorted(pile_a))
	{
		free_pile(pile_a);
		return (1);
	}
	pile_b = (t_pile *)malloc(sizeof(t_pile));
	if (!pile_b)
		return (1);
	init_pile_b(pile_b, pile_a->size);
	if (pile_a->size < 9)
		sort_small(pile_a, pile_b);
	else
		sort_big(pile_a, pile_b);
	free_pile(pile_b);
	free_pile(pile_a);
	return (0);
}
