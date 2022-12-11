/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:48:49 by gehebert          #+#    #+#             */
/*   Updated: 2022/12/08 12:33:38 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_status;

static int	token_etype(t_table *tab) //, char **a[2])//, int *i) // endtype (int)
{
    t_token *token;
    char **cmd;
    int id;

    id = 0;
    cmd = tab->node; //[id][node[;]
    token = tab->token;
		//
    printf("\nendtype\n");
			//	get to *node[0]	== token->cmds
			//	get *node[len-1] == 
			//	get *node[len]	== token->endtype
				// DEAD_END  = 0,
				// PIPE_END  = 1,
				// OUTF1_END = 2,
				// OUTF2_END = 3,
				// INF1_END  = 4,
				// INF2_END  = 5,
				// ERR_END   = 6

    // while (id <= tab->tk_num)
    // {
        if (token->cmd && (token->id < token->tk_len) && (token->id < token->tk_len))
        {
            // if (tab->cmds == ">" && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
            // 	token = get_outfile2(token, mx[id]);//nod
            if (*cmd[id] == '>' && cmd  && *cmd[id + 1] == '>')
                tab->token->endtype = 3;	
                // if (mx[id][cmd][nod] == '>' && mx[id][cmd + 1] && mx[id][cmd + 1][nod] == '>')
                // 	token = get_outfile2(token, mx[id]);//nod


            else if (*cmd[id] == '>')
                tab->token->endtype = 2;
                        // token = get_outfile1(token, mx[id]);//nod
                        // else if (a[0][*i][0] == '<' && a[0][*i + 1] && 
                        // 	a[0][*i + 1][0] == '<')
                        // 	m = get_infile2(m, a[1], i);*/
                        // else if (mx[id][cmd][nod] == '<')
                        // 	token = get_infile1(token, mx[id]);	//nod

            else if (*cmd[id] != '|')
                tab->token->endtype = 1;
            else if (*cmd[id] != '\0')
                tab->token->endtype = 0;
                
        }
						// 	m->full_cmd = ft_mx_ext(m->full_cmd, a[1][*i]);
						// else
						// {
							//mini_perror(PIPENDERR, NULL, 2);
							// *i = -2;
						// }
						// return (token);
		// }	
		// mini_perror(PIPENDERR, NULL, 2);
		// *i = -2;
        return (tab->token->endtype);
}
// set == endtype char_split	i[x] == start_pos/sub_end/end_pos


/*       char **args = tab->cmds  :  token chunk    */
static t_table *split_all(char **node, t_table *tab)  
{
    char **box;
    char *set;
    int     i;
    int     id;     // tkn_id     
    int     focus_id;
    int quotes[2];

    i = -1;
    id = 0;

    quotes[0] = 0;
    quotes[1] = 0;
    set = "<|>";
    box = NULL;

    while (node && node[++i])       
    {
         //args = tab->cmds[id]
            //        :: node_id[0]/node_id[len-1] {(attr = null) if (len = 2)}
            //        :: token->[cmd][attr][end] ==>> token->[cmd=id[0]] [attr] [end=id[len-1]] */
        //expand_var ...   
        node[i] = expand_vars(node[i], -1, quotes, tab);  
        //expand_var ...   
        node[i] = expand_path(node[i], -1, quotes, ms_getenv("HOME", tab->envp, 4));
        //expand_path ...         
        box = div_token(node[i], set, tab, tab->tk_num); 
        //div_token ...
        printf("DEBUG: spl_ll tkn[%d]_node_id[%d]::[%s]::\n", tab->token->id, i, node[i]);
        if (tab->tk_num > 0)
                {
       //goto token_node
                    tab->token->cmd = ft_mx_ext(tab->token->cmd, node[i]);
                    ++id;
                    if (ft_strchar_i(node[i], set))        
                    {

                        tab->token->cmd = ft_mx_ext(tab->token->cmd, "\0");
                        ++id;
                    }
                    tab->token->tk_len = id;
                    tab->tk_num--;

                    // printf("DEBUG: split:token_len[%d]:: node left[%d]  \n",tab->token->tk_len, tab->tk_num);
                } 
                focus_id = tab->token->id;
                if (tab->tk_num == 0 ) 
                {
                    // printf("DEBUG: _ll token->len= %d \n", ft_mx_len(tab->token->cmd));
                    // mx_display_tab(tab->cmds[focus_id]);
                    tab->token->id++;
                    // ft_mx_free(&tab->token->cmd);
                }
        
 //  ls  -lta | wc -l >> out.txt 

 //  ls  -lta| head -2| wc -l >> out.txt 

         // tab->token = token_nodes(tab);
        // printf("tk_id[%d] ==> ...%s... \n", id, tab->token->cmd[i]);


        // printf("DEBUG: split_all :: tk_id = %d\n", id);
        // printf("DEBUG: split all :: t->cmd = %s\n", tab->token->cmd[i]);
    }
    return (tab); 
}

