/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:39:59 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 21:58:26 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct DequeArray
{
	int	front;
	int	rear;
	int	*data;
	int	size;
}		t_pile;

// init_pile
void	init_pile(t_pile *pile, int argc, char **argv);
void	init_pile_b(t_pile *pile, int size);
int		*str_array(char *str, int size);
int		*args_array(int argc, char **argv);
void	index_data(t_pile *pile, int *array);

//instructions
void	swap(t_pile *pile, char ab);
void	rotate(t_pile *pile, char ab);
void	rrotate(t_pile *pile, char ab);
void	push(t_pile *pile_from, t_pile *pile_to, char ab);
int		countpile(t_pile *pile);

//sort
void	sort_small(t_pile *pile_a, t_pile *pile_b);
void	sort_big(t_pile *pile_from, t_pile *pile_to);
void	radix_sort(t_pile *pile_a, t_pile *pile_b, int i, int max);
int		is_sorted(t_pile *pile);

//sort small
void	sort_3(t_pile *pile);
void	sort_3_b(t_pile *pile);
void	sort_4(t_pile *pile_a, t_pile *pile_b);
void	sort_5(t_pile *pile_a, t_pile *pile_b);
void	sort_6(t_pile *pile_a, t_pile *pile_b);

//sort radix
void	radix_1(t_pile *pile_a, t_pile *pile_b, int i);
void	radix_1_b(t_pile *pile_a, t_pile *pile_b, int i);
void	radix_2_ab(t_pile *pile_a, t_pile *pile_b, int i);
void	radix_2_ba(t_pile *pile_b, t_pile *pile_a, int i);
void	radix_4(t_pile *pile_a, t_pile *pile_b, int i);

void	bits_first_ab(t_pile *pile_a, t_pile *pile_b, int i);
void	bits_second_1b(t_pile *pile_a, t_pile *pile_b, int i);
void	bits_second_2a(t_pile *pile_a, t_pile *pile_b, int i);
void	bits_first_4(t_pile *pile_a, t_pile *pile_b, int i);
void	bits_first_ba(t_pile *pile_b, t_pile *pile_a, int i);
void	bits_second_1a(t_pile *pile_b, t_pile *pile_a, int i);
void	bits_second_2b(t_pile *pile_b, t_pile *pile_a, int i);

//utile
void	print_error(void);
void	free_pile(t_pile *pile);
void	dup_check(int *array, t_pile *pile);
int		atoi_check(char *str);
int		ft_atoi(char const *str);

void	add_rear(t_pile *pile, int data);
int		get_front(t_pile *pile);
int		get_rear(t_pile *pile);
void	add_front(t_pile *pile, int data);
void	delete_front(t_pile *pile);

int		countword(char const *str, char c);
char	*copyword(char const *str, int start, int end);
char	**ft_split(char *str, char c);
void	free_split(char **split, int size);
char	**allocate_split(char *str, char c);

#endif
