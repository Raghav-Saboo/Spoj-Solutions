#include <stdio.h>
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right);
long long int mer_sort(long long int arr[],long long int left,long long int right)
{
	long long  int mid, inv_count = 0,temp[10000],f=10000007;
  	if (right > left)
  	{
    	mid = (right + left)/2;
    	inv_count  = mer_sort(arr, left, mid);
    	inv_count%=f;
    	inv_count = inv_count + mer_sort(arr, mid+1, right);
    	inv_count%=f;
		inv_count += merge(arr, temp, left, mid+1, right);
		inv_count%=f;
  	}
	 return inv_count;
}
  
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right)
{
  long long int i, j, k;
  long long int inv_count = 0;
  
  i = left; 
  j = mid;  
  k = left; 
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
      inv_count%=10000007;
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  while (j <= right)
    temp[k++] = arr[j++];
  
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}
int main(void) {
	// your code goes here
	long long int t,n,a[10000],i=0,l;
	scanf("%lld",&t);
	while(t--)
	{
		l++;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		printf("Case %lld: %lld\n",l,mer_sort(a,0,n-1));
	}
	return 0;
}
