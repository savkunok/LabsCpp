#include <iostream>
using namespace std;

template <typename T> 
class Stack
{
private:
   struct Node
   {
        T data;
        Node* next;
   };
   Node* root;
public:
    Stack() : root (nullptr) {}
   
    ~Stack(){
        while (!empty())
        {
            pop();
        }
        
    } 
    bool empty() const{
        return root == nullptr;
    }
    void push(const T& x){
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = root;
        root = newnode;
    } 
    T pop(){
        if(empty()){
            cout << "stack is empty" << endl;
        }
        Node* delnode = root;
        T x = delnode->data;
        root = delnode->next;
        delete delnode;
        return x;
    } 
    void printStack(){
        if(empty()){
            cout << "stack is empty" << endl;
            
        }
        cout<<"stack:" <<endl;
        while (!empty())
        {
            cout<< pop() << endl;
        }
    }

};
///////////////////////////////////////////////////////////////////////
template <> class Stack<char*>
{
private:
   struct Node
   {
        char* data;
        Node* next;
   };
   Node* root;
public:
    Stack() : root (nullptr) {}
   
    ~Stack(){
        while (!empty())
        {
            pop();
        }
        
    } 
    bool empty() const{
        return root == nullptr;
    }
    void push(char* x){
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = root;
        root = newnode;
    } 
    char* pop(){
        if(empty()){
            cout << "stack is empty" << endl;
        }
        Node* delnode = root;
        char* x = delnode->data;
        root = delnode->next;
        delete delnode;
        return x;
    } 
    void printStack(){
        if(empty()){
            cout << "stack is empty" << endl;
            
        }
        cout<<"stack:" <<endl;
        while (!empty())
        {
            cout<< pop() << endl;
        }
    }

};
int main()
{
    char string1[10];
    char string2[10];
    char string3[10];
    cout<<"Enter 1 string:"<<endl;
    cin >> string1;
    cout<<"Enter 2 string:"<<endl;
    cin >> string2;
    cout<<"Enter 3 string:"<<endl;
    cin >> string3;
    Stack<char*> st;
    st.push(string1);
    st.push(string2);
    st.push(string3);
    st.printStack();

    return 0;
}

 
