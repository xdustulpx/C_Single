/*BigNat类型数组使用下标逆序（0到k-1位分别对应最低位到最高位）存大整型数，300!估计不到700位，故令LG_MAX=700*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define LG_MAX 700
typedef int BigNat[LG_MAX];//定义一个新的的数据类型BigNat，和数组类型
BigNat* lire(int N,int k);//定义一个读取BigNat类型的子程序
void ecrire(BigNat fac[],int k);//定义一个打印BigNat类型的子程序
int additionner(BigNat* a,BigNat* b,BigNat* sum);//实现BigNat类型整数加法运算
int soustraire(BigNat* a,BigNat* b,BigNat* diff);//实现BigNat类型整数减法运算
int multiplier(BigNat* a,BigNat* b,BigNat* product);//实现BigNat类型整数乘法运算
int diviser(BigNat* a,BigNat* b,BigNat* div);//实现BigNat类型整数除法运算
int modulo(BigNat* a,BigNat* b,int k,BigNat* mod);//实现BigNat类型整数求模运算
int factorielle(BigNat* n,BigNat* fac);//实现BigNat类型整数阶乘运算
int comparaisons(BigNat* a,BigNat* b,int k,char* c);//实现BigNat类型整数比较
void initialisation(BigNat* a,int k);//实现BigNat类型整数初始化存入
int main(void){
    int N,bits,len=0;
    scanf("%d",&N);
    assert(N);
    bits=log10(abs(N))+1;//求整数N的十进制位数（BigNat类型数组的位数）
    BigNat n[bits],fac[LG_MAX];
    initialisation(n,bits);
    initialisation(fac,LG_MAX);//初始化数组
    n=lire(N,bits);
    len=factorielle(n,fac);
    ecrire(fac,len);
    return EXIT_SUCCESS;
}
BigNat* lire(int N,int k){
    BigNat n[k];
    for(int i=0;i<k;i++){
        n[i]=(N/(int)pow(10,i))%10;//按数组下标顺序存入从个位到最高位的每一位十进制数字
    }
   return n;//不确定是否能返回数组n，目前一种方法是使用realloc()来动态分配内存，存疑？
}
void ecrire(BigNat fac[],int k){
    for(int i=k-1;i>=0;i--){
        printf("%d",fac[i]);
    }
}
int additionner(BigNat* a,BigNat* b,BigNat* sum){
    int i,k,bit_a,bit_b,counter,len=0;
    bit_a=sizeof(a)/sizeof(*a);//求出a的位数
    bit_b=sizeof(b)/sizeof(*b);//求出b的位数
    int carry=0;//进位，计数器，数组长度初始化
    k=__max(bit_a,bit_b);//取a,b中位数更大的一个做位数
    for(i=0;i<k;i++){
        counter++;
        carry=((int)(*(a+i))+(int)(*(b+i)))/10;//计算a,b两个数的第i位数相加后是否进位
        (int)*(sum+i+1)+=carry;//给下一位（i+1）进位
        (int)(*(sum+i))+=(*(a+i)+(*(b+i)))%10;//此处*sum是初始化为零的数组
        if(carry>0&&i==k-1){
            counter++;
            break;
        }
/**version 1.0
        (sum+i)=(*(a+i)+*(b+i))%10;
        else if(carry==1&&i==1){
            *(sum+i)=(*(a+i)+*(b+i))%10;
            *(sum+i+1)+=carry;
        }
        else{//第i位相加后向i+1位进位
            carry=(*(a+i-1)+*(b+i-1))/10;//计算a,b两个数的第i位数相加后是否进位
            *(sum+i)=(*(a+i)+*(b+i)+carry)%10;
            *(sum+i+1)+=carry;
            if(i=k-1){
                counter++;
                break;//两个数的最高位相加后，进位情况下，最高位进一位
            }
        }*/
    }
    len=counter;
    return len;
}
int soustraire(BigNat* a,BigNat* b,BigNat* diff){
    int i,k,bit_a,bit_b,counter,len=0;
    bit_a=sizeof(a)/sizeof(*a);//求出a的位数
    bit_b=sizeof(b)/sizeof(*b);//求出b的位数
    int borrow=0;
    k=__max(bit_a,bit_b);//取a,b中位数更大的一个做位数
    for(i=0;i<k;i++){
        counter++;
        borrow=1;//借位时，高一位借一
        diff[i]=a[i]-b[i];
      if(a[i]-b[i]<0){//需要借位的情况下
            diff[i+1]-=borrow;
            diff[i]+=10*borrow;
            if(diff[i+1]==0&&i==k-1){//最高位借位后为零，位数减一位 
                counter--;
                break;
            }
      }
      else{
        *(diff+i)=(*(a+i)-*(b+i));
      }
/***version 1.0
            if(*(*(a+i-1)-*(b-i-1)-borrow<0)){
            *(diff+i)=abs(10+*(a+i)-*(b+i)-borrow)%10;
            }
        }
        else if(*(a+i)-*(b+i)-borrow==0){
            *(diff+i)=0;
            if(i==k-1){//最高位借位后为零，位数减一位 
                counter--;
                break;
            }
        }
        else{
            *(diff+i)=*(a+i)-*(b+i);
        }*/
    }
    len=counter;
    return len;
}
int multiplier(BigNat* a,BigNat* b,BigNat* product){
    int i,j,bit_a,bit_b,counter,len=0;
    bit_a=sizeof(a)/sizeof(*a);//求出a的位数
    bit_b=sizeof(b)/sizeof(*b);//求出b的位数
    for(i=0;i<bit_a;i++){
        for(j=0;j<bit_b;j++){
            counter++;
            if(((*(a+i))*(*(b+j)))/10=0)//第i位与第j位数的乘法不进位
            *(product+i+j)=(*(a+i)*(*(b+j)))%10;
            else{//第i位与第j位数相乘后向i+j+1位进位
                *(product+i+1)+=(*(a+i)**(b+j))/10;
                *(product+i)+=(*(a+i)**(b+j))%10;//数组*product要初始化为零
                if(i==bit_a-1&&j==bit_b-1){//判定在a,b两个数的最高位相乘时进位，位数加一
                    counter++;
                    break;
                }
            }
        }
    }
    len=counter;
    return len;
}
int diviser(BigNat* a,BigNat* b,BigNat* div){
    int bit_a,bit_b,counter,len=0;
    bit_a=sizeof(a)/sizeof(*a);//求出a的位数
    bit_b=sizeof(b)/sizeof(*b);//求出b的位数

}
/// @brief 
/// @param a 
/// @param b 
/// @param k 
/// @param mod 
/// @return 
int modulo(BigNat* a,BigNat* b,int k,BigNat* mod){
    int i,bit_a,bit_b,len=0;
    bit_a=sizeof(a)/sizeof(*a);//求出a的位数
    bit_b=sizeof(b)/sizeof(*b);//求出b的位数
    k=__max(bit_a,bit_b);
    for(i=0;i<k;i++){
        soustraire(a,b);
        if(comparaisons(a,b,'<')){
            *mod=*a;
        }
        break;
    }
    len=sizeof(mod)/sizeof(*mod);
    return len;
}
int comparaisons(BigNat* a,BigNat* b,int k,char c){
    if(c=='<'){
        for(int i=k-1;i>=0;i--){
            if (a[i]<b[i])
            return EXIT_SUCCESS;
            else if (a[i]==b[i])
            continue;
            else
            return EXIT_FAILURE;
        }       
    }
    if(c=='='){
        for(int i=k-1;i>=0;i--){
            if(a[i]==b[i]){
                continue;
                if(i==0)
                return EXIT_SUCCESS;
            }
            else
            return EXIT_FAILURE;
        }
    }
    if(c=='>'){
        for(int i=k-1;i>=0;i--){
            if(a[i]>b[i]){
                continue;
                if(i==0){
                    return EXIT_SUCCESS;
                }
            }
            else
            return EXIT_FAILURE;
        }
    }
    if(c=='<='){
        for(int i=k-1;i>0;i--){
            if(a[i]<=b[i]){
                continue;
                if(i==0){
                    return EXIT_SUCCESS;
                }
            }
            else
            return EXIT_FAILURE;
        }
    }
    if(c=='>='){
        for(int i=k-1;i>0;i--){
            if(a[i]>=b[i]){
                continue;
                if(i==0){
                    return EXIT_SUCCESS;
                }
            }
            else
            return EXIT_FAILURE;
        }
    }
    if(c=='!='){
        for(int i=k-1;i>0;i--){
            if(a[i]!=b[i]){
                continue;
                if(i==0){
                    return EXIT_SUCCESS;
                }
            }
            else
            return EXIT_FAILURE;
        }
    }
}
int factorielle(BigNat* n,BigNat* fac){
    int len=0;
    fac[LG_MAX]=0;
    for(BigNat* i=0;comparaisons(i,n,'<');i++){
        *fac=multiplier(fac,n);
    }
    len=sizeof(fac)/sizeof(*fac);
    return len;
}
void initialisation(BigNat* a,int k){
    for(int i=0;i<k;i++){
        a[i]=0;
    }
}
