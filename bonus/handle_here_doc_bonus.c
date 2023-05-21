#include "pipex_bonus.h"

int ft_here_doc_exists(char *av[])
{
    if (!ft_strncmp(av[1], "here_doc", 8))
        return (1);
    return (0);
}

void    ft_handle_here_doc(char *breaker, int *fd)
{
    breaker = ft_strjoin(breaker, "\n");
    dup2(*fd, 0);
    while (ft_strncmp(get_next_line(0), breaker, ft_strlen(breaker)))
        ;
}