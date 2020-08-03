//
// Created by 黄湘 on 2020/7/26.
//



#include <iostream>
#include <cstdio>
#include "user_dao.h"
#include "mysql_connect.h"

using namespace std;


string User::getUserName() {
    return _userName;
}

string User::getLoginNo() {
    return _loginNo;
}

string User::getPassword() {
    return _password;
}

void User::setUserName(string userName) {
    _userName = userName;
}

void User::setLoginNo(string loginNo) {
    _loginNo = loginNo;
}

void User::setPassword(string password) {
    _password = password;
}


MYSQL mysql ;
//行的一个查询结果集
MYSQL_RES *res;
// sql 语句
char sql[150];
// sql 执行结果
int result;


/**
 * 判断用户是否已存在
 * @param mysql
 * @param user
 */
bool UserDao::isUserExit(User user){

    // 初始化mysql连接
    initMysqlConnect(&mysql);
    // 判断用户是否已存在
    sprintf(sql,"select * from user where login_no = '%s';",user.getLoginNo().c_str());
    cout << sql << endl;
    result = mysql_query(&mysql,sql);
    res = mysql_store_result(&mysql);
    int resultNum = mysql_num_rows(res);
    if(resultNum == 0){
        printf("user not exit", mysql_error(&mysql));
        return  false;
    }
    else{
        return true;
    }
}

int UserDao::insertUser(User user) {
    // 初始化mysql连接
    initMysqlConnect(&mysql);
    // 拼接sql语句
    sprintf(sql,"insert into user (user_name,login_no,password) values ('%s','%s','%s')",user.getUserName().c_str(),user.getLoginNo().c_str(),user.getPassword().c_str());
    cout << sql << endl;
    // 执行sql
    result = mysql_query(&mysql,sql);
    if(result!=0){
        cout<< "insert fail" << mysql_error(&mysql) << endl;
    }
    // 关闭数据库连接
    closeMysqlConnect(&mysql);
    return 0;
}


