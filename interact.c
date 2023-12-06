#include <stdio.h>
#include <unistd.h>

int main(int agc, char **argv){
if (isatty(STDIN_FILENO)){
        printf("shell is in interactive mode\n");
}
else{
        printf("is not in interactive mode\n");
}
return (0);
}
