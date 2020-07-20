/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reveal_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:52:40 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:52:49 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

short int			check_position(struct s_sp spot, struct s_gs gen)
{
	if (spot.y + gen.figure.vert_dim > gen.field.vert_dim)
	{
		return (1);
	}
	else if (spot.x + gen.figure.hor_dim > gen.field.hor_dim)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

short int			check_try(struct s_sp spot, struct s_gs gen)
{
	short int		onum;
	struct s_sp		p;

	onum = 0;
	p.y = 0;
	while (p.y < gen.figure.vert_dim)
	{
		p.x = 0;
		while (p.x < gen.figure.hor_dim)
		{
			if (gen.figure.keys[p.y][p.x] == '*')
				if (gen.field.keys[spot.y + p.y][spot.x + p.x] == gen.foe.sign)
					return (1);
			if (gen.figure.keys[p.y][p.x] == '*')
				if ((gen.field.keys[spot.y + p.y][spot.x + p.x] == gen.gg.sign)
					&& ++onum > 1)
					return (1);
			p.x++;
		}
		p.y++;
	}
	if (onum < 1)
		return (1);
	return (0);
}

short int			check_spot(struct s_gs gen, struct s_sp spot)
{
	short int		result;

	if (check_position(spot, gen))
	{
		return (2);
	}
	result = check_try(spot, gen);
	return (result);
}
