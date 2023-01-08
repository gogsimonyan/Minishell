#include "lexer.h"


int main(int argc, char **argv)
{
	t_data data;

	data.error_status = 0;

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