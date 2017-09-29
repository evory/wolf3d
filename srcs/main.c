/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:29:20 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/29 03:31:58 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	wolf3d_init(t_ms *ms)
{
	ms->posx = 6;
	ms->posy = 6;
	ms->dirx = -1;
	ms->diry = 0;
	ms->planex = 0;
	ms->planey = 0.66;
	ms->ms = 0.06;
	ms->rs = 0.05;
	ms->move_up = 0;
	ms->move_down = 0;
	ms->move_left = 0;
	ms->move_right = 0;
	ms->texture = 1;
	ms->textx = 0;
	ms->texty = 0;
	load_textures(ms);
}

void	mlx_win_init(t_ms *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WDTH, HGHT, "wolf3d");
}

int		main(int ac, char **argv)
{
	t_ms	*ms;

	(void)argv;
	if (ac != 1)
	{
		ft_putendl("No parameter require");
		return (0);
	}
	if (!(ms = (t_ms *)malloc(sizeof(t_ms))))
		return (0);
	ms->fd = open("map", O_RDONLY);
	ft_parser(ms);
	close(ms->fd);
	ms->fd = open("map", O_RDONLY);
	ft_parser(ms);
	close(ms->fd);
	mlx_win_init(ms);
	mlx_hook(ms->win, 17, 0L, cross_close, ms);
	mlx_hook(ms->win, 2, (1L << 0), key_press, ms);
	mlx_hook(ms->win, 3, (1L << 1), key_release, ms);
	wolf3d_init(ms);
	launch_wolf(ms);
	mlx_loop_hook(ms->mlx, move, ms);
	mlx_loop(ms->mlx);
	free(ms);
}
