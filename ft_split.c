/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:04:12 by migugar2          #+#    #+#             */
/*   Updated: 2024/09/23 19:24:51 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	get_q_words(const char *s, int c)
{
	size_t	q;
	size_t	i;

	q = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			q++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (q);
}

static size_t	get_l_word(const char *s, int c)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != c)
		l++;
	return (l);
}

static char	**free_r(char **r, size_t i)
{
	while (i > 0)
	{
		i--;
		free(r[i]);
	}
	free(r);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	q;
	size_t	l;
	size_t	i;
	size_t	j;

	q = get_q_words(s, c);
	r = (char **)malloc(sizeof(char *) * (q + 1));
	if (r == NULL)
		return (r);
	i = 0;
	j = 0;
	while (i < q)
	{
		while (s[j] && s[j] == c)
			j++;
		l = get_l_word(s + j, c);
		r[i] = ft_substr(s, j, l);
		if (r[i] == NULL)
			return (free_r(r, i));
		i++;
		j += l;
	}
	r[i] = NULL;
	return (r);
}
