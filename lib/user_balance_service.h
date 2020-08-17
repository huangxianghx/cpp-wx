//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_SERVICE_H
#define CPP_STUDY_USER_SERVICE_H
#include "user_balance_dao.h";

struct ChargeRequest{

};

class UserBalanceService {
public:
    /**
     * 充值
     * @param user
     * @return
     */
    int charge();
    /**
     * 消费
     * @param user
     * @return
     */
    int consume();
    /**
     * 查询订单
     * @param user
     * @return
     */
    int queryOrder();
};
#endif //CPP_STUDY_USER_SERVICE_H
