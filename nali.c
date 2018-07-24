#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "libqqwry/qqwry.h"
#include "config.h"
int main(int argc, char *argv[])
{
    char *ip;
    if (argc != 2) {
        ip=(char *)malloc(128);//有可能前面有大段非数字字符，所以申请128
        ip=fgets(ip,128,stdin);
    } else {
        ip=argv[1];
    }
    
    char country[1024]={'\0'};
    char area[1024]={'\0'};

    //char *test_ip2 = "127.0.0.1";
    //char *test_ip2 = "72.14.207.191";
    //char *test_ip2 = "121.0.23.2";
    FILE *wry_file;
    int i=0;
    for (;i<2;++i) {
        if (i==0) {
            wry_file=fopen(NALI_QQWRY_PATH,"r");
        } else if (i==1) {
            wry_file=fopen("./QQWry.Dat","r");
        }
        if (wry_file!=NULL) {
            break;
        }
    }
    qqwry_get_location(country,area,ip,wry_file);
    fclose(wry_file);
    if (strlen(country)>0) {
        printf("%s",country);
    }
    if (strlen(area)>0) {
        if (strlen(country)>0) {
            printf(" ");
        }
        if (strlen(country)<=0) {
            printf("unknown");
        } else {
            printf("%s",area);
        }
    }
    printf("\n");
    return 0;
}

