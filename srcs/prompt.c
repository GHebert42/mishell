/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:58:53 by gehebert          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/09 03:51:33 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../incs/minishell.h"
# include "../libft/includes/libft.h"

extern int g_status;

static char *get_home(t_prompt prompt)
=======
/*   Updated: 2022/11/10 21:58:25 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int g_status;

static char *get_home(t_dot p)
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
{
    char *tmp;
    char *pwd;
    char *home;

    pwd = getcwd(NULL, 0);                                        
    if (!pwd)
        pwd = ft_strdup("@ ");
<<<<<<< HEAD
    home = mini_getenv("HOME", prompt.envp, 4);
=======
    home = mini_getenv("HOME", p.envp, 4);
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    if (home && home[0] && ft_strnstr(pwd, home,ft_strlen(pwd)))  
    {
        tmp = pwd;
        pwd = ft_strjoin("-", &pwd[ft_strlen(home)]);
        free(tmp);
    }
    free(home);
    home = ft_strjoin(BLUE, pwd);
    free(pwd);
    pwd = ft_strjoin(home, " ");
    free(home);
    return(pwd); 
}

<<<<<<< HEAD
static char *get_user(t_prompt prompt)
=======
static char *get_user(t_dot p)
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
{
    char **user;
    char *tmp;
    char *tmp2;

    user = NULL;
    tmp2 = NULL;
<<<<<<< HEAD
    exec_custom(user, "/usr/bin/whoami", "whoami", prompt.envp);  
=======

    // exec_custom(user, "/usr/bin/whoami", "whoami", prompt.envp);  
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    if (!user)
        user = ft_mx_ext(user, "guest");                          
    if (!ft_strncmp(user[0], "root", 4))
        tmp2 = ft_strjoin(NULL, RED);
    else if ((int)(user[0][0]) % 5 == 0)
        tmp2 = ft_strjoin(NULL, CYAN);
    else if ((int)(user[0][0]) % 5 == 1)
        tmp2 = ft_strjoin(NULL, GRAY);
    else if ((int)(user[0][0]) % 5 == 2)
        tmp2 = ft_strjoin(NULL, GREEN);
    else if ((int)(user[0][0]) % 5 == 3)
        tmp2 = ft_strjoin(NULL, MAGENTA);
    else 
        tmp2 = ft_strjoin(NULL, YELLOW);
    tmp = ft_strjoin(tmp2, *user);
<<<<<<< HEAD
=======
    if (!(p.envp))
        return (tmp);
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    free(tmp2);
    ft_mx_free(&user);
    return (tmp); 
}

<<<<<<< HEAD
char    *mini_getprompt(t_prompt prompt)
=======
char    *mini_getprompt(t_dot p)
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
{
    char *tmp;
    char *tmp2;
    char *aux;

<<<<<<< HEAD
    tmp = get_user(prompt);                          
    tmp2 = ft_strjoin(tmp, "@mishell");
    free(tmp);
    aux = get_home(prompt);                   
=======
    tmp = get_user(p);                          
    tmp2 = ft_strjoin(tmp, "@mishell");
    free(tmp);
    aux = get_home(p);                   
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    tmp = ft_strjoin(tmp2, aux);
    free(aux);
    free(tmp2);
    if (!g_status || g_status == -1)
        tmp2 = ft_strjoin(tmp, BLUE);
    else
        tmp2 = ft_strjoin(tmp, RED);
    free(tmp);
    tmp =ft_strjoin(tmp2, "$ ");
    free(tmp2);
    tmp2 = ft_strjoin(tmp, DEFAULT);
    free(tmp);
    return (tmp2); 
}