/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:10:25 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/24 20:26:23 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_print(char *str)
{
	dup2(2, 1);
	printf("minishell-69: %s: command not found\n", str);
	exit(1);
}

int	nargs(t_line *lm)
{
	int		i;

	i = 0;
	while (lm)
	{
		if (ft_strcmp(lm->typ, "arg"))
			i++;
		lm = lm->nxt;
	}
	return (i + 2);
}

char	**join_arg(t_line *lm)
{
	char	**cmd;

	cmd = malloc(sizeof(char *) * nargs(lm));
	
}

void	childs(t_pipe *sp)
{
	char	**cmd;
	t_line	*lm;

	open_fin(sp);
	open_fout(sp);
	lm = sp->lin;
	while (sp->lin && ft_strcmp(sp->lin->typ, "cmd"))
		sp->lin = sp->lin->nxt;
	if (!sp->lin->path)
		exit_print(sp->lin->shx);
	cmd = join_arg(lm);
	// execve(sp->lin->path, cmd, g_va.envp);
	// 	print_error(sp->lin->shx);
	exit (0);
}
