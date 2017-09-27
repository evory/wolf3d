/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:17:54 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/27 17:32:55 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	dda_init(t_ms *ms)
{
	ms->Xdeltadist = sqrt(1 + (ms->Yraydir * ms->Yraydir)
			/ (ms->Xraydir * ms->Xraydir));
	ms->Ydeltadist = sqrt(1 + (ms->Xraydir * ms->Xraydir)
			/ (ms->Yraydir * ms->Yraydir));
	if (ms->Xraydir < 0)
	{
		ms->Xstep = -1;
		ms->Xsidedist = (ms->Xraypos - ms->Xmap) * ms->Xdeltadist;
	}
	else
	{
		ms->Xstep = 1;
		ms->Xsidedist = (ms->Xmap + 1.0 - ms->Xraypos) * ms->Xdeltadist;
	}
	if (ms->Yraydir < 0)
	{
		ms->Ystep = -1;
		ms->Ysidedist = (ms->Yraypos - ms->Ymap) * ms->Ydeltadist;
	}
	else
	{
		ms->Ystep = 1;
		ms->Ysidedist = (ms->Ymap + 1.0 - ms->Yraypos) * ms->Ydeltadist;
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
			ms->Xmap += ms->Xstep;
			ms->side = 0;
		}
		else
		{
			ms->Ysidedist += ms->Ydeltadist;
			ms->Ymap += ms->Ystep;
			ms->side = 1;
		}
		if (ms->array[ms->Xmap][ms->Ymap] > 0)
			ms->hit = 1;
	}
}

void	ray_casting_init(t_ms *ms, int x)
{
	ms->Xcam = 2 * x / (double)(WDTH) - 1;
	ms->Xraypos = ms->Xpos;
	ms->Yraypos = ms->Ypos;
	ms->Xraydir = ms->Xdir + ms->Xplane * ms->Xcam;
	ms->Yraydir = ms->Ydir + ms->Yplane * ms->Xcam;
	ms->Xmap = (int)ms->Xraypos;
	ms->Ymap = (int)ms->Yraypos;
	dda_init(ms);
	dda(ms);
	if (ms->side == 0)
		ms->walldist = (ms->Xmap - ms->Xraypos +
				(1 - ms->Xstep) / 2) / ms->Xraydir;
	else
		ms->walldist = (ms->Ymap - ms->Yraypos +
				(1 - ms->Ystep) / 2) / ms->Yraydir;
}

void	floor_and_ceiling(t_ms *ms, int x)
{
	if (ms->texture == 0)
	{
		if (ms->start > 0)
		{
			ms->color = 0x66CCFF;
			ms->y = -1;
			if (x < WDTH && ms->y < HGHT)
				while (++ms->y < ms->start)
				{
					ft_memcpy(ms->img_ptr + 4 * WDTH * ms->y + x * 4,
							&ms->color, sizeof(int));
				}
		}
	}
	if (ms->end > 0)
	{
		ms->color = 0x333333;
		ms->y = ms->end - 1;
		if (x < WDTH && ms->y < HGHT)
			while (++ms->y < HGHT)
				ft_memcpy(ms->img_ptr + 4 * WDTH * ms->y + x * 4,
						&ms->color, sizeof(int));
	}
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
		floor_and_ceiling(ms, ms->x);
	}
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	mlx_destroy_image(ms->mlx, ms->img);
}
