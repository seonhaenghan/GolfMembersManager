#include "MembersManageService.h"
#include <cstring>

extern char *clientInputData;
extern char *buffer;
MembersManageService::MembersManageService(ComDev *comDev)
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
    this->comDev = comDev;
    
}

MembersManageService::~MembersManageService()
{
}

void MembersManageService::setComDev(ComDev *comDev)
{
    this->comDev = comDev;
}

void MembersManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
        // case CARD_READER :
        //     if (devName == "ModeButton") {
        //         membersManagerState = CARD_REGISTER;
        //         printf("changed to CARD_REGISTER State\n");
        //     }
        // break;
        // case CARD_REGISTER :
        //     if (devName == "ModeButton") {
        //         membersManagerState = CARD_READER;
        //         printf("changed to CARD_READER State\n");
        //     }
        // break;

        case CARD_READER :
            if (devName == "ModeButton") {
                membersManagerState = CARD_REGISTER;
                printf("changed to CARD_REGISTER State\n");
            }
        break;
        case CARD_REGISTER :
            if (devName == "ModeButton") {
                membersManagerState = CARD_DELETE;
                printf("changed to CARD_DELETE State\n");
            }
        break;

        case CARD_DELETE :
            if (devName == "ModeButton") {
                membersManagerState = CARD_SEARCH;
                printf("changed to CARD_SERACH State\n");
            }
        break;

        case CARD_SEARCH :
            if (devName == "ModeButton") {
                membersManagerState = CARD_READER;
                printf("changed to CARD_READER State\n");
            }
        break;
    }
}

void MembersManageService::updateStateMesg(int state)
{
    switch(state)
    {
        case CARD_READER:
            membersManagerState = CARD_READER;
            printf("CARD_READER_MODE\n");
        break;

        case CARD_REGISTER:
            membersManagerState = CARD_REGISTER;
            printf("CARD_REGISTER_MODE\n");
        break;

        case CARD_DELETE:
            membersManagerState = CARD_DELETE;
            printf("CARD_DELETE_MODE\n");
        break;

        case CARD_SEARCH:
            membersManagerState = CARD_SEARCH;
            printf("CARD_SEARCH_MODE\n");
        break;

    }
}

void MembersManageService::checkCardNumber(int *cardNum)    // 카드를 찍었을 때 할 수 있는 동작들 
{   char buff[BUFSIZ];
    static int idSet = 100001;
    switch (membersManagerState)
    {
        case CARD_READER :
            if (membersEntity->findMemberInfo(cardNum)) {
                printf("Registered Member!\n");
                //membersEntity->printMemberInfo(cardNum);
                //comDev->sendData(cardNum);  // server에서 user한테 전송 
            }
            else {
                printf("Not Registered Member!\n");
            }
        break;
        case CARD_REGISTER :
            MemberInfo tempMember;
            if(membersEntity->findMemberInfo(cardNum))
            {
                printf("It's a registered card\n");
            }
            else
            {
                idSet++;
                tempMember.id = idSet; // begin()을 써서 가장 뒤에 있는 id값 +1을 적용 
                //sprintf(buff, "Name : ");
                //comDev->sendData(buff);
                printf("Name : ");
                scanf("%s", tempMember.name);

                // sprintf(buff,"Address Ex)xxxDong-xxxHo : ");
                // comDev->sendData(buff);
                printf("Address Ex)xxxDong-xxxHo : ");
                scanf("%s", tempMember.address);

                // sprintf(buff,"Phone Num. Ex)010-xxxx-xxxx :");
                // comDev->sendData(buff);
                printf("Phone Num. Ex)010-xxxx-xxxx :");
                scanf("%s", tempMember.phoneNumber);    //>> scanf가 아니라 console에서 입력 받아야함 
                /* text code*/
                // strcpy(tempMember.name, "LeeSoonShin");
                // strcpy(tempMember.address, "101Dong 123Ho");
                // strcpy(tempMember.phoneNumber, "010-1234-5678");
                memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));
                membersEntity->addMemberInfo(tempMember);
                printf("Member Registered!\n");
            }
            
        break;

        case CARD_DELETE :
            membersEntity->delMemberInfo(cardNum);
            // 삭제 후 찾기 진행 했을 때 없으면 success message 전송 
            if (membersEntity->findMemberInfo(cardNum)) {
                printf("failed Delete!!\n");
                membersEntity->printMemberInfo(cardNum);
            }
            else {
                printf("success Delete\n");
            }
        break;

        case CARD_SEARCH :
            if(membersEntity->findMemberInfo(cardNum))
            {
                printf("Success Search !!\n");
                membersEntity->printMemberInfo(cardNum);
            }
            else
            {
                printf("Failed Search!!\n");
            }
        break;

    }
    
}

