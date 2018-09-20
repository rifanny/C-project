#include<stdio.h>
#include<conio.h>
struct simulation{
int cust_no;
int rd_ar;
int intr_arr_time;
int arr_time;
int rd_se;
int service_begin;
int service_time;
int time_ser_end;
int waiting_time;
int idle_time;
};
typedef struct simulation Simulation;

void schedule_arrival_time(Simulation s[],int n);
void schedule_service_time(Simulation s[],int n);
void schedule_completion_of_service(Simulation s[],int n);
void waiting_and_idle_time(Simulation s[],int n);

int main (){
Simulation s[200];
int i,j,n;
printf("enter customer number:");
scanf("%d",&n);
printf("enter random digit for arrival time for each customer:\n");
for (i=1;i<2;i++){
    printf("RD.arrival[1]:\n");
    s[i].cust_no=1;
        s[i].rd_ar=0;
        s[i].intr_arr_time=0;
}
for(i=2;i<=n;i++){
        printf("RD.ARRIVAL[%d]: ",i);
        scanf("%d",&s[i].rd_ar);
        s[i].cust_no=i;
        if(s[i].rd_ar>0 && s[i].rd_ar<126) s[i].intr_arr_time=1;
        else if(s[i].rd_ar>125 && s[i].rd_ar<251) s[i].intr_arr_time=2;
        else if(s[i].rd_ar>250 && s[i].rd_ar<376) s[i].intr_arr_time=3;
        else if(s[i].rd_ar>375 && s[i].rd_ar<501) s[i].intr_arr_time=4;
        else if(s[i].rd_ar>500 && s[i].rd_ar<626) s[i].intr_arr_time=5;
        else if(s[i].rd_ar>625 && s[i].rd_ar<751) s[i].intr_arr_time=6;
        else if(s[i].rd_ar>750 && s[i].rd_ar<876) s[i].intr_arr_time=7;
        else if(s[i].rd_ar>875 && s[i].rd_ar<1001) s[i].intr_arr_time=8;
        else {printf("Warning!!Please Enter RD. Around 1-1000");return;}
    }

    schedule_arrival_time(s,n);

    printf("Enter random digit for service time for each customer: \n");
    for(i=1;i<2;i++){
        s[i].service_begin=0;
    }
    for(i=1;i<=n;i++){
        printf("RD.Service[%d]: ",i);
        scanf("%d",&s[i].rd_se);
        if(s[i].rd_se>0 && s[i].rd_se<11) s[i].service_time=1;
        else if(s[i].rd_se>10 && s[i].rd_se<31) s[i].service_time=2;
        else if(s[i].rd_se>30 && s[i].rd_se<61) s[i].service_time=3;
        else if(s[i].rd_se>60 && s[i].rd_se<86) s[i].service_time=4;
        else if(s[i].rd_se>85 && s[i].rd_se<96) s[i].service_time=5;
        else if(s[i].rd_se>95 && s[i].rd_se<101) s[i].service_time=6;
        else{printf("Warning!!Please Enter RD. around 1-100");return;}
    }
    schedule_service_time(s,n);
    schedule_compilation_of_service(s,n);
    schedule_service_time(s,n);
    schedule_compilation_of_service(s,n);

    waiting_and_idle_time(s,n);
    printf("\n   --------------------------------------------------------------------------------------------------------");
    printf("\n  |cust. | RD. For | Inter Arrival| Arrival | RD. For | Service | Service |Service | Waiting  | Server| \n");
    printf("  |  No  |Arrival.T|       Time   |  Time   |Service.T|  Time   |  Begin.T|End Time|in Queue  | Idle.T|");
    printf("\n   --------------------------------------------------------------------------------------------------------\n");
    for(i=1;i<=n;i++){

        printf("    %d         %d           %d            %d         %d         %d         %d        %d          %d         %d \n",
               s[i].cust_no,s[i].rd_ar,s[i].intr_arr_time,s[i].arr_time,s[i].rd_se,s[i].service_time,s[i].service_begin,
               s[i].time_ser_end,s[i].waiting_time,s[i].idle_time);
    printf("  ----------------------------------------------------------------------------------------------------------\n");
    }

    printf("\n\n\n\n");

    return 0;
}
void schedule_arrival_time(Simulation s[],int n){
        int i;
    for(i=2;i<=n;i++){
        s[i].arr_time=s[i-1].arr_time+s[i].intr_arr_time;
    }
}
void schedule_service_time(Simulation s[],int n){
    int i;
    for(i=2;i<=n;i++){
        if(s[i].arr_time>s[i-1].time_ser_end){
            s[i].service_begin=s[i].arr_time;
        }
        else{
            s[i].service_begin=s[i-1].time_ser_end;
        }

    }
}
void schedule_compilation_of_service(Simulation s[], int n){
    int i;
    for(i=1;i<=n;i++){
        s[i].time_ser_end=s[i].service_begin+s[i].service_time;
    }
}
void waiting_and_idle_time(Simulation s[],int n){
   int i;
   s[1].waiting_time=0;
   s[1].idle_time=0;
   for(i=2;i<=n;i++){
    if(s[i].arr_time>s[i-1].time_ser_end){
        s[i].idle_time=s[i].arr_time - s[i-1].time_ser_end;
        s[i].waiting_time=0;
    }
    else{
        s[i].waiting_time=s[i-1].time_ser_end-s[i].arr_time;
        s[i].idle_time=0;
    }

   }
}

