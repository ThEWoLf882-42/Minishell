/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:20:53 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/12 18:05:16 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_access(t_line *lm, char *path)
{
	if (!access(path, F_OK))
		if (!access(path, X_OK))
			return (lm->path = path, 1);
	return (0);
}

static void	get_path(t_line *lm, char *arg)
{
	char	*path;
	int		i;
	int		j;
	int		y;

	path = malloc(sizeof(char) * (ft_strlen(arg) + ft_strlen(lm->shx) + 2));
	if (!path)
		return ;
	i = 5;
	while (arg[i])
	{
		j = 0;
		y = -1;
		while (arg[i] && arg[i] != ':')
			path[j++] = arg[i++];
		path[j++] = '/';
		while (lm->shx && lm->shx[++y])
			path[j++] = lm->shx[y];
		path[j] = '\0';
		if (check_access(lm, path))
			return ;
		if (arg[i])
			i++;
	}
	free(path);
}

static void	set_path(t_line *lm)
{
	t_env	*em;
	char	*pa;

	em = g_va.env;
	while (em)
	{
		if (!ft_strncmp(em->arg, "PATH=", 5))
			get_path(lm, em->arg);
		em = em->nxt;
	}
	if (!lm->path)
	{
		pa = ft_strjoin2fr(ft_strdup("PATH="), getcwd(NULL, 0));
		get_path(lm, pa);
		free(pa);
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
		if (lm && !lm->shx)
			while (lm && !lm->shx && !lm->typ)
				lm = lm->nxt;
		if (lm && !lm->typ)
		{
			lm->typ = "cmd";
			if (lm && ft_strchr(lm->shx, '/'))
				lm->path = ft_strdup(lm->shx);
			else
				set_path(lm);
		}	
		sm = sm->nxt;
	}
}
