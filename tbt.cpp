#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct patient
{
    string name,disease;
};

class Q
{
    int front;
    int rear;
    patient p[20];
    int n;

    public:
    Q()
    {
        int front = -1;
        int rear = -1;
    }

    void insertq(string val,string disease)
    {
        if(front==0&&rear==n-1||front==rear+1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front==-1)
        {
            front=0;
            rear=0;
        }
    else
    {
        if(rear==n-1)
        {
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
    }
    p[rear].name=val;
}

void deleteCQ()
{
    if(front==-1)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    cout<<"Element deleted from the Queue is : "<<p[front]<<endl;
    
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==n-1)
        {
            front=0;
        }
        else
        {
            front=front+1;
        }
    }
}

void displayCQ_forward()
{
    int f=front;
    int r=rear;
    if(front==-1)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    cout<<"Queue Elements are : "<<endl;
    if(f<=r)
    {
        while(f<=r)
        {
            cout<<p[f]<<" ";
            f++;
        }
    }
    else
    {
        while(f<n-1)
        {
            cout<<p<<" ";
            f++;
        }
        f=0;
        while(f<=r)
        {
            cout<<p[f]<<" ";
            f++;
        }
    }
    cout<<endl;
}

};


int main()
{
    Q q;
    q.insertq("rugved")
}