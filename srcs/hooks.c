/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:10:59 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/29 03:25:18 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int		key_press2(int keycode, t_ms *ms)
{
	if (keycode == 4)
	{
		if (ms->help == 0)
			ms->help = 1;
		else
			ms->help = 0;
	}
	else if (keycode == 17)
	{
		if (ms->texture == 0)
			ms->texture = 1;
		else
			ms->texture = 0;
	}
	return (0);
}

int		key_press(int keycode, t_ms *ms)
{
	if (keycode == 13 || keycode == 126)
		ms->move_up = 1;
	else if (keycode == 1 || keycode == 125)
		ms->move_down = 1;
	else if (keycode == 2 || keycode == 124)
		ms->move_right = 1;
	else if (keycode == 0 || keycode == 123)
		ms->move_left = 1;
	else if (keycode == 257 || keycode == 258)
	{
		ms->ms = 0.1;
		ms->rs = 0.025;
	}
	else if (keycode == 53)
		exit(1);
	else if (keycode == 117)
		wolf3d_init(ms);
	else
		key_press2(keycode, ms);
	return (0);
}

int		key_release(int keycode, t_ms *ms)
{
	if (keycode == 13 || keycode == 126)
		ms->move_up = 0;
	else if (keycode == 1 || keycode == 125)
		ms->move_down = 0;
	else if (keycode == 2 || keycode == 124)
		ms->move_right = 0;
	else if (keycode == 0 || keycode == 123)
		ms->move_left = 0;
	else if (keycode == 257 || keycode == 258)
	{
		ms->ms = 0.05;
		ms->rs = 0.05;
	}
	return (0);
}

void	move_side(t_ms *ms)
{
	if (ms->move_right == 1)
	{
		ms->olddirx = ms->dirx;
		ms->dirx = ms->dirx * cos(-ms->rs) - ms->diry * sin(-ms->rs);
		ms->diry = ms->olddirx * sin(-ms->rs) + ms->diry * cos(-ms->rs);
		ms->oldplanex = ms->planex;
		ms->planex = ms->planex * cos(-ms->rs) - ms->planey * sin(-ms->rs);
		ms->planey = ms->oldplanex * sin(-ms->rs) + ms->planey * cos(-ms->rs);
	}
	if (ms->move_left == 1)
	{
		ms->olddirx = ms->dirx;
		ms->dirx = ms->dirx * cos(ms->rs) - ms->diry * sin(ms->rs);
		ms->diry = ms->olddirx * sin(ms->rs) + ms->diry * cos(ms->rs);
		ms->oldplanex = ms->planex;
		ms->planex = ms->planex * cos(ms->rs) - ms->planey * sin(ms->rs);
		ms->planey = ms->oldplanex * sin(ms->rs) + ms->planey * cos(ms->rs);
	}
}

int		move(t_ms *ms)
{
	if (ms->move_up == 1)
	{
		if (ms->array[(int)(ms->posx + ms->dirx * ms->ms)][(int)(ms->posy)]
		== 0)
			ms->posx += ms->dirx * ms->ms;
		if (ms->array[(int)(ms->posx)][(int)(ms->posy + ms->diry * ms->ms)]
		== 0)
			ms->posy += ms->diry * ms->ms;
	}
	if (ms->move_down == 1)
	{
		if (ms->array[(int)(ms->posx - ms->dirx * ms->ms)][(int)(ms->posy)]
		== 0)
			ms->posx -= ms->dirx * ms->ms;
		if (ms->array[(int)(ms->posx)][(int)(ms->posy - ms->diry * ms->ms)]
		== 0)
			ms->posy -= ms->diry * ms->ms;
	}
	move_side(ms);
	launch_wolf(ms);
	return (0);
}
