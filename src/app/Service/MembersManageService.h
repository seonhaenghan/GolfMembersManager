#ifndef __MEMBERSMANAGESERVICE_H__
#define __MEMBERSMANAGESERVICE_H__
#include <string>
#include "MembersEntity.h"
#include "MemberInfo.h"
#include "ComDev.h"
#include "State.h"
#include <string.h>
#include <iostream>

class MembersManageService
{
private:
    int membersManagerState;
    MembersEntity *membersEntity;
    ComDev  *comDev;

public:
    MembersManageService(ComDev *comDev);
    virtual ~MembersManageService();
    void setComDev(ComDev *comDev);
    void updateStateEvent(std::string devName);
    void checkCardNumber(int *cardNum);
    void updateStateMesg(int state);
};

#endif /* __MEMBERSMANAGESERVICE_H__ */