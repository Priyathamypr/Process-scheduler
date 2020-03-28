	#include<stdio.h> 
#include<conio.h>

void rr(int num,int Remaining_Time[10],int Cur_t,int Arrival_Time[10], int Burst_Time[10]);

main() 
{
	int Process_Number,j,num,current,Remaining_Process,indicator,Time_Quantum,wait,tut,Arrival_Time[10],Burst_Time[10],Remaining_Time[10],x=1;
	indicator = 0;
	wait = 0;
	tut = 0;
	printf("\n\n\n\t\t\t\t\tInput the number of process: "); 
	scanf("%d",&num);
	Remaining_Process = num;
	
	printf("\n\n\t\t\tInput the Arrival time and Burst time of the process respectively :\n");
	for(Process_Number = 0;Process_Number < num;Process_Number++) 
	{
		printf("\n\t\t\t =>Process P%d\n",Process_Number+1);
		printf("\t\t\t =>Arrival time = "); 
		scanf("%d",&Arrival_Time[Process_Number]);
		printf("\t\t\t =>Burst time = "); 
		scanf("%d",&Burst_Time[Process_Number]); 
		Remaining_Time[Process_Number]=Burst_Time[Process_Number]; 
	} 
	printf("\n\tTime Quantum details:\n");
	printf("\tThe Time quantum of first round is 3.\n\n"); 
	Time_Quantum=3;
	current=0;
	for(Process_Number=0;Remaining_Process!=0;) 
	{
		if(Remaining_Time[Process_Number]<=Time_Quantum && Remaining_Time[Process_Number]>0)
		{ 
			current+=Remaining_Time[Process_Number]; 
			Remaining_Time[Process_Number]=0; 
			indicator=1; 
		} 
		else if(Remaining_Time[Process_Number]>0)
		{ 
			Remaining_Time[Process_Number]-=Time_Quantum; 
			current+=Time_Quantum; 
		} 
		if(Remaining_Time[Process_Number]==0 && indicator==1)			
		{ printf("%d",Process_Number);
			Remaining_Process--;				
			printf("P %d",Process_Number+1); 
			printf("\t\t\t%d",current-Arrival_Time[Process_Number]);
			printf("\t\t\t%d\n",current-Burst_Time[Process_Number]-Arrival_Time[Process_Number]);
			wait+=current-Arrival_Time[Process_Number]-Burst_Time[Process_Number]; 
			tut+=current-Arrival_Time[Process_Number]; 
			indicator=0; 
                       
		} 
		if(Process_Number==num-1){
			x++;
			if(x==2){
				Process_Number=0;
				Time_Quantum=6;
				
				printf("\n\tThe time quantum for second round is 6. \n");
			}
			else{
				break;
			}
		}
		else if(current >= Arrival_Time[Process_Number+1]){
			Process_Number++;
		}
		else{
			Process_Number=0;
		}
	}
	
	rr(num,Remaining_Time,current,Arrival_Time,Burst_Time);
	
	return 0;
}


void rr(int num,int Remaining_Time[10],int Cur_t,int Arrival_Time[10], int Burst_Time[10]){
	
	float avg_wait,avg_tut;
    int i,j,n=num,temp,btime[20],Process_Number[20],w_time[20],tut_t[20],total=0,loc;
    
    printf("\n\tThird round with least burst time.\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=Remaining_Time[i];
        w_time[i]=Cur_t-Arrival_Time[i]-btime[i];
		Process_Number[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=Process_Number[i];
        Process_Number[i]=Process_Number[loc];
        Process_Number[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=btime[j];
        }
        total+=w_time[i];
    }
 
    avg_wait=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tut_t[i]=btime[i]+w_time[i];
        total=total + tut_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",Process_Number[i],btime[i],w_time[i],tut_t[i]);
    }
    avg_tut=(float)total/n;
    printf("\n\nAvg waiting time = %f",avg_wait);
    printf("\n Avg turnaround time = %f\n",avg_tut);
	
}



