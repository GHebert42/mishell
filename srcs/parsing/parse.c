/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehebert <gehebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:48:49 by gehebert          #+#    #+#             */
/*   Updated: 2023/02/01 04:07:15 by gehebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int g_status;
/*
* etype spot endtype index (tk_len, tk_num)
*/
static t_table	*redir_type(t_table *tab) 
{
    char    **cmd;
    int     n;
    int     id;
    int     *ref;

    id = -1;
    cmd = ft_mx_dup(tab->node); 
    n = ft_mx_len(cmd);    
    // printf  ("DEBUG: node_num[%d]\n", n);
    tab->token->id = 0;
    ref[tab->token->id] = 0; 
    while (id++ <= n)
    {
        tab->token->id = tab->tk_num;
        if (cmd[id] && (id < n))
        {
            if (*cmd[id] == '<' && *cmd[id + 1] == '<')
                tab->tk_num++; 
            else if (*cmd[id] == '<')
                 tab->tk_num + 0;//;  
            else if (*cmd[id] == '>' && *cmd[id + 1] == '>')
                 tab->tk_num + 0;//+;  
            else if (*cmd[id] == '>')
                  tab->tk_num + 0;//+;  
            else if (*cmd[id] == '|')
                tab->tk_num++;  
            // else if (*cmd[id] == '@')
            //       tab->token->id = tab->tk_num++; 
            ref[tab->token->id] = id; 
            // if (tab->token->id < tab->tk_num)
            //     printf  ("DEBUG: id[%d] ::REDIR::{%s}:: tk_num[%d]\n", id, cmd[id], tab->tk_num);
        }
    

    }
    // printf  ("DEBUG: tk_num[%d]\n", tab->tk_num);
    tab->refs = ref;
    return (tab);
}

static t_table *split_all(t_table *tab)  
{
      
    int     i;
    int     tkn_id;     
    int quotes[2];

    i = -1;
    tab->token->id = 1;
    tkn_id = 1;
    quotes[0] = 0;
    quotes[1] = 0;

    // need to build get_token HERE...
        // set token->cmd** ==> node[cmd] + node[arg]
        // set token->path* =>> (!is_buitins) 
        // (if) set token->full*  ===>> {"cmd"+" "+"arg"...} (in case)
        // set endtype  ==>  token->endtype  ==> behavior related!
        // infile=0; outfile=1; 
    tab = token_alloc(tab); // malloc each token + each token[cmd]    
    while (tab->node[++i] && tkn_id <= tab->tk_num)       
    {
        //expand_var ...   meta-char- safe-check execeptions 
        tab->node[i] = expand_vars(tab->node[i], -1, quotes, tab);  
        	// printf("DEBUG/: split_all tab->node[id:%d] node{%s} \n", i, tab->node[i]);	
            
        //expand_path ...         t->cmd[0] = "cmd" : t->cmd[1] = "cmd args etype" 
        tab->node[i] = expand_path(tab->node[i], -1, quotes, ms_getenv("HOME", tab->envp, 4));

        //must be token->path here
            // could add token->full here-now ... 
            //  token->cmd[0] ==> char *:"cmd"
            //  token->cmd[1] ==> char *:"full cmd arg etype" ...etype will fall later

            // printf("DEBUG: split_all tab->token->path == {%s} \n", tab->token->path);
    }
    tab = div_token(tab, "<|>"); // padd endtype + set token 
    // tab->token = get_token(tab, tab->token, tkn_id);
    return (tab); 
}

static t_token *set_token(t_table *tab)
{
    
    int id;
    int len;

    id = tab->token->id;
       /// set token >> malloc each >> 
		// printf("ok ici SET_T:: tk_num [%d]\n", tab->tk_num);
		// printf("ok ici SET_T:: token->id [%d]\n", tab->token->id);
        if (tab->token->id == 0)
            tab->token->id = 1;
        // else
            // tab->token->id++;
        tab->token->cmd = ft_split(tab->token->cmd[tab->token->id], ' ');
        // ft_split(*tab->token->cmd, ' ');
        // tab->token->lead = ft_strdup(lead[0]);

				// mx_display_tab(tab->token->cmd);
				// printf("DEBUG: token_fill path {%s} \n", tab->node[i + 1]);	
				// printf("DEBUG: token->full __%s__\n", tab->token->full);
				// printf("DEBUG: token->ofile {%s} \n\n", tab->token->ofile);
				printf("DEBUG:  SET_T:: token->cmd[%d] {%s} \n", id, tab->token->cmd[id-1]);

    	// setting t->ofile value OUTFILE 1 & 2
        len = ft_mx_len(tab->token->cmd);
        tab->token->endtype = set_endtype(tab,tab->cmds[tab->token->id][len]);
        printf("DEBUG: SET_T:token->endtype [%d]\n", tab->token->endtype);
        if (tab->token->endtype == 2 )// || tab->token->endtype == 3)
            tab->token = get_outfile1(tab->token, tab);
        else if (tab->token->endtype == 3)
            tab->token = get_outfile2(tab->token, tab);
        else if (tab->token->endtype == 4)
            tab->token = get_infile1(tab->token, tab);
        else if (tab->token->endtype == 5)
            tab->token = get_infile2(tab->token, tab);   
			// else if (tab->token->endtype == 0)
    return(tab->token);
}

