/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:20:41 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/29 03:25:31 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	put_pxl_to_img(t_ms *ms, int x, int y, int color)
{
	if (ms->texture == 1 && x < WDTH && y < HGHT)
	{
		ms->texty = abs((((y * 256 - HGHT * 128 + ms->lineheight * 128) * 64)
					/ ms->lineheight) / 256);
		ft_memcpy(ms->img_ptr + 4 * WDTH * y + x * 4,
				&ms->tex[ms->id].data[ms->texty % 64 * ms->tex[ms->id].sizeline
				+ ms->textx % 64 * ms->tex[ms->id].bpp / 8], sizeof(int));
	}
	else if (x < WDTH && y < HGHT)
		ft_memcpy(ms->img_ptr + 4 * WDTH * y + x * 4,
				&color, sizeof(int));
}

void	sky_ground(t_ms *ms, int x)
{
	if (ms->start > 0)
	{
		ms->color = 0x58ACFA;
		ms->y = -1;
		if (x < WDTH && ms->y < HGHT)
		{
			while (++ms->y < ms->start)
			{
				ft_memcpy(ms->img_ptr + 4 * WDTH * ms->y + x * 4,
					&ms->color, sizeof(int));
			}
		}
	}
	if (ms->end > 0)
	{
		ms->color = 0xF3F781;
		ms->y = ms->end - 1;
		if (x < WDTH && ms->y < HGHT)
			while (++ms->y < HGHT)
				ft_memcpy(ms->img_ptr + 4 * WDTH * ms->y + x * 4,
				&ms->color, sizeof(int));
	}
}

void	draw_wall(int x, int start, int end, t_ms *ms)
{
	if (ms->texture == 1)
	{
		ms->id = ms->array[ms->mapx][ms->mapy];
		if (ms->side == 0)
			ms->wallx = ms->raposy + ms->walldist * ms->radiry;
		else
			ms->wallx = ms->raposx + ms->walldist * ms->radirx;
		ms->textx = (int)(ms->wallx * (double)(64));
		if (ms->side == 0 && ms->radirx > 0)
			ms->textx = 64 - ms->textx - 1;
		ms->textx = abs(ms->textx);
	}
	while (++start <= end)
		put_pxl_to_img(ms, x, start, ms->color);
}

void	load_textures(t_ms *ms)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	ms->tex[1].img = mlx_xpm_file_to_image(ms->mlx, "tex/stone.xpm", &a, &b);
	ms->tex[1].data = mlx_get_data_addr(ms->tex[1].img, &ms->tex[1].bpp,
			&ms->tex[1].sizeline, &ms->tex[1].endian);
	ms->tex[2].img = mlx_xpm_file_to_image(ms->mlx, "tex/mossy.xpm", &a, &b);
	ms->tex[2].data = mlx_get_data_addr(ms->tex[2].img, &ms->tex[2].bpp,
			&ms->tex[2].sizeline, &ms->tex[2].endian);
	ms->tex[3].img = mlx_xpm_file_to_image(ms->mlx, "tex/redbrick.xpm", &a, &b);
	ms->tex[3].data = mlx_get_data_addr(ms->tex[3].img, &ms->tex[3].bpp,
			&ms->tex[3].sizeline, &ms->tex[3].endian);
	ms->tex[4].img = mlx_xpm_file_to_image(ms->mlx, "tex/wood.xpm", &a, &b);
	ms->tex[4].data = mlx_get_data_addr(ms->tex[4].img, &ms->tex[4].bpp,
			&ms->tex[4].sizeline, &ms->tex[4].endian);
}

int		cross_close(void)
{
	exit(1);
	return (0);
}
