#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/history.h>
#include <readline/readline.h>

typedef struct s_token
{
	char *value;
	int type;
	struct s_token *next;
	struct s_token *prev;
} t_token;


typedef struct s_env
{
	char *name;
	char *value;
	struct s_env *next;
	struct s_env *prev;
} t_env;

typedef struct s_data
{
	t_token *token_list;
	char *command;
	int error_status;
	t_env *env_list;
} t_data;

typedef enum
{
	SEP = 1,
	WORD,
	FIELD,
	EXP_FIELD,
	REDIRECT_OUT,  // >
	REDIRECT_IN,  // <
	REDIRECT_APPEND, // >>
	REDIRECT_INSOURCE, // <<
	PIPE,
	SEMICOLON
} defines;


// -------------------LEXER-----------------------------
int ft_strlen(char *str);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strtrim(char *str);
char *ft_substr(char *str, int start, size_t len);
char *ft_strdup(char *s1);
int ft_print_error(t_data *data, char *error_str);
int ft_word_len(char *word, int i);
int ft_is_space(char c);
int ft_is_redirection_in(char c);
int ft_is_redirection_out(char c);
int ft_is_word(char c);
int ft_add_field(t_data *data, int i);
t_token *ft_add_new_token(char *str, int type);
t_token *ft_add_token_back(t_token *token, char *str, int type);
int ft_add_word(t_data *data, int i);
int ft_add_redirection_in(t_data *data, int i);
int ft_add_redirection_out(t_data *data, int i);
int ft_add_pipe(t_data *data, int i);
void ft_lexer(t_data *data);
// --------------------ENV------------------------------------
t_env *ft_add_new_env(char *value);
t_env *ft_add_env_back(t_env *env_list, char *value);
void ft_create_env_list(t_data *data, char **env);
void ft_env(t_data *data);
// ------------------EXPAND---------------------------------
int ft_expanding(t_data *data);