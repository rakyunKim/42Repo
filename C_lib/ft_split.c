/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakim <fkrdbs234@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:10:10 by rakim             #+#    #+#             */
/*   Updated: 2024/10/08 16:05:17 by rakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	free_all(char **result, int result_len)
{
	int	idx;

	idx = 0;
	while (idx < result_len)
		free(result[idx++]);
	free(result);
}

void	malloc_each(char **result, char const*s, char c, int result_len)
{
	int	out_idx;
	int	s_idx;
	int	len;

	out_idx = 0;
	s_idx = 0;
	len = 0;
	while (out_idx < result_len)
	{
		while (s[s_idx++] && s[s_idx] != c)
			len++;
		if (len > 0)
		{
			result[out_idx] = (char *)malloc(sizeof(char) * (len + 1));
			if (result[out_idx] == NULL)
			{
				free_all(result, result_len);
				return ;
			}
			result[out_idx++][len] = '\0';
		}
		len = 0;
	}
}

int	get_total_len(char const *s, char c)
{
	int	prev_posibble;
	int	result;
	int	s_idx;

	result = 0;
	s_idx = 0;
	prev_posibble = 0;
	while (s[s_idx])
	{
		if (s[s_idx] == c && prev_posibble)
		{
			result++;
			prev_posibble = 0;
		}
		else if (s[s_idx] != c)
			prev_posibble = 1;
		s_idx++;
	}
	if (prev_posibble)
		result++;
	return (result);
}

void	copy_value(char **result, char const *s, char c)
{
	int	s_idx;
	int	out_idx;
	int	in_idx;
	int	is_change;

	s_idx = 0;
	out_idx = 0;
	in_idx = 0;
	is_change = 0;
	while (s[s_idx])
	{
		while (s[s_idx] != c && s[s_idx])
		{
			result[out_idx][in_idx] = s[s_idx];
			in_idx++;
			s_idx++;
			is_change = 1;
		}
		if (is_change)
			out_idx++;
		else
			s_idx++;
		is_change = 0;
		in_idx = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		result_len;

	result_len = get_total_len(s, c);
	result = (char **)malloc(sizeof(char *) * result_len + 1);
	if (result == NULL)
		return (NULL);
	malloc_each(result, s, c, result_len);
	if (result == NULL)
		return (NULL);
	copy_value(result, s, c);
	result[result_len] = NULL;
	return (result);
}