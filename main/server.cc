//
// Created by 黄湘 on 2020/7/25.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include "../lib/user_service.h"


using namespace std;

int socket_fd;


/**
 * 启动服务端
 * @return
 */
int start() {
    //1.创建一个socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        cout << "socket 创建失败： " << endl;
        exit(1);
    }
    //2.准备通讯地址（必须是服务器的）192.168.1.49是本机的IP
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);//将一个无符号短整型的主机数值转换为网络字节顺序，即大尾顺序(big-endian)
    addr.sin_addr.s_addr = inet_addr("172.18.4.189");//net_addr方法可以转化字符串，主要用来将一个十进制的数转化为二进制的数，用途多于ipv4的IP转化。
    //3.bind()绑定
    //参数一：0的返回值（socket_fd）
    //参数二：(struct sockaddr*)&addr 前面结构体，即地址
    //参数三: addr结构体的长度
    int res = bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1) {
        cout << "bind创建失败： " << endl;
        exit(-1);
    }
    cout << "bind ok 等待客户端的连接" << endl;

}

/**
 * 监听客户端连接
 * @param socket_fd
 * @return
 */
int accept() {
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int fd = accept(socket_fd, (struct sockaddr *) &client, &len);
    if (fd == -1) {
        cout << "accept错误\n" << endl;
        exit(-1);
    }
    //6.使用第5步返回socket描述符，进行读写通信。
    char *ip = inet_ntoa(client.sin_addr);
    cout << "客户： 【" << ip << "】连接成功" << endl;
    return fd;
}

/**
 * 参数解析
 * @param message
 * @param op 操作
 * @param userName 用户名
 * @param loginNo 登录号
 * @param password 密码
 * @return
 */
void paramSplit(char *message,char **op,char **userName,char **loginNo,char **password) {
    const char *split = "&";
    char *tmpStr = strtok(message, split);
    if(tmpStr == nullptr){
        return ;
    }
    *op = tmpStr;

    tmpStr = strtok(nullptr, split);
    if(tmpStr == nullptr){
        return ;
    }
    *userName = tmpStr;

    tmpStr = strtok(nullptr, split);
    if(tmpStr == nullptr){
        return ;
    }
    *loginNo = tmpStr;

    tmpStr = strtok(nullptr, split);
    if(tmpStr == nullptr){
        return ;
    }
    *password = tmpStr;

    tmpStr = strtok(nullptr, split);
    if(tmpStr == nullptr){
        return ;
    }
}

/**
 * 构建响应结果
 * @param result
 * @param response
 */
void buildResponse(int result,char *response){
    if(result ==0){
        sprintf(response, "insert fail");
    }
    else{
        sprintf(response, "insert success");
    }
}

/**
 * 注册用户
 * @param userName
 * @param loginNo
 * @param password
 */
int registerUser(string userName,string loginNo,string password){
    UserService userService;
    User user;
    user.setUserName(userName);
    user.setLoginNo(loginNo);
    user.setPassword(password);
    int result = userService.registerUser(user);
    return result;
}

/**
 * 用户登录
 * @param userName
 * @param loginNo
 * @param password
 */
int login(string userName,string loginNo,string password){
    UserService userService;
    User user;
    user.setUserName(userName);
    user.setLoginNo(loginNo);
    user.setPassword(password);
    int result = userService.login(user);
    return result;
}


/**
 * 处理客户端请求
 * @param fd
 * @return
 */
int biz(int fd) {
    // 轮训获取客户端请求
    while (true) {
        char request[255] = {};
        //通过fd与客户端联系在一起,返回接收到的字节数
        read(fd, request, sizeof(request));
        cout << "接受请求request：" << request << endl;
        if (strcmp(request, "exit") == 0) {
            break;
        }
        char response[255];
        int result;
        // 业务处理
        char *op ;
        char *userName;
        char *loginNo;
        char *password;
        // 参数解析
        paramSplit(request,&op,&userName,&loginNo,&password);
        if(strcmp(op,"register")==0){
            result = registerUser(userName,loginNo,password);
        }
        else if(strcmp(op,"login")==0){
            result = login(userName,loginNo,password);
        }
        buildResponse(result,response);
        // 返回响应
        cout << "返回响应response：" << response << endl;
        write(fd, response, sizeof(response));
    }
    cout << "关闭socket连接" << endl;
    close(fd);
    return 0;
}




int main() {
    // 启动服务端
    start();

    //监听客户端listen()函数
    listen(socket_fd, 30);

    // 处理客户端连接事件
    while (true) {
        // 监听客户端请求
        int fd = accept();
        // 处理业务逻辑
        biz(fd);
    }

}


