#include<stdio.h>
struct node// defining a structure
{
    int num;
    struct node *flink;
    struct node *blink;
};
void forwarddisplay(struct node *rider)//to print the list in forward direction
{
    printf("\nThe list in forward display is:\n");
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->flink;
    }
}
void backwarddisplay(struct node *rider)//to print the list in backward direction
{
    printf("\nThe list in backward display is:\n");
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->blink;
    }
}
void addatbeg(struct node **startptr,struct node **endptr)//to add the element at the beginning
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be added :");
    scanf("%d",&(nnodeptr->num));
    if(*startptr==NULL)//if initially the list is empty
    {
        nnodeptr->flink=nnodeptr->blink=NULL;
        *startptr=*endptr=nnodeptr;
    }
    else//if there already exist a list
    {
        nnodeptr->blink=NULL;
        nnodeptr->flink=*startptr;
        (*startptr)->blink=nnodeptr;
        *startptr=nnodeptr;
    }
}
void addatend(struct node **startptr,struct node **endptr)//to add the element at the end
{
    struct node *nnodeptr;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be added:");
    scanf("%d",&(nnodeptr->num));
    nnodeptr->flink=NULL;
    nnodeptr->blink=*endptr;
    (*endptr)->flink=nnodeptr;
    *endptr=nnodeptr;
}
void insertbefore(struct node **startptr,struct node **endptr,struct node *rider)//to insert a new number
{
    int elem=0,f=0;
    struct node *nnodeptr,*r;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the num before which the new num should be inserted:");
    scanf("%d",&elem);
    while(rider!=NULL)
    {

        if(rider->num==elem)
        {
            f=1;
            break;
        }
        else
        {
            r=rider;
            rider=rider->flink;
        }
    }

    if(f==1)
    {
        if(rider!=(*startptr))
        {
            printf("\nEnter the element to be added :");
            scanf("%d",&(nnodeptr->num));
            nnodeptr->blink=r;
            nnodeptr->flink=rider;
            r->flink=nnodeptr;
            rider->blink=nnodeptr;
        }
        else
        {

            addatbeg(startptr,endptr);
        }
    }
    else
        printf("\nThere is no such given number");
}
void insertafter(struct node **startptr,struct node **endptr,struct node *rider)//to insert a new number
{
    int elem=0,f=0;
    struct node *nnodeptr,*r;
    nnodeptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the num after which the new num should be inserted:");
    scanf("%d",&elem);
    while(rider!=NULL)
    {
        r=rider->flink;
        if(rider->num==elem)
        {
            f=1;
            break;
        }
        else
            rider=rider->flink;
    }

    if(f==1)
    {
        if(rider!=(*endptr))
        {
            printf("\nEnter the element to be added:");
            scanf("%d",&(nnodeptr->num));
            nnodeptr->blink=rider;
            nnodeptr->flink=r;
            r->blink=nnodeptr;
            rider->flink=nnodeptr;
        }
        else
        {

            addatend(startptr,endptr);
        }
    }

    else
        printf("\nThere is no such given number");
}
void deletebeg(struct node **startptr,struct node **endptr)//to delete the element from the beginning
{
    *startptr=(*startptr)->flink;
    (*startptr)->blink=NULL;
}
void deleteend(struct node **startptr,struct node **endptr)//to delete the element from the end
{
    *endptr=(*endptr)->blink;
    (*endptr)->flink=NULL;
}
void deletebefore(struct node **startptr,struct node *rider)//to delete an element before a node
{
    int elem,f=0;
    struct node *r;
    printf("\nEnter the node before which the node should be deleted:");
    scanf("%d",&elem);
    while(rider!=NULL)
    {
        if(rider->num==elem)
        {
            f=1;
            break;
        }
        else
        {
            r=rider;
            rider=rider->flink;
        }
    }
    if(f==1)
    {
        if((r->blink)!=NULL)
        {
            rider->blink=r->blink;
            r->blink->flink=rider;
        }
        else
        {
            rider->blink=NULL;
            *startptr=rider;
        }
    }
    else
        printf("\nThere is no such element in the list");
}
void deleteafter(struct node **endptr,struct node *rider)//to delete an element after a node
{
    int elem,f=0;
    struct node *r;
    printf("\nEnter the node after which the node should be deleted:");
    scanf("%d",&elem);
    while(rider!=NULL)
    {
        r=rider->flink;
        if(rider->num==elem)
        {
            f=1;
            break;
        }
        else
        {
            rider=rider->flink;
        }
    }
    if(f==1)
    {
        if((r->flink)!=NULL)
        {
            rider->flink=r->flink;
            r->flink->blink=rider;
        }
        else
        {
            rider->flink=NULL;
            *endptr=rider;
        }
    }
    printf("\nThere is no such element in the list");
}
void deleteelem(struct node **startptr,struct node **endptr,struct node *rider)//to delete a particular number from the list
{
    int elem,f=0;
    printf("\nEnter the element to be deleted:");
    scanf("%d",&elem);
    while(rider!=NULL)
    {
        if(rider->num==elem)
        {
            f=1;
            break;
        }
        else
        {
            rider=rider->flink;
        }
    }
    if(f==1)
    {

        if((rider!=*startptr)&&(rider!=*endptr))
        {
            printf("%d",rider->num);
            rider->blink->flink=rider->flink;
            rider->flink->blink=rider->blink;
        }
        else if(rider==(*startptr))
        {
            if((*startptr)==(*endptr))
            {
                *startptr=*endptr=NULL;
            }
            else
            {
               *startptr=(*startptr)->flink;
            (*startptr)->blink=NULL;
            }
        }
        else
        {
            *endptr=(*endptr)->blink;
            (*endptr)->flink=NULL;
        }
    }
    else
        printf("\nThere is no such element in the list");
}
void main()
{
    int *start=NULL,*end=NULL,*rider,ch;
    printf("The list is:\n");
    forwarddisplay(start);
    backwarddisplay(end);
    while(1)
    {
        printf("\n1.Addatbeg\n2.Addatend\n3.Insertbefore\n4.Insertafter\n5.Deletebeg\n6.Deleteend\n7.Deletebefore\n8.Deleteafter\n9.Delete particular element\n10.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1)
        {
            addatbeg(&start,&end);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==2)
        {
            addatend(&start,&end);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==3)
        {
            insertbefore(&start,&end,start);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==4)
        {
            insertafter(&start,&end,start);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==5)
        {
            deletebeg(&start,&end);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==6)
        {
            deleteend(&start,&end);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==7)
        {
            deletebefore(&start,start);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==8)
        {
            deleteafter(&end,start);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==9)
        {
            deleteelem(&start,&end,start);
            forwarddisplay(start);
            backwarddisplay(end);
        }
        if(ch==10)
        {
            break;
        }
    }
}
