/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:21:19 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/30 21:52:21 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_exp(char *arg)
{
	char	*dec_x;
	int		i;
	int		j;

	i = 0;
	dec_x = malloc(sizeof(char) * (ft_strlen(arg) + 3));
	if (!dec_x)
		return (0);
	j = 0;
	while (arg[j] && arg[j] != '=')
		dec_x[i++] = arg[j++];
	if (arg[j] == '=')
	{
		dec_x[i++] = arg[j++];
		dec_x[i++] = '"';
		while (arg[j])
			dec_x[i++] = arg[j++];
		dec_x[i++] = '"';
	}
	dec_x[i] = '\0';
	return (dec_x);
}

void	set_xport(t_env *em)
{
	char		*dec_x;

	while (em)
	{
		dec_x = copy_exp(em->arg);
		ft_backexp(&g_va.xport, new_exp(dec_x));
		free(dec_x);
		em = em->nxt;
	}
}

void	loop(t_line *lm)
{
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
		{
			add_env(lm->shx);
			add_exp(lm->shx);
		}
		lm = lm->nxt;
	}
}

void	export_cmd(t_line *lm, int x)
{
	t_exp	*xm;

	xm = g_va.xport;
	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	if (!lm->nxt || ft_strcmp(lm->nxt->typ, "arg"))
	{
		while (xm)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(xm->xarg, 1);
			ft_putchar_fd('\n', 1);
			// printf("declare -x %s\n", xm->xarg);
			xm = xm->nxt;
		}
	}
	lm = lm->nxt;
	loop(lm);
	close_fd();
	if (x)
		exit(0);
}
