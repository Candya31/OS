#include <unistd.h>
#include <stdio.h>

//Question 1.3
int main(){
    for (int i=0; i<50000000; i++){
        getpid(); //appel systeme
    }    
    return 0;
}