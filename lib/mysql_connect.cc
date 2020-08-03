//
// Created by 黄湘 on 2020/7/24.
//


#include <cstring>
#include "mysql_connect.h"

using namespace std;

/**
 * 获取mysql连接
 * @param mysql
 */
void initMysqlConnect(MYSQL *mysql) {
    // 初始化mysql连接
    mysql_init(mysql);
    // 建立mysql连接
    mysql_real_connect(
            mysql,
            "47.107.147.126",
            "root",
            "root",
            "test",
            3306,
            NULL,
            0
    );
}

/**
 * 关闭数据库连接
 * @param mysql
 */
void closeMysqlConnect(MYSQL *mysql) {
    mysql_close(mysql);
}

