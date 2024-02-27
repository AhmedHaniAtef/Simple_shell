 
#include<stdio.h> 
 
// chdir function is declared 
// inside this header 
#include<unistd.h> 
#include <sys/types.h>
#include <pwd.h>
int main() 
{ 
    char s[100]; 
 
    // printing current working directory 
    printf("%s\n", getcwd(s, 100)); 
 
    // using the command 
    struct passwd *pw = getpwuid(getuid());

   const char *homedir = pw->pw_dir;
    chdir(homedir); 
 
    // printing current working directory 
    printf("%s\n", getcwd(s, 100)); 
 
    // after chdir is executed 
    return 0; 
} 