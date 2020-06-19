#include <stdio.h> /* FILE */
#include <fcntl.h>/* O_RDWR */
#include <linux/fb.h>
#include <sys/mman.h>/* PROT_READ,PROT_WRITE,MAP_SHARED */
#include <string.h>/* memset() */
#include <asm/ioctl.h>	/* _IO */
#include <unistd.h>

void led_init(void)
{
	if(access("/sys/class/gpio/gpio71/value",F_OK))
		system("echo 71 > /sys/class/gpio/export");
	if(access("/sys/class/gpio/gpio75/value",F_OK))
		system("echo 75 > /sys/class/gpio/export");
	if(access("/sys/class/gpio/gpio76/value",F_OK))
		system("echo 76 > /sys/class/gpio/export");
	
	system("echo out > /sys/class/gpio/gpio71/direction");
	system("echo out > /sys/class/gpio/gpio75/direction");
	system("echo out > /sys/class/gpio/gpio76/direction");
	
	system("echo 1 > /sys/class/gpio/gpio71/value");
	system("echo 1 > /sys/class/gpio/gpio75/value");
	system("echo 1 > /sys/class/gpio/gpio76/value");
}

void led_set(char *num,char *ops)
{
	if(num[0] == '1'){
		if(strncmp(ops,"on",2) == 0)
			system("echo 0 > /sys/class/gpio/gpio76/value");
		else if(strncmp(ops,"off",3) == 0)
			system("echo 1 > /sys/class/gpio/gpio76/value");
	}
	else if(num[0] == '2'){
		if(strncmp(ops,"on",2) == 0)
			system("echo 0 > /sys/class/gpio/gpio71/value");
		else if(strncmp(ops,"off",3) == 0)
			system("echo 1 > /sys/class/gpio/gpio71/value");
	}
	else if(num[0] == '3'){
		if(strncmp(ops,"on",2) == 0)
			system("echo 0 > /sys/class/gpio/gpio75/value");
		else if(strncmp(ops,"off",3) == 0)
			system("echo 1 > /sys/class/gpio/gpio75/value");
	}
}

int main(int argc, char *argv[])
{
	led_init();
	led_set(argv[1],argv[2]);
	return 0;	
}