static t_token  *parse_args(t_table *tab)
{
    int i; // int is_exit; // is_exit = 0;
    int type_id;
    int tk_id;

    t_token *token;
    token = tab->token;

    i = 0;
    tk_id = 0;
    type_id = 0;

    
            
    tab = split_all(tab->node, tab); 
    // printf("DEBUG: parse >>token_num = [%d] \n",tab->tk_num);
    while( token->endtype != 0)
    {
        token->tk_len = ft_mx_len(tab->cmds[tk_id]);

        // //
        token->endtype = token_etype(tab);
        // type_id = endtype(tab);
        //
        // //
    }
            // tab->cmds[tk_id] = ft_mx_rpl(tab->cmds, tab->node, tab_len);
            // tab_len = ft_mx_len(tab->cmds[i]);
            // printf("DEBUG: parse >>token_len = [%d] \n",tab->tk_num );

            //          pass nodes splited to be check /meta
            // token = token_nodes(tab);
            // printf("DEBUG: parse... tab->token >>\n");
    if (tab->cmds[tab->tk_num])
    {
        // mx_display_str(*tx[0]);
        i = ft_mx_len(tab->cmds[tab->tk_num]);
         printf("DEBUG: parse >>tab->cmds[%d] len = %d >>\n",tab->tk_num, i);
    }

    // token = token_nodes(tab);  
    // mx_display_tab(token->cmd);
     //     node breaker =>   node_token == token_builder ...
        
        /*  tab->node [*str]  sep.space. node -ID.less
            tab >> tab->token-> ... arg-set value ...TBD            
            // tab->
            // i = ft_lstsize(tab->cmds);
            // g_status = builtin(p, p->cmds, &is_exit, 0);             
         */    
         
    i = 0;
    while (i-- > 0)
        waitpid(-1, &g_status, 0);
    if (g_status > 255)
        g_status = g_status / 255;
    
       // if (!is_exit && &g_status == 13)
        //     g_status = 0;
        // if (args && is_exit)
        // {
        //     ft_lstclear(&p->cmds, free_content);
        //     return (NULL);
        // }
    
    return (tab->token);
}

t_table  *check_args(char *input, t_table *tab)  // main deply >parse
{
     int n;     //int node
    //  int i;    // i = 0;
    n = 0;
    if (!input)
    {
        printf("exit\n");
        return (NULL);
    }
    if (input[0] != '\0')
        add_history(input);
        
    // should call node_spec 
    //
    // remove over_space
    // add space padding
    
    tab->node = init_split(input, " ", tab); // space split 
    if (tab->node)
    {   
        n = ft_mx_len(tab->node);
        printf("DEBUG: check :: node_num ::%d::\n", n);
        // mx_display_tab(tab->node);
    }
    tab->token = parse_args(tab);    // tab->node        
     // while(tab->node)
        // {
        //     i = 0;
        //     while(*tab->node[i] != '\0')
        //     {
        //         printf("\n check node > [%s] \n", tab->node[i]);
        //         i++;
        //     }
        //     tab->node++;
        // }
        // *tab->cmds = node_check(tab->node, "|");

        // }
            // printf("\nOK TEST INPUT :: :: END\n");   
                // mx_display_tab(tab->cmds);
                // display_tkn(tab);
                // len = ft_mx_len(tab->node);
                // printf("\n%d :::\n", len);
                // return (tab);
        // if (tab->cmds[0])
        //     printf("DEBUG : into... check_arg\n");
        // exit(0);
            // if (tab->cmds && tab->tk_num > 0)
            // else
            //     return (NULL);
        /*
                    if (tab && tab->token)
                        display_tkn(tab);

        token need to be ID _cmd, _attr, _end         */
                /*
                    if (tab && tab->cmds && tab->token && tab->tk_num > 0)
                    {
                        // p->envp = ms_setenv("_", m->full_cmd[ft_mx_len(m->full_cmd)
                        //  - 1], p->envp, 1);                                    
                            //     ft_lstclear(&p->cmds, free_content);
        */
    // }

    // free(input);
    return (tab); 

/*
from check.c
    check_args  => take input to be init_split to build table command
    init_split   => will do that init_split into a tab **       ==> init_split.c
    parse_args  => call fill_node  return *p (list-> p.cmds)    ==> nodes.c
    split_all   =>  token's alternate end if it's not! 
                    div_token  ('<','>','|')                    ==> divide.c
                    expand_vars & expand_path                   ==> expand.c
    *** so in my mind a token is : CMD + ARG + END 
    *** in fact ARG is facultative
*/
}
