#include <iostream>

#include<string>

#include<stdio.h>

#include<malloc.h>

typedef struct aaa

{

    int num;

    int cnt;

    int stat;

}AAA_T;

AAA_T A[20] =

{

    {1, 2, 0},

    {2, 2, 0},

    {3, 2, 0},

    {4, 2, 0},

    {5, 2, 0},

    {6, 4, 0},

    {7, 4, 0},

    {8, 4, 0},

    {9, 4, 0},

    {10, 6, 0}

};

int find(int cnt, int n)

{

    int i = 0;

    for (i = 0; i < n; i++)

    {



        if (0 == A[i].stat)

        {



            if (A[i].cnt >= cnt)

            {

                printf("编号:%d的座位可接待%d人\n", A[i].num, cnt);

                A[i].cnt = A[i].cnt - cnt;

                if (A[i].cnt == 0)

                    A[i].stat = 1;

                return A[i].num;

            }

        }

    }

    printf("找不到可接待%d个人的座位\n", cnt);

    return -1;

}

int zengjia(int n) {

    int d;

    scanf("%d", &d);//添加的座位能做多少人

    A[n].num = n + 1;

    A[n].cnt = d;

    A[n].stat = 0;

    return n + 1;

}

int shanjian(int n) {

    int d;

    scanf("%d", &d);//要删除桌子的标号

    int i = 0, j = 0;

    for (i = 0; i < n; i++) {

        if (A[i].num == d) {

            for (j = d; j < n; j++) {

                A[j] = A[j + 1];

            }

        }



    }

    return n - 1;



}





int main()

{

    int cnt = 0;

    int num = 0;

    int i = 0;

    int n;

    int sum, sum1;//变换后桌子数

    int f;//代表了功能

    scanf("%d", &n);//原有桌子数

    sum = sum1 = n;

    printf("f为1时进行查找；\n");

    printf("f为2时进行增加;\n");

    printf("f为3时进行删除;\n");

    printf("f为4时 结束\n");

    while (1)

    {

        scanf("%d", &f);

        if (f == 1) {

            printf("请输入当前需要接待的顾客数:\n");

            scanf("%d", &cnt);

            num = find(cnt, n);

            if (-1 == num)

            {

                printf("\n");

                continue;

            }

        }//找位置

        else if (f == 2) {

            sum1 = zengjia(sum);

            if (sum1 == n + 1) {

                printf("增加成功");

            }

        }//增加桌子

        else if (f == 3) {

            sum1 = shanjian(sum);

            if (n == sum1 + 1) {

                printf("减少成功");

            }

        }//删减桌子

        else if (f == 4)break;

        else {

            printf("没有这个操作，请重新输入");

        }

    }

    return 0;

}

