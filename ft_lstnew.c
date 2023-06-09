/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:05:04 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:19:55 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*new_sp(char *str)
{
	t_pipe	*sp;

	sp = malloc(sizeof(t_pipe));
	if (!sp)
		return (NULL);
	sp->pl = ft_strdup(str);
	sp->nxt = NULL;
	sp->lin = NULL;
	sp->fin = NULL;
	sp->fout = NULL;
	return (sp);
}

t_line	*new_lin(char *str, char *ty, int i)
{
	t_line	*lin;

	lin = malloc(sizeof(t_line));
	if (!lin)
		return (NULL);
	if (i)
		lin->shx = ft_strdup(str);
	else
		lin->shx = str;
	lin->bex = NULL;
	lin->space = 0;
	lin->path = NULL;
	lin->nxt = NULL;
	lin->typ = ty;
	lin->prv = NULL;
	lin->del = NULL;
	return (lin);
}

t_env	*new_env(char *str)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->arg = ft_strdup(str);
	env->nxt = NULL;
	return (env);
}

t_fin	*new_fin(t_line *lm, char *file, int her, char *del)
{
	t_fin	*fin;

	fin = malloc(sizeof(t_fin));
	if (!fin)
		return (NULL);
	fin->lm = lm;
	fin->herdoc = her;
	fin->del = del;
	fin->file = file;
	fin->fd = 0;
	if (!her)
		fin->flag = O_RDONLY;
	else
	{
		fin->flag = O_CREAT;
		fin->bex = lm->nxt->del;
	}
	fin->nxt = NULL;
	return (fin);
}

t_fout	*new_fout(t_line *lm, char *file, int app)
{
	t_fout	*fout;

	fout = malloc(sizeof(t_fout));
	if (!fout)
		return (NULL);
	fout->lm = lm;
	fout->file = file;
	fout->fd = 0;
	if (app == 1)
		fout->flag = O_WRONLY | O_CREAT | O_APPEND;
	else
		fout->flag = O_WRONLY | O_CREAT | O_TRUNC;
	fout->perm = 0644;
	fout->nxt = NULL;
	return (fout);
}
