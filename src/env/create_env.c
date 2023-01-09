#include "../minishell.h"

void ft_create_env_list(t_data *data, char *envp[])
{
    int i;

    i = 0;
    while (envp[i])
    {
        data->env_list = ft_add_env_back(data->env_list, envp[i]);
        i++;
    }
}
