#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum1( int A[], int N );
int MaxSubseqSum2( int A[], int N );
int MaxSubseqSum3( int List[], int N );
int MaxSubseqSum4 (int List[], int N );
int main()
{

    int a[8] = {-1,3,-2,4,-6,1,6,-1};
    int max = 0;

//   max = MaxSubseqSum1(a,8);
//   max = MaxSubseqSum2(a,8);
    max = MaxSubseqSum3(a,8);
    printf("%d",max);



    return 0;
}



//�������
int MaxSubseqSum1( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for( i = 0; i < N; i++ )
    {
        for( j = i; j < N; j++ )
        {
            ThisSum = 0;
            for( k = i; k <= j; k++ )
            {
                ThisSum += A[k];
            }

            if( ThisSum > MaxSum )
                MaxSum = ThisSum;

        }
    }
    return MaxSum;
}

//ȥ����һ��ѭ��
int MaxSubseqSum2( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for( i = 0; i < N; i++ )
    {
        ThisSum = 0;
        for( j = i; j < N; j++ )
        {
            ThisSum += A[j];
            if( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}


//�ֶ���֮ �����õݹ�
int Max3( int A, int B, int C )
{ /* ����3�������е����ֵ */
    //return A > B ? A > C ? A : C : B > C ? B : C;
    if(A>B)
    {
        if(A>C)

            return A;
        else
            return C;
    }
    else
    {
        if(B>C)

            return B;
        else
            return C;
    }


}




int DivideAndConquer( int List[], int left, int right )
{ //���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; //�������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; //��ſ�ֽ��ߵĽ��

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )
    { // �ݹ����ֹ����������ֻ��1������
        if( List[left] > 0 )
            return List[left];
        else
            return 0;
    }

    //������"��"�Ĺ��� */
    center = ( left + right ) / 2; //�ҵ��зֵ�
    //�ݹ�����������е�����
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    // �������ֽ��ߵ�������к�
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- )
    {
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ )
    {
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    printf("%d  %d  %d\n",MaxLeftSum,MaxRightSum,MaxLeftBorderSum + MaxRightBorderSum);
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int List[], int N )
{
    return DivideAndConquer( List, 0, N-1 );
}


//��̬�滮
int MaxSubseqSum4 (int List[], int N )
{
    int sum = 0,i = 0;
    int maxsum = 0;
    for(i = 0;i < N;i++)
    {
        sum += List[i];
        if(maxsum < sum)
        {
            maxsum = sum;
        }
        if (sum < 0)
            sum = 0;
    }

return maxsum;
}












