/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelee <thelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:49:53 by thelee            #+#    #+#             */
/*   Updated: 2024/07/08 22:17:49 by thelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countword(char const *str, char c)
{
	int	count;
	int	lettre;

	count = 0;
	lettre = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str != c && lettre == 0)
		{
			lettre = 1;
			count++;
		}
		else if (*str == c)
			lettre = 0;
		str++;
	}
	return (count);
}

char	*copyword(char const *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) + (end - start + 1));
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**allocate_split(char *str, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (countword(str, c) + 1));
	if (!str || !split)
		return (NULL);
	return (split);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		start;
	char	**split;

	if (countword(str, c) == 0)
		return (NULL);
	split = allocate_split(str, c);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		split[j] = copyword(str, start, i);
		if (!split[j])
			return (free_split(split, j), NULL);
		j++;
	}
	split[j] = 0;
	return (split);
}

void	free_split(char **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
