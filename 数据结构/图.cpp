#include<iostream>
using namespace std;
#include<stdlib.h>
#define OK 0
#define ERROR 1	
#define MaxInt 32767   //��ʾ����ֵ 
#define MVNum 100	//��󶥵���	

typedef char  VerTexType;//�������������Ϊ�ַ��� 
typedef int ArcType;//�ߵ�Ȩֵ����Ϊ����
typedef int Status; 

//  ͼ�ľ���洢��ʾ 
typedef struct
{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;
} AMGraph;


//�����ڽӾ���
Status CreateUDN(AMGraph &G )
{
	int i,j,k,v1,v2;
	cout<<"�������ܽ�������ܱ�����"<<endl; 
	cin>>G.vexnum>>G.arcnum;  //		�����ܽ����	 �ܱ���
	cout<<"��������������Ϣ��"<<endl; 
	for(i=0;i<G.vexnum;++i)
	cin>>G.vexs[i];
	
	for(i=0;i<G.vexnum;++i)
		for(j=0;j<G.vexnum;++j)
			G.arcs[i][j]=0;
	for(k=0;k<G.arcnum;++k)
	{	
		
		cout<<"�������"<<k+1<<"�������˵Ķ�����±꣺"<<endl; 
		cin>>i>>j;		//����һ���������Ķ���
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
{  //����ͼG�ж���V�ĵ�һ���ڽӵ�  
    if(G.vexnum==0) return -1; //ȷ��ͼG����  
    for(int j=0;j<G.vexnum;++j)
	{  
        if(G.arcs[v][j]==1)  
        return j;  
    }  
    return -1; 
}  

int NextAdjVex(AMGraph G,int v,int w)
{  //���ض���v�������w����һ���ڽӵ�  
    if(G.vexnum==0) return -1; //ȷ��ͼG����  
    for(int j=w+1;j<G.vexnum;++j)
	{  
        if(G.arcs[v][j]==1)  
        return j;  
    }  
    return -1;  
}  



void DFS(AMGraph G,int v)
{// �ӵ�V����������ݹ��������ȱ���ͼG��
	int w; 
	cout<<G.vexs[v];visited[v]=true; 
	for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
	//���μ��v�������ڽӵ�w��FirstAdjVex(G,v)��ʾV��һ���ڽӵ� 
	//NextAdjVEx(G.v.w)��ʾv�����w��һ���ڽӵ㣬w>=0��ʾ�����ڽӵ� 
	if(!visited[w])  DFS(G,w); 
}

Status DFSTraverse(AMGraph G)
{  
    //��ͼ��������ȱ���  
   for(int v=0;v<G.vexnum;++v)
	{  //���ʱ�־�����ʼ��  
        visited[v]=false;  
    }  
    
    for(int v=0;v<G.vexnum;++v)
	{  
        if(!visited[v]) DFS(G,v); //����δ���ʵĽ�����DFS  
    }  
}  



//---------------------���е�˳��洢�ṹ ---------------------------- 
typedef VerTexType QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
typedef int Status;
#define OVERFLOW -2
#define MAXSIZE 100
//��ʼ��
Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXSIZE];
	if(!Q.base)      return ERROR;
	Q.front=Q.rear=0;
	return OK;
}
//���
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXSIZE==Q.front)
	     return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
//����
Status DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.rear==Q.front)
	     return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
//�ӿ�
bool QueueEmpty(SqQueue Q)
{
	return Q.rear==Q.front;
} 
Status BFS(AMGraph G,int v)
{//��������ȷǵݹ������ͨͼG
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
	{  //���ʱ�־�����ʼ��  
        visited[v]=false;  
    }  
    
    for(int v=0;v<G.vexnum;++v)
	{  
        if(!visited[v]) BFS(G,v); //����δ���ʵĽ�����DFS  
    }  

} 

int main()
{	

	
	AMGraph G;
	if(CreateUDN(G)==OK)
	cout<<"ͼ�����ɹ���"<<endl;
	cout<<"�ڽӾ���Ϊ��"<<endl; 
	show(G);
	
	cout<<"������ȱ���Ϊ��"<<endl ;
	DFSTraverse(G);cout<<endl;
	
	cout<<"��ȶ����ȱ���Ϊ��"<<endl ;
	BFSTraverse(G);
	
	return 0;
}




















