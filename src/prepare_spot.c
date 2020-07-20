/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 03:22:59 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/18 03:23:03 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

short int			position(struct s_gs gen)
{
	short			z;
	struct s_sp		potential_spot;

	z = 0;
	potential_spot = nearest_coord(gen);
	while (spot_ok(gen, potential_spot) == 0)
	{
		write(1, "0 0\n", 4);
		exit(z);
	}
	ft_putnbr(potential_spot.y);
	write(1, " ", 1);
	ft_putnbr(potential_spot.x);
	write(1, "\n", 1);
	return (z);
}

int					fl_target_check(int i)
{
	if (i != 0)
	{
		return (-1);
	}
	return (1);
}

short int			spot_ok(struct s_gs gen, struct s_sp spot)
{
	short int		pos_res;
	short int		field_res;

	pos_res = 0;
	field_res = 0;
	if (spot.x >= 0 && spot.y >= 0)
		pos_res = 1;
	if (spot.x < gen.field.hor_dim && spot.y < gen.field.vert_dim)
		field_res = 1;
	if (pos_res != 0 && field_res != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

struct s_sp			loop_for_spot(struct s_gs gen, struct s_sp a)
{
	struct s_sp		svr;

	a.x = gen.aim.x;
	if (gen.aim.x == 0)
	{
		while (a.x < gen.field.hor_dim)
		{
			if (gen.field.keys[a.y][a.x] == gen.gg.sign && beset(gen, a, &svr))
				return (svr);
			a.x = a.x + fl_target_check(gen.aim.x);
		}
	}
	else
	{
		while (a.x >= 0)
		{
			if (gen.field.keys[a.y][a.x] == gen.gg.sign && beset(gen, a, &svr))
				return (svr);
			a.x = a.x + fl_target_check(gen.aim.x);
		}
	}
	return (a);
}
