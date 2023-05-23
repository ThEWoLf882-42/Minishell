/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:11:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/23 13:18:20 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (s[start] && i < (size_t)len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_charloc(char *str, int n)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == n)
			return (i);
		i++;
	}
	return (ft_strlen(str));
}

void	copy_bef(char *new, int start)
{
	int	i;
	int	j;

	i = -
}

void	copy_bef(char *new, int start)
{
	
}

void	copy_bef(char *new, int start)
{
	
}

void	exp_dlr(t_line *lm, int start, int end)
{
	char	*found;
	char	*get;
	char	*new;
	int		len;

	get = ft_substr(lm->shx, start + 1, end);
	found = getenv(get);
	len = (ft_strlen(lm->shx) - (ft_strlen(get) + 1)) + ft_strlen(found) + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return ;
	copy_bef(new, start);
	copy_mid(new, start, found);
	copy_af(new, start + ft_strlen(found));
	printf("g = %s   f = %s  end = %d start = %d  len = %d\n",get,found, end, start, len);
}

void	expand_it(t_line *lm)
{

	int		start;
	int		end;

	end = 0;
	while (lm->shx[end])
	{
		start = ft_charloc(lm->shx, 31);
		if (!lm->shx[start])
			break ;
		end = start + 1;
		if ((lm->shx[start + 1] == 31 || lm->shx[start + 1] == '?'))
			end++;
		else
			while (ft_isdigit(lm->shx[end]) || ft_isalpha(lm->shx[end]) || lm->shx[end] == '_')
				end++;
		exp_dlr(lm, start, end);
	}
	// lm->len = ft_strlen(lm->shx);
	
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