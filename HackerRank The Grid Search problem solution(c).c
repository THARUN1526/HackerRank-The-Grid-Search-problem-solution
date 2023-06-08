#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int is_match(char** a,int r, int c,char **pat,int pr,int pc,int starty,int startx){
    int i,j;
    if(pr+starty>r||pc+startx>c)
        return 0;
    for(i=0;i<pr;i++){
        for(j=0;j<pc;j++){
            if(a[starty+i][startx+j]!=pat[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    int ntest;
    scanf("%i",&ntest);
    int s;
    int found=0;
    for(s=0;s<ntest;s++){
        int r,c;
        scanf("%i %i",&r,&c);
        char** test;
        test=malloc(sizeof(char*)*r);
        int i;
        for(i=0;i<r;i++){
            test[i]=calloc(sizeof(char),1+c);
            scanf("%s",test[i]);
        }
        int R,C;
        scanf("%i %i",&R,&C);
        
        char **pattern;
        pattern=malloc(sizeof(char*)*R);
        for(i=0;i<R;i++){
            pattern[i]=calloc(sizeof(char),1+C);
            scanf("%s",pattern[i]);
        }
  
        for(i=0;i<r;i++){
            int j;
            for(j=0;j<c;j++){
                if(is_match(test,r,c,pattern,R,C,i,j))
                   {
                       found=1;
                       goto quit;
                   }
            }
        }
            quit:
        if(found)
            printf("YES\n");
        else
            printf("NO\n");
        found=0;
        for(i=0;i<R||i<r;i++){
            if(i<R)
            free(pattern[i]);
            free(test[i]);
         
        }
        
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}