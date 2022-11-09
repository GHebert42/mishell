#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* fd Refs*/
# define READ_END 0
# define WRITE_END 1

/* Colors Defined*/
# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[0;90m\002"
# define RED "\001\033[0;91m\002"
# define GREEN "\001\033[0;92m\002"
# define YELLOW "\001\033[0;93m\002"
# define BLUE "\001\033[0;94m\002"
# define MAGENTA "\001\033[0;95m\002"
# define CYAN "\001\033[0;96m\002"
# define WHITE "\001\033[0;97m\002"

/* Token type Define*/
enum TokenType{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_SQUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_SPACE = ' ',
	CHAR_ESCAPESEQ = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN = -1,
};

typedef struct s_prompt t_prompt;
typedef struct s_token t_token;
typedef struct s_lexer t_lexer; 
typedef struct s_mini t_mini;

struct s_prompt
{
	char *cmds;		
	char **envp;	/*  store env  tab[][]  */
	pid_t	pid;
};

struct s_token
{
	char *data;
	int type;
	t_token *next;
};


struct s_lexer
{
	t_token *listok;
	int  ntok;
};

struct s_mini
{
	char **full_story;
	char *full_path;
	int infile;
	int outfile;
};

//signal
void    handle_sigint(int sig);
char    *mini_getenv(char *var, char **envp, int n);
char    **mini_setenv(char *var, char *value, char **envp, int n);
//prompt 
char   	*mini_getprompt(t_prompt prompt);
//parse
void    *check_args(char *out, t_prompt *p);
//subsplit
char **ft_cmdtrim(const char *s, char *set);
//update
void    exec_custom(char **out, char *full, char *args, char **envp) ;

#endif
