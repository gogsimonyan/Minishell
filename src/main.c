#include "minishell.h"

int main(int argc, char **argv)
{
	t_data data;
	char **env;

	(void)argv;
	(void)argc;
	data.error_status = 0;

	env = malloc(sizeof(char *) * 3);
	env[0] = ft_strdup("PWD=/Users/gsimonya/Desktop/minishell");
	env[1] = ft_strdup("_=./minishell");
	env[2] = NULL;

	ft_create_env_list(&data, env);

	while (1)
	{
		data.error_status = 0;
		data.command = readline("Minishell$ ");
		ft_lexer(&data);
		if(data.error_status == 1)
			continue;
		while(data.token_list)
		{
			printf("%s %d\n", data.token_list->value, data.token_list->type);
			data.token_list = data.token_list->next;
		}
	}

	return (0);
}