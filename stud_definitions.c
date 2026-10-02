#include"student.h"
void add(SLL **head){ //add a new record
    SLL *new,*temp,*last;
    int r=1; // start roll no with 1
    new=malloc(sizeof(SLL));
    if(new==0){
        printf("\033[31;1;4;5mMemory Allocation Failed\033[0m\n\n");
        return;
    }
    while(1){ //find smallest unused roll number
        temp=*head;
        while(temp!=0){
            if(temp->rollno==r){
                r++;  //increment if roll no existed
                break;
            }
            temp=temp->next;
        }
        if(temp==0)
            break;
    }
    new->rollno=r; //assign rollno
    printf("Enter name & Percentage:"); // scan data
    scanf("%s %f",new->name,&new->percent);
    new->next=0; //add end : always new next is 0
    if (*head==0){ //if 1st record
        *head=new; //update head
    }
    else{ //from 2nd record onwards
        last=*head; //start from first node
        while(last->next!=0) //finding lastnode
            last=last->next; //visit last node

        last->next=new; //update last node
    }
}
void display(SLL *ptr){   //display records
    if(ptr==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return;   
    }
    printf("\033[36m----------------------------\n");
    printf("Student Records present are:\n");
    printf("----------------------------\033[0m\n");
    while(ptr){
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percent);
        ptr=ptr->next;
    }
}
void save_file(SLL *ptr){ //save records in a file
    if(ptr==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return;
    }
    FILE *fp=fopen("student.dat","w");
    while(ptr){
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percent);
        ptr=ptr->next;
    }
    printf("\033[36mFile saved Sucessfully\033[0m\n");
    fclose(fp);
}
void del(SLL **head){ // delete a specific recrd
    if(*head==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return; 
    }
    SLL *temp,*prev;
    int rollno;
    char op,name[20];
    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter your choice: ");
    scanf(" %c",&op);
    if(op=='r'||op=='R'){ //delete by rollno
        printf("Enter roll number: ");
        scanf("%d",&rollno);
        temp=*head;
        prev=0;
        while(temp){
            if(temp->rollno==rollno)
            {
                if(prev==0)
                    *head=temp->next;
                else
                    prev->next=temp->next;
                free(temp);
                printf("\033[36mRecord deleted successfully\033[0m\n");
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        printf("\033[31;1;4;5mRecord not found\033[0m\n");
    }
    else if(op=='n'||op=='N'){ //delete by name
        printf("Enter name: ");
        scanf(" %s",name);
        temp=*head;
        while(temp){
            if(strcmp(temp->name,name)==0)// display the records of similar names
                printf("Roll No: %d Name: %s Percentage: %f\n",
                       temp->rollno,temp->name,temp->percent);
            temp=temp->next;
        }
        printf("Enter roll number to delete: "); //identify the rollno to delete
        scanf("%d",&rollno);
        temp=*head;
        prev=0;
        while(temp){
            if(temp->rollno==rollno){
                if(prev==0)
                    *head=temp->next;
                else
                    prev->next=temp->next;

                free(temp);
                printf("\033[36mRecord deleted successfully\033[0m\n");
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        printf("\033[31;1;4;5mRecord not found\033[0m\n");
    }
    else
        printf("\033[31;1;4;5mInvalid option\033[0m\n");
}

void del_all(SLL **head){ //delete all records
    SLL *temp,*next;
    if(*head==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return;
    }
    temp=*head;
    while(temp){
        next=temp->next;
        free(temp);
        temp=next;
    }
    *head=0;
    printf("\033[36mAll records deleted successfully\033[0m\n");
}

void rev(SLL **head){ //reverse the linked list
    SLL *prev=0,*temp,*next;
    if(*head==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return;
    }
    temp=*head;
    while(temp){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    *head=prev;
    printf("\033[36mList reversed successfully\033[0m\n");
}

void modify(SLL **head){ //modify a specific record
    SLL *temp;
    int rollno;
    float percent;
    char op,name[20];
    if(*head==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return;
    }
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c",&op);
    if(op=='r'||op=='R'){ //search by rollno
        printf("Enter roll number: ");
        scanf("%d",&rollno);
        temp=*head;
        while(temp){
            if(temp->rollno==rollno){
                printf("Current: %d %s %f\n",
                       temp->rollno,temp->name,temp->percent);
                printf("Enter new name & Percentage: ");
                scanf("%s %f",temp->name,&temp->percent);
                printf("\033[36mRecord modified successfully\033[0m\n");
                return;
            }
            temp=temp->next;
        }
        printf("\033[31;1;4;5mRecord not found\033[0m\n");
    }
    else if(op=='n'||op=='N'){ //search by name
        printf("Enter name: ");
        scanf("%s",name);
        temp=*head;
        while(temp){
            if(strcmp(temp->name,name)==0)
                printf("Roll No: %d Name: %s Percentage: %f\n",
                       temp->rollno,temp->name,temp->percent);
            temp=temp->next;
        }
        printf("Enter roll number to modify: ");
        scanf("%d",&rollno);
        temp=*head;
        while(temp){
            if(temp->rollno==rollno){
                printf("Enter new name & Percentage: ");
                scanf("%s %f",temp->name,&temp->percent);
                printf("\033[36mRecord modified successfully\033[0m\n");
                return;
            }
            temp=temp->next;
        }
        printf("\033[31;1;4;5mRecord not found\033[0m\n");
    }
    else if(op=='p'||op=='P'){ //search by percentage
        printf("Enter percentage: ");
        scanf("%f",&percent);
        temp=*head;
        while(temp){
            if(temp->percent==percent)
                printf("Roll No: %d Name: %s Percentage: %f\n",
                       temp->rollno,temp->name,temp->percent);

            temp=temp->next;
        }
        printf("Enter roll number to modify: ");
        scanf("%d",&rollno);
        temp=*head;
        while(temp){
            if(temp->rollno==rollno){
                printf("Enter new name & Percentage: ");
                scanf("%s %f",temp->name,&temp->percent);

                printf("\033[36mRecord modified successfully\033[0m\n");
                return;
            }
            temp=temp->next;
        }
        printf("\033[31;1;4;5mRecord not found\033[0m\n");
    }
    else
        printf("\033[31;1;4;5mInvalid option\033[0m\n");
}

void sort(SLL **head){ //sort the records
    SLL *temp,*next;
    int rollno;
    char name[20];
    float percent;
    char op;
    if(*head==0){
        printf("\033[31;1;4;5mNo records found\033[0m\n");
        return;
    }
    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c",&op);

    if(op=='n'||op=='N'){ //sort by name
        for(temp=*head;temp!=0;temp=temp->next){
            for(next=temp->next;next!=0;next=next->next){
                if(strcmp(temp->name,next->name)>0){
                    rollno=temp->rollno;
                    strcpy(name,temp->name);
                    percent=temp->percent;

                    temp->rollno=next->rollno;
                    strcpy(temp->name,next->name);
                    temp->percent=next->percent;

                    next->rollno=rollno;
                    strcpy(next->name,name);
                    next->percent=percent;
                }
            }
        }
        printf("\033[36mRecords sorted by name\033[0m\n");
    }
    else if(op=='p'||op=='P'){ //sort by percentage descending
        for(temp=*head;temp!=0;temp=temp->next){
            for(next=temp->next;next!=0;next=next->next){
                if(temp->percent<next->percent){
                    rollno=temp->rollno;
                    strcpy(name,temp->name);
                    percent=temp->percent;

                    temp->rollno=next->rollno;
                    strcpy(temp->name,next->name);
                    temp->percent=next->percent;

                    next->rollno=rollno;
                    strcpy(next->name,name);
                    next->percent=percent;
                }
            }
        }
        printf("\033[36mRecords sorted by percentage\033[0m\n");
    }
    else
        printf("\033[31;1;4;5mInvalid option\033[0m\n");
}