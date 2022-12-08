/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:16:15 by gehebert          #+#    #+#             */
/*   Updated: 2022/12/06 12:51:09 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"
// set = endtype*char	count 0++; 

static int	token_count(char *s, char *set, int tkn)
{
	int		q[2];
	int		i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (s && s[i] != '\0')
	{
		tkn++;
		if (!ft_strchr(set, s[i]))
		{
			while ((!ft_strchr(set, s[i]) || q[0] || q[1]) && s[i] != '\0')
			{
    
					q[0] = (q[0] + (!q[1] && s[i] == '\'')) % 2;
					q[1] = (q[1] + (!q[0] && s[i] == '\"')) % 2; 
					i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else 
			i++;
	}
<<<<<<< HEAD
		printf("DEBUG: token_count :: tkn = %d\n", tkn);
	return (tkn); //how many end..
=======
			printf("DEBUG: token_count :: tkn = %d\n", tkn);
	return (tkn ); //how many end..
>>>>>>> 9d3502c8a4dda4a24c2b4b0969f5d62893d7c757
}

// static t_token	*token_params(t_table *tab) //, char **a[2])//, int *i) // endtype (int)
	// {
	// 	t_token *token;
	// 	char **cmd;
	// 	char ***mx;
	// 	int id;
	// 
	// 	id = 0;
	// 	// cmd = NULL;
	// 	// token->cmd = tab->node;
	// 	cmd = tab->node; //[id][node[;]
	// 	// cmd = tab->node;
	// 
	// 	if (token->cmd && (token->id < token->cmd_len) && (token->id < tab->token_len))
	// 	{
	// 		printf("\n\n\n");
	// 		if (tab->cmds == ">" && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
	// 		if (mx[id][cmd][nod] == '>' && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
	// 			token = get_outfile2(token, mx[id]);//nod
	// 		else if (mx[id][cmd][nod] == '>')
	// 			token = get_outfile1(token, mx[id]);//nod
	// 		else if (a[0][*i][0] == '<' && a[0][*i + 1] && 
	// 			a[0][*i + 1][0] == '<')
	// 			m = get_infile2(m, a[1], i);*/
	// 		else if (mx[id][cmd][nod] == '<')
	// 			token = get_infile1(token, mx[id]);	//nod
	// 		else if (mx[id][cmd][nod] != '|')
	// 		// 	m->full_cmd = ft_mx_ext(m->full_cmd, a[1][*i]);
	// 		// else
	// 		{
	// 			//mini_perror(PIPENDERR, NULL, 2);
	// 			// *i = -2;
	// 		}
<<<<<<< HEAD
	// 		return (token);
=======
	// 					// 	m->full_cmd = ft_mx_ext(m->full_cmd, a[1][*i]);
	// 					// else
	// 					// {
	// 						//mini_perror(PIPENDERR, NULL, 2);
	// 						// *i = -2;
	// 					// }
	// 					// return (token);
	// 	// }	
	// 	// mini_perror(PIPENDERR, NULL, 2);
	// 	// *i = -2;
	// 	return (tab->token->endtype);
// }


//	`
// set == endtype char_split	i[x] == start_pos/sub_end/end_pos
	// static char	**token_fill(char *s, char *set, t_table *tab)
		// {	
		// 	int tk_id;
		// 	// int i;
		// 		// int len;
		// 		// int		q[2];
		// 		// q[0] = 0;
		// 		// q[1] = 0;
		// 		// len = ft_strlen(s);

		// 	// i = 0;
		// 	tk_id = 0;
		// 		// how many token
		// 		// how long token is 
		// 		// which endtype that closeit...
		// 		// printf("DEBUG: token_Fill :: set ::%s::\n", set);
		// 		// printf("DEBUG: token_Fill :: node ::%s::\n", s);
		// 		// printf("DEBUG: token_Fill :: tk_num ::%d::\n", tab->tk_num);

		// 	if (ft_mx_len(*tab->cmds) > 0)
		// 		printf("\ntk_id > 0\n");

		// 	// {

		// 		// add mx_ext str to an arr!

		// 	if(!ft_strchar_i(set, s))
		// 		tab->cmds[tk_id] = ft_mx_ext(*tab->cmds, s);
		// 	// {
		// 	// 	// i++
		// 	// 	printf("DEBUG: token_Fill :: not_end cmds[%d] ::%s::\n", tk_id, *tab->cmds[tk_id]);
		// 	// 	tk_id++;
		// 	// }
		// 	// if(ft_strchar_i(set, s)) 
		// 	// {
		// 	// 	tab->cmds[tk_id] = ft_mx_ext(tab->cmds[tk_id], s);
		// 	// 	printf("DEBUG: token_Fill :: endtype cmds[%d] ::%s::\n", tk_id, *tab->cmds[tk_id]);
		// 	// 	tk_id++;

		// 	// }	
		// 		// }
		// 		// tab->cmds[tk_id] = ft_mx_ext(tab->cmds[tk_id], s);
		// 		// mx_display_tab(tab->cmds[tk_id]);
		// 		return (tab->cmds[tk_id]);
		// 			// *tab->cmds[tk_id] = s;


		// 			// while (s)
		// 			// {

		// 				// i[1] = i[0];
		// 				// while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
		// 				// {
		// 				// 	q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
		// 				// 	q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2; 
		// 				// 	i[0]++;
		// 				// }
		// 				// if (i[1] >= len)
		// 				// 	aux[i[2]++] = "\0";
		// 				// else
		// 				// 	aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
		// 				// 	// tab->token
		// 				// while (s[i[0]] && i[0] <= len)
		// 				// {
		// 				// 	while(ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
		// 				//     	i[0]++;
		// 				// 	i[1] = i[0];
		// 				// 	while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
		// 				// 	{
		// 				// 		q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
		// 				// 		q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2; 
		// 				// 		i[0]++;
		// 				// 	}
		// 				// 	if (i[1] >= len)
		// 				//     	aux[i[2]++] = "\0";
		// 				// 	else
		// 				// 		aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
		// 				// 		// tab->token
		// 				// 	}
		// 				// mx_display_tab(aux);
