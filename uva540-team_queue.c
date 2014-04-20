#include <stdio.h>
#define MAX_CHILDREN 1000
#define MAX_TEAMS 1000
typedef struct t_child {
        int val;
        struct t_child *next;
        struct t_child *previous;
} child;

typedef struct t_team{
  int val;
  struct t_team *next;
  struct t_team *previous;
  child *firstChild;
  child *lastChild;
  child children[MAX_CHILDREN];
  int totalChildren;
  int b_inQueue;
} team;

team teams[MAX_TEAMS];
team *firstTeam, *lastTeam;
int total=0;
int T;

team *findTeam (int element){
    int i,j;
    for(i=0;i<T;i++){
      for(j=0;j<teams[i].totalChildren;j++){
        if (teams[i].children[j].val == element)
          return &teams[i];
      }
    }
    return NULL;
}

child *findChild (int element){
  int i,j;
   for(i=0;i<T;i++){
      for(j=0;j<teams[i].totalChildren;j++){
        if (teams[i].children[j].val == element)
          return &teams[i].children[j];
      }
    }
    return NULL;
}

void enqueueTeam (team *myTeam, child *me){
  lastTeam->next = myTeam;
  myTeam->previous = lastTeam;
  myTeam->next = NULL;
  myTeam->firstChild = me;
  myTeam->lastChild = me;
  myTeam->b_inQueue = 1;
  lastTeam = myTeam;
}

void enqueueChild (child *me, team *myTeam){
    if (myTeam->lastChild != NULL)
      myTeam->lastChild->next = me;  
    me->previous = myTeam->lastChild;
    myTeam->lastChild = me;
    me->next = NULL;
}

void enqueue(int val){
  team *myTeam = findTeam(val);
  child *me = findChild(val);

  team *cur;
  int i;

  if(total==0){
    firstTeam = myTeam;
    lastTeam = myTeam;
    enqueueTeam(myTeam, me);
    enqueueChild (me, myTeam);
  }else{
        if (myTeam->b_inQueue){
          enqueueChild (me,myTeam);
        }else{
           enqueueTeam (myTeam, me);
           enqueueChild (me, myTeam);
        }
  }
  total++;
}

child *dequeue(){
     child *curChild;
     if (total > 0){
       if (firstTeam->firstChild->next != NULL){
         curChild = firstTeam->firstChild;
         firstTeam->firstChild = firstTeam->firstChild->next;
       }else{
         curChild = firstTeam->firstChild;
         firstTeam->b_inQueue = 0;
         if (firstTeam->next != NULL){
           firstTeam = firstTeam->next;
           firstTeam->previous = NULL;
         }
       }
       total--;
     }else{
       curChild = NULL;
     }
     return curChild;
}

int k = 1;
int main(){
    int i,j,qtd, element;
    char cmd[10];
    child *curChild;
    while(1){
    scanf("%d",&T);
    if (T==0)
      break;
    total=0;
    for(i=0;i<T;i++){
      teams[i].val = i;
      teams[i].totalChildren = 0;
      teams[i].b_inQueue = 0;
      scanf("%d", &qtd);
      for(j=0;j<qtd;j++){
        scanf("%d", &teams[i].children[j].val);
        teams[i].totalChildren++;
      }
    }
    printf("Scenario #%d\n", k++);
    while(1){
      scanf("%s",cmd);
      if (strcmp(cmd,"STOP")==0){
         break;
      }
      if(strcmp(cmd,"ENQUEUE")==0){
         scanf("%d",&element);
         enqueue(element);
      }
      if(strcmp(cmd,"DEQUEUE")==0){
        curChild = dequeue();
        if (curChild != NULL)
          printf("%d\n", curChild->val);
      }
    }
    printf("\n");
    }
    return 0;    
}
