/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:21:19 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:18:06 by agimi            ###   ########.fr       */
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
		if (ft_strcmp(em->arg, "_=./minishell"))
		{
			dec_x = copy_exp(em->arg);
			ft_backexp(&g_va.xport, new_exp(dec_x));
			free(dec_x);
		}
		em = em->nxt;
	}
}

int	valid_exp(char *shx)
{
	int	i;

	i = 0;
	if (shx[i] != '_' && !ft_isalpha(shx[i]))
		return (0);
	while (shx[++i] && shx[i] != '=')
		if (shx[i] != '_' && !ft_isalpha(shx[i]) && !ft_isdigit(shx[i]))
			return (0);
	return (1);
}

int	loop(t_line *lm)
{
	int	b;

	b = 0;
	while (lm)
	{
		if (!valid_exp(lm->shx))
		{
			ft_putstr_fd("minishell-69: ", 2);
			ft_putstr_fd(lm->shx, 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
			g_va.exit_s = 1;
			b = 1;
		}
		else if (!ft_strcmp(lm->typ, "arg"))
		{
			add_env(lm->shx);
			add_exp(lm->shx);
		}
		lm = lm->nxt;
	}
	return (b);
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
	if (!lm->nxt || ft_strcmp(lm->nxt->typ, "arg") || !lm->nxt->shx)
	{
		while (xm)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(xm->xarg, 1);
			ft_putchar_fd('\n', 1);
			xm = xm->nxt;
		}
	}
	else if (loop(lm->nxt))
		return ;
	close_fd();
	if (x)
		exit(0);
}
