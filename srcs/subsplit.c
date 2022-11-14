/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:05:13 by gehebert          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/09 01:09:01 by gehebert         ###   ########.fr       */
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

static int ft_count_words(const char *s, char *c, int i[2])
{
    int     q[2];
=======
/*   Updated: 2022/11/10 22:00:31 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int word_count(const char *s, char *c, int i[2])
{
    int     q[2];   // quotes match delimter
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1

    q[0] = 0;
    q[1] = 0;
    while (s[i[0]] != '\0')
    {
        if (!ft_strchr(c, s[i[0]]))
        {
            i[1]++;
            while ((!ft_strchr(c, s[i[0]]) || q[0]) && s[i[0]] != '\0')
            {
                if(!q[1] && (s[i[0]] == '\"' || s[i[0]] != '\0')) //"
                    q[1] = s[i[0]];
                q[0] = (q[0] + (s[i[0]] == q[1])) % 2;
                q[1] *= q[0] != 0;
                i[0]++;
            }
            if (q[0])
                return (-1);
        }
        else
            i[0]++;
    }
    return (i[1]);
}

static char **ft_fill_array(char **aux, const char *s, char *set, int i[3])
{
    int     len;
<<<<<<< HEAD
    int     q[2];
=======
    int     q[2];       // quotes match
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1

    q[0] = 0;
    q[1] = 0;
    len = ft_strlen(s);
    while (s[i[0]])
    {
        while(ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
            i[0]++;
        i[1] = i[0];
        while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) & s[i[0]])
        {
            q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
            q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2; //"
            i[0]++;
        }
        if (i[1] >= len)
            aux[i[2]++] = "\0";
        else
            aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
    }
    return (aux);
}

char **ft_cmdtrim(const char *s, char *set)
{
    char    **aux;
    int     nwords;
<<<<<<< HEAD
    int     i[3];
    int     count[2];
=======
    int     i[3];       //state pos: start, sub-end, end
    int     count[2];   // str sub len [0:start/1:end]
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1

    i[0] = 0;
    i[1] = 0;
    i[2] = 0;
    count[0] = 0;
    count[1] = 0;
    if (!s)
        return (NULL);
<<<<<<< HEAD
    nwords = ft_count_words(s, set, count);
=======
    nwords = word_count(s, set, count);
>>>>>>> 0899604fbd76ebb5d884b258fef592fcc32fd7f1
    if (nwords == -1)
        return (NULL);
    aux = malloc(sizeof(char *) * (nwords + 1));
    if (aux == NULL)
        return (NULL);
    aux = ft_fill_array(aux, s, set, i);
    aux[nwords] = NULL;
    return (aux);   
}
