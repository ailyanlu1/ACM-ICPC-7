#include <stdio.h>
#define MAX 130
char s[MAX];
char stack[MAX];
int last = 0;
int verificaString(){
    int i;
    for (i = 0; i < strlen(s); i++){
        if (s[i] == '(' || s[i] == '['){
           stack[last++] = s[i];
        } else if ( last != 0 && s[i] == ')' && stack[last-1] == '('){
          last--;
        } else if ( last != 0 && s[i] == ']' && stack[last-1] == '['){
          last--;
        }else{
              return 0;
        }
    }
    if (last != 0) return 0;
    return 1;
}

int main(){
    int c, N;
    scanf ("%d",&N);
    gets(s);
    for ( c = 0 ; c < N; c++){
        gets(s);
        last = 0;
        if (verificaString()){ 
           printf("Yes\n");
        }else{
               printf("No\n");
               }
    }
return 0;    
}
