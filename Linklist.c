#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int count = 0;

void append_front(char ch) {   //เพิ่ม node ใน linked list ด้านหน้าสุดของ list
    node *n = malloc(sizeof(node)); 
    if(head == NULL) { 
        head = n; 
        tail = n; 
        n->next = NULL;
    }  
    else { 
        n->next = head; 
        head = n; 
    } 
    n->c = ch; 
    count++ ;
}
void append_behindHead(char ch){   // เพิ่มต่อท้ายnode Head (แรกสุดของlist) เสมอ
    node *n = malloc(sizeof(node));
    if(head == NULL){
        head = n;
        tail = n;
        n->next = NULL;
    }
    else if (head == tail){
        n->next = head->next ;
        head->next = n;
        tail = n;
    }
    else{
        n->next = head->next ;
        head->next = n; 
    }
    n->c = ch;
    count++ ;
}

void append_beforeTail(char ch) {  
    node *n = malloc(sizeof(node));

    // Check if the original list is empty
    if (head == NULL) { 
        head = n; 
        tail = n;   
        tail->next = NULL;  
    }
    // Check if the original list has only one node
    else if (head == tail) { 
        head->next = n; // Assign the new node to be after the head
        tail = n; // Assign tail to the new node
        tail->next = NULL;
    }
    
    // Check if the original list has two or more nodes
    else {  
        node *prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        n->next = prev->next;
        prev->next = n;
        
    }
    n->c = ch; 
    count++;
}
void print_list()
{
    node *current = head;
    while (current != NULL)
    {
        printf("%c ", current->c);
        current = current->next;
    }
}

void delete_node(char ch)
{
    node *current;
    node *prev;
    current = head;
    if (head->c == ch)
    {
        head = head->next;
    }
    else
    {
        while ((current != NULL) && (current->c != ch))
        {
            prev = current;
            current = current->next;
        }
        if (current->c == ch){
            if (tail->c==ch)
                tail = prev;
            prev->next = current->next;
            current->next = NULL;
        }
        if(current->c == ch){
            count--;
        }
        else if(current->c != ch)
        {
            printf("%c is not in the list\n", ch);
        }
        free(current);
    }
}
node *search_list(char ch)
{
    node *current;
    current = head;
    while ((current != NULL) && (current->c != ch))
    {
        current = current->next;
    }
    return current;
}
void destroy_list()
{
    node *ptr;
    while (count > 0)
    {
        ptr = head;
        head = head->next;
        count--;
        free(ptr);
    }
}

int main()
{
    char choice,ch;
    int option;
    while(1){
        printf("---------------------------\n");
        printf("1. Append\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Search\n");
        printf("5. Destroy\n");
        printf("6. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        

        switch(choice)
        {
        case '1':
            printf("Choose a position to append ( 1. append front , 2. behind head, 3. before tail): ");
            /*
            1. เลือกฟังก์ชัน append_fornt = เพิ่มโหนดใน link list ทางด้านหน้าสุดของ list 
            2. เลือกฟังก์ชัน append_behindHead = เพิ่มโหนด โดยถ้า link list เดิมไม่ว่าง โหนดที่เพิ่มเข้าไปต้องต่อท้ายโหนดแรกสุดของ list เสมอ
            3.เลือกฟังก์ชัน append_beforeTail = เพิ่มโหนด โดยถ้า link list เดิมไม่ว่าง โหนดที่เพิ่มเข้าไปต้องอยู่ก่อนหน้าโหนดสุดท้ายของ list เสมอ*/
            scanf("%d", &option);
            printf("Enter a character to append: ");
            scanf(" %c", &ch);

            if (option == 1){
                append_front(ch);
            }
            else if (option == 2){
                append_behindHead(ch);
            }
            else if (option == 3){
                append_beforeTail(ch);
            }
            else{
                printf("Invalid option\n");
            }
            break;
        case '2':
            printf("Enter a character to delete: ");
            scanf(" %c", &ch);
            delete_node(ch);
            break;
        case '3':
            printf("---------------------------\n");
            printf("List: ");
            print_list();
            printf("\n");
            printf("---------------------------\n");
            printf("\n");
            break;
        case '4':
            printf("Enter a character to search: ");
            scanf(" %c", &ch);
            node *result = search_list(ch);
            if (result == NULL){
                printf("---------------------------\n");
                printf("%c is not in the list\n", ch);
                printf("---------------------------\n");
                printf("\n");
            }
            else {
                printf("---------------------------\n");
                printf("%c is in the list\n", result->c);
                printf("---------------------------\n");
                printf("\n");
            }
            break;
        case '5':
            destroy_list();
            printf("List is destroyed \n");
            break;
        case '6':
            return 0;
        default:
            printf("Invalid choice\n");
            printf("---------------------------\n");
            printf("\n");
            break;
        }
    }
    return 0;
}
