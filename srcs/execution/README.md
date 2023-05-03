```
typedef struct s_process
{
    t_type  *parts;

    t_env   *env;
    int     type; // Not sure
    int     in_fd;
    int     out_fd;
    int     err_fd;
    char    *path; 


}   t_process;
```