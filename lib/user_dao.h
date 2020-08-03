//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_DAO_H
#define CPP_STUDY_USER_DAO_H

#include <cstring>

using namespace std;
class User{
public:
    string getUserName();
    string getLoginNo();
    string getPassword();
    void setUserName(string userName);
    void setLoginNo(string loginNo);
    void setPassword(string password);

private:
    string _loginNo;
    string _userName;
    string _password;
};

class UserDao {
public:
    /**
     * 新增用户
     * @param user
     * @return
     */
    int insertUser(User user);
    /**
     * 查询用户是否存在
     * @param user
     * @return
     */
    bool isUserExit(User user);
};
#endif //CPP_STUDY_USER_DAO_H
