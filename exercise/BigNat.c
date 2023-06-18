/*BigNat类型数组使用下标逆序（0到k-1位分别对应最低位到最高位）存大整型数，300!估计不到700位，故令LG_MAX=700*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#define BOOL int//定义布尔型变量
#define TRUE 1
#define FALSE 0
#define LG_MAX 700
typedef int BigNat[LG_MAX];//定义一个新的的数据类型BigNat，和数组类型
void lire(int N,int k,BigNat n);//定义一个读取BigNat类型的子程序
void ecrire(int k,BigNat n);//定义一个打印BigNat类型的子程序
int additionner(int k_a,int k_b,BigNat a,BigNat b,BigNat sum);//实现BigNat类型整数加法运算
int soustraire(int k_a,int k_b,BigNat a,BigNat b,BigNat diff);//实现BigNat类型整数减法运算
int multiplier(int k_a,int k_b,BigNat a,BigNat b,BigNat product);//实现BigNat类型整数乘法运算
int diviser(int k_a,int k_b,BigNat a,BigNat b,BigNat div);//实现BigNat类型整数除法运算
int modulo(int k_a,int k_b,BigNat a,BigNat b,BigNat mod);//实现BigNat类型整数求模运算
int factorielle(int n,BigNat fac);//实现BigNat类型整数阶乘运算
BOOL comparaisons(int k_a,int k_b,BigNat a,BigNat b,char *c);//实现BigNat类型整数比较
void initialisation(int k,BigNat a);//实现BigNat类型整数初始化存入
int calculate_bits(BigNat a);//计算数组存入数字的实际位数
int main(void){
    int N,len=0;
    BigNat fac;
    scanf("%d",&N);
    assert(N>0);//保证正整数N为合法输入
    initialisation(LG_MAX,fac);//初始化fac数组
    len=factorielle(N,fac);//得到用BigNat类型表示的阶乘结果fac和位数len
    ecrire(len,fac);//将BigNat类型的fac由最高位到最低位在屏幕上打印出来，共有len位数字
    return EXIT_SUCCESS;
}
void lire(int N,int k,BigNat n){
    for(int i=0;i<k;i++){
        n[i]=(N/(int)pow(10,i))%10;//按数组下标顺序存入从个位到最高位的每一位十进制数字
    }
//不确定是否能返回数组n，目前一种方法是使用realloc()来动态分配内存，存疑？(已解决)
}
void ecrire(int k,BigNat fac){
    for(int i=k-1;i>=0;i--){
        printf("%d",fac[i]);//按照数组下标顺序从最高位到个位依次打印出来
    }
}
int additionner(int k_a,int k_b,BigNat a,BigNat b,BigNat sum){
    int i,counter,len,k=0;
    int carry=0;//进位，计数器，数组长度初始化
    k=__max(k_a,k_b);//取a,b中位数更大的一个做位数
    initialisation(k,a);
    initialisation(k,b);
    for(i=0;i<k;i++){
        counter++;
        carry=(a[i]+b[i])/10;//计算a,b两个数的第i位数相加后是否进位
        sum[i+1]=sum[i+1]+carry;//给下一位（i+1）进位
        sum[i]=sum[i]+(a[i]+b[i])%10;//此处*sum是初始化为零的数组
        if(carry>0&&i==k-1){
            counter++;
            break;
        }
    }
    len=counter;
    return len;
}
int soustraire(int k_a,int k_b,BigNat a,BigNat b,BigNat diff){
    int i,counter,len,k=0;
    int borrow=0;
    k=__max(k_a,k_b);//取a,b中位数更大的一个做位数
    for(i=0;i<k;i++){
        counter++;
        borrow=1;//借位时，高一位借一
        diff[i]=a[i]-b[i];
        if(a[i]-b[i]<0){//需要借位的情况下
            diff[i+1]=diff[i+1]-borrow;
            diff[i]=diff[i]+10*borrow;
            if(diff[i+1]==0&&i==k-1){//最高位借位后为零，位数减一位 
                counter--;
                break;
            }
        }
        else{
            diff[i]=(a[i]-b[i]);
        }
    }
    len=counter;
    return len;
}
int multiplier(int k_a,int k_b,BigNat a,BigNat b,BigNat product){
    int i,j,counter,len=0;
    for(i=0;i<k_a;i++){
        for(j=0;j<k_b;j++){
            counter++;
            if((a[i]*b[j])/10==0)//第i位与第j位数的乘法不进位
            product[i+j+1]=(a[i]*b[j])%10;
            else{//第i位与第j位数相乘后向i+j+1位进位
                product[i+1]=product[i+1]+(a[i]*b[j])/10;
                product[i]=product[i]+(a[i]*b[j])%10;//数组*product要初始化为零
                if(i==k_a-1&&j==k_b-1){//判定在a,b两个数的最高位相乘时进位，位数加一
                    counter++;
                    break;
                }
            }
        }
    }
    len=counter;
    return len;
}
int diviser(int k_a,int k_b,BigNat a,BigNat b,BigNat div){
    int i,counter,len,k,move=0;
    k=fmax(k_a,k_b);
    initialisation(k,div);
    if(comparaisons(k_a,k_b,a,b,"<"))//被除数小于除数
    div[0]=0;
    else if(comparaisons(k_a,k_b,a,b,"="))//被除数等于除数
    div[0]=1;
    else{
        //确定移位的位数
        while(comparaisons(k_a,k_b,a,b,">")){
            for(int i=0;i<k;i++){
                b[i+1]=b[i];//移位
            }
            b[0]=0;//补零
            move++;
        }//将b[]移位来快速减法
        for(i=0;i<k;i++){
            a[i]=a[i]-b[i];
        }
        for(int j=0;j<move;j++){
            for(i=0;i<k;i++){
                    b[i+1]=b[i];//移位
                }
                b[i]=0;//补零
        }//将b[]复原
        while(comparaisons(k_a,k_b,a,b,">")){
            for(i=0;i<k;i++){
                a[i]=a[i]-b[i];
            }
            if(comparaisons(k_a,k_b,a,b,"<")){
                break;
            }
            counter++;
        }
        len=abs(k_a-k_b);
        lire(pow(10,move)+counter,len,div);
    }
    return len;
}
int modulo(int k_a,int k_b,BigNat a,BigNat b,BigNat mod){
    int k,len,len_div=0;
    BigNat div;
    k=abs(k_a-k_b);
    initialisation(k,div);
    len_div=diviser(k_a,k_b,a,b,div);
    len=soustraire(k_a,len_div,a,div,mod);
    return len;
}
BOOL comparaisons(int k_a,int k_b,BigNat a,BigNat b,char *c){
    int k=0;
    int temp;
    k=fmax(k_a,k_b);
    if(strcmp(c,"<")){
        if(k_a<=k_b)
        for(int i=k-1;i>=0;i--){
            if (a[i]<b[i])
            temp=EXIT_SUCCESS;
            else if (a[i]==b[i])
            continue;
            else
            temp=EXIT_FAILURE;
        }
        else
        temp=EXIT_FAILURE;      
    }
    else if(strcmp(c,"=")){
        for(int i=k-1;i>=0;i--){
            if(a[i]==b[i]){
                if(i==0)
                temp=EXIT_SUCCESS;
                else 
                continue;
            }
            else
            temp=EXIT_FAILURE;
        }
    }
    else if(strcmp(c,">")){
        for(int i=k-1;i>=0;i--){
            if(a[i]>b[i]){
                if(i==0){
                    temp=EXIT_SUCCESS;
                }
                else
                continue;
            }
            else
            temp=EXIT_FAILURE;
        }
    }
    else if(strcmp(c,"<=")){
        for(int i=k-1;i>0;i--){
            if(a[i]<=b[i]){
                if(i==0){
                    temp=EXIT_SUCCESS;
                }
                else
                continue;
            }
            else
            temp=EXIT_FAILURE;
        }
    }
    else if(strcmp(c,">=")){
        for(int i=k-1;i>0;i--){
            if(a[i]>=b[i]){
                if(i==0){
                    temp=EXIT_SUCCESS;
                }
                else
                continue;
            }
            else
            temp=EXIT_FAILURE;
        }
    }
    else if(strcmp(c,"!=")){
        for(int i=k-1;i>0;i--){
            if(a[i]!=b[i]){
                if(i==0){
                    temp=EXIT_SUCCESS;
                }
                else
                continue;
            }
            else
            temp=EXIT_FAILURE;
        }
    }
    else{
    return EXIT_FAILURE;
    }
    return temp;
}
int factorielle(int n,BigNat fac){
    int i,j,carry,bits,temp=0;
    fac[0]=1;
    bits=1;
    for(i=2;i<=n;i++){
        carry=0;//进位归零
        for(j=0;j<bits;j++){
            temp=fac[j]*i+carry;//将一个数的每一位数字乘上i
            fac[j]=temp%10;//将一个数的每一位数字用fac数组存入
            carry=temp/10;
        }
        while(carry){//保证退出循环时，carry为零
            fac[bits]=carry%10;
            carry=carry/10;
            bits++;
        }
    }
    return bits;
}
void initialisation(int k,BigNat a){
    for(int i=0;i<k;i++){//循环变量i从0递增到最高位
        a[i]=0;
    }
}
int calculate_bits(BigNat a){
    int len,i,counter=0;
    for(i=LG_MAX-1;i>=0;i--){//循环变量i从699递减到0
        if(a[i]==0)
        counter++;
        else
        break;
    }
    len=LG_MAX-counter;
    return len;
}
