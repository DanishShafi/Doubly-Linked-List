#include<iostream>
using namespace std;
/*

  -> Insertion
  -> Deletion
  -> Searching
  -> Printing 

*/
struct node{
	int info;
	node *next, *previous;
};

class linked_list{
	private:
		node *head, *temp, *ptr, *temp2;
		
	public:
		linked_list()
		{
			head = NULL;
			temp = NULL;
		}
		
		void insert_front(int x)
		{
			if(head==NULL)
			{
				head=new node();
				head->info=x;
				head->next = head->previous = NULL;
				return ;
			}
			else
			{
				temp= new node();
				temp->info=x;
				temp->next=head;
				temp->previous=NULL;
				head->previous=temp;
				head=temp;
			}
		}
		/*.......................................................*/
		
		int insert_middle(int x, int key)    
		{
			cout<<" "<<endl;
			temp=head;
			while(temp!=NULL)
			{
				if(temp->info ==  key)
				{
					ptr =new node();
					ptr->info=x;
					temp2=temp->next;
					temp->next=ptr;
					ptr->previous=temp;
					ptr->next=temp2;
					temp2->previous=ptr;
				}
				temp = temp->next;
			}	
		}		
		
		int delete_middle(int x)
		{
			temp=head;
			while(temp != NULL)
			{
				if(temp->next->info == x)
				{
					ptr=temp->next;
					temp->next=temp->next->next;
					temp->next->next->previous=temp;
					delete ptr;
					ptr=NULL;
					return 0;
				}
				temp=temp->next;
			}
		}
		int delete_end()
		{
			temp=head;
			while(temp != NULL)
			{
				if(temp->next->next == NULL)
				{
					ptr=temp->next;
					temp->next=NULL;
					delete ptr;
					ptr=NULL;
					return 0;
				}
					
				temp=temp->next;
			}
		}
		
		int delete_front()
		{
			temp=head;
			if(temp==NULL)
			{
				cout<<"list empty"<<endl;
			}
			else
			{
				head=head->next;
				head->previous=NULL;
				delete temp;
				temp=NULL;
				return 0;
			}
		} 
		
		int search(int x)
		{
			temp=head;
			while(temp != NULL)
			{
				if(temp->info==x)
				{
					cout<<"Sucessfully found value ===  "<<x<<endl;
				}
				temp=temp->next;
			}
		}
		void print()
		{
			temp = head;
			while(temp != NULL)
			{
				cout<< temp->info <<" ";
				temp = temp->next;
			}
			
		}
};

int main(){
	linked_list l;
	l.insert_front(1);
	l.insert_front(2);
	l.insert_front(3);  
	l.insert_front(5);
	
	
	cout<<"Insertion of front value form left side"<<endl;
	l.print();
	
	cout<<" "<<endl;
	cout<<"Insertion of middle value"<<endl;
	l.insert_middle(4,5);
	l.print();
	
	cout<<" "<<endl;
	cout<<"Deletion of middle value"<<endl;
	l.delete_middle(3);
	l.print();
	
	cout<<" "<<endl;
	l.search(4);
	
	cout<<" "<<endl;
	cout<<"Deletion of end value"<<endl;
	l.delete_end();
	l.print();
	
	cout<<" "<<endl;
	cout<<"Deletion of first value"<<endl;	
	l.delete_front();
	l.print();
	return 0;
}
