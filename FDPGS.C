#include<stdio.h> 
#include<conio.h> 
void main() 
{ 
char task[7]={'t0','t1','t2','t3','t4','t5','t6'}; 
char node[4]={'X','Y','Z','N'}; 
int i;
int temp=0; 
float wt[7];//WAITING TIME 
int j; int n=0; int pos[4]; 
float ext[7]={1.2,1.4,2.1,2.0,1.1,4.1,2.7};//EXECUTION TIMING 
float trt[4];//COST TO SEND SUBTASK TO GRID RESOURCE 
float size[4]={4.0,4.2,4.8,5.0}; 
float rtt[4]={0.8,0.6,1.2,0.9};//RETRUN BACK TIME FROM ONE NODE T ORIGIN NODE
float wsize[4]={0.8,0.4,1.2,1.1};//WINDOW SIZE BETWEEN 2 NODES
 int ld[4]={2.8,2.5,3.2,2.9};
float oldw[4]={8.8,8.3,8.0,9.2};//OLD WORKLOAD
float assw[4];//ASSUMED WORKLOAD
float rb[4];//RESULTBACK TIME
clrscr();
//CALCULATING WAITING TIME
for(i=0;i<7;i++)
{
 if(i==0)
 {
  wt[i]=0.0;
  printf("Waiting Time 0th TASK %f\n",wt[i]);
 }
 else if(i>=1 && i<=4)
 {
  wt[i]=ext[0];
  printf("Waiting Time %dth TASK %f\n",i,wt[i]);
 }
 else
 {
  wt[i]=ext[1]+ext[2]+ext[3]+ext[4];
  printf("Waiting Time %dth TASK %f\n",i,wt[i]);
 }
}
for(i=0;i<5;i++)
{
trt[i]=(size[i]/wsize[i])*rtt[i];
}
//CALCULATING ASSUMED WORKLOAD
for(i=0;i<4;i++)
{
 if(oldw[i]>=trt[i] && oldw[i]>=wt[i])
 assw[i]=oldw[i]+ld[i];
 else if(trt[i]>=oldw[i] && trt[i]>=wt[i])
 assw[i]=trt[i]+ld[i];
 else if(wt[i]>=trt[i] && wt[i]>=oldw[i])
 assw[i]=wt[i]+ld[i];
 printf("ASSUMED WORKLOAD %dth NODE %f\n",i,assw[i]);
 rb[i]=assw[i]+rtt[i];
 printf("RESULTBACK TIME %dth NODE %f\n",i,rb[i]);
}
//SORTING NODES ON BASIS OF RESULTBACK TIME
for(i=0;i<4;i++)
{
 for(j=i+1;j<4;j++)
 {
  if(rb[i]>rb[j])
  {
   temp=rb[i];
   rb[i]=rb[j];
   rb[j]=temp;
   pos[i]=j;
   pos[i+1]=i;
  }
  else
  {
   continue;
  }
 }
}
printf("AFTER SORTING NODE ORDER \n");
 for(i=0;i<4;i++)
 {
  n=pos[i];
  printf("NODE %d\n",n);
 }
printf("ASSIGNING TASK NODE WISE");
getch();
}
