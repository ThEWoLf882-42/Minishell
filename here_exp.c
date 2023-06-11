/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:01:17 by agimi             #+#    #+#             */
/*   Updated: 2023/06/11 15:12:59 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_sp(char *get, int fd)
{
	char	*sta;

	sta = NULL;
	if (!*get)
		ft_putchar_fd('$', fd);
	else if (!ft_strcmp(get, "?"))
	{
		sta = ft_itoa(g_va.exit_s);
		ft_putstr_fd(sta, fd);
		free(sta);
	}
	else if (!ft_strcmp(get, "$"))
		ft_putstr_fd("69", fd);
	if (!*get || !ft_strcmp(get, "?") || !ft_strcmp(get, "$"))
		return (1);
	return (0);
}

void	print_env(char *get, int fd)
{
	t_env	*em;

	em = g_va.env;
	if (print_sp(get, fd))
		return ;
	while (em)
	{
		if (!ft_strncmp(em->arg, get, ft_strlen(get)))
		{
			ft_putstr_fd(&em->arg[ft_strlen(get) + 1], fd);
			break ;
		}
		em = em->nxt;
	}
}

void	here_exp(char *li, int fd)
{
	char	*get;
	int		i;
	int		j;

	i = -1;
	get = malloc(sizeof(char) * ft_strlen(li) + 1);
	while (li[++i])
	{
		if (li[i] != '$')
			ft_putchar_fd(li[i], fd);
		else
		{
			j = -1;
			if (li[i + 1] == '$' || li[i + 1] == '?')
				get[++j] = li[++i];
			while (li[++i] && (ft_isalpha(li[i])
					|| ft_isdigit(li[i]) || li[i] == '_'))
				get[++j] = li[i];
			get[++j] = '\0';
			print_env(get, fd);
			i--;
		}
	}
	ft_putchar_fd('\n', fd);
	free(get);
}
