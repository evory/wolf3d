/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:17:54 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/29 03:24:37 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	dda_init(t_ms *ms)
{
	ms->deltadistx = sqrt(1 + (ms->radiry * ms->radiry)
			/ (ms->radirx * ms->radirx));
	ms->deltadisty = sqrt(1 + (ms->radirx * ms->radirx)
			/ (ms->radiry * ms->radiry));
	if (ms->radirx < 0)
	{
		ms->stepx = -1;
		ms->sidedistx = (ms->raposx - ms->mapx) * ms->deltadistx;
	}
	else
	{
		ms->stepx = 1;
		ms->sidedistx = (ms->mapx + 1.0 - ms->raposx) * ms->deltadistx;
	}
	if (ms->radiry < 0)
	{
		ms->stepy = -1;
		ms->sidedisty = (ms->raposy - ms->mapy) * ms->deltadisty;
	}
	else
	{
		ms->stepy = 1;
		ms->sidedisty = (ms->mapy + 1.0 - ms->raposy) * ms->deltadisty;
	}
}

void	dda(t_ms *ms)
{
	ms->hit = 0;
	while (ms->hit == 0)
	{
		if (ms->sidedistx < ms->sidedisty)
		{
			ms->sidedistx += ms->deltadistx;
			ms->mapx += ms->stepx;
			ms->side = 0;
		}
		else
		{
			ms->sidedisty += ms->deltadisty;
			ms->mapy += ms->stepy;
			ms->side = 1;
		}
		if (ms->array[ms->mapx][ms->mapy] > 0)
			ms->hit = 1;
	}
}

void	ray_casting_init(t_ms *ms, int x)
{
	ms->camx = 2 * x / (double)(WDTH) - 1;
	ms->raposx = ms->posx;
	ms->raposy = ms->posy;
	ms->radirx = ms->dirx + ms->planex * ms->camx;
	ms->radiry = ms->diry + ms->planey * ms->camx;
	ms->mapx = (int)ms->raposx;
	ms->mapy = (int)ms->raposy;
	dda_init(ms);
	dda(ms);
	if (ms->side == 0)
		ms->walldist = (ms->mapx - ms->raposx +
				(1 - ms->stepx) / 2) / ms->radirx;
	else
		ms->walldist = (ms->mapy - ms->raposy +
				(1 - ms->stepy) / 2) / ms->radiry;
}

void	launch_wolf(t_ms *ms)
{
	ms->x = -1;
	ms->img = mlx_new_image(ms->mlx, WDTH, HGHT);
	ms->img_ptr = mlx_get_data_addr(ms->img, &ms->bpp, &ms->sl, &ms->endian);
	while (++ms->x < WDTH)
	{
		ray_casting_init(ms, ms->x);
		ms->lineheight = (int)(HGHT / ms->walldist);
		ms->start = -ms->lineheight / 2 + HGHT / 2;
		if (ms->start < 0)
			ms->start = 0;
		ms->end = ms->lineheight / 2 + HGHT / 2;
		if (ms->end >= HGHT)
			ms->end = HGHT - 1;
		if (ms->side == 1)
			ms->color = 0x31B404;
		else
			ms->color = 0x0B3B39;
		draw_wall(ms->x, ms->start - 1, ms->end, ms);
		sky_ground(ms, ms->x);
	}
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	mlx_destroy_image(ms->mlx, ms->img);
}
