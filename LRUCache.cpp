#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key,val;
    Node* next;
    Node* prev;
    Node()
    {
        key=val=-1;
        next=prev=NULL; 
    }
    Node(int k,int value)
    {
        key=k;
        val=value;
        next=prev=NULL;

    }
};
class LRUCache{
    private:
    unordered_map<int,Node*>mpp;
    int cap;
    Node* head;
    Node* tail;
    void delNode(Node* node)
    {
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    void insertafterhead(Node* node)
    {
            Node* nextnode=head->next;
            head->next=node;
            nextnode->prev=node;
            node->prev=head;
            node->next=nextnode;

    }

    public:
    LRUCache(int capacity){
        cap=capacity;
        mpp.clear();
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->prev=NULL;
    }
    int get(int key){
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        int val=node->val;
        delNode(node);
        insertafterhead(node);
        return val;
    }
    void put(int key,int value){
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            delNode(node);
            insertafterhead(node);
            return;
        }
        if(mpp.size()==cap)
        {
            Node* node=tail->prev;
            mpp.erase(node->key);
            delNode(node);
            delete node;
        }
        Node* newnode=new Node(key,value);
        mpp[key]=newnode;
        insertafterhead(newnode);
    }
};
int main()
{
    int capacity;
    cin>>capacity;
    LRUCache cache(capacity);
    int q;
    cin>>q;
    while(q--)
{
        string op;
        cin>>op;
        if(op== "put"){
            int key,value;
            cin>>key>>value;
            cache.put(key,value);
        }
        else if(op=="get")
        {
            int key;
            cin>>key;
            cout<<cache.get(key)<<endl;
        }
}
return 0;
}