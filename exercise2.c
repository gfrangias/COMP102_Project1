#include <stdio.h>
#include <stdlib.h>

//Declaring the list
typedef struct list{
    int value;
    struct node* next;
} node;

findOddResult(struct list * node, int pos){
    int i=0;
    if(node != NULL){
        pos++;
        i=findOddResult(node->next,pos);
        if(pos%2==1){
        i = i+(node->value);
        }
        printf("%d[%d]  ",node->value,i);
    }
    return i;
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
    printf("%d\n\n", l->value);

}

int main()
{
    printf("\n-----------------------------------\nWELCOME TO THE LINKED LIST PROGRAM 2\n-----------------------------------\n\n\n");
    node *head=NULL;
    int N;
    int pos = 0;
    //Getting the number of nodes in the list
    printf("\nHow many nodes do you want for your linked list?\n");
    scanf("%d", &N);

    //Creating the list with n nodes, getting the values of each node and printing the list
    head=createList(N);
    printList(head);

    //Running the basic function
    findOddResult(head,pos);
    return 0;
}
