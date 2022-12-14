#include<iostream>
#include"stack.hpp"
#include"queue.hpp"

template<class T>
class node{
    T data;
    node<T>*left;
    node<T>*right;

    public:
    node(T data,node<T>*left=NULL,node<T>*right=NULL){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    ~node(){
        left=NULL;
        right=NULL;
    }
    template<class U>
    friend class bst;
};

template<class T>
class bst{
    node<T>* root;
    public:
    bst(){
        root=NULL;
    }
    
   void insertion(T data){
      if(root==NULL){
        root=new node<T>(data);
        return;
      }
      node<T>  *prev,*p;
      p=root;
      while(p!=NULL){
        prev=p;
        if(p->data > data){
            p=p->left;
        }
        else{

            p=p->right;
        }
      }

        if(data > prev->data){
            prev->right=new node<T>(data);
        }
        else{
            prev->left=new node<T>(data);
        }
      

    }

   bool search(T data){
        if(root==NULL){
            cout<<"Tree Empty"<<endl;
            return false;
        }
        node<T>*p;
        p=root;
        while(p!=NULL){
             if(p->data == data){
                return true;
             }
             else if(data < p->data){
                p=p->left;
             }
             else{
                p=p->right;
             }
        }
        return false;
    }


    // traversal bfs
    void bfs(){
        queue<node<T>*>q;
        node<T>*p;
        p=root;
        q.push(p);
        while(!q.empty()){
            node<T>*temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }

    // traversals dfs
private:


   void pre(node<T>* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        pre(root->left);
        pre(root->right);
    } 
     void inor(node<T>* root){
        if(root==NULL){
            return;
        }
       
        inor(root->left);
         cout<<root->data<<" ";
        inor(root->right);
    } 
     void post(node<T>* root){
        if(root==NULL){
            return;
        }
       
        post(root->left);
        post(root->right);
         cout<<root->data<<" ";
    }  
    
    // height
    int heighttree(node<T>*root){
        if(root==0){
            return 0;
        }
        int lefth=heighttree(root->left);
        int righth=heighttree(root->right);
        return max(lefth,righth)+1;
    }



    public:
    int height(){
        heighttree(root);
    }

    void preorder(){
        pre(root);
    }
    void postorder(){
         post(root);
    }
   void inorder(){
        inor(root);
    }

    // iterative
    void preorderit(){
        node<T>*r=root;
        stack<node<T>*>st;
        st.push(r);
        while(!st.empty()){
            node<T>*p=st.top();
            st.pop();
            while(p!=NULL){
                cout<<p->data<<" ";
                if(p->right!=NULL){
                    st.push(p->right);
                    
                }
                p=p->left;
            }
        }
    }
    
    void postorderit(){
        node<T>*p=root;
        node<T>*q=root;
        stack<node<T>*>st;
        while(p!=NULL){
            while(p->left!=NULL){
                st.push(p);
                p=p->left;
            }
            while((p!=0 && p->right == 0)|| p->right==q){
                cout<<p->data<<" ";
                q=p;
                if(st.empty()){
                    return;
                }
                p=st.top();
                st.pop();
            }
            st.push(p);
            p=p->right;
        }
    }
    
    void inorderit(){
        node<T>*p=root;
        stack<node<T>*>st;
        while(p!=0){
            while(p!=0){
                if(p->right){
                    st.push(p->right);
                }
                    st.push(p);
                    p=p->left;
                
            }
            p=st.top();
            st.pop();
            while(!st.empty() && p->right==0){
                cout<<p->data<<" ";
                p=st.top();
                st.pop();
            }
            cout<<p->data<<" ";
            if(!st.empty()){
                p=st.top();
                st.pop();
            }
            else{
                p=0;
            }
        }
    }


    // mirror binary tree
   private: void mirror(node<T>*root){
        if(root==NULL){
            return;
        }
        mirror(root->left);
        mirror(root->right);

        swap(root->left,root->right);
    }
    public: 
    void mirrorrtree(){
        mirror(root);
    }

    // deletion of node 
    
   // deletion by merging -- 
   void deletion(T data){
       if(root==NULL){
           cout<<"tree empty"<<endl;
           return;
       }
       if(root->left==NULL && root->right==NULL && root->data==data){
        //   root->data==data;
           root=NULL;
           return;
       }
       // finding the node to be deleted
       node<T>*temp=root;
       node<T>*prev=root;
       bool flag=false;
       while(temp!=NULL && temp->data!=data){
           if(temp->data==data){
               flag=true;
               break;
           }
           if(temp->data < data){
               prev=temp;
               temp=temp->right;
           }
           else{
               prev=temp;
               temp=temp->left;
           }
           
       }
       if(temp==NULL){
           cout<<"Element not present"<<endl;
           return;
       }
       // now we need to delete the temp
       
       if(temp->left == NULL && temp->right==NULL){
           if(prev->left==temp){
               prev->left=NULL;
           }
           else{
               prev->right=NULL;
           }
           delete temp;
           return;
       }
       
       
       // temp has at least one child
       if(temp->left ==NULL && temp->right!=NULL){
           if(prev->left==temp){
               prev->left=temp->right;
           }
           else{
               prev->right=temp->right;
           }
           delete temp;
           return;
       }
        if(temp->left !=NULL && temp->right==NULL){
           if(prev->left==temp){
               prev->left=temp->left;
           }
           else{
               prev->right=temp->left;
           }
           delete temp;
           return;
       }
       
      
       
       // temp has both left and right child
       cout<<"1. Do you want to delete it my copying"<<endl;
       cout<<"2. Do you want to delete by merging "<<endl;
       int choice;
       cin>>choice;
       if(choice==1){
           if(temp->left!=NULL && temp->right!=NULL){
              node<T>*curr=temp->left;
              if(curr->right!=NULL){
                  node<T>*t1=temp->right;
                  while(t1->left!=NULL){
                      t1=t1->left;
                  }
                  t1->left=curr->right;
              }
              curr->right=temp->right;
              if(prev->left==temp){
                   prev->left=curr;
                   
               }
               else{
                   prev->right=curr;
               }
               delete temp; 
              
              
           } 
       }
       else if(choice==2){
          // here we would replace left successor with temp and attach right subtree to it's right
            //   node<T>*rightmost=findright(temp->left);
               node<T>*prev2=temp;
               node<T>*curr=temp->left;
               
               while(curr->right!=NULL){
                   prev2=curr;
                   curr=curr->right;
               }
               
                if(curr==temp->left){
                    curr->right=temp->right;
                }
                else{
                    prev2->right=NULL;
                    curr->right=temp->right;
                    curr->left=temp->left;
                }
               
               if(prev->left==temp){
                   prev->left=curr;
                   
               }
               else{
                   prev->right=curr;
               }
               delete temp; 
       }
       
       
       
       
   }
    


};


int main(){
    
    bst<int>a;

    bool flag=true;
    while(flag){
        int n;
        cout<<"Menu"<<endl;
        cout<<"1.Insertion"<<endl;
        cout<<"2.Searching"<<endl;
        cout<<"3.transversal"<<endl;
        cout<<"4.Deletion"<<endl;
        cout<<"5 exit"<<endl;

        cout<<"Enter which operation do you want to perform"<<endl;
        cin>>n;
        
        
        if(n==1)
		{
            cout<<"Enter the number to insert "<<endl;
            int data;
            cin>>data;
            a.insertion(data);
        }
        else if(n==2){
            cout<<"Enter the element to be searched"<<endl;
            int key;
            cin>>key;
            if(a.search(key)){
                cout<<key<<" is present in tree "<<endl;
            }
            else{
                cout<<key<<" is not present in tree"<<endl;
            }
        }
        else if(n==3){
                cout<<"1. Preorder"<<endl;
                cout<<"2. Inorder"<<endl;
                cout<<"3. Postorder"<<endl;
                cout<<"Which traversal do you want to perform"<<endl;
                int choice;
                cin>>choice;
                if(choice==1){
                    cout<<"Preorder Traversal is : ";
                    a.preorder();
                }
                else if(choice==2){
                    cout<<"Preorder Traversal is : ";
                    a.inorder();
                }
                else if(choice==3){
                    cout<<"Preorder Traversal is : ";
                    a.postorder();
                }
                else{
                    cout<<"Wrong choice"<<endl;
                }
        }
        else if(n==4){
                cout<<"Enter the element to be deleted"<<endl;
                int key;
                cin>>key;
                a.deletion(key);
                           
        }
        else if(n==4)
        {
        	flag=0;
		}
        else{
            cout<<"Wrong choice"<<endl;
        }
    }
}
