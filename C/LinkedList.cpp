using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;
void Insert(int x,int n){
    Node* temp1 = new Node();
    temp1 -> data = x;
    temp1 -> next = NULL;
    if (n==1){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < n-2; i++){
        temp2 = temp2->next; //traverse the linked list to get to the n-1th node
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
};

void Delete(int n){//delete a node at nth position
    Node* temp1 = head;
    if(n==1){
        head = temp1 -> next;//head points to second node
        free(temp1);
        return;
    }
    for(int i = 0; i < n - 2; i++){
        temp1 = temp1 -> next;
    }
    Node* temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;
    free(temp2);//free memory, deallocates whatever memory is allocated on heap for node  

};
void Print()
{
    Node* temp = head;//temporary variable(pointer to node(head) and then we traversed the list)
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp -> next;
    }
    printf("\n");
};
int main()
{
    head = NULL;
    //code for specific example
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
    Delete(2);
    Delete(2);
    Print();
}
