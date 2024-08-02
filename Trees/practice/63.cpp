#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelorderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }

}

Node* buildtree(Node* root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    cout<<"Enter data in left of "<<root->data<<endl;
    root->left=buildtree(root->left);

    cout<<"Enter data in right of: "<<root->data<<endl;
    root->right=buildtree(root->right);

    return root;

}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

     int left=height(root->left);
     int right=height(root->right);
     int ans=max(left,right)+1;
     return ans;

}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int opt1=diameter(root->left);
    int opt2=diameter(root->right);
    int opt3=height(root->left)+1+height(root->right);

    int ans=max(max(opt1,opt2),opt3);
    return ans;
}

pair<int,int> diameterFast(Node* root){
    if(root==NULL){
        pair<int,int> p= make_pair(0,0);
        return p;
    }

    pair<int,int> left=diameterFast(root->left);
    pair<int,int> right=diameterFast(root->right);

    int opt1=left.first;
    int opt2=right.first;

    int opt3=left.second+right.second+1;

    pair<int,int> ans;
    ans.first=max(max(opt1,opt2),opt3);
    ans.second=max(left.second,right.second)+1;

    return ans;

}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }

    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    Node* root=NULL;
    root=buildtree(root);

    levelorderTraversal(root);

    int ans=height(root);

    cout<<"Height of tree is: "<<ans<<endl;

    int sol1=diameter(root);
    cout<<"Diameter of tree is: "<<sol1<<endl;

    pair<int,int> sol2=diameterFast(root);
    cout<<"Diameter of tree fast is: "<<sol2.first<<endl;

    bool b=isBalanced(root);
    if(b){
        cout<<"Tree is balanced"<<endl;
    }
    else{
        cout<<"Tree is not balanced"<<endl;
    }




    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
}