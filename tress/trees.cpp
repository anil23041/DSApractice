#include<stdio.h>
#include<vector>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
      this->data=val;
      left=right=NULL;    
    }
};

static int idx=-1;



int main(){
    vector<int> nodes={1,2,4,-1,5,-1,-1,3,-1,6,-1,-1};


}