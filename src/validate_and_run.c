/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:54:33 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:54:44 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			set_targets(struct s_gs *gen, t_load *vars)
{
	vars->sp_x = gen->foe.st.x - gen->gg.st.x;
	if (vars->sp_x < 0)
	{
		gen->aim.x = 0;
	}
	else
	{
		gen->aim.x = gen->field.hor_dim - 1;
	}
	vars->sp_y = gen->foe.st.y - gen->gg.st.y;
	if (vars->sp_y < 0)
	{
		gen->aim.y = 0;
	}
	else
	{
		gen->aim.y = gen->field.vert_dim - 1;
	}
}

short int			run(struct s_gs *gen)
{
	struct s_sp		p;
	t_load			vars;

	vars.result = 1;
	p.y = 0;
	p.x = 0;
	while (p.y < gen->field.vert_dim)
	{
		while (p.x < gen->field.hor_dim)
		{
			if (gen->field.keys[p.y][p.x] == gen->gg.sign)
			{
				gen->gg.st = p;
			}
			else if (gen->field.keys[p.y][p.x] == gen->foe.sign)
			{
				gen->foe.st = p;
			}
			p.x = p.x + 1;
		}
		p.y = p.y + 1;
	}
	set_targets(gen, &vars);
	return (vars.result);
}

static char			get_side_number(const char *txt)
{
	char			pn;
	short int		k;

	pn = '0';
	k = 0;
	while (txt && k < 11)
	{
		pn = txt[k];
		k++;
	}
	return (pn);
}

static short int	validate_starting_params(char *txt, struct s_gs *gen)
{
	char			*tr;
	size_t			l;
	char			pn;
	char			x;
	char			o;

	o = '1';
	x = '2';
	tr = "$$$ exec p";
	l = ft_strlen(txt);
	pn = get_side_number(txt);
	if (!txt || ft_strncmp(txt, tr, 9) || l < 11 || !(pn == x || pn == o))
		return (0);
	else
	{
		gen->p_num = pn;
		return (1);
	}
}

int					main(void)
{
	int				err;
	int				s;
	struct s_gs		gen;
	char			*buffer;
	int				check_gnl;

	s = 0;
	err = 1;
	ft_memset(&gen, s, sizeof(gen));
	buffer = NULL;
	check_gnl = get_next_line(s, &buffer);
	if (!check_gnl || !validate_starting_params(buffer, &gen))
		return (err);
	else
	{
		dump_string(&buffer);
		start_filler(gen.p_num, &gen);
	}
	return (s);
}
