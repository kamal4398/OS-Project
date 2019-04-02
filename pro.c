#include<stdio.h>
int main()
{
            int i,j,n,head,seek=0,d,temp,temp1=0,temp2=0;
            int a2[20],a1[20],a[5000];            
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            printf("Enter the size of queue request\n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    a1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    a2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(a1[i]>a1[j])
                                    {
                                                temp=a1[i];

                                                a1[i]=a1[j];
                                                a1[j]=temp;
                                    }
                        }
            }
            for( i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(a2[i]<a2[j])
                                    {
                                                temp=a2[i];
                                                a2[i]=a2[j];
                                                a2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            {
			a[i]=a1[j];
			a[i]=5000;
		    }
            for(i=temp1+2,j=0;j<temp2;i++,j++)
            {
			  a[i]=a2[j];
			  a[i]=0;
              a[0]=head;
            }
            for(j=0;j<=n+1;j++)
            {
                        d=abs(a[j+1]-a[j]);
                        seek+=d;
                        printf("Disk head moves from %d to %d with seek time %d\n",a[j],a[j+1],diff);
            }
            printf("Total distance  is %d\n",seek);
            return 0;
}
