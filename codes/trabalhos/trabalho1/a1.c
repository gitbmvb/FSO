#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull;
typedef struct Node{
    int pid;
    ull exectime;
    struct Node * prev, * next;
} Node;

int main(){
    int n;
    ull t;
    scanf("%d\n%llu", &n, &t);
    Node * head = malloc(sizeof(Node)), * temp = NULL;
    head->prev = head->next = NULL;
    while(n--){
        Node * new = malloc(sizeof(Node));
        new->prev = new->next = NULL;
        scanf("%d\n%llu", &new->pid, &new->exectime);
        new->exectime *= 1000;
        if(temp){
            new->prev = temp;
            temp->next = new;
        }
        if(!head->next) {
            head->next = new;
            new->prev = head;
        }
        temp = new;
    }
    temp = head->next;
    ull clock = 0;
    while(head->next){
        clock += t;
        if(temp->exectime > t){
            temp->exectime -= t;
        } else{
            printf("%d (%llu)\n", temp->pid, clock);
            temp->prev->next = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
        }
        temp = temp->next;
        if(!temp) temp = head->next;
    }
}