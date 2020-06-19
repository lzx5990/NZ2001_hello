#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    FILE *fp1, *fp2;

    char cmd[] = "cat /proc/stat";

    fp1 = popen(cmd, "r");
    if(fp1 == NULL)
    {
        perror("fail to popen");
        exit(1);
    }

    usleep(1000000);

    fp2 = popen(cmd, "r");
    if(fp1 == NULL)
    {
        perror("fail to popen");
        exit(1);
    }

    char buf1[128] = "";
    char buf2[128] = "";

    fgets(buf1, 128, fp1);
    fgets(buf2, 128, fp2);
    
    printf("%s\n", buf1);
    printf("%s\n", buf2);
    
    int data1[10];
    int data2[10];
    sscanf(buf1, "%*s %d %d %d %d %d %d %d %d %d %d", &data1[0], &data1[1], &data1[2], &data1[3], &data1[4],\
            &data1[5], &data1[6], &data1[7], &data1[8], &data1[9]);
    sscanf(buf2, "%*s %d %d %d %d %d %d %d %d %d %d", &data2[0], &data2[1], &data2[2], &data2[3], &data2[4],\
            &data2[5], &data2[6], &data2[7], &data2[8], &data2[9]);

    int sum1 = 0, sum2 = 0;
    int totalCpuTime;
    int i;
    for(i = 0; i <= 9; i++)
    {
        sum1 += data1[i];
    }

    for(i = 0; i <= 9; i++)
    {
        sum2 += data2[i];
    }

    totalCpuTime = sum2 - sum1;
    printf("totalCpuTime = %d\n", totalCpuTime);

    int sum3 = 0, sum4 = 0;
    int idle;
    for(i = 0; i <=3; i++)
    {
        sum3 += data1[i];
    }

    for(i = 0; i <=3; i++)
    {
        sum4 += data2[i];
    }

    idle = sum4 - sum3;
    printf("idle = %d\n", idle);

    float pcpu = 100 * (float)(totalCpuTime - idle) / (float)totalCpuTime;
    printf("cpu使用率：%.2f%%\n", pcpu);
    
    return 0;
}


This is lzx demo

hahahahahahahaha
heiheiheiheihei
hehehehehehehehe
