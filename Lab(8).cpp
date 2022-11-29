#include <iostream>
#include <string>

using namespace std;



class StackException 
{
    private:
    string m_error;
public:
	StackException(string Exception) : m_error(Exception)
    {

    } 

    string what()
    {
        return m_error;
    }
};

//////////////////////////////////////////

void My_Term()
{
	std::cout << "The programm was terminated" << std::endl;
	exit(-1);
}

///////////////////////////////////////////



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
        while (!empty()){
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
     bool find(T& x){
        if(empty()){
            throw StackException("stack is empty");
        }
        while(!empty()){
            if (x == pop()){
                std::cout << "element was finded" << std::endl;
                return 1;
            }
        }
        return 0; 

    } 

    T pop(){
        if(empty()){
            throw StackException("stack is empty");
        }
        Node* delnode = root;
        T x = delnode->data;
        root = delnode->next;
        delete delnode;
        return x;
    } 
    void printStack(){
        if(empty()){
            throw StackException("stack is empty"); 
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
            throw StackException("stack is empty");
        }
        Node* delnode = root;
        char* x = delnode->data;
        root = delnode->next;
        delete delnode;
        return x;
    } 
    void printStack(){
        if(empty()){
            throw StackException("stack is empty");
            
        }
        cout<<"stack:" <<endl;
        while (!empty())
        {
            cout<< pop() << endl;
        }
    }
    
    bool find( char* x){
        if(empty()){
            throw StackException("stack is empty");
        }
        while(!empty()){
            if (x == pop()){
                std::cout << "element was finded" << std::endl;
                return 1;
            }
        }
        return 0; 

    } 
   

};
int main()
{
    set_terminate(My_Term);

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
    try
    {
        st.push(string1);
        st.push(string2);
        st.push(string3);
        st.printStack();
        if(st.find(string1) == 1){
            std::cout << "element was finded" << std::endl;
        }
        st.printStack();
    }
    catch(StackException e)
    {
        cout << e.what() << '\n';
    }
    
   
    if(st.find(string1) == true){
        std::cout << "element was finded" << std::endl;
    }
    

    terminate();
    return 0;
}
