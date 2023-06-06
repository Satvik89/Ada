#include <stdio.h>
#define Max 10
int stack[Max],top=-1;
void push(int stack[Max],int x){
   if(top==Max-1){
    printf("Stack overflow\n");
   }
   else{
        top++;
        stack[top]=x;
   }
}

int pop(int stack[Max]){
    int val;
    if(top==-1){
        printf("Stack Underflow");
        return -1;
    }
    else{
        val=stack[top];
        top--;
        return val;
    }
}

void dfs(int adj[Max][Max],int stack[Max], int s, int n){
    int visited[Max],i,a,order[Max],count=0;
     push(stack,s);
     for(i=0;i<n;i++){
        visited[i]=0;
     }
     visited[s]=1;
     while(top>=0){
        a=pop(stack);
        if(a==-1){
            break;
        }
        order[count++]=a;
        for(i=0;i<n;i++){
            if(adj[a][i]==1 && visited[i]==0){
                push(stack,i);
                visited[i]=1;
            }
        }
     }
      printf("Order of visited vertices: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", order[i]);
  }
  printf("\n");

}
int main(){
    int adj[Max][Max],i,j,s,n;
  printf("No. of elements");
  scanf("%d",&n);
  printf("Source Element:");
  scanf("%d",&s);
  printf("Adjacency Matrix :");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&adj[i][j]);
    }
  }
  dfs(adj,stack,s,n);
}
