/*
 *  ��������demo20.cpp���˳�����ʾfreecplus��ܲ���ַ�������CCmdStr��ʹ�á�
 *  ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20190525
*/
//#include "../_freecplus.h"
#include "CCmdStr.h"


int main()
{
  char buffer[301];  
  STRCPY(buffer,sizeof(buffer),"messi10true30,68.5;2100000,Barcelona");
  char buffer1[500];
  char buffer2[500];
  CCmdStr CmdStr;
  CmdStr.SplitToCmd(buffer,";");        // ���buffer
  CmdStr.GetValue(0, buffer1,500); 
  CmdStr.GetValue(1, buffer2,500);    
 
  printf("name=%s,no=%s,\n",\
         buffer1,buffer2);  //����ԷֺŽ���

}

