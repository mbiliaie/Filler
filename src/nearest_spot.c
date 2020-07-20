/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:49:13 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:49:26 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			load_struct(struct s_gs *gen, struct s_sp *spot)
{
	while (gen->field.hor_dim > spot->x)
	{
		if (gen->field.keys[spot->y][spot->x] == gen->gg.sign)
		{
			gen->s_bff[gen->s_num] = *spot;
			gen->s_num++;
		}
		else if (gen->field.keys[spot->y][spot->x] == gen->foe.sign)
		{
			gen->d_bff[gen->d_num] = *spot;
			gen->d_num++;
		}
		spot->x++;
	}
}

short int			form_arr(struct s_gs *gen)
{
	int				vol;
	short int		out;
	size_t			mem_area;

	out = 0;
	vol = gen->field.vol;
	mem_area = vol * sizeof(struct s_sp);
	while (gen->s_bff)
	{
		dump_memory((void **)&gen->s_bff);
		break ;
	}
	while (gen->d_bff)
	{
		dump_memory((void **)&gen->d_bff);
		break ;
	}
	if (!(gen->s_bff = ft_memalloc(mem_area)))
		return (out);
	else if (!(gen->d_bff = ft_memalloc(mem_area)))
		return (out);
	ft_memset(gen->s_bff, out, mem_area);
	ft_memset(gen->d_bff, out, mem_area);
	return (out);
}

static int			compare_vars(int p1, int p2, short int mode)
{
	int				res_small;
	int				res_big;

	if (mode)
	{
		if (p1 > p2)
			res_big = p1;
		else
			res_big = p2;
		return (res_big);
	}
	else
	{
		if (p1 < p2)
			res_small = p1;
		else
			res_small = p2;
		return (res_small);
	}
}

int					fill_nearest_arr(struct s_gs *gen)
{
	short			z;
	struct s_sp		spot;
	short int		result;

	z = 0;
	result = form_arr(gen);
	if (result)
		exit(z + 1);
	gen->s_num = z;
	gen->d_num = z;
	spot.y = z;
	while (spot.y < gen->field.vert_dim)
	{
		spot.x = z;
		load_struct(gen, &spot);
		spot.y = spot.y + 1;
	}
	return (z);
}

short int			interval(struct s_sp a, struct s_sp b)
{
	short int		result;
	short int		x_calc;
	short int		y_calc;

	x_calc = compare_vars(a.x, b.x, 1) - compare_vars(a.x, b.x, 0);
	y_calc = compare_vars(a.y, b.y, 1) - compare_vars(a.y, b.y, 0);
	result = x_calc + y_calc;
	return (result);
}
