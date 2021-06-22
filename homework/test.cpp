#include <stdio.h>
int nums[20000];
int max(int a,int b)
{
    return (a > b) ? a : b;
}

int min(int a,int b)
{
    return (a < b) ? a : b;
}

void product(int n)
{
    int ans = nums[0];
    int a[20000][2];
    a[0][0] = a[0][1] = nums[0];
    for (int i = 1; i < n; i ++ )
    {
        a[i][0] = max(nums[i], max(a[i - 1][0] * nums[i], a[i - 1][1] * nums[i]));
        a[i][1] = min(nums[i], min(a[i - 1][0] * nums[i], a[i - 1][1] * nums[i]));
        ans = max(max(a[i][0], a[i][1]), ans);
    }
    printf("%d",ans);
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",&nums[i]);
    product(n);
    return 0;
}
