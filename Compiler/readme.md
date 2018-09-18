# 编译原理--表达式布尔值判断编译器


简介
---
设计一个简单的编译器，根据输入的表达式，判断其布尔值。

（一）文法设计
---
S->R;
R->R ||R |!R|R&&R| (R) | B;
B-> B>=B | B>B | B<=B | B<B| B==B |B!=B |VALUE;

将运算比较符的优先级设置为最高，括号与布尔比较符次之。VALUE为数值。

（二）语法制导定义设计
---
为文法的非终结符添加属性bo,计算布尔值。产生式与语义规则如下。

S->R          { if(R.bo)printf("Output: true.");else printf("Output: false."); return 0; }

R->R1 ||R2    { R.bo= (R1.bo || R2.bo;}
!R1        {R .bo =!R1.bo；}
R1&&R2    {R.bo = (R1.bo && R2.bo;}
 (R1)       {R.bo = R1.bo;}
B         { R.bo =B.bo; }

B->B1>=B2    {B .bo = (B1 .bo >= B2 .bo;}
 B1>B2     { B .bo = (B1 .bo > B2 .bo;} 
 B1<=B2    { B .bo = (B1.bo <= B2 .bo;}
 B1<B2     { B .bo = (B1.bo < B2 .bo;}
 B1==B2    { B .bo = (B1 .bo == B2 .bo;}
B1!=B2    { B .bo = (B1 .bo!= B2 .bo;}
 VALUE     { B .bo = VALUE .yylval ;}


 （三）基于flex的词法分析器
---

 1. 定义模式
digit	[0-9]
letter [a-zA-Z]
num  {digit}+

 2. 错误输入提示
[.]     {printf("input error");}
{letter}+  {printf("input error");}


（四）基于bison的语法和语义分析器
---

 1. 语义动作实现：
 
通过对栈操作，实现语义动作，如：

 - 输出表达式的逻辑真值，若R（$1）为1 输出true；否则false。

> S: R {{if($1)printf("Output: true.");else printf("Output: false.");
> return 0;}}

 - 计算||运算结果，对操作数1和3进行||运算，结果存在$$中

> R:R OR R { $$ = ($1 || $3);}

 2. 结合顺序定义：
 
 - 左结合：

> %left LT LE GT GE EQ NE AND OR

 - 右结合：

> %right NOT

 3. 错误提示：

> void yyerror(char const *msg)   {  
>     fprintf(stderr, "%s\n",msg);   }

（五）运行示例
---
![此处输入图片的描述][1]


  [1]: https://github.com/LLLLLumos/Undergraduate_works/blob/master/Compiler/%E8%BF%90%E8%A1%8C%E7%A4%BA%E4%BE%8B%E6%88%AA%E5%9B%BE.png?raw=true
