// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *nextnode=head,*curr=head,*prev=NULL;
        // reverse the linked list
        while(nextnode!=NULL)
        {
            nextnode=nextnode->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        head=prev;
        Node *res=head,*temp;
        int carry=1,sum=0;
        while(head!=NULL)
        {
            sum=carry+head->data;
            if(sum>=10)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            sum=sum%10;
            head->data=sum;
            temp=head;
            head=head->next;
        }
        if(carry>0)
        {
            Node *newnode = new Node(carry);
            temp->next=newnode;
        }
        
        nextnode=res;// assign res here very imp
        curr=res;// assign res here very imp
        prev=NULL;
        // reverse the linked list
        while(nextnode!=NULL)
        {
            nextnode=nextnode->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        head=prev;
        return head;
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
