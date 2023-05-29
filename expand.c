/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:11:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/29 16:21:23 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
get is the variable in env substr start + 1 to skip $ and len to 
substr is = end - (start + 1),EX: $USER&# len = 4  start + 1 = U, end = &
found is USER variable in env
start + ft_strlen(found) len in the new 
start + ft_strlen(get) + 1 len in the old shx
*/
char	*sp_d(char *get, int *bf, int *af)
{
	*bf = 0;
	*af = 0;
	if (!*get)
		return (ft_strdup("$"));
	if (get[0] == 31 && get[1] == '\0')
		return (ft_strdup("69"));
	if (get[0] == '?' && get[1] == '\0')
		return (ft_itoa(g_va.exit_s));
	return (NULL);
}

void	creat_nod(t_line **newlm, char *found, int bf, int af)
{
	char	**str;
	int		i;

	(void)bf;
	(void)af;
	str = ft_split(found, ' ');
	i = -1;
	while (str[++i])
	{
		ft_backline(newlm, new_lin(str[i]));
		free(str[i]);
	}
	free(str);
}

char	*expanded_nod(t_line *lm, char *found, int bf, int af)
{
	t_line	*tmp_af;
	t_line	*tmp_bef;
	t_line	*newlm;

	newlm = NULL;
	tmp_af = lm->nxt;
	tmp_bef = lm;
	creat_nod(&newlm, found, bf, af);
	// if (!bf)
	// 	jo_bf(lm, newlm);
	// if (!af)
	// 	jo_af(lm, ft_lastline(newlm));
	// // while (newlm)
	return (NULL);
}
// add tab maybe <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
char	*which_env(char *get, int *bf, int *af)
{
	t_env	*em;

	em = g_va.env;
	if (!*get || (get[0] == 31 && get[1] == '\0')
		|| (get[0] == '?' && get[1] == '\0'))
		return (sp_d(get, bf, af));
	while (em)
	{
		if (!ft_strncmp(get, em->arg, ft_strlen(get)))
		{
			if (em->arg[ft_strlen(get) + 1] == ' ')
				*bf = 1;
			else
				*bf = 0;
			if (em->arg[ft_strlen(em->arg) - 1] == ' ')
				*af = 1;
			else
				*af = 0;
			return (ft_strdup(&em->arg[ft_strlen(get) + 1]));
		}
		em = em->nxt;
	}
	return (NULL);
}

void	exp_dlr(t_line *lm, int start, int end)
{
	char	*found;
	char	*get;
	int		bf;
	int		af;

	get = ft_substr(lm->shx, start + 1, end - (start + 1));
	found = which_env(get, &bf, &af);
	expanded_nod(lm, found, bf, af);
	// if (!found && (end - start == (int)ft_strlen(lm->shx)))
	// {
	// 	free(lm->shx);
	// 	lm->shx = NULL;
	// }
	// else
	// {
	// 	len = (ft_strlen(lm->shx) - (ft_strlen(get) + 1)) + ft_strlen(found) + 1;
	// 	new = malloc(sizeof(char) * len);
	// 	if (!new)
	// 		return ;
		// copy_bef(new, start, lm->shx);
		// copy_mid(new, start, found);
	// 	copy_af(new, start + ft_strlen(found), start + ft_strlen(get) + 1, lm->shx);
	// 	free(get);
	// 	free(lm->shx);
	// 	lm->shx = new;
	// }
}
/*
locat the 31 and incrementend untill reaching non expandable char
*/

void	expand_it(t_line *lm)
{
	int		start;
	int		end;

	end = 0;
	while (1)
	{
		start = charloc(lm->shx, 31);
		if (start == -1 || !lm->shx[start])
			break ;
		end = start + 1;
		if ((lm->shx[start + 1] == 31 || lm->shx[start + 1] == '?'
				|| ft_isdigit(lm->shx[start + 1])))
			end++;
		else
			while (ft_isdigit(lm->shx[end]) || ft_isalpha(lm->shx[end])
				|| lm->shx[end] == '_')
				end++;
		exp_dlr(lm, start, end);
		pause();
	}
}

void	put_dlr_bex(t_line *lm)
{
	int	i;

	i = -1;
	lm->bex = ft_strdup(lm->shx);
	while (lm->bex[++i])
		if (lm->bex[i] == 31)
			lm->bex[i] = '$';
}

void	expand(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (ft_strchr(lm->shx, 31))
			{
				put_dlr_bex(lm);
				expand_it(lm);
			}
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
