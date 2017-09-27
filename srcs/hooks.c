/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:10:59 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/27 17:33:59 by bbrandt          ###   ########.fr       */
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
		ms->ms = 0.1;
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
		ms->ms = 0.05;
	return (0);
}

void	move_side(t_ms *ms)
{
	if (ms->move_right == 1)
	{
		ms->Xolddir = ms->Xdir;
		ms->Xdir = ms->Xdir * cos(-ms->rs) - ms->Ydir * sin(-ms->rs);
		ms->Ydir = ms->Xolddir * sin(-ms->rs) + ms->Ydir * cos(-ms->rs);
		ms->Xoldplane = ms->Xplane;
		ms->Xplane = ms->Xplane * cos(-ms->rs) - ms->Yplane * sin(-ms->rs);
		ms->Yplane = ms->Xoldplane * sin(-ms->rs) + ms->Yplane * cos(-ms->rs);
	}
	if (ms->move_left == 1)
	{
		ms->Xolddir = ms->Xdir;
		ms->Xdir = ms->Xdir * cos(ms->rs) - ms->Ydir * sin(ms->rs);
		ms->Ydir = ms->Xolddir * sin(ms->rs) + ms->Ydir * cos(ms->rs);
		ms->Xoldplane = ms->Xplane;
		ms->Xplane = ms->Xplane * cos(ms->rs) - ms->Yplane * sin(ms->rs);
		ms->Yplane = ms->Xoldplane * sin(ms->rs) + ms->Yplane * cos(ms->rs);
	}
}

int		move(t_ms *ms)
{
	if (ms->move_up == 1)
	{
		if (ms->array[(int)(ms->Xpos + ms->Xdir * ms->ms)][(int)(ms->Ypos)] == 0)
			ms->Xpos += ms->Xdir * ms->ms;
		if (ms->array[(int)(ms->Xpos)][(int)(ms->Ypos + ms->Ydir * ms->ms)] == 0)
			ms->Ypos += ms->Ydir * ms->ms;
	}
	if (ms->move_down == 1)
	{
		if (ms->array[(int)(ms->Xpos - ms->Xdir * ms->ms)][(int)(ms->Ypos)] == 0)
			ms->Xpos -= ms->Xdir * ms->ms;
		if (ms->array[(int)(ms->Xpos)][(int)(ms->Ypos - ms->Ydir * ms->ms)] == 0)
			ms->Ypos -= ms->Ydir * ms->ms;
	}
	move_side(ms);
	launch_wolf(ms);
	return (0);
}
