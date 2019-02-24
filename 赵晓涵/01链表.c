#include<stdio.h>
//define node
struct node {//node
    int num;
    int number;
    struct node *next;//next lnode
};
//creat a null linked list
struct node *creat() {
    struct node *head, *temp;
    head = temp = NULL;//null linked list
    return head;//return head node
}
//print linked list
void printNode(struct node *p) {
    struct node *temp  = p;
    while (temp != NULL) {//when node is not null
        printf("Output:%d,%d\n", temp->num,temp->number);//print num
        temp = temp->next;//point to next node
    }
}
//add or insert linked list
struct node *insert(struct node *head) {
    struct node *newnode, *temp, *last;//new node,middle node,last node
    int value;//add or insert value
    int number;
    printf("input num: ");
    scanf("%d", &value);//satisfy the condition,continue to enter
    printf("input number: ");
    scanf("%d", &number);
    while (value > 0) {
        newnode = (struct node *)malloc(sizeof(struct node));//open up a new node
        newnode->num = value;//update num
        newnode->number = number;
        temp = head;
        newnode->next = NULL;
        if (head == NULL) {//if head=null,means linked list is null
            head = newnode;//head point to new node
            newnode->next = NULL;
        }
        else {//if linked list is not null
            while (temp->next != NULL&&temp->num < value) {//find insert position
                last = temp;
                temp = temp->next;
            }
            if (temp->num >= value) {//insert middle or before head
                if (head == temp) {//insert before head
                    newnode->next = head;
                    head = newnode;
                }
                else {//insert middle
                    last->next = newnode;
                    newnode->next = temp;
                }
            }
            else {//insert to end
                temp->next = newnode;
                newnode->next = NULL;
            }
        }
        printf("input num: ");
        scanf("%d", &value);//satisfy the condition,continue to enter
        if (value > 0) {
            printf("input number: ");
            scanf("%d", &number);
        }
    }
    return head;
}
//delete a node
struct node *deleteNode(struct node *head) {
    struct node *temp=head,*last;
    int a;
    printf("input delete node's num: ");
    scanf("%d", &a);
    if (head == NULL)
        printf("linked is NULL");
    else {
        while (temp != NULL&&temp->num != a) {//find position a
            last = temp;
            temp = temp->next;
        }
        if (temp == head) {//if is head
            head = temp->next;
            free(temp);
        }
        else {
            last->next = temp->next;
            free(temp);
        }
    }
    return head;
}
int main()
{
    struct node *head;
    head = creat();//creat a null linked list
    head = insert(head);//insert or add
    printNode(head);//print linked list
    head = deleteNode(head);
    printNode(head);//print linked list after delete
    return 0;
}
