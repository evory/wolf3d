/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:20:41 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/27 17:45:34 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	put_pxl_to_img(t_ms *ms, int x, int y, int color)
{
	if (ms->texture == 1 && x < WDTH && y < HGHT)
	{
		ms->Ytext = abs((((y * 256 - HGHT * 128 + ms->lineheight * 128) * 64)
					/ ms->lineheight) / 256);
		ft_memcpy(ms->img_ptr + 4 * WDTH * y + x * 4,
				&ms->tex[ms->id].data[ms->Ytext % 64 * ms->tex[ms->id].sizeline +
				ms->Xtext % 64 * ms->tex[ms->id].bpp / 8], sizeof(int));
	}
	else if (x < WDTH && y < HGHT)
		ft_memcpy(ms->img_ptr + 4 * WDTH * y + x * 4,
				&color, sizeof(int));
}

void	draw_wall(int x, int start, int end, t_ms *ms)
{
	if (ms->texture == 1)
	{
		ms->id = ms->array[ms->Xmap][ms->Ymap];
		if (ms->side == 0)
			ms->Xwall = ms->Yraypos + ms->walldist * ms->Yraydir;
		else
			ms->Xwall = ms->Xraypos + ms->walldist * ms->Xraydir;
		ms->Xtext = (int)(ms->Xwall * (double)(64));
		if (ms->side == 0 && ms->Xraydir > 0)
			ms->Xtext = 64 - ms->Xtext - 1;
		if (ms->side == 1 && ms->Yraydir < 0)
			ms->Xtext = 64 - ms->Xtext - 1;
		ms->Xtext = abs(ms->Xtext);
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
	ms->tex[0].img = mlx_xpm_file_to_image(ms->mlx, "textures/wood.xpm", &a, &b);
	ms->tex[0].data = mlx_get_data_addr(ms->tex[0].img, &ms->tex[0].bpp,
			&ms->tex[0].sizeline, &ms->tex[0].endian);
	ms->tex[1].img = mlx_xpm_file_to_image(ms->mlx, "textures/stone.xpm", &a, &b);
	ms->tex[1].data = mlx_get_data_addr(ms->tex[1].img, &ms->tex[1].bpp,
			&ms->tex[1].sizeline, &ms->tex[1].endian);
	ms->tex[2].img = mlx_xpm_file_to_image(ms->mlx, "textures/mossy.xpm", &a, &b);
	ms->tex[2].data = mlx_get_data_addr(ms->tex[2].img, &ms->tex[2].bpp,
			&ms->tex[2].sizeline, &ms->tex[2].endian);
	ms->tex[3].img = mlx_xpm_file_to_image(ms->mlx,
			"textures/redbrick.xpm", &a, &b);
	ms->tex[3].data = mlx_get_data_addr(ms->tex[3].img, &ms->tex[3].bpp,
			&ms->tex[3].sizeline, &ms->tex[3].endian);
	ms->tex[4].img = mlx_xpm_file_to_image(ms->mlx, "textures/wood.xpm", &a, &b);
	ms->tex[4].data = mlx_get_data_addr(ms->tex[4].img, &ms->tex[4].bpp,
			&ms->tex[4].sizeline, &ms->tex[4].endian);
	load_textures2(ms, a, b);
}

void	load_textures2(t_ms *ms, int a, int b)
{
	ms->tex[5].img = mlx_xpm_file_to_image(ms->mlx, "textures/sand.xpm", &a, &b);
	ms->tex[5].data = mlx_get_data_addr(ms->tex[5].img, &ms->tex[5].bpp,
			&ms->tex[5].sizeline, &ms->tex[5].endian);
	a = 512;
	b = 512;
	ms->tex[6].img = mlx_xpm_file_to_image(ms->mlx, "textures/sky.xpm", &a, &b);
	ms->tex[6].data = mlx_get_data_addr(ms->tex[6].img, &ms->tex[6].bpp,
			&ms->tex[6].sizeline, &ms->tex[6].endian);
}
