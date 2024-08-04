#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};

vector<int> Zigzag(Node* root){

    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<Node*> q;
    q.push(root);
    bool leftorright=true;
    while(!q.empty()){

        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            Node* front=q.front();
            q.pop();
            int index=(leftorright)?i:size-i-1;
            ans[index]=front->data;

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        leftorright=!leftorright;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}

Node* buildtree(Node* &root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root=new Node(data);

    
    cout<<"Insert data inserting at left of "<<data<<endl;
    buildtree(root->left);

    cout<<"Insert data inserting at right of "<<data<<endl;
    buildtree(root->right);

    return root;

}


int main(){
    Node *root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildtree(root);

    vector<int>answer=Zigzag(root);
    cout<<"Priniting zigzag order traversal: "<<endl;

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    // 1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1

}