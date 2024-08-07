#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

void levelorder(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

Node* buildtree(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=buildtree(root->right,data);
    }
    else{
        root->left=buildtree(root->left,data);
    }
    return root;

}

void takeinput(Node* &root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    while(data!=-1){
        root=buildtree(root,data);
        cin>>data;
    }
    
}

bool searchinBST(Node* &root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if (x < root->data) {
        searchinBST(root->left, x); // Search left subtree if x is smaller
    } else {
        searchinBST(root->right, x); // Search right subtree if x is larger
    }

}
//iterative
bool searchele(Node* root,int x){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(x<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}

Node* min(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* max(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

void inorderpred(Node* root,int key,Node* &pred, Node* &succ){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        if(root->left!=NULL){
            Node* temp=root->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            pred=temp;
        }
        if(root->right!=NULL){
            Node* temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            succ=temp;
        }
        return;
    
    }
    if(root->data>key){
        succ=root;
        inorderpred(root->left,key,pred,succ);
    }
    else{
        pred=root;
        inorderpred(root->right,key,pred,succ);
    }

}

Node* deletefromBST(Node* root,int key){
    if(root==NULL){
        return root;
    }

    if(root->data==key){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child present
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //right subchild present
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=min(root->right)->data;
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
            
        }
    }
    else if(root->data>key){
        root->left=deletefromBST(root->left,key);
    }
    else{
        root->right=deletefromBST(root->right,key);
    }
}

int main(){
    Node* root=NULL;
    takeinput(root);

    levelorder(root);
    int x;
    cout<<"Enter value of x: "<<endl;
    cin>>x;
    bool ans=searchele(root,x);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }

    cout<<"Minimum element is: "<<min(root)->data<<endl;
    cout<<"Maximum element is: "<<max(root)->data<<endl;

    Node* pred=NULL;
    Node* succ=NULL;

    inorderpred(root,x,pred,succ);
    cout<<"Predecessor of "<<x<<" is "<<pred->data<<endl;
    cout<<"Successor of "<<x<<" is "<<succ->data<<endl;

    deletefromBST(root,x);
    levelorder(root);

    // 10 12 14 11 9 7 5 8 2 20 21 17 -1
 
}