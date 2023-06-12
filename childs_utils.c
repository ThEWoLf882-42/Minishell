/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:58:02 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/12 16:14:25 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nargs(t_line *lm)
{
	int		i;

	i = 0;
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
			i++;
		lm = lm->nxt;
	}
	return (i + 2);
}

char	**join_arg(t_line *lm)
{
	char	**cmd;
	int		i;

	i = -1;
	cmd = malloc(sizeof(char *) * nargs(lm));
	while (++i < nargs(lm))
		cmd[i] = NULL;
	i = 0;
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "cmd"))
			cmd[0] = lm->shx;
		if (!ft_strcmp(lm->typ, "arg"))
			cmd[++i] = lm->shx;
		lm = lm->nxt;
	}
	cmd[++i] = NULL;
	return (cmd);
}

void	is_dir(char *cmd)
{
	if (opendir(cmd))
	{
		ft_putstr_fd("minishell-69: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
}

void	nf_nd(char *shx, int count)
{
	if (!count)
	{
		ft_putstr_fd("minishell-69: ", 2);
		ft_putstr_fd(shx, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
}

void	if_nopath(t_line *lm)
{
	t_env	*em;
	int		count;

	em = g_va.env;
	count = 0;
	is_dir(lm->shx);
	if (ft_strchr(lm->shx, '/'))
		return ;
	while (em)
	{
		if (!ft_strncmp(em->arg, "PATH=", 5))
		{
			if (!em->arg[5])
				count = 0;
			else
				count++;
		}
		em = em->nxt;
	}
	if (!lm->path)
		nf_nd(lm->shx, count);
}
