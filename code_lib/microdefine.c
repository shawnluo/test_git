// 用预处理指令#define 声明一个常数，用以表明1年中有多少秒（忽略闰年问题）


#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
// 注意：（1）#define 语法的基本知识（例如：不能以分号结束，括号的使用，等等）
// 　　　（2) 意识到这个表达式将使一个16位机的整型数溢出-因此要用到长整型符号L,告诉编译器这个常数是的长整型数.
// 　　　（3) 如果你在你的表达式中用到UL（表示无符号长整型），那么你有了一个好的起点。记住，第一印象很重要。