//
// Created by 黄湘 on 2020/7/24.
//
#include <iostream>
#include "user_balance_dao.h"
#include "user_balance_service.h"

using namespace std;

UserBalanceDao userBalanceDao;
/**
 * 充值
 * @param chargeRequest
 * @return
 */
int UserBalanceService::charge(string userId, string orderId, double amount) {
    cout << "charge" <<endl;
    cout << userId << endl;
    cout << orderId << endl;
    cout << amount << endl;
    return 0;
}

/**
 * 消费
 * @param consumeRequest
 * @return
 */
int UserBalanceService::consume(string userId, string orderId, double amount) {
    cout << "consume" << endl;
    return 0;
}

/**
 * 查询余额
 * @param queryBalanceRequest
 * @return
 */
int UserBalanceService::queryBalance(string userId) {
    cout << "queryBalance" << endl;
    return 0;
}

/**
 * 查询订单
 * @param queryOrderRequest
 * @return
 */
int UserBalanceService::queryOrder(string userId,string orderId) {
    cout << "queryOrder" << endl;
    return 0;
}

