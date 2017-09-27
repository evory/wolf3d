/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:29:20 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/27 19:32:42 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	wolf3d_init(t_ms *ms)
{
	ms->Xpos = 1;
	ms->Ypos = 1;
	ms->Xdir = -1;
	ms->Ydir = 0;
	ms->Xplane = 0;
	ms->Yplane = 0.66;
	ms->ms = 0.05;
	ms->rs = 0.05;
	ms->move_up = 0;
	ms->move_down = 0;
	ms->move_left = 0;
	ms->move_right = 0;
	ms->Xtext = 0;
	ms->Ytext = 0;
	load_textures(ms);
}

void	mlx_win_init(t_ms *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WDTH, HGHT, "wolf3d");
}

int		main(int ac, char **argv)
{
	t_ms *ms;

	if (ac != 2)
	{
		ft_putendl("Only 1 parameter. Select from \"maps\"");
		return (0);
	}
	if (!(ms = (t_ms *)malloc(sizeof(t_ms))))
		return (0);
	ms->name = argv[1];
	ms->fd = open(argv[1], O_RDONLY);
	ft_parser(ms);
	close(ms->fd);
	ms->fd = open(argv[1], O_RDONLY);
	ft_parser(ms);
	mlx_win_init(ms);
	mlx_hook(ms->win, 2, (1L << 0), key_press, ms);
	mlx_hook(ms->win, 3, (1L << 1), key_release, ms);
	wolf3d_init(ms);
	launch_wolf(ms);
	mlx_loop_hook(ms->mlx, move, ms);
	mlx_loop(ms->mlx);
}
