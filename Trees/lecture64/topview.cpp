#include<iostream>
#include<queue>
#include<stack>
#include<map>
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

vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD, then do nothing
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode -> data;
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
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

    vector<int>answer=topView(root);
    cout<<"Priniting TOP VIEW order: "<<endl;

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

}