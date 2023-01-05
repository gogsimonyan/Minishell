#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_token
{
    char *value;
    int type;
    struct s_token *next;
    struct s_token *prev;
} t_token;

typedef struct s_data
{
    t_token *token_list;
    char *command;
} t_data;

#define SEP  1
#define WORD 2
#define FIELD 3
#define EXP_FIELD 4
#define REDIRECT_OUT 5  // >
#define REDIRECT_IN 6  // <
#define REDIRECT_APPEND 7 // >>
#define REDIRECT_INSOURCE 8 // <<
#define PIPE 9
#define SEMICOLON 10

int ft_strlen(char *str);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strtrim(char *str);
char *ft_substr(char *str, int start, size_t len);
int ft_print_error(char *error_str);
int ft_word_len(char *word, int i);
int ft_isspace(char c);
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
int ft_add_semicolon(t_data *data, int i);
void ft_lexer(t_data *data);