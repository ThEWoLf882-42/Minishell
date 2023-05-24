/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:11:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/24 18:29:26 by zouaraqa         ###   ########.fr       */
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

void	exp_dlr(t_line *lm, int start, int end)
{
	char	*found;
	char	*get;
	char	*new;
	int		len;

	get = ft_substr(lm->shx, start + 1, end - (start + 1));
	found = getenv(get);
	len = (ft_strlen(lm->shx) - (ft_strlen(get) + 1)) + ft_strlen(found) + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return ;
	copy_bef(new, start, lm->shx);
	copy_mid(new, start, found);
	copy_af(new, start + ft_strlen(found), start + ft_strlen(get) + 1, lm->shx);
	free(get);
	get = NULL;
	free(lm->shx);
	lm->shx = new;
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
		if (!lm->shx[start])
			break ;
		end = start + 1;
		if ((lm->shx[start + 1] == 31 || lm->shx[start + 1] == '?'))
			end++;
		else
			while (ft_isdigit(lm->shx[end]) || ft_isalpha(lm->shx[end])
				|| lm->shx[end] == '_')
				end++;
		exp_dlr(lm, start, end);
	}
}

void	expand(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		i;

	i = -1;
	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (ft_strchr(lm->shx, 31))
				expand_it(lm);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
