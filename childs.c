/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:10:25 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/06 12:21:56 by zouaraqa         ###   ########.fr       */
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
		if (!ft_strcmp(cmd[i], "") || !ft_strcmp(cmd[i], " "))
			i--;
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

void	if_nopath(t_line *lm)
{
	t_env	*em;
	int		count;

	em = g_va.env;
	count = 0;
	is_dir(lm->shx);
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
	if (!count)
	{
		ft_putstr_fd("minishell-69: ", 2);
		ft_putstr_fd(lm->shx, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
}

void	childs(t_pipe *sp, int i)
{
	char	**cmd;
	t_line	*lm;

	which_pipe(i);
	open_file(sp, 1);
	lm = sp->lin;
	while (sp->lin && ft_strcmp(sp->lin->typ, "cmd"))
		sp->lin = sp->lin->nxt;
	builtins(lm, 1);
	if (!sp->lin || !sp->lin->shx)
		exit(0);
	if_nopath(sp->lin);
	if (!sp->lin->path || !*sp->lin->shx)
		exit_print(sp->lin->shx);
	cmd = join_arg(lm);
	if (execve(sp->lin->path, cmd, g_va.envp))
		print_error(sp->lin->shx, 127, 1);
	exit (0);
}
