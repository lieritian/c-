#ifndef __CCMDSTR_H
#define __CCMDSTR_H
#include "_cmpublic.h"

// 以下是字符串操作相关的函数和类

// 安全的strcpy函数。
// dest：目标字符串，不需要初始化，在STRCPY函数中会对它进行初始化。
// destlen：目标字符串dest占用内存的大小。
// src：原字符串。
// 返回值：目标字符串dest的地址。
char *STRCPY(char* dest,const size_t destlen,const char* src);
// CCmdStr类用于拆分有分隔符的字符串。
// 字符串的格式为：字段内容1+分隔符+字段内容2+分隔符+字段内容3+分隔符+...+字段内容n。
// 例如："messi,10,striker,30,1.72,68.5,Barcelona"，这是足球运动员梅西的资料，包括姓名、
// 球衣号码、场上位置、年龄、身高、体重和效力的俱乐部，字段之间用半角的逗号分隔。
class CCmdStr
{
public:
  vector<string> m_vCmdStr;  // 存放拆分后的字段内容。

  CCmdStr();  // 构造函数。

  // 把字符串拆分到m_vCmdStr容器中。
  // buffer：待拆分的字符串。
  // sepstr：buffer中采用的分隔符，注意，sepstr参数的数据类型不是字符，是字符串，如","、" "、"|"、"~!~"。
  // bdelspace：拆分后是否删除字段内容前后的空格，true-删除；false-不删除，缺省删除。
  void SplitToCmd(const string buffer,const char *sepstr,const bool bdelspace=true);

  // 获取拆分后字段的个数，即m_vCmdStr容器的大小。
  int CmdCount();

  // 从m_vCmdStr容器获取字段内容。
  // inum：字段的顺序号，类似数组的下标，从0开始。
  // value：传入变量的地址，用于存放字段内容。
  // 返回值：true-成功；如果inum的取值超出了m_vCmdStr容器的大小，返回失败。
  bool GetValue(const int inum,char *value,const int ilen=0); // 字符串，ilen缺省值为0。
  bool GetValue(const int inum,int  *value); // int整数。
  bool GetValue(const int inum,unsigned int *value); // unsigned int整数。
  bool GetValue(const int inum,long *value); // long整数。
  bool GetValue(const int inum,unsigned long *value); // unsigned long整数。
  bool GetValue(const int inum,double *value); // 双精度double。
  bool GetValue(const int inum,bool *value); // bool型。

  ~CCmdStr(); // 析构函数。
};

#endif