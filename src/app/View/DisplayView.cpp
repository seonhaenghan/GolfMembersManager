#include "DisplayView.h"

DisplayView::DisplayView(LCD *lcd)
{
    this->lcd = lcd;
}

DisplayView::~DisplayView()
{

}

void DisplayView::displayMode(int mode)
{
    char buff[30];
    char initbuff[30];
    switch(mode)
    {
        case CARD_READER:
            //LCD를 초기화 code test 진행해봐야 함 
            sprintf(initbuff, "                ");
            lcd->WriteStringXY(0, 0, initbuff);
            lcd->WriteStringXY(1, 0, initbuff);

            
            sprintf(buff, "CARD READER");
            lcd->WriteStringXY(1, 0, buff);
        break;

        case CARD_REGISTER:
            
            sprintf(initbuff, "                ");
            lcd->WriteStringXY(0, 0, initbuff);
            lcd->WriteStringXY(1, 0, initbuff);

            
            sprintf(buff, "CARD REGISTER");
            lcd->WriteStringXY(1, 0, buff);
        break;

        case CARD_DELETE:
            
            sprintf(initbuff, "                ");
            lcd->WriteStringXY(0, 0, initbuff);
            lcd->WriteStringXY(1, 0, initbuff);

            
            sprintf(buff, "CARD DELETE");
            lcd->WriteStringXY(1, 0, buff);
        break;

        case CARD_SEARCH:
            
            sprintf(initbuff, "                ");
            lcd->WriteStringXY(0, 0, initbuff);
            lcd->WriteStringXY(1, 0, initbuff);

            
            sprintf(buff, "CARD SEARCH");
            lcd->WriteStringXY(1, 0, buff);
    }
}