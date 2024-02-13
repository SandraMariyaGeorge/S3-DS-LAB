#include <stdio.h>
void main()
{
	int i, n, a[50], low, high, flag, mid, key, pos;
	printf("Enter the no. of elements\n");
	scanf("%d", &n);
	printf("Enter the array elements(sorted)\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d", &key);
	low = 0;
	high = n - 1;
	flag = 0;

	mid = (low + high) / 2;
	while (low <= high)
	{
		if (a[mid] == key)
		{
			pos = mid;
			flag = 1;
			break;
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	printf("The Entered Array is \n");
	for (i = 0; i < n; i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	if (flag == 1)
	{
		printf("Element found at %d\n", pos);
	}
	else
	{
		printf("Element not found\n");
	}
}