/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:21:19 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/26 21:18:43 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exp	*ft_lastexp(t_exp *exp)
{
	if (!exp)
		return (NULL);
	while (exp->nxt)
		exp = exp->nxt;
	return (exp);
}

t_exp	*new_exp(char *str)
{
	t_exp	*exp;

	exp = malloc(sizeof(t_exp));
	if (!exp)
		return (NULL);
	exp->xarg = ft_strdup(str);
	exp->nxt = NULL;
	return (exp);
}

void	ft_backexp(t_exp **exp, t_exp *new)
{
	if (!exp || !new)
		return ;
	if ((*exp))
		ft_lastexp((*exp))->nxt = new;
	else
		(*exp) = new;
}

char	*copy_it(char *dec_x, char *arg)
{
	char	*const_x;
	int		i;
	int		j;

	i = -1;
	const_x = "declare -x ";
	while (const_x[++i])
		dec_x[i] = const_x[i];
	j = 0;
	while (arg[j])
		dec_x[i++] = arg[j++];
	dec_x[i] = '\0';
	return (dec_x);
}

void	set_xport(t_env *em)
{
	size_t		xlen;
	char		*dec_x;

	xlen = ft_strlen("declare -x ");
	while (em)
	{
		dec_x = malloc(sizeof(char) * (xlen + ft_strlen(em->arg) + 1));
		if (!dec_x)
			return ;
		dec_x = copy_it(dec_x, em->arg);
		ft_backexp(&g_va.exprt, new_exp(dec_x));
		free(dec_x);
		em = em->nxt;
	}
}

void	change_arg(t_env *em, char *narg)
{
	(void)em;
	(void)narg;
	printf("lala\n");
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
			change_arg(em, narg);
			break ;
		}
		else if (!em->nxt)
			ft_backenv(&g_va.env, new_env(narg));
		em = em->nxt;
	}
}

void	export_cmd(t_line *lm, int x)
{
	t_exp	*xm;

	xm = g_va.exprt;
	if (open_file(g_va.sp, x))
		return ;
	if (!lm->nxt || ft_strcmp(lm->nxt->typ, "arg"))
	{
		while (xm)
		{
			printf("%s\n", xm->xarg);
			xm = xm->nxt;
		}	
	}
	lm = lm->nxt;
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
			add_env(lm->shx);
		lm = lm->nxt;
	}
	close_fd();
	if (x)
		exit(0);
}
