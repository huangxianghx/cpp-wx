//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_SERVICE_H
#define CPP_STUDY_USER_SERVICE_H
#include "user_dao.h";

class UserService {
public:
    /**
     * 注册用户
     * @param user
     * @return
     */
    int registerUser(User user);
    /**
     * 用户登录
     * @param user
     * @return
     */
    int login(User user);
};
#endif //CPP_STUDY_USER_SERVICE_H
