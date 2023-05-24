/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:07:45 by agimi             #+#    #+#             */
/*   Updated: 2023/05/24 22:01:45 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct file_in
{
	int				fd;
	int				herdoc;
	int				flag;
	char			*file;
	char			*del;
	struct file_in	*nxt;
}	t_fin;

typedef struct file_out
{
	int				fd;
	int				flag;
	char			*file;
	mode_t			perm;
	struct file_out	*nxt;
}	t_fout;

//pipe line
//line struct
typedef struct pipe
{
	char		*pl;
	struct line	*lin;
	struct pipe	*nxt;
	t_fin		*fin;
	t_fout		*fout;
}	t_pipe;

//Shanks
//type
typedef struct line
{
	char		*shx;
	char		*typ;
	char		*path;
	struct line	*nxt;
	struct line	*prv;
}	t_line;

typedef struct envir
{
	char			*arg;
	struct envir	*nxt;
}	t_env;

//struct pipe
typedef struct vars
{
	char	**envp;
	char	*line;
	t_pipe	*sp;
	t_env	*env;
	pid_t	*pids;
}	t_vars;

t_vars	g_va;

/***********************LIBFT***********************/
void	ft_backpipe(t_pipe **sp, t_pipe *new);
void	ft_backline(t_line **lin, t_line *new);
void	ft_backfin(t_fin **fin, t_fin *new);
void	ft_backfout(t_fout **fout, t_fout *new);
void	ft_lstclear(t_pipe **sp);
t_pipe	*ft_lastpipe(t_pipe *sp);
t_line	*ft_lastline(t_line *lin);
t_fin	*ft_lastfin(t_fin *fin);
t_fout	*ft_lastfout(t_fout *fout);
t_pipe	*new_sp(char *str);
t_fin	*new_fin(char *file, int her, char *del);
t_fout	*new_fout(char *file, int app);
t_line	*new_lin(char *str);
t_env	*new_env(char *str);
t_env	*ft_lastenv(t_env *env);
void	ft_backenv(t_env **env, t_env *new);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(char c);
int		ft_isred(char c);
int		ft_isquot(char c);
int		ft_isspec(char c);
int		ft_isdlr(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_pipesize(t_pipe *sp);
void	ft_free(void);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, int start, int len);
/***********************LIBFT***********************/

int		fill_sp(char *line);
void	fill_lin(void);
void	trim_space(char *line);
void	clean_lin(void);
int		check_error(void);
int		check_pipe(void);
int		check_quote(void);
int		check_red(void);
void	lin_type(void);
void	expand(void);
int		charloc(char *str, int n);
void	copy_bef(char *new, int start, char *lin);
void	copy_mid(char *new, int start, char *found);
void	copy_af(char *new, int start, int nst, char *lin);
void	clean(void);
void	set_cmd(void);
void	set_env(char **env);
void	set_arg(void);
void	forking(void);
void	set_file(void);
void	open_fin(t_pipe *sp);
void	open_fout(t_pipe *sp);
void	print_error(char *str);
void	childs(t_pipe *sp);
void	free_env(t_env **env);
void	free_fin(t_pipe *sp);
void	free_fout(t_pipe *sp);

#endif