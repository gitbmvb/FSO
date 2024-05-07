#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int pid, time;
    struct Node * next;
} Node;

typedef struct {
    Node * head, * tail;
    int qtd;
} LinkedList;

int main(void){
    int n, t, clock = 0;
    scanf("%d\n%d", &n, &t);
    LinkedList * threads = malloc(sizeof(LinkedList));
    threads->head = NULL;
    threads->tail = NULL;
    threads->qtd = n;
    while(n--){
        Node * new = malloc(sizeof(Node));
        scanf("%d %d", &new->pid, &new->time);
        new->next = NULL;
        if(!threads->head) threads->head = new;
        if(!threads->tail) threads->tail = new;
        else{
            threads->tail->next = new;
            threads->tail = new;
        }
    }
    Node * temp = threads->head, * prev = NULL;
    while(threads->qtd){
        clock += t;
        if(temp->time - t <= 0){
            threads->qtd--;
            printf("%d (%d)\n", temp->pid, clock);
            if(!threads->qtd) break;
            if(!prev){
                threads->head = temp->next;
            }
            prev->next = temp->next;
        } else {
            temp->time -= t;
            prev = temp;
            temp = temp->next;
        }
        if(!temp) {
            temp = threads->head;
            prev = NULL;
        }
    }
}