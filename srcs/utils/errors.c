
#include "../../includes/minishell.h"

extern int g_status;

void *chk_error(int err_type, char *param, int err)
{
    g_status = err;
    if (err_type == QUOTE)
		ft_putstr_fd("minishell: error while looking for matching quote\n", 2);
	else if (err_type == NDIR)
		ft_putstr_fd("minishell: No such file or directory: ", 2);
	else if (err_type == NPERM)
		ft_putstr_fd("minishell: permission denied: ", 2);
	else if (err_type == NCMD)
		ft_putstr_fd("minishell: command not found: ", 2);
	else if (err_type == DUPERR)
		ft_putstr_fd("minishell: dup2 failed\n", 2);
	else if (err_type == FORKERR)
		ft_putstr_fd("minishell: fork failed\n", 2);
	else if (err_type == PIPERR)
		ft_putstr_fd("minishell: error creating pipe\n", 2);
	else if (err_type == PIPENDERR)
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	else if (err_type == MEM)
		ft_putstr_fd("minishell: no memory left on device\n", 2);
	else if (err_type == IS_DIR)
		ft_putstr_fd("minishell: Is a directory: ", 2);
	else if (err_type == NOT_DIR)
		ft_putstr_fd("minishell: Not a directory: ", 2);
	ft_putendl_fd(param, 2);
    return (NULL);
}

// void free_cont(void *content, int id)
// {
//     t_token *token;

//     token->cmd = content;
//     ft_mx_free(&token->cmd);
//     free(token->path);
//     if (token->infile != STDIN_FILENO)
//         close(token->infile);
//     if (token->outfile != STDOUT_FILENO)
//         close(token->outfile);
//     free(token);
// }

void free_cont(void *content)
{
    t_token *token;

    token = content;
    ft_mx_free(&token->cmd);
	// free(token->ofile);
    free(token->path);
	free(token->full);
    if (token->infile != STDIN_FILENO)
        close(token->infile);
    if (token->outfile != STDOUT_FILENO)
        close(token->outfile);
    free(token);
}