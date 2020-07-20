/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:51:02 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:51:13 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

short					beset(struct s_gs gen, struct s_sp p, struct s_sp *svr)
{
	short int			z;
	struct s_sp			stepup;

	z = 0;
	stepup.y = z;
	while (gen.figure.vert_dim > stepup.y)
	{
		stepup.x = z;
		while (gen.figure.hor_dim > stepup.x)
		{
			svr->x = p.x - stepup.x;
			svr->y = p.y - stepup.y;
			if (gen.figure.keys[stepup.y][stepup.x] == '*')
			{
				if (spot_ok(gen, *svr) == 1)
				{
					while (check_spot(gen, *svr) == 0)
						return (++z);
				}
			}
			stepup.x++;
		}
		stepup.y++;
	}
	return (z);
}

static struct s_sp		get_res(short fin_len, struct s_gs gen, struct s_sp	a)
{
	if (fin_len == gen.field.vol)
	{
		return (get_spot(gen));
	}
	else
	{
		return (a);
	}
}

struct s_sp				count_coord(short fin_len, struct s_gs gen)
{
	short				s_act;
	short				d_act;
	struct s_sp			svr;
	struct s_sp			a;

	s_act = 0;
	while (gen.s_num > s_act)
	{
		d_act = 0;
		while (gen.d_num > d_act)
		{
			if (interval(gen.s_bff[s_act], gen.d_bff[d_act]) <= fin_len)
			{
				if (beset(gen, gen.s_bff[s_act], &svr))
				{
					a = svr;
					fin_len = interval(gen.s_bff[s_act], gen.d_bff[d_act]);
				}
			}
			d_act = d_act + 1;
		}
		s_act = s_act + 1;
	}
	return (get_res(fin_len, gen, a));
}

struct s_sp				nearest_coord(struct s_gs gen)
{
	short				fin_len;
	struct s_sp			result;

	fin_len = gen.field.vol;
	fill_nearest_arr(&gen);
	result = count_coord(fin_len, gen);
	return (result);
}

struct s_sp				get_spot(struct s_gs gen)
{
	struct s_sp		a;

	a.y = gen.aim.y;
	if (gen.aim.y == 0)
	{
		while (a.y < gen.field.vert_dim)
		{
			a = loop_for_spot(gen, a);
			a.y = a.y + fl_target_check(gen.aim.y);
		}
	}
	else
	{
		while (a.y >= 0)
		{
			a = loop_for_spot(gen, a);
			a.y = a.y + fl_target_check(gen.aim.y);
		}
	}
	return (a);
}
