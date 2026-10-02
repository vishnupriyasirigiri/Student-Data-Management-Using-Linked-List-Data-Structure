#include"student.h"
int main(){
    SLL *head=0;
    char op;
    while(1){
        printf("----------------------\n");
        printf("Student Database Menu:\n");
        printf("----------------------\n");
        printf("a/A: Add new record\nd/D: Delete\ns/S: Display\nm/M: Modify\nv/V: Save File\nt/T: Sort\nl/L: Delete all\nr/R: Reverse\ne/E: Exit\n");
        printf("----------------------\n");
        printf("Enter your choice:");
        scanf(" %c",&op);
        switch(op){
            case 'a':
            case 'A':   // Add a new record
                add(&head);break;  
            case 'd':
            case 'D':   // Delete a specific record
                del(&head);break;  
            case 's':
            case 'S':   // Display all records
                display(head);break;
            case 'm':
            case 'M':   // Modify a specific record
                modify(&head);break; 
            case 'v':
            case 'V':   // Save the data to a file
                save_file(head);break; 
            case 't':
            case 'T':   // Sort the database records
                sort(&head);break;
                
            case 'l':
            case 'L':   // Delete all database records
                del_all(&head);break;
                
            case 'r':
            case 'R':   // Reverse the linked list
                rev(&head);break; 
            case 'e': 
            case 'E':   //Exit
                return 0;
            default: printf("\033[31;1;4;5mUnknow Option\033[0m\n");
        }
    }
    return 0;
} 