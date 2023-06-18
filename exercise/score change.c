#include<stdio.h>
int main()
{
    printf("please input a score:");
    double score;
    scanf("%lf",&score);
    if(score>0&&score<100)
    {   
        if(0<=score&&score<60)
       {
           printf("the score is D");
           
       }
        else if(score>=60&&score<70)
       {
           printf("the score is C");
           
       }
        else if(score>=70&&score<80)
       {
           printf("the score is B");
           
       }
        else
       {
           printf("the score is A");
           
       } 
    }
    else
    {
        printf("the score is error");
        
    }
    return 0;
}