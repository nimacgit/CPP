/*
 * =====================================================================================
 *
 *       Filename:  segment_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۱۰ ۱۷:۰۷:۲۹
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>


using namespace std;


struct node
{
	int val, start, end;
	node *left, *right;
	node(int s, int e)
	{
		left = right = NULL;
		val = 0;
		start = s;
		end = e;
		if(s != e)
		{
			left = new node(s, (s + e) / 2);
			right = new node((s + e) / 2 + 1, e);
		}
	}

	void add(int i, int value)
	{
		if(start <= i && i <= end)
		{
			val += value;
			if(left != NULL)
				left->add(i, value);

			if(right != NULL)
				right->add(i, value);
		}
	}

	int getsum(int s, int e)
	{
		if(start > e || s > end)
			return 0;
		if(s <= start && end <= e)
			return val;
		return right->getsum(s, e) + left->getsum(s, e); 
	}

};




const int maxn = 1000 * 1000;
int arr[maxn + 100];
int n;
int seg[maxn * 4 + 1000 ]; 

int s , e , andis, value ; 

void add(const int &  start, int end, int andis , int value , int segnum){
	if( start <= andis && andis<= end){
		seg[segnum] += value;  
		if(start!=end){
			int mid = (start+end)/2 ; 
			add(start,mid,andis,value,2*segnum);
			add(mid+1,end,andis,value,2*segnum+1);
		}
	}
}

int getsum(int start, int end, int s, int e, int segnum){
	if(start > e || s>end)
		return 0; 
	if(s<=start && end<=e)
		return seg[segnum];
	int mid = (start+end)/2; 
	return getsum(start,mid,s,e,2*segnum) + getsum(mid+1,end,s,e,2*segnum+1);  
}

node *root;




void input()
{
	cin >> n;
	root = new node(1, n);
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		root->add(i, arr[i]);
		add(1,n,i,arr[i],1); 
	}
}

int naive(const int & l , const int & r ){
	int sum = 0 ; 
	for(int i=l;i<=r;i++)
		sum+=arr[i]; 
	return sum; 
}

void check(){
	for(int i =1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(naive(j,i) != root->getsum(j,i) || naive(j,i) != getsum(1,n,j,i,1)){
				cerr<<i<<" " << j<<endl;
				return; 
			}
	cerr<<"Successful"<<endl;
}

int main()
{
	input();
	check();
	return 0;
}

