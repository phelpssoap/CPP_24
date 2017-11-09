#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
    CURL *curl = NULL;
    CURLcode res;

    //创建爱你一个curl句柄
    curl = curl_easy_init();
    if(curl == NULL)
    {
        printf("curl inti error\n");
        exit(1);
    }

    //给这个句柄设置一些参数(服务器ip 域名 端口...)
    res = curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
    if(curl == NULL)
    {
        printf("curl inti error\n");
        exit(1);
    } 

    //发送post请求
    res = curl_easy_setopt(curl, CURLOPT_POST, 0);
    if(res != CURLE_OK)
    {
        printf("curl setopt get errori\n");
        exit(1); 
    }
    
    //将请求提(真正发出请求)
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    {
        printf("curl perform error\n");
        exit(1);
    }

    //处理从服务器返回的数据
    //如果不处理返回的数据，curl默认为把服务器的返回的数据打印到stdout
    
    //释放curl句柄
    curl_easy_cleanup(curl);


    return 0;
}
