/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:38:53 by agimi             #+#    #+#             */
/*   Updated: 2023/05/28 22:38:03 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		while (arg[++i] && arg[i] == 'n')
			;
		if (!arg[i])
			return (1);
	}
	return (0);
}
/*
echo  echo $asd  
*/

void	skip_n(t_line **lm, int *n)
{
	if (!lm || !*lm || !(*lm)->shx)
		return ;
	while ((*lm) && check_arg((*lm)->shx))
	{
		if (check_arg((*lm)->shx))
			*n = 1;
		(*lm) = (*lm)->nxt;
	}
}

void	echo_cmd(t_line *lm, int x)
{
	int	n;

	if (open_file(g_va.sp, x))
		return ;
	n = 0;
	skip_n(&lm, &n);
	while (lm && lm->shx)
	{
		if (!ft_strcmp(lm->typ, "arg"))
		{
			printf("%s", lm->shx);
			if (lm->nxt)
				printf(" ");
		}
		lm = lm->nxt;
	}
	if (!n)
		printf("\n");
	if (x)
		exit(0);
	close_fd();
}
