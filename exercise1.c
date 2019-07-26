#include <stdio.h>
#include <stdlib.h>

//Declaring the list
typedef struct list {
    int value;
    struct list* next;
} node;

//Basic function of the exercise
struct list * findAndPushBack(int n, node * node){
    struct list *l;
    l=node;
    //Declaring two pointers one before the desirable node and one on the last node
    struct list *prp=node;
    struct list *lasp=node;

    while((lasp->next)!=NULL){
                lasp = lasp->next;
    }
    while((l->value)!=n && l!=lasp){
        l = l->next;
    }
    //The four different possibilities
    if((l->value)!= n){
        printf("Number %d was not found in the list, so no changes in the list\n\n", n);
    }
    else if(l == lasp){
        printf("Number %d was found in the last node, so no changes in the list\n\n", n);
    }
    else{
        if((l->next->value)<n){
            printf("Number %d was found in the list, but the next node has a smaller value, so no changes in the list\n\n", n);
        }
        else{
            printf("Number %d was found in the list and the next node has a bigger value, so %d's node will be pushed to the back of the list\n\n", n, n);
            while((prp->next)!=l){
                prp = prp->next;
            }
            if((l->next) == node){
                l->next = lasp->next;
                lasp->next = l;
                node = node->next;
            }
            else{
                prp->next = l->next;
                l->next = lasp->next;
                lasp->next = l;
            }

        }
    }
return node;
}

//Function to create the list and fill the value of each node
node *createList(int n){

    int i=0;
    node *head=NULL;
    node *temp=NULL;
    node *l=NULL;
    //Loop where the user allocates memory and enters each node's value individually
    for(i=0; i<n; i++){
        temp=(node*)malloc(sizeof(node));
        printf("\nPlease enter the value of node number %d : ",i+1);
        scanf("%d",&(temp->value));
        temp->next=NULL;
        //In case the list is empty
        if(head==NULL){
            head=temp;
        }
        else{
            l=head;
            while(l->next!=NULL)
            l=l->next;
            l->next=temp;
        }
    }
    return head;
}

//Function to print the list
 void printList(node *head){
	node *l=head;
	printf("\t");
	while((l->next) != NULL){
		printf("%d -> ", l->value);
		l = l->next;
    }
    printf("%d\n", l->value);

}

int main()
{
    printf("\n-----------------------------------\nWELCOME TO THE LINKED LIST PROGRAM 1\n-----------------------------------\n\n\n");
    int N=0, n;
    node *head=NULL;

    //Getting the number of nodes in the list
    printf("\nHow many nodes do you want for your linked list?\n");
    scanf("%d", &N);

    //Creating the list with n nodes, getting the values of each node and printing the list
    head=createList(N);
    printList(head);

    printf("Please enter the integer that you want to find in the list\n");
    scanf("%d", &n);

    head=findAndPushBack(n,head);
    printList(head);

    return 0;
}



