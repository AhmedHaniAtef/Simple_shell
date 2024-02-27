#include "main.h"



int main ()
{
    // register child signal function to kill zombies processes
    // register_child_signal(on_child_exit())

    // go to default directory as defined
    // cd(Current_Working_Directory)

    // start the shell
    shell();
    return 0;
}

char directory[100];
/**
 * @brief Contains main operation of shell
 * 
 */
void shell(void)
{
    char **command = NULL;
    COMMANDS_t input_command;
    COMMANDS_t input_type;
    do
    {
        memset(directory, '\0', 100);
        getcwd(directory, 100);
        printf("%s---$  ", directory); 
        command = parse_input();

        input_command = command_detect(command);
        if ((input_command == CD) || (input_command == ECHO) || input_command == EXPORT)
        {
            input_type = SHELL_BUILT_IN;
        }
        else
        {
            input_type = input_command;
        }
        switch (input_type)
        {
        case SHELL_BUILT_IN:
            execute_shell_bultin(input_command, command);
            break;

        case EXECUTABLE_OR_ERROR:
            /* code */
            break;

        default:
            break;
        }
    }while(strcmp(command[0], "exit") != STRING_MATCH);
    exit(0);
}

int counter_args = 0;
char **parse_input()
{
    static char input[100];
    char *temp_input = NULL;
    char **final_input = NULL;
    const char delim[2] = " ";

    
    memset(input, '\0', 100);
    fgets(input, 100, stdin);
    char *temp = strpbrk(input, "\n");
    temp[0] = '\0';
    fflush(stdin);

    temp_input = strtok(input, delim);
    if(temp_input != NULL)
    {
        counter_args = 1;
        final_input = (char **)calloc(counter_args, sizeof(char*));
        while (temp_input != NULL)
        {
            final_input = (char **)realloc(final_input, counter_args * sizeof(char *));
            *(final_input + counter_args - 1) = temp_input;

            temp_input = strtok(NULL, delim);
            counter_args++;
        }
        counter_args--;
    }
    
    return final_input;
}

COMMANDS_t command_detect(char **command)
{
    COMMANDS_t input_command;
    if(strcmp(command[0], "cd") == STRING_MATCH)
    {
        input_command = CD;
    }
    else if(strcmp(command[0], "echo") == STRING_MATCH)
    {
        input_command = ECHO;
    }
    else if(strcmp(command[0], "export") == STRING_MATCH)
    {
        input_command = EXPORT;
    }
    else
    {
        input_command = EXECUTABLE_OR_ERROR;
    }
    return input_command;
}

void execute_shell_bultin(COMMANDS_t input_command, char **command)
{
    switch (input_command)
    {
    case CD:
        cd_command_handle(command);
        break;
    
    case ECHO:
        echo_command_handle(command);
        break;
    
    case EXPORT:
        export_command_handle(command);
        break;

    default:
        if (strcmp(command[0], "exit") != STRING_MATCH)
        {
            printf("Error : No command %s\n", command[0]);
        }
        else
        {
           exit(0); 
        }
        break;
    }
}

void cd_command_handle(char **command)
{
    int length = counter_args;
    if (length > 2)
    {
        printf("bash: cd: too many arguments");
    }
    else if (length == 1)
    {
        // Nothing
    }
    else
    {
        if (strcmp(command[1], "~") == STRING_MATCH)
        {
            struct passwd *pw = getpwuid(getuid());
            const char *homedir = pw->pw_dir;
            chdir(homedir); 
        }
        else
        {
            if (chdir(command[1]) != 0)
            {
                perror(command[1]); 
            }
        }
    }
}

void echo_command_handle(char **command)
{
    int counter = 1;
    for (counter = 1; counter < counter_args; counter++)
    {
        printf("%s", command[counter]);
        printf(" ");
    }
    printf("\n");
}

void export_command_handle(char **command)
{

}


















