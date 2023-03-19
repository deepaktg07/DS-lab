#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define ss 30
int mstack[ss], top=-1, result;
char prefix[ss];
//push operation
void push(int ele)
{
if (top==ss-1)
{
printf("Stack Overflow!\n");
}
top++;
mstack[top]=ele;
}
//pop operation
int pop()
{
int ele;
if (top==-1)
{
printf("Stack Underflow!\n");
}
ele=mstack[top];
top--;
return ele;
}
//expression reversal
void reverse(char *prefix, int begin, int end)
{
int temp;
while (begin<=end)
{
temp=*(prefix+begin);
*(prefix+begin)=*(prefix+end);
*(prefix+end)=temp;
begin++; end--;
}
}
//prefix evaluation
int main()
{
printf("Enter prefix expression:");
scanf("%s", prefix);
reverse(prefix, 0, strlen(prefix)-1);
int operand1, operand2, res;
for (int i=0; prefix[i]!='\0'; i++)
{
if (isdigit(prefix[i]))
{
push(prefix[i]-'0');
}
else
{
operand2=pop();
operand1=pop();
switch(prefix[i])
{
case '+':
res=operand2+operand1;
break;
case '-':
res=operand2-operand1;
break;
case '*':
res=operand2*operand1;
break;
case '/':
res=operand2/operand1;
break;
case '$':
case '^':
res=pow(operand2,operand1);
break;
}
push(res);
}
}
while (top!=-1)
{
result=pop();
}
printf("Result of prefix evaluation: %d\n", result);
}
