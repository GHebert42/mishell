/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:54:28 by bylkus            #+#    #+#             */
/*   Updated: 2023/02/06 13:23:51 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_status;
int is_builtin(t_token *t)
{
    int l;
    int id;
    
    id = 0; 
    if (!(t->cmd[0]))
		return (0);
	if (t->cmd && ft_strchr(*t->cmd, '/') || (t->path && ft_strchr(t->path, '/')))
		return (0);
	l = ft_strlen(*t->cmd);
	if (!ft_strncmp(*t->cmd, "pwd", l) && l == 3)
		return (1);
	if (!ft_strncmp(*t->cmd, "env", l) && l == 3)
		return (1);
	if (!ft_strncmp(*t->cmd, "cd", l) && l == 2)
		return (1);
	if (!ft_strncmp(*t->cmd, "export", l) && l == 6)
		return (1);
	if (!ft_strncmp(*t->cmd, "unset", l) && l == 5)
		return (1);
	if (!ft_strncmp(*t->cmd, "echo", l) && l == 4)
		return (1);
	if (!ft_strncmp(*t->cmd, "exit", l) && l == 4)
		return (1);
	return (0);
}


void    exit_builtin(char **cmd)
{
    int exiit = 0;
    int i = 0;
    if(cmd[1] && !cmd[2])
    {
        while(cmd[1][i])
        {
            if(!ft_isdigit(cmd[1][i]) && cmd[1][i] != '-')
                error_msg("exit: numeric argument required\n", 255);
            i++;                
        }
        exiit = ft_atoi(cmd[1]);
    }
    exit(exiit);
}


// void    builtins_handler(char *input, char **envp)
int    builtins_handler(t_table *tab, t_token *token)
{
    char *input;
    char **envp;

    // int i = 0;
    // envp = tab->envp;
     printf("\nDEBUG: b_handler:: chk_bltn ::[id:%d] \n", tab->token->id);//t->path { %s }\n", token->path); 	//len[%d]", l);
    token = get_token(tab, tab->token, tab->token->id);
    input = *tab->cmds[tab->token->id];//token->cmd;
    envp = save_old_pwd(envp);    
    if (ft_strnstr(input, "exit", 5))
        exit_builtin(ft_split(input, ' '));
    else if(ft_strnstr(input, "cd", 10))
        g_status = cd(ft_split(input, ' '), envp);
    else if(ft_strnstr(input, "export", 10))
        g_status = ms_export(ft_split(input, ' ') , envp);
    else if(ft_strnstr(input, "unset", 10))
    {
        if(unset(ft_split(input, ' '), envp) == 0)
            printf("No such variable\n");
    } 
    else if(ft_strnstr(input, "env", 5))
        env(envp);
    else 
    {
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
        execmd(tab, token);
        
    }
    return (g_status);
    // else if(ft_strnstr(input, "echo", 10))
    //     g_status = echo(ft_split(input, ' '));
    // else if (ft_strnstr(input, "pwd", 10))
    //     g_status = pwd();
}


