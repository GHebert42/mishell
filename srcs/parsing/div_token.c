/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:16:15 by gehebert          #+#    #+#             */
/*   Updated: 2022/12/08 11:04:46 by gehebert         ###   ########.fr       */
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
		// if (ft_strchr(set, s[i]))
		tkn++;
		if (!ft_strchr(set, s[i]))
		{
			while ((!ft_strchr(set, s[i])) && s[i] != '\0')
			{ 
					q[0] = (q[0] + (!q[1] && s[i] == '\'')) % 2;
					q[1] = (q[1] + (!q[0] && s[i] == '\"')) % 2; 
					i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		i++;
		// if (ft_strchar_i(&s[i], set))
		// 	tkn++;
	}
			printf("DEBUG: token_count :: tkn = %d\n", tkn);
	return (tkn ); //how many end..
}

// static int	token_etype(t_table *tab) //, char **a[2])//, int *i) // endtype (int)
	// {
	// 	t_token *token;
	// 	char **cmd;
	// 	int id;

	// 	id = 0;
	// 	cmd = tab->node; //[id][node[;]
	// 	token = tab->token;
	// 	//
	// 		//	get to *node[0]	== token->cmds
	// 		//	get *node[len-1] == 
	// 		//	get *node[len]	== token->endtype
	// 			// DEAD_END  = 0,
	// 			// PIPE_END  = 1,
	// 			// OUTF1_END = 2,
	// 			// OUTF2_END = 3,
	// 			// INF1_END  = 4,
	// 			// INF2_END  = 5,
	// 			// ERR_END   = 6

	// 	// while (id <= tab->tk_num)
	// 	// {
	// 			printf("\nendtype\n");
	// 		if (token->cmd && (token->id < token->tk_len) && (token->id < token->tk_len))
	// 		{
	// 			// if (tab->cmds == ">" && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
	// 			// 	token = get_outfile2(token, mx[id]);//nod
	// 			if (*cmd[id] == '>' && cmd  && *cmd[id + 1] == '>')
	// 				tab->token->endtype = 3;	
	// 			// if (mx[id][cmd][nod] == '>' && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
	// 			// 	token = get_outfile2(token, mx[id]);//nod


	// 			else if (*cmd[id] == '>')
	// 				tab->token->endtype = 2;
	// 						// token = get_outfile1(token, mx[id]);//nod
	// 						// else if (a[0][*i][0] == '<' && a[0][*i + 1] && 
	// 						// 	a[0][*i + 1][0] == '<')
	// 						// 	m = get_infile2(m, a[1], i);*/
	// 						// else if (mx[id][cmd][nod] == '<')
	// 						// 	token = get_infile1(token, mx[id]);	//nod

	// 			else if (*cmd[id] != '|')
	// 				tab->token->endtype = 1;
	// 			else if (*cmd[id] != '\0')
	// 				tab->token->endtype = 0;
					
	// 		}
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

//	
// set == endtype char_split	i[x] == start_pos/sub_end/end_pos
	// 

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


	//  ls -lat | wc -l > out.txti  
	// 	ls -lt| head -2 |wc -c>> out.txt
// 	set = {"<",">","|"} :: if(!set) ? end : err 
char	 **div_token(const char *s, char *set, t_table *tab, int tkn_num) // call by parse>split_all
{
	
	char    **tkn;			// token sub_split by endtype
	int i[3];

		// int 	tk_id;		// focus token	// tk_id = 0;
	i[0] = 0;				// set start pos ptr
	i[1] = 0;				// set sub_end pos ptr
	i[2] = 0;	
	if (!s)					// s <<  args[i]  << tab->cmds
		return (NULL);
	//
	if (!(tkn_num > 0))
	{
		tab->tk_num = token_count((char *)s, set, 1);	// how many end at_least_1
		// tab->token->id++;
	}
		
	
	if (tab->tk_num == (-1))
		return (NULL);
		
	// printf("DEBUG: div_token :: tk_num = %d\n", tab->tk_num);

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
  //   ls  -lta | wc -l >> out.txt   
	// tab->token->tk_len = ft_mx_len(tkn);
	
		// t_fill reciv array *str endtyp
		//		**tkn << tab->cmds >> sub_split / endtype char
	
		///		ft_mx_ext ... 
		//		
		///;
			// tab->token = token_etype(tab)
			// if (*tkn)
			// {
			// 	tab->node[tk_id] = tkn[tk_id];
			// 	tk_id++;		// tab->token->id = 0;		// tab->token->id++;
			// 	while (tk_id < tab->tk_num)
			// 	{
			// 		tab->node[tk_id] = tkn[tk_id];
			// 		tk_id++;
			// 	}
				// mx_display_tab(tkn);
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
 // return (tab->cmds[i])
 
/*
from parse.c /split_all ->
	div_token 	=> token spliter by ending char (<,>,|)
	word_count & ft_fill_array ... no comment!
	*** return table_command : called token !
*/