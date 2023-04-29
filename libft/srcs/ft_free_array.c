#include <libft.h>

void    ft_free_array(char **array)
{
    int i;

    if (array)
    {
        i = 0;
        while (array[i])
        {
            free(array[i]);
            i++;
        }
        free(array);
    }
}

