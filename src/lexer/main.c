#include "lexer.h"



int main(int argc, char **argv)
{
    t_data data;

    data.command = "echo  ; << ;";
    ft_lexer(&data);
    
    while(data.token_list->next)
    {
        printf("%s %d\n", data.token_list->value, data.token_list->type);
        data.token_list = data.token_list->next;
    }

    return (0);
}