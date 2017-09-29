/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:17:54 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/29 03:20:59 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	dda_init(t_ms *ms)
{
	ms->Xdeltadist = sqrt(1 + (ms->Yradiry * ms->Yradiry)
			/ (ms->Xradiry * ms->Xradiry));
	ms->Ydeltadist = sqrt(1 + (ms->Xradiry * ms->Xradiry)
			/ (ms->Yradiry * ms->Yradiry));
	if (ms->Xradiry < 0)
	{
		ms->stepx = -1;
		ms->Xsidedist = (ms->Xraposy - ms->mapx) * ms->Xdeltadist;
	}
	else
	{
		ms->stepx = 1;
		ms->Xsidedist = (ms->mapx + 1.0 - ms->Xraposy) * ms->Xdeltadist;
	}
	if (ms->Yradiry < 0)
	{
		ms->stepy = -1;
		ms->Ysidedist = (ms->Yraposy - ms->mapy) * ms->Ydeltadist;
	}
	else
	{
		ms->stepy = 1;
		ms->Ysidedist = (ms->mapy + 1.0 - ms->Yraposy) * ms->Ydeltadist;
	}
}

void	dda(t_ms *ms)
{
	ms->hit = 0;
	while (ms->hit == 0)
	{
		if (ms->Xsidedist < ms->Ysidedist)
		{
			ms->Xsidedist += ms->Xdeltadist;
			ms->mapx += ms->stepx;
			ms->side = 0;
		}
		else
		{
			ms->Ysidedist += ms->Ydeltadist;
			ms->mapy += ms->stepy;
			ms->side = 1;
		}
		if (ms->array[ms->mapx][ms->mapy] > 0)
			ms->hit = 1;
	}
}

void	ray_casting_init(t_ms *ms, int x)
{
	ms->Xcam = 2 * x / (double)(WDTH) - 1;
	ms->Xraposy = ms->posx;
	ms->Yraposy = ms->posy;
	ms->Xradiry = ms->dirx + ms->Xplane * ms->Xcam;
	ms->Yradiry = ms->diry + ms->planey * ms->Xcam;
	ms->mapx = (int)ms->Xraposy;
	ms->mapy = (int)ms->Yraposy;
	dda_init(ms);
	dda(ms);
	if (ms->side == 0)
		ms->walldist = (ms->mapx - ms->Xraposy +
				(1 - ms->stepx) / 2) / ms->Xradiry;
	else
		ms->walldist = (ms->mapy - ms->Yraposy +
				(1 - ms->stepy) / 2) / ms->Yradiry;
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
