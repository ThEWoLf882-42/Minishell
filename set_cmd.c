/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:20:53 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/23 19:32:08 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_access(t_line *lm, char *path)
{
	if (!access(path, F_OK))
	{
		if (!access(path, X_OK))
		{
			lm->path = path;
			return (1);
		}
	}
	return (0);
}

void	get_path(t_line *lm, char *arg)
{
	char	*path;
	int		i;
	int		j;
	int		y;

	path = malloc(sizeof(char) * ft_strlen(arg) + 1);
	if (!path)
		return ;
	i = 4;
	while (arg[++i])
	{
		j = 0;
		y = -1;
		while (arg[i] && arg[i] != ':')
			path[j++] = arg[i++];
		path[j++] = '/';
		while (lm->shx[++y])
			path[j++] = lm->shx[y];
		path[j] = '\0';
		if (check_access(lm, path))
			return ;
	}
}

void	set_path(t_line *lm)
{
	t_env	*em;
	int		i;

	i = -1;
	em = g_va.env;
	while (em)
	{
		if (ft_strcmp(em->arg, "PATH="))
			get_path(lm, em->arg);
		em = em->nxt;
	}
}

void	set_cmd(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm && lm->typ)
			lm = lm->nxt;
		if (lm)
		{
			lm->typ = "cmd";
			if (ft_strchr(lm->shx, '/'))
				lm->path = lm->shx;
			else
				set_path(lm);
		}
		sm = sm->nxt;
	}
}
