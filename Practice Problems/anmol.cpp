#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define in insert
#define pb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define mp make_pair
#define vpii vector<pii>
#define mod 998244353
#define INF 1e9
// cin >> s1 >> s2;
// cout << s1 << " " << s2;
// cout << s1 << "\n" << s2;
// int len = s.length();
struct node
{
	node * left ;
	int data ;
	node * right ;
};

node * addnode (int v)
{
	node * temp ;
	temp=(node *) malloc(sizeof(node));
	temp->data=v;
    temp->left = NULL;
    temp->right = NULL;
	return(temp);
}

// void join(node * parent , string s , node * child )
// {
//     // s is left or right
//     if(s==l)
//     {
//         parent->left=child ; 	
//     }
//     else
//     {
//     	parent->right=child ; 
//     }
	
// }

void preorder(node * root)
{
    if(root)
    {
    	cout << root->data << " " ;
    	preorder(root->left) ;
    	preorder(root->right) ;
    } 
}

void postorder(node * root)
{
    if(root)
    {
    	postorder(root->left) ;
    	postorder(root->right) ;
    	cout << root->data << " " ;	
    }
}

void inorder(node * root)
{
    if(root)
    {
    	inorder(root->left) ;
    	cout << root->data << " " ;
    	inorder(root->right) ;
    }
}

int main()
{
    
    node * root , * n1 , * n2 , * n3 , * n4 , * n5 , * n6 ;
	root=addnode(4);
    n1=addnode(2);
    n3=addnode(1);
    n5=addnode(3);
    n2=addnode(6);
    n4=addnode(5);
    n6=addnode(7);

    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n5;
    n2->left=n4;
    n2->right=n6;
    // n3->left=NULL;
    // n4->left=NULL;
    // n5->left=NULL;
    // n6->left=NULL;
    // n3->right=NULL;
    // n4->right=NULL;
    // n5->right=NULL;
    // n6->right=NULL;
    
    // join(root,l,n1);
    // join(root,r,n2);
    // join(n1,l,n3);
    // join(n1,r,n5);
    // join(n2,l,n4);
    // join(n2,r,n6);
    // join(n3,l,NULL);
    // join(n4,l,NULL);
    // join(n5,l,NULL);
    // join(n6,l,NULL);
	// join(n3,r,NULL);
	// join(n4,r,NULL);
	// join(n5,r,NULL);
	// join(n6,r,NULL);

	preorder(root);
	cout << endl ;
	inorder(root);
	cout << endl ;
	postorder(root) ;
}

