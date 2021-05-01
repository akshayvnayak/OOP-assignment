// 1. a) Perform these basic vector operation using Standard Template Library:
// i) Find the number of elements in the vector.
// ii) Check whether the vector is empty or not.
// iii) Insert some elements into the vector.
// iv) Remove the element at a particular position.
// v) Find the index of a particular element in a vector.


#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void isEmpty(vector<int> &v)
{
    if(v.size())
        cout<<"Vector is not empty\n";
    else
        cout<<"Vector is empty\n";
}
void display(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
        cout<<" "<<v[i];
    cout<<endl;
}
void insertEle(vector<int> &v)
{
    int pos;
enterPos:
    cout<<"\nEnter the index to insert : ";
    cin>>pos;
    if(pos>v.size() || pos<0)
    {
        cout<<"Invalid index!";
        goto enterPos;
    }
    else
    {
        int key;
        cout<<"Enter element to insert : ";
        cin>>key;
        v.insert(v.begin()+pos,key);
        cout<<"Vector after insertion :";
        display(v);
    }
}
void removeEle(vector<int> &v)
{
    if(v.size()==0)
    {
        cout<<"Vector is empty!\n";
        return;
    }
    int s;
    enterPos:
    cout<<"\nEnter the index to remove :";
    cin>>s;

    if(s>=v.size())
    {
        cout<<"Invalid index!";
        goto enterPos;
    }
    else
    {
        v.erase(v.begin()+s);
        cout<<"\nAfter removing element at index "<<s<<", Vector : ";
        display(v);
    }
}
void findIndex(vector<int> &v)
{
    int x;
    vector<int>::iterator it;
    cout<<"Enter an element : ";
    cin>>x;
    it=find (v.begin(), v.end(), x);
    if (it != v.end())
        cout<<"Element "<<x<<" is found at index : "<<it - v.begin()<<endl;
    else
        cout<<"Element not found!\n";
}
int main()
{
    vector<int> v;
    int ch;

CHOICE:
    cout<<"\n1) Find the number of elements in the vector."<<endl
        <<"2) Check whether the vector is empty or not."<<endl
        <<"3) Insert some elements into the vector."<<endl
        <<"4) Remove the element at a particular position."<<endl
        <<"5) Find the index of a particular element in a vector."<<endl
        <<"Press any other keys to exit."<<endl
        <<"Enter your choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        cout << "Size = " << v.size()<<endl;
        break;
    case 2:
        isEmpty(v);
        break;
    case 3:
        insertEle(v);
        break;
    case 4:
        removeEle(v);
        break;
    case 5:
        findIndex(v);
        break;

    default:
        return 0;
    }
    goto CHOICE;
}
