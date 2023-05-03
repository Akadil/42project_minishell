# Interesting  observations

1. Behavior of the env variables

When I  type
```bash
$ (unset USER) && echo $USER
```
the output is "akalimol", but when I 
```bash
$ unset USER && echo $USER
```
the output is nothing. `It means that each time there is a parenthesis, it generates a new microshell` 

2. Behavior of the new microshell

when I type
```bash
$ > output.txt (cat file1.txt && cat file2.txt) && cat file3.txt >> output.txt
```
it gives me a syntax error, but when I type
```bash
$ (cat file1.txt && cat file2.txt) > output.txt  && cat file3.txt >> output.txt
```
everything is ok. which means that microshell require specific syntaxis for creation

3. 

---
## Approximate view of the microshell
```
typedef struct  t_shell
{
    // All parenthesis ()
    
    t_micro *micro;
    t_env   *env;
    t_drc   *directions;
}

typedef struct  t_micro
{
    // && and ||
    t_cmd   cmds;

}

typedef struct  t_cmd
{
    // Cmd and pipes
    char    *name;
    char    *directions; // inherited
    char    *params;
}

```