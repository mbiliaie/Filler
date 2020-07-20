/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:53:24 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:53:33 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			inner_cycle(char *txt, struct s_gs *gen)
{
	char			*aim0;
	char			*aim1;

	aim0 = "Plateau ";
	aim1 = "Piece ";
	if (!ft_strncmp(txt, aim1, 6))
	{
		load_object(txt, 0, &gen->figure);
		position(*gen);
	}
	else if (!ft_strncmp(txt, aim0, 8))
	{
		load_object(txt, 4, &gen->field);
		if (gen->activated == 0)
		{
			gen->activated = 1;
			run(gen);
		}
	}
}

static short int	general_cycle(struct s_gs *gen)
{
	char			*txt;
	int				gnl_ret;
	short int		out;
	int				stdin;

	stdin = 0;
	gnl_ret = get_next_line(stdin, &txt);
	out = 1;
	while (gnl_ret > -1)
	{
		if (!txt)
		{
			out++;
			continue;
		}
		inner_cycle(txt, gen);
		dump_string(&txt);
		gnl_ret = get_next_line(stdin, &txt);
	}
	return (out);
}

static void			set_id(char pn, struct s_gs *gen)
{
	char			zero;
	char			cross;

	zero = 'O';
	cross = 'X';
	if (pn != '2')
	{
		gen->gg.sign = zero;
		gen->foe.sign = cross;
	}
	else
	{
		gen->gg.sign = cross;
		gen->foe.sign = zero;
	}
}

short int			start_filler(char pn, struct s_gs *gen)
{
	short int		z;

	z = 0;
	set_id(pn, gen);
	gen->activated = z;
	general_cycle(gen);
	return (z);
}
