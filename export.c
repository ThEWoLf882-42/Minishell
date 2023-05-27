/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:21:19 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/27 13:24:41 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_it(char *arg)
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
		dec_x = copy_it(em->arg);
		ft_backexp(&g_va.xport, new_exp(dec_x));
		free(dec_x);
		em = em->nxt;
	}
}

void	change_envarg(t_env *em, char *narg)
{
	free(em->arg);
	em->arg = ft_strdup(narg);
	// printf("em[%s] na[%s]\n", em->arg, narg);
}

void	change_xarg(t_exp *xm, char *narg)
{
	free(xm->xarg);
	xm->xarg = copy_it(narg);
	// printf("xm[%s] na[%s]\n", xm->arg, narg);
}

void	add_env(char *narg)
{
	t_env	*em;
	int		i;

	i = 0;
	em = g_va.env;
	if (!ft_strchr(narg, '='))
		return ;
	while (narg[i] && narg[i] != '=')
		i++;
	while (em)
	{
		if (!ft_strncmp(em->arg, narg, i))
		{
			change_envarg(em, narg);
			break ;
		}
		em = em->nxt;
	}
	if (!em)
		ft_backenv(&g_va.env, new_env(narg));
}

void	add_exp(char *narg)
{
	t_exp	*xm;
	int		len;
	char	*dec_x;

	len = 0;
	xm = g_va.xport;
	while (narg[len] && narg[len] != '=')
		len++;
	while (xm)
	{
		if (!ft_strncmp(xm->xarg, narg, len))
		{
			change_xarg(xm, narg);
			break ;
		}
		xm = xm->nxt;
	}
	if (!xm)
	{
		dec_x = copy_it(narg);
		ft_backexp(&g_va.xport, new_exp(dec_x));
		free(dec_x);
	}
}

void	export_cmd(t_line *lm, int x)
{
	t_exp	*xm;

	xm = g_va.xport;
	if (open_file(g_va.sp, x))
		return ;
	if (!lm->nxt || ft_strcmp(lm->nxt->typ, "arg"))
	{
		while (xm)
		{
			printf("declare -x %s\n", xm->xarg);
			xm = xm->nxt;
		}
	}
	lm = lm->nxt;
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
		{
			add_env(lm->shx);
			add_exp(lm->shx);
		}
		lm = lm->nxt;
	}
	close_fd();
	if (x)
		exit(0);
}
