//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_MYSQL_CONNECT_H
#define CPP_STUDY_MYSQL_CONNECT_H
#include <mysql/mysql.h>

/**
 * 初始化mysql连接
 * @param mysql
 */
void initMysqlConnect(MYSQL *mysql);

/**
 * 关闭mysql连接
 * @param mysql
 */
void closeMysqlConnect(MYSQL *mysql);
#endif //CPP_STUDY_MYSQL_CONNECT_H
