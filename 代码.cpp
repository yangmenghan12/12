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

                printf("���:%d����λ�ɽӴ�%d��\n", A[i].num, cnt);

                A[i].cnt = A[i].cnt - cnt;

                if (A[i].cnt == 0)

                    A[i].stat = 1;

                return A[i].num;

            }

        }

    }

    printf("�Ҳ����ɽӴ�%d���˵���λ\n", cnt);

    return -1;

}

int zengjia(int n) {

    int d;

    scanf("%d", &d);//��ӵ���λ����������

    A[n].num = n + 1;

    A[n].cnt = d;

    A[n].stat = 0;

    return n + 1;

}

int shanjian(int n) {

    int d;

    scanf("%d", &d);//Ҫɾ�����ӵı��

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

    int sum, sum1;//�任��������

    int f;//�����˹���

    scanf("%d", &n);//ԭ��������

    sum = sum1 = n;

    printf("fΪ1ʱ���в��ң�\n");

    printf("fΪ2ʱ��������;\n");

    printf("fΪ3ʱ����ɾ��;\n");

    printf("fΪ4ʱ ����\n");

    while (1)

    {

        scanf("%d", &f);

        if (f == 1) {

            printf("�����뵱ǰ��Ҫ�Ӵ��Ĺ˿���:\n");

            scanf("%d", &cnt);

            num = find(cnt, n);

            if (-1 == num)

            {

                printf("\n");

                continue;

            }

        }//��λ��

        else if (f == 2) {

            sum1 = zengjia(sum);

            if (sum1 == n + 1) {

                printf("���ӳɹ�");

            }

        }//��������

        else if (f == 3) {

            sum1 = shanjian(sum);

            if (n == sum1 + 1) {

                printf("���ٳɹ�");

            }

        }//ɾ������

        else if (f == 4)break;

        else {

            printf("û���������������������");

        }

    }

    return 0;

}

