#include<stdio.h>
#include<stdlib.h>
struct sub{
int mse1;
int mse2;
int mse3;
int la1;
int la2;};

int main()
{
    struct sub s[5];
    float sum[5],c;
    char *ch,sel[1];

    do{
    printf("select chem for chemistry cycle and phy for physics cycle\n");
    scanf("%s",ch);
    if(ch[0]=='p')
        printf("welcome to our cie program \nsubject1:maths\nsubject2:physics\nsubject3:ele\nsubject4:eme\nsubject5:cp\nint the following order mse1,mse2,mse3,la1,la2");
    else if(ch[0]=='c')
        printf("welcome to our cie program \nsubject1:maths\nsubject2:chemistry\nsubject3:eln\nsubject4:em\nsubject5:cp\nint the following order mse1,mse2,mse3,la1,la2");
    else{
        printf("error no such cycle\ntry again with valid cycle name\nthank you :)");
        exit(1);}
    for(int i=0;i<5;i++){
        printf("\nenter the marks for subject%d\n",i+1);
        scanf("%d%d%d%d%d",&s[i].mse1,&s[i].mse2,&s[i].mse3,&s[i].la1,&s[i].la2);
        sum[i]=add(s[i]);
    }
    c=grade(sum);
    printf("the internal cgpa of the student is: %f\n",c/5);
     printf("do you want to continue\nreply y for yes and N for no\n");
    scanf("%s",sel);
}while(sel[0]!='N');
}
add(struct sub a)
{
  float b= bestavg(a.mse1,a.mse2,a.mse3)+a.la1+a.la2;
  return b;
}
grade(float a[])
{   float grade;
    for(int i=0;i<5;i++){
    if(a[i]>45)
    grade+=10;
    else if(a[i]<=45&&a[i]>40)
        grade+=9;
    else if(a[i]<=40&&a[i]>35)
        grade+=8;
    else if(a[i]<=35&&a[i]>30)
        grade+=7;
    else if(a[i]<=30&&a[i]>25)
        grade+=6;
    else if(a[i]<=25&&a[i]>20)
    grade+=5;
    else if(a[i]<=20&&a[i]>15)
        grade+=4;
    }
    return grade;
}
bestavg(int a, int b, int c)
{
    float d;
    if(a>=b&&b>=c)
        d=(a+b)/2;
    else if(b>=c&&c>=a)
        d=(b+c)/2;
    else
        d=(a+c)/2;
    return d;
}

