#include "lexer.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

size_t ft_strlcpy(char *dest, char *src, size_t size)
{
    size_t src_s;
    size_t i;

    i = 0;
    src_s = ft_strlen(src);
    if (size == 0)
        return (src_s);
    while (i < size - 1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (src_s);
}

char *ft_strtrim(char *str)
{
    size_t start;
    size_t last;
    char *ptr;

    ptr = NULL;
    if (str != NULL)
    {
        start = 0;
        last = ft_strlen(str);
        while (str[start] != '\0' && ft_isspace(str[start]))
            start++;
        while (ft_isspace(str[last - 1]) && last > start)
            last--;
        ptr = (char *)malloc(sizeof(char) * (last - start + 1));
        if (!ptr)
            exit(1);
        if (ptr)
            ft_strlcpy(ptr, str + start, last - start + 1);
    }
    return (ptr);
}

char *ft_substr(char *str, int start, size_t len)
{
    char *ptr;
    unsigned int i;
    int end;

    i = 0;
    end = len + start;
    if (!str)
        return (NULL);
    ptr = (char *)malloc((len + 1) * sizeof(char));
    if (!ptr)
        exit(1);
    if (start <= ft_strlen(str))
    {
        while (start < end && str[start] != '\0')
        {
            ptr[i] = str[start];
            i++;
            start++;
        }
    }
    ptr[i] = '\0';
    return (ptr);
}

int ft_word_len(char *word, int i)
{
    int len;
    char c;

    len = 0;
    while (word[i] && ft_is_word(word[i]))
    {
        len++;
        i++;
    }
    return (len);
}

int ft_print_error(char * error_str)
{
    printf("%s\n", error_str);
    exit(1);
}