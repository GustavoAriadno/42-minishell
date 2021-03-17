/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:16:10 by aroque            #+#    #+#             */
/*   Updated: 2021/03/17 10:06:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include "libft.h"
# include "hash.h"
# include "token.h"
# include "job.h"

# define BIN	"./minishell"

typedef struct	s_variable
{
	char		*value;
	bool		env;
}				t_variable;

typedef	struct	s_shell
{
	t_job		*jobs;
	t_hashtable	*env;
	char		**envp;
	char		**child_envp;
	size_t		envp_size;
	bool		exit;
}				t_shell;

extern t_shell	*g_shell;

void			prompt(t_hashtable *env);
int				create_process(t_shell *shell);
void			sighandler_prompt(int signum);
void			sighandler_process(int signum);
void			repl(t_shell *shell);
char			**getpaths(const char *argv, const char *path);
t_hashtable		*load_env(char *envp[]);
char			**unload_env(t_hashtable *env, size_t *envp_size);
int				execute_command(t_shell *shell);
void			free_shell(t_shell *shell);

int				pathslen(char c, const char *path);
char			*setpath(const char *path, const char *argv, int i);
char			*abspath(const char *argv);

int				execute_all(t_shell *shell);
int				execute_builtin(t_process *p, t_shell *shell,
					bool *builtin, int out);
int				execute_process(t_process *p, t_shell *shell, int in, int out);
void			free_array(void **array);

int				redirect_handler(t_process *p, int in, int out);
int				file_descriptor_handler(int in, int out);
char			*get_value(t_hashtable *env, const char *key);
void			set_exit_status(t_hashtable *env, int status);
char			*set_value(t_hashtable *env, const char *pair, bool is_env);

char			*node_to_envp(t_htlist *node);
char			**local_envp(char **local_envp, char **envp, size_t envp_size);

void			freemat(char **mat);
void			free_buffer(char **buffer);
void			free_variable(void *v);
void			free_shell(t_shell *shell);

#endif