>>>>>>> 9d3502c8a4dda4a24c2b4b0969f5d62893d7c757
	// 	}
	// 	mini_perror(PIPENDERR, NULL, 2);
	// 	*i = -2;
	// 	return (token);
// }

<<<<<<< HEAD
	// set == endtype char_split	i[x] == start_pos/sub_end/end_pos
static char	**token_fill(char **aux, char *s, char *set, int i[3])
{	
	int len;
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	len = ft_strlen(s);
	// printf("DEBUG: token_Fill :: set ::%s::\n", set);
	while (s[i[0]])
	{
		while(ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
        	i[0]++;
		i[1] = i[0];
		while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
		{
			q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
			q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2; 
			i[0]++;
		}
		if (i[1] >= len)
        	aux[i[2]++] = "\0";
		else
			aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
			// tab->token
		}
		return (aux);
}

// 	set = {"<",">","|"} :: if(!set) ? end : err //	s = 
=======

	static char	**token_fill(char **aux, char *s, char *set, int i[3])
	{	// set == endtype char_split	i[x] == start_pos/sub_end/end_pos
		int		q[2];

		q[0] = 0;
		q[1] = 0;
		while (s && s[i[0]] != '\0')
		{
			i[1] = i[0];
			if (!ft_strchr(set, s[i[0]]))
			{
				while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
				{
					q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
					q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2; 
					i[0]++;
				}
			}
			else
				i[0]++;
			aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
				// tab->token
			}
			return (aux);
	}


	//  ls -lat | wc -l > out.txt  
// 	set = {"<",">","|"} :: if(!set) ? end : err 
>>>>>>> 9d3502c8a4dda4a24c2b4b0969f5d62893d7c757
char	 **div_token(const char *s, char *set, t_table *tab) // call by parse>split_all
{
		
	char    **tkn;			// token sub_split by endtype
	int 	tk_id;			// focus token

	tk_id = 0;
	if (!s)					// s <<  args[i]  << tab->cmds
		return (NULL);

    tab->tk_num = token_count((char *)s, set, 0);	// how many end
	if (tab->tk_num == (-1))
		return (NULL);
<<<<<<< HEAD
	printf("DEBUG: div_token :: tk_num = %d\n", tab->tk_num);

    tkn = (char **)malloc(sizeof(char *) * (tab->tk_num + 2)); 
    if (!(*tkn))
	    return (NULL);
    tkn = token_fill(tkn, (char *)s, set, 0);	
=======
		
	printf("DEBUG: div_token :: tk_num = %d\n", tab->tk_num);

	tkn = (char **)malloc(sizeof(char *) * (tab->tk_num + 2)); 
	if (!(*tkn))
	    return (NULL);
		
	tkn = token_fill(tkn, (char *)s, set, i);	
	if (!(*tkn))
	    return (NULL);
	// printf("DEBUG: div_token :: tkn_str_len = %d\n", ft_mx_len(tkn));	
	// printf("DEBUG: div_token :: tk_len = %s\n", tkn[0]);	
			// tab->token->cmd = (char **)malloc(sizeof(char *) * (tab->tk_num + 1)); 
			// if (!(tab->token->cmd))
			// 	return (NULL);	
			// else
			// {
			// mx_display_tab(tkn);
			// }
	  
			// tab->token->endtype = token_etype(tab);
			// tk_id = token_etype(tab);
				// printf("DEBUG: div_token :: endtype = %d\n", tab->token->endtype);	
	
	// printf("DEBUG: div_token :: end...\n");
	return (tkn);    
}
  //   ls  -lta| wc -l >> out.txt   
>>>>>>> 9d3502c8a4dda4a24c2b4b0969f5d62893d7c757
	// tab->token->tk_len = ft_mx_len(tkn);
	// printf("DEBUG: div_token :: tk_len = %d\n", tab->token->tk_len);
	// t_fill reciv array *str endtyp
		//		**tkn << tab->cmds >> sub_split / endtype char
	
	///		ft_mx_ext ... 
		// if (*tkn)
		// {
		// 	tab->node[tk_id] = tkn[tk_id];
		// 	tk_id++;		// tab->token->id = 0;		// tab->token->id++;
		// 	while (tk_id < tab->tk_num)
		// 	{
		// 		tab->node[tk_id] = tkn[tk_id];
		// 		tk_id++;
		// 	}
		// 	// mx_display_tab(tkn);
	// }
	/*
		while (nb < tknum)
		{
			token->id = nb;
			token->cmd = aux[0];
			token->endtype = 
		}
		aux ** == tab->node[id][str]] 
		tab->node[token_id] = NULL;
	*/
    return (tkn);    
}

/*
from parse.c /split_all ->
	div_token 	=> token spliter by ending char (<,>,|)
	word_count & ft_fill_array ... no comment!
	*** return table_command : called token !
*/