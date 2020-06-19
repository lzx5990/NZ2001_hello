#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp_disk, *fp_mem;

    long DISK_total; //磁盘总量
    long DISK_used_space; //磁盘已用空间
    float DISK_used_percentage; //磁盘使用率
    int RAM_total; //内存总量
    int RAM_used; //内存占用
    int RAM_free; //内存空闲

    char cmd_disk[] = "df -l | grep /dev/sda";
    char cmd_mem[] = "free -m | grep Mem";

    fp_disk = popen(cmd_disk, "r");
    if(fp_disk == NULL)
    {
        perror("fail to popen");
        exit(1);
    }

    fp_mem = popen(cmd_mem, "r");
    if(fp_mem == NULL)
    {
        perror("fail to popen");
        exit(1);
    }

    char buf_disk[128] = "";
    fgets(buf_disk, 128, fp_disk);
    printf("buf_disk = %s\n", buf_disk);

    char buf_mem[128] = "";
    fgets(buf_mem, 128, fp_mem);
    printf("buf_mem = %s\n", buf_mem);

    sscanf(buf_disk, "%*s %ld %ld", &DISK_total, &DISK_used_space);
    DISK_used_percentage = (float)DISK_used_space/(float)DISK_total*100;

    sscanf(buf_mem, "%*s %d %d", &RAM_total, &RAM_used);
    RAM_free = RAM_total - RAM_used;

    printf("磁盘总量：%.0fG, 磁盘已用：%.2fG，磁盘使用率：%.2f%%\n", \
        (float)DISK_total/1024/1024, (float)DISK_used_space/1024/1024,\
        (float)DISK_used_space/(float)DISK_total*100);

    printf("内存总量：%.0f, 内存占用：%.2f, 内存空闲：%.2f\n", \
        (float)RAM_total/1024, (float)RAM_used/1024, (float)RAM_free/1024);
    
    return 0;
}
