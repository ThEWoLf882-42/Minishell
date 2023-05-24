/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:10:25 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/24 20:00:42 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_print(char *str)
{
	dup2(2, 1);
	printf("minishell-69: %s: command not found\n", str);
	exit(1);
}

void	childs(t_pipe *sp)
{
	// char **cmd;

	open_fin(sp);
	open_fout(sp);
	while (sp->lin && ft_strcmp(sp->lin->typ, "cmd"))
		sp->lin = sp->lin->nxt;
	if (!sp->lin->path)
		exit_print(sp->lin->shx);
	// cmd = malloc(sizeof(char *)* 3);
	// cmd[0] = "catt";
	// cmd[1] = NULL;
	// cmd[0]
	// execve(sp->lin->path, cmd, g_va.envp);
	// 	print_error(sp->lin->shx);
	exit (0);
}