static t_table  *parse_args(t_table *tab)
{

    int is_exit;
    // int tk_id;
    t_token *token;

    token = tab->token;
    is_exit = 0;
    tab->token->id = 1;
    printf("DEBUG: into... parse\n");
    tab = redir_type(tab); // *refs[id] tk_num [end_pos] == tk_len
    // printf("DEBUG:  REDIR __%d__ ...\n", tab->tk_num);             
    //
        ///
        // tab = token_alloc(tab); // malloc each token + each token[cmd]    
        // tab = div_token(tab, "<|>"); // padd endtype + set token 
        //
        ///
        //  OK NOW HERE : tab->cmds[id] shld have every node set... 
        //  SO IF INFILE2 GET ENDTYPE at the begening ... // tab->token = get_token(tab, tab->token, tkn_id);
        ///
    //
    tab = split_all(tab);         
       /*  tab->node [*str]  sep.space. node -ID.less
            tab >> tab->token-> ... arg-set value ...TBD            
            i = ft_lstsize(tab->cmds);     */
           // g_status = builtin(p, p->cmds, &is_exit, 0);       
            // if (tab->token->endtype >= 0)
        // tab->token = get_token(tab, tab->token, tab->token->id);
       // while (tab->token->endtype <= 0)
    tab->token->id = 1;
    tab->token = get_token(tab, tab->token, tab->token->id);
    printf("DEBUG:: parse: t->id[%d] ::  tk_num[%d]\n", tab->token->id, tab->tk_num);
    while (tab->token->id <= tab->tk_num)
    {
        // printf("\nDEBUG: parse_ #token[%d] . . .\n\n", tab->token->id);     
        set_token(tab);
        // first get token 
            // all of them 
            // then do it
            // free conte   nt...

            // set a token for each endtype
            //
            // tab->token->id++;
            //  // fill is form ... t->cmd** t->path t->endtype
            //  // 
        g_status = is_builtin(token);       
        if (g_status == 1)
            printf("\nDEBUG : is_builtin {%d}::\n", g_status);     
        g_status = builtins_handler(tab, tab->token, token->id);
        
        // tab->token->id++;
        token->path = NULL;
        tab->token->id++;
        // {
        
            // if (tab->token->endtype == 0)
            // {
            //     execmd(tab, tab->token, tk_id);

            // }
            //     tab->token->tk_len--;
            // else
            // printf("DEBUG : g_status << {%d} >>::\n", g_status);     

            // free_cont(tab->token, tk_id);
            // tk_id--;
            // tab->token->id++;
            // if (tk_id > 0 )//|| tab->tk_num == 0)
                // tab->token = get_token(tab, tab->token, 1);
            // tab->tk_num--;
            //     break;

    }
   
    while (tab->token->id <= tab->tk_num)
        waitpid(-1, &g_status, 0);
        //
    if (!is_exit && g_status == 13)
        g_status = 0;

    if (g_status > 255)
        g_status = g_status / 255;
    if (tab->cmds && is_exit)
    {
        // tab->tk_num = 0;
        ft_mx_free(tab->cmds);
        ft_mx_free(&tab->node);
        free_cont(tab->token,tab->token->id);
        ft_mx_free(&tab->token->cmd);
        return (NULL);
    }
    
    return (tab);
}

void  *check_args(char *input, t_table *tab)    // main deply >parse
{
    int n;     //int node
     
    n = 0;
    if (!input)
        return (NULL);
    if (input[0] != '\0')
        add_history(input);
    // tab->node        
    tab->node = init_split(input, " ", tab);    // space split  checked!!!
    if (!tab)
        return ("");
    // parse
    tab = parse_args(tab);

    free(input);
    //token should be execute here...
    ///
        // builtins_handler(tab->node[0], tab->envp);
        // builtins_handler(input, tab->envp);
    
        // if (tab->cmds[0])
        // if (tab->cmds && tab->tk_num > 0)
        //    if (tab && tab->cmds && tab->token && tab->tk_num > 0)
        //  {
                // p->envp = ms_setenv("_", m->full_cmd[ft_mx_len(m->full_cmd)
                //  - 1], p->envp, 1);                                    
                //     ft_lstclear(&p->cmds, free_content);
        // exit(0);
        // }
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

    ls -lt -a| head -3|wc -w>>out.txt
    ls -lt>>popox.txt

*/ 
}
