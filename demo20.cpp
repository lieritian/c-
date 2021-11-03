/*
 *  程序名：demo20.cpp，此程序演示freecplus框架拆分字符串的类CCmdStr的使用。
 *  作者：C语言技术网(www.freecplus.net) 日期：20190525
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
  CmdStr.SplitToCmd(buffer,";");        // 拆分buffer
  CmdStr.GetValue(0, buffer1,500); 
  CmdStr.GetValue(1, buffer2,500);    
 
  printf("name=%s,no=%s,\n",\
         buffer1,buffer2);  //输出以分号结束

}

