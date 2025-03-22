#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
	移位操作符的使用

	想让二进制某一位置1,例如让a第5位置(低到高)1
	a=13,b=1;		
	a:00000000 00000000 00000000 00001101
	b:00000000 00000000 00000000 00000001
 b<<4:00000000 00000000 00000000 00010000
  a|b:00000000 00000000 00000000 00011101
	  即让b移位,将最低位的1移动到对应位置去与a对应的位置做或运算

	如何还原那个位置？			->用0对该位进行与运算
	00000000 00000000 00000000 00011101
	11111111 11111111 11111111 11101111	->通过对00000000 00000000 00000000 00010000取反可得->通过对1移位可得

	所以：置1	对1移位再或运算
		  置零  对1移位取反再与运算
*/
int main() {
	int a = 13, b = 1,n;
	printf("a=%d,请输入其二进制想要置1的位数:",a);
	scanf("%d",&n);
	a = a |( b<<n-1);
	printf("第%d位置1后=%d\n",n,a);
	printf("a=%d,请输入其二进制想要置0的位数:",a);
	scanf("%d", &n);
	a = a & (~(b << n - 1));
	printf("第%d位置0后=%d\n", n, a);

	//负数算术右移，高位补符号位(1)			->计算机中都是以补码的形式存储和运算
	int i = -1;
	i = i >> 2;
	printf("i:%d",i);
	/*							   对于操作符若没有赋值操作符则都不会改变变量的值
	 赋值操作符
	 直接赋值:=
	 复合赋值:+=,-=,*=,/=,%=,>>=,<<=,^=,&=,|=,~=等	   左值(复合赋值)右值->左值=左值(操作符)右值

	 连续赋值的方式	从左到右依次赋值	->不利于可读性，建议拆开写
	 int a,b,c;
	 a=b=c=10;
	 注意：连续赋值时一定是先定义再进行连续赋值的操作
	 int x=y=z;--->此时只有x是定义的，y和z是没有定义的
	 */
	int y, z;
	int x = y = z = 10;
	printf("\nx=%d,y=%d,z=%d\n",x,y,z);
	/*
	=赋值
	==判断数值是否<相等>				相等返回1，否则返回0
	strcmp判断两个字符串是否<不相等>	前大返回1,前小返回-1,相等返回0--->从左至右边直到出现不同，比较其ascll码
	
	
	*/

	int s=strcmp("string","string");
	printf("%d",s);
	/*
	单目操作符:
	!逻辑取反
	~按位(二进制)取反
	+正
	-负

	&取地址符
	*解引用操作符
	sizeof(xxx)		求xxx所占空间大小,单位字节			当求变量时,()可以去掉,但为了代码可读性最好加()进行分隔
	--->所以证明sizeof是操作符而非函数
	xxx可以是变量，数组，表达式，类型，数组名->整个数组所占空间大小(注意区分,指的是结构区而非数据区)
	
	数组类型的表达格式->去掉数组名剩下的,即int [常数]

	<sizeof中的表达式不会被执行>	 -->因此也不会改变变量的值

	涉及到编译原理
	编译阶段(源文件)   链接阶段   执行阶段(可执行文件)
	sizeof是在编译阶段进行的,只会对表达式的值进行类型分析并得到结果,实际并不会去执行表达式
	在编译阶段就已经确定值,所以在执行阶段sizeof(表达式)就已经是一个常数,从而就不会再去执行表达式


*/
	int t = 1000, arr[10] = {1,2,3,4};
	printf("\n%d\n",sizeof(10));
	printf("short:%d\n", sizeof(short));
	printf("long:%d\n", sizeof(long));
	printf("long long:%d\n", sizeof(long long));
	printf("%d\n", sizeof t);
	printf("%d\n", sizeof arr);		
	printf("%d\n", sizeof (int[20]));//也可以写数组的类型

	int test = 5;
	printf("test:%d\n", sizeof(test=5+5));
	printf("test:%d\n",test);

	int p = -1;
	p = ~p;		//包括符号位,再次提示(只有原反补才涉及到符号位的不变，其他运算,符号位都作为二进制参与运算)
				//计算机中都是以二进制补码的形式进行运算和存储,以原码的结果展示给用户
	/*
	原码:10000000 00000000 00000000 00000001
	补码:11111111 11111111 11111111 11111111
	~	:00000000 00000000 00000000 00000000	->0的补码
	原码:00000000 00000000 00000000 00000000	->+0



	不管是以+0还是-0(进位溢出,高位舍弃),得到的补码形式都是唯一的
	 00000000 00000000 00000000 00000000	+0	=0
	 10000000 00000000 00000000 00000000    -0	=0
补码:00000000 00000000 00000000 00000000
	所以:所以有+0和-0之分，只是其原码不一样,但值是相同的都是0,而且最终补码的形式都是一样的(即0的补码唯一)
	*/

	printf("~p=%d",p);


	/*
	++--的前置后置									单独使用无区别,如a++和++a;
	和其他语句或表达式结合使用则有运算规则			先运算再使用或者先使用再运算
	例如:如与for循环的结合使用,一般是希望在执行完循环体的部分，变化部分再变化，所以for循环的变化部分一般都是后置++


	注意避免垃圾代码(无效无意义无用有歧义等)	 如:int b=1;a=(++b)+(++b)+(++b);		->问题:到底是先执行谁?	不同系统其判定的运算顺序不一样,结果则不一样

	*/

	for (int u = 0; u <= 10; u++) {			//在本层循环中,初始条件只执行一次,++后置则在循环体执行完才会自增
		printf("%d\n",u);
	}







	return 0;
}