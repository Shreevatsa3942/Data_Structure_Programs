/*Program: graph representation using adjacent matrix */
//Name:Shreevatsa
//Reg No:200970093
//Modified Date:25-06-2021
#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout<<"select graph type : \t1: undirected \telse : directed\nchoice : ";
	int status,ch;
	cin>>status;
	cout<<"enter total number of vertices in a graph : ";
	int n;
	string str;
	cin>>n;
	str="indexes :   ";
	int adj[n][n];
	for(int i=0;i<n;i++)
	{
		str=str+to_string(i)+" : v"+to_string(i)+"\t\t";
	}
	str=str+"\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adj[i][j]=0;
	do{
		cout<<"graph :\n1:add edge\t2:display adjacent matrix\n0:exit\tchoice :";
		cin>>ch;
		switch(ch)
		{
		case 1:if(status==1)
		       {
			       int x,y;
				cout<<str<<"enter indexes of adjacent vertices of edge : ";
				cin>>x>>y;
				if(x==y)
				{
					cout<<"self loops cannot be added\n";
				}
				else if(adj[x][y]==1)
				{
					cout<<"edge aldready exsist , parllel edge cannot be added\n";
				}
				else
				{
					adj[x][y]=1;
					adj[y][x]=1;
					cout<<"edge added between v"<<to_string(x)<<" and v"<<to_string(y)<<endl;
				}
		       }
		       else
		       {
			       int x,y;
				cout<<str<<"enter indexes of from and to vertices of edge : ";
				cin>>x>>y;
				if(x==y)
				{
					cout<<"self loops cannot be added\n";
				}
				else if(adj[x][y]==1)
				{
					cout<<"edge aldready exsist , parllel edge of same directon cannot be added\n";
				}
				else
				{
					adj[x][y]=1;
					cout<<"edge added from v"<<to_string(x)<<" to v"<<to_string(y)<<endl;
				}
		       }
		       break;
		case 2:cout<<"adjacency matrix : \n  \t";
		       for(int i=0;i<n;i++)
			       cout<<"v"<<to_string(i)<<"\t";
			cout<<endl;
		       for(int i=0;i<n;i++)
		       {
			       cout<<"v"<<to_string(i)<<"\t";
		       		for(int j=0;j<n;j++)
					cout<<adj[i][j]<<"\t";
				cout<<endl;
			}
		       break;
		case 0:cout<<"\t\tthank you\n";
		       break;
		default:cout<<"invalid choice\n";
			break;
		}
		cout<<"--------------------------------------------------\n";

	}while(ch!=0);

	return 0;
}
