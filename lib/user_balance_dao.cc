//
// Created by 黄湘 on 2020/7/26.
//
#include <iostream>
#include <cstdio>
#include "user_balance_dao.h"
#include "mysql_connect.h"

using namespace std;

MYSQL mysql;
//行的一个查询结果集
MYSQL_RES *res;
// sql 语句
char sql[150];
// sql 执行结果
int result;

// 初始值 0
const static double ZERO = 0;


/**
 * 创建用户余额
 * @param mysql
 * @param user
 */
bool UserBalanceDao::createUserBalance(string userId) {
    // 初始化mysql连接
    initMysqlConnect(&mysql);
    // 判断用户是否已存在
    sprintf(sql, "insert into user_balance "
                 "(user_id,balance,version,create_time,update_time) "
                 "values ('%s','%d','%d',now(),now())",
            userId.c_str(), ZERO, ZERO);
    cout << sql << endl;
    result = mysql_query(&mysql, sql);
    res = mysql_store_result(&mysql);
    int resultNum = mysql_num_rows(res);
    if (resultNum == 0) {
        printf("create user balance fail ", mysql_error(&mysql));
        // 关闭数据库连接
        closeMysqlConnect(&mysql);
        return false;
    } else {
        // 关闭数据库连接
        closeMysqlConnect(&mysql);
        return true;
    }
}

/**
 * 更新用户余额
 * @param userBalance
 * @return
 */
bool UserBalanceDao::updateUserBalance(string userId,double amount) {
    // 初始化mysql连接
    initMysqlConnect(&mysql);
    // 拼接sql语句
    sprintf(sql, "update user_balance set balance = '%d' where user_id = '%s';",
            amount, userId.c_str());
    cout << sql << endl;
    // 执行sql
    result = mysql_query(&mysql, sql);
    res = mysql_store_result(&mysql);
    int resultNum = mysql_num_rows(res);
    if (resultNum == 0) {
        printf("create user balance fail ", mysql_error(&mysql));
        // 关闭数据库连接
        closeMysqlConnect(&mysql);
        return false;
    } else {
        // 关闭数据库连接
        closeMysqlConnect(&mysql);
        return true;
    }
}

/**
 * 查询用户余额
 * @param userBalance
 * @return
 */
UserBalance UserBalanceDao::queryUserBalance(string userId) {
    UserBalance userBalance;
    // 初始化mysql连接
    initMysqlConnect(&mysql);
    // 拼接sql语句
    sprintf(sql, "select user_id,balance,version,update_time from user_balance where user_id = '%s';", userId.c_str());
    cout << sql << endl;
    // 执行sql
    auto result = mysql_query(&mysql, sql);
    if (!resule.isEmpty()) {
//        result.fetch(userBalance.getUserId(),userBalance.getBalance(),userBalance.getVersion(),userBalance.getUpdateTime);
    }
    // 关闭数据库连接
    closeMysqlConnect(&mysql);
    return userBalance;
}


