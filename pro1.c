#include<stdio.h>
int main()
{   int i,t,s;
    int wt[50];
    wt[0]=0;
	printf("Enter NO: of teachers \n");
	scanf("%d",&t);
	printf("Enter NO: of students \n");
	scanf("%d",&s);
	

	int at1[t],at2[s];
	//taking input of arrival time

	printf("Enter Arrival time of Teachers\n");
	for(i=0;i<t;i++)
	{
	printf("Enter Arrival time of Teacher %d \n",i+1);
	scanf("%d",&at1[i]);
	}

	printf("Enter Arrival time of Students\n");
	for(i=0;i<s;i++)
	{
	printf("Enter Arrival time of Student %d \n",i+1);
	scanf("%d",&at2[i]);
	}


// taking input for burst time
    int bt1[t],bt2[s];
    printf("Enter Burst time for Teachers\n");
    for(i=0;i<t;i++)
	{
	printf("Enter Burst time of Teacher %d\n",i+1);
	scanf("%d",&bt1[i]);
	}

	printf("Enter Burst time for Student\n");
    for(i=0;i<s;i++)
	{
	printf("Enter Burst time of Student %d\n",i+1);
	scanf("%d",&bt2[i]);
	}

// sorting acc. to their arrival time
// for teacher process
   int at3[t];
   int temp;
   for(i=0;i<t;i++)
   {
   at3[i]=at1[i];
   }
   i=0;
   while(i<t)
   {
   if(at1[i]>at1[i+1])
   {
   temp=at1[i];
   at1[i]=at1[i+1];
   at1[i]=temp;
   }
   i++;
   }


// for student process
   int at4[s];
   for(i=0;i<s;i++)
   {
   at4[i]=at2[i];
   }
   i=0;
   while(i<s)
   {
   if(at2[i]>at2[i+1])
   {
   temp=at2[i];
   at2[i]=at2[i+1];
   at2[i]=temp;
   }
   i++;
   }
   
   
   
   
   
   int tt[20];
   tt[0]=0;
    int j=0;
    int p=t+s;
    int m[20];
    for(i=0;i<p;i++)
    { 
    if((at1[i]<=at2[j]) && (i<3))
    {
       tt[i+1]=bt1[i]+tt[i];
    }
    else if((at1[i]<=tt[i]) && (i<3))
    {
    	tt[i+1]=bt1[i]+tt[i];
	}
	else
	{
		tt[i+1]=bt2[j]+tt[i];
		j++;
	}
    /*else if(at2[j]<at1[i])
    {
    	tt[i+1]=bt2[j]+tt[i];
    	j++;
    }
    else if(at2[i]==NULL)
    {
    	tt[i+1]=bt2[j]+tt[i];
    	j++;
	}*/
   
}


   int wt1[10],wt2[10];
   for(i=0;i<t;i++)
   {
   	wt1[i]=tt[i+1]-(bt1[i]+at1[i]);
   }
   int a=t;
   for(i=0;i<s;i++)
   {
   	wt2[i]=tt[a]-(bt2[i]+at2[i]);
   	a++;
   }




   // finding Waiting time
    /*for(i=0;i<t;i++)
    {
    int j=0;
    if(at1[i]<=at2[j])
    {
       wt[i+1]+=bt1[i];
    }
    else if(at2[j]<at1[i])
    {
    wt[i+1]=bt2[j];
    j++;
    }
    else
    {
    wt[i+1]=bt2[j];
    j++;
    }
    }*/

    printf("Arrival and Burst Time\n");
    printf("For Teacher Process\n");
    for(i=0;i<t;i++)
    {
    printf("t%d \t  arrival time  %d \t and burst time   %d  and total time  %d  and Waiting time %d\n",i+1,at1[i],bt1[i],tt[i+1],wt1[i]);
    }
    j=3;
    for(i=0;i<s;i++)
    {
    printf("s %d \t  arrival time  %d \t  and burst time  %d and total time is %d and Waiting time %d\n",i+1,at2[i],bt2[i],tt[j+1],wt2[i]);
    j++;
    }
    /*int p=t+s;
    for(i=0;i<p;i++)
    {
    printf("Waiting time %d\n",tt[i]);
    }*/

}
