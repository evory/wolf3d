/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:24:21 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/27 19:10:44 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	check_map_validity(t_ms *ms)
{
	if (ms->array[1][1] != 0)
		{
			ft_putendl("Bad map...");
			exit(1);
		}
}

void	check_map_name(t_ms *ms)
{
	if (ft_strcmp(ms->name, "maps/map1.wolf") != 0 &&
	ft_strcmp(ms->name, "maps/map2.wolf") != 0)
	{
		ft_putendl("Wrong map, enter [maps/map1.wolf] or [maps/map2.wolf]");
		exit(1);
	}
}

int		**ft_fill_array(int x, int y, char **splitstr, int **tab)
{
	while (splitstr[x])
	{
		tab[y][x] = ft_atoi(splitstr[x]);
		x++;
	}
	return (tab);
}

int		**ft_malloc_array(int x, int y)
{
	int **tab;

	tab = NULL;
	tab = malloc(sizeof(int*) * y--);
	while (y + 1 >= 0)
	{
		tab[y] = malloc(sizeof(int) * x);
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
	check_map_name(ms);
	while (get_next_line(ms->fd, &line) != 0)
	{
		x = 0;
		splitstr = ft_strsplit(line, ' ');
		if (ms->array == NULL)
		{
			while (splitstr[x])
			{
				printf("%d\n", x);
				x++;
			}
			ms->map_lenght = x;
		}
		else
		{
			ms->array = ft_fill_array(x, y, splitstr, ms->array);
		}
		if (ms->map_lenght < 3 && ms->array == NULL)
		{
			ft_putendl("Bad map...");
			exit(1);
		}
		y++;
	}
	if (ms->array == NULL)
		ms->array = ft_malloc_array(x, y);
	free(line);
}
