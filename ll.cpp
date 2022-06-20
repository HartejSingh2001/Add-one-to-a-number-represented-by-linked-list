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

