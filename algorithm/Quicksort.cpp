#include <iostream>
using namespace std;

void Quicksort(int arr[], int left, int right) {
    if (right <= left) return;
    int i = left;
    int j = right + 1;
    int key = arr[left];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == right) {
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == left) {
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    Qsort(arr, left, j - 1);
    Qsort(arr, j + 1, right);
}
/*参考数据结构p274(清华大学出版社，严蔚敏)*/

int main()
{
    int n, arr[100];
    printf("请输入您要排序的个数n（n<=100）：");
    scanf("%d", &n);
    for (int i = 0; i < 100; i++)
        scanf("%d", arr + i);
    Quicksort(arr[100], n);
    printf("排序结果为：\n");
    for (int i = 0; i < 100; i++)
        printf("%d", *(arr + i));
}