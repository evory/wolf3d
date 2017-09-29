/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:24:21 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/29 03:41:12 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int		**ft_fill_array(int x, int y, char **splitstr, int **tab)
{
	while (splitstr[x])
	{
		tab[y][x] = ft_atoi(splitstr[x]);
		free(splitstr[x]);
		x++;
	}
	free(splitstr);
	return (tab);
}

int		**ft_malloc_array(int x, int y, t_ms *ms)
{
	int **tab;

	ms->map_height = y;
	tab = NULL;
	if (!(tab = malloc(sizeof(int*) * y--)))
		exit(-1);
	while (y >= 0)
	{
		if (!(tab[y] = malloc(sizeof(int) * x - 1)))
			exit(-1);
		y--;
	}
	return (tab);
}

void	ft_parser(t_ms *ms)
{
	char	*line;
	char	**splitstr;
	int		x;
	int		y;

	y = 0;
	while (get_next_line(ms->fd, &line) != 0)
	{
		x = 0;
		splitstr = ft_strsplit(line, ' ');
		free(line);
		if (ms->array == NULL)
		{
			while (splitstr[x])
				free(splitstr[x++]);
			free(splitstr);
			ms->map_width = x;
		}
		else
			ms->array = ft_fill_array(x, y, splitstr, ms->array);
		y++;
	}
	if (ms->array == NULL)
		ms->array = ft_malloc_array(x, y, ms);
}
