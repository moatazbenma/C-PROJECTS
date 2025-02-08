#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int hour, second, minute;
    hour=minute=second=0;
    while(1){
        system("clear");
        printf("%02d %2d %02d", hour, minute, second);
        fflush(stdout);
        second ++;
        
        
        if(second == 60){
            minute+=1;
            second = 0;
        }
        if(minute == 60){
            hour +=1;
            minute = 0;
        }
        if(hour == 24){
            minute = 0;
            second = 0;
        }
        sleep(1);
    }
    return 0;
    
}