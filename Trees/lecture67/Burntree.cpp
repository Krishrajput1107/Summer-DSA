#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildtree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "Enter data in left of " << data << endl;
    root->left = buildtree();

    cout << "Enter data in right of " << data << endl;
    root->right = buildtree();

    return root;
}

//mapping node to parent
//return the target node also
Node* createmapping(Node* root,int target,map<Node*,Node*> &nodetoParent){

    Node* res=NULL;
    queue<Node*> q;
    q.push(root);
    nodetoParent[root]=NULL;

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front->data==target){
            res=front;
        }
        if(front->left){
            nodetoParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodetoParent[front->right]=front;
            q.push(front->right);
        }

    }
    return res;

}

//burn tree
int burntree(Node* targetNode,map<Node*,Node*> nodetoParent){
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode]=true;
    int ans=0;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=true;
            }

            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=true;
            }

            if(nodetoParent[front] && !visited[nodetoParent[front]]){
                flag=1;
                q.push(nodetoParent[front]);
                visited[nodetoParent[front]]=true;
            }
        }

        if(flag==1){
            ans++;
        }

    }
    return ans;
}

int BurnTree(Node* root, int target){

    //step1 create nodetoparent mapping
    //step2 find target node
    //step3 burn the tree in mintime
    map<Node*,Node*> nodetoParent;
    Node* targetNode=createmapping(root,target,nodetoParent);

    int ans=burntree(targetNode,nodetoParent);
    return ans;
}

int main() {
    Node* root = NULL;
    int target=6;
    root = buildtree();

    int ans = BurnTree(root,target);

    cout << "Time to burn tree with target "<< target<<" is: " << ans << endl;

    return 0;
}



// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1