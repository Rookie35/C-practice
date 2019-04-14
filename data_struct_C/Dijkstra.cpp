#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define MaxSize 10;
#define MAXCOST 10000

template<class T>
struct Graph
{
	T vertex[MaxSize];//���ͼ�ж�������
	int arc[MaxSize][MaxSize];//���ͼ�бߵ�����
	int vertexNum,arcNum;//������������ 
};

void Dijkstra(Graph<string> G,int v)
{
	int dist[MaxSize];//i��j��·������ 
	string path[MaxSize];//·���Ĵ� 
	int s[MaxSize];//���ҵ����·���ĵ�ļ��� 
	bool Final[MaxSize];//Final[w]=1��ʾ��ö���V0��Vw�����·�� 
	
	for(int i=0;i<G.vertexNum;i++)
	{
		Final[i]=false;
		dist[i]=G.arc[v][i];
		if(dist[i]!=MAXCOST)
			path[i]=G.vertex[v]+G.vertex[i];
		else
			path[i]=" ";
	}
	
	s[0]=v;
	Final[v]=true;
	int num=1;
	while(num<G.vertexNum)
	{
		int k=0,min=MAXCOST;
		for(int i=0;i<G.vertexNum;i++)
		{
			if(i==v) continue;
			if(!=Final[i]&&dist[i]<min)
			{
				k=i;
				min=dist[i];
			}
		}
		cout<<dist[k]<<path[k]<<endl;
		s[num++]=k;
		Final[k]=true;
		
		for(int i=0;i<G.vertexNum;i++)
		{
			if(!Final[i]&&dist[i]>dist[k]+G.arc[k][i])
			{
				dist[i]=dist[k]+G.arc[k][i];
				path[i]=path[k]+G.vertex[i];
			 } 
		}
	}
 } 
 
 int main()
 {
 	Graph<string> G;
 	string temp[]={"v0","v1","v2","v3","v4"};
 	
 	ifstream in("input.txt");
 	in >> G.vertexNum >> G.arcNum;
 	
 	for(int i=0;i<G.vertexNum;i++)
 	{
 		G.vertex[i]=temp[i];
	 }
	 
	for(int i=0;i<G.vertexNum;i++)
	{
		for(int j=0;j<G.vertexNum;j++)
		{
			G.arc[i][j]=MAXCOST;
		}
	}
	
	for(int i=0;i<G.arcNum;i++)
	{
		int m,n,cost;
		in>>m>>n>>cost;
		G.arc[m][n]=cost;
	}
	Dijkstra(G,0);
	system("pause");
	return 0;
 	
 }