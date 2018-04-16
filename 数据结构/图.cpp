#include<iostream>
using namespace std;
#include<stdlib.h>
#define OK 0
#define ERROR 1	
#define MaxInt 32767   //表示极大值 
#define MVNum 100	//最大顶点数	

typedef char  VerTexType;//顶点的数据类型为字符型 
typedef int ArcType;//边的权值类型为整型
typedef int Status; 

//  图的矩阵存储表示 
typedef struct
{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;
} AMGraph;


//创建邻接矩阵
Status CreateUDN(AMGraph &G )
{
	int i,j,k,v1,v2;
	cout<<"请输入总结点数和总边数："<<endl; 
	cin>>G.vexnum>>G.arcnum;  //		输入总结点数	 总边数
	cout<<"请依次输入点的信息："<<endl; 
	for(i=0;i<G.vexnum;++i)
	cin>>G.vexs[i];
	
	for(i=0;i<G.vexnum;++i)
		for(j=0;j<G.vexnum;++j)
			G.arcs[i][j]=0;
	for(k=0;k<G.arcnum;++k)
	{	
		
		cout<<"请输入第"<<k+1<<"条边两端的顶点的下标："<<endl; 
		cin>>i>>j;		//输入一条边依附的顶点
		G.arcs[i][j]=1;
		G.arcs[j][i]=G.arcs[i][j];
	}
	 
	 return OK; 
} 


void show(AMGraph G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		cout<<G.arcs[i][j]<<" ";
		cout<<endl;
	}
}
	

bool visited [MVNum];

Status FirstAdjVex(AMGraph G,int v)
{  //返回图G中顶点V的第一个邻接点  
    if(G.vexnum==0) return -1; //确定图G存在  
    for(int j=0;j<G.vexnum;++j)
	{  
        if(G.arcs[v][j]==1)  
        return j;  
    }  
    return -1; 
}  

int NextAdjVex(AMGraph G,int v,int w)
{  //返回顶点v的相对与w的下一个邻接点  
    if(G.vexnum==0) return -1; //确定图G存在  
    for(int j=w+1;j<G.vexnum;++j)
	{  
        if(G.arcs[v][j]==1)  
        return j;  
    }  
    return -1;  
}  



void DFS(AMGraph G,int v)
{// 从第V个顶点出发递归地深度优先遍历图G；
	int w; 
	cout<<G.vexs[v];visited[v]=true; 
	for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
	//依次检查v的所有邻接点w，FirstAdjVex(G,v)表示V的一个邻接点 
	//NextAdjVEx(G.v.w)表示v相对于w的一个邻接点，w>=0表示存在邻接点 
	if(!visited[w])  DFS(G,w); 
}

Status DFSTraverse(AMGraph G)
{  
    //对图做深度优先遍历  
   for(int v=0;v<G.vexnum;++v)
	{  //访问标志数组初始化  
        visited[v]=false;  
    }  
    
    for(int v=0;v<G.vexnum;++v)
	{  
        if(!visited[v]) DFS(G,v); //对尚未访问的结点调用DFS  
    }  
}  



//---------------------队列的顺序存储结构 ---------------------------- 
typedef VerTexType QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
typedef int Status;
#define OVERFLOW -2
#define MAXSIZE 100
//初始化
Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXSIZE];
	if(!Q.base)      return ERROR;
	Q.front=Q.rear=0;
	return OK;
}
//入队
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXSIZE==Q.front)
	     return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
//出队
Status DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.rear==Q.front)
	     return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
//队空
bool QueueEmpty(SqQueue Q)
{
	return Q.rear==Q.front;
} 
Status BFS(AMGraph G,int v)
{//按广度优先非递归遍历联通图G
	SqQueue Q;QElemType u;
	cout<<v+1;visited[v]=true;
	InitQueue(Q); 
	EnQueue(Q,v);
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,u);
		for(int w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
		{
			if(!visited[w])
			{
				cout<<G.vexs[w];visited[w]=true; EnQueue(Q,w);
			}	
		}	
	}
} 

Status BFSTraverse(AMGraph G)

{  
    for(int v=0;v<G.vexnum;++v)
	{  //访问标志数组初始化  
        visited[v]=false;  
    }  
    
    for(int v=0;v<G.vexnum;++v)
	{  
        if(!visited[v]) BFS(G,v); //对尚未访问的结点调用DFS  
    }  

} 

int main()
{	

	
	AMGraph G;
	if(CreateUDN(G)==OK)
	cout<<"图创建成功！"<<endl;
	cout<<"邻接矩阵为："<<endl; 
	show(G);
	
	cout<<"深度优先遍历为："<<endl ;
	DFSTraverse(G);cout<<endl;
	
	cout<<"广度度优先遍历为："<<endl ;
	BFSTraverse(G);
	
	return 0;
}




















