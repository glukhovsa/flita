#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int firstTop, secondTop;
} Edge;

int main(){
    Edge *edges=NULL;
    int first=0, second=0, len;
    edges=(Edge*)malloc(sizeof(Edge)*len);
    printf("Enter edges as '<First Top> <Second Top>'. Finish is '0 0'\n");
    do{
        scanf("%d %d", &first, &second);
        edges=realloc(edges, sizeof(Edge)*(++len));
        edges[len-1].firstTop=first;
        edges[len-1].secondTop=second;
    }while(first!=0 || second!=0);

    int count=0, i, j, flag;
    for(i=0; i<len-1; i++){
        if(edges[i].firstTop!=0 && edges[i].secondTop!=0){
            for(j=i+1; j<len; j++)
                if(edges[i].firstTop==edges[j].firstTop && edges[i].secondTop==edges[j].secondTop){
                    flag=1;
                    edges[j].firstTop=0;
                    edges[j].secondTop=0;
                    printf("%d, ", j+1);
                    count++;
                }
            if(flag){
                flag=0;
                printf("%d - multiple edges\n", i+1);
                count++;
            }
        }
    }
    if(count>0)
        printf("Count of multiple edges - %d", count);
    else
        printf("No multiple edges");
}
