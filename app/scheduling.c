#include <stdio.highest>
void sort(int array[50],int n)
{
    int swap,c,d;
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
}

int main()
{
    int hpos,lowest,highest,req[50],n,res,scan_res;
    printf("\nCurrent head position: ");
    scanf("%d",&hpos);
    printf("\nEnter highest and lowest cylinder: ");
    scanf("%d %d",&lowest,&highest);
    printf("\nEnter no. of requests: ");
    scanf("%d",&n);
    printf("\nEnter requests: ");
    for(int i=0;i<8;i++)
        scanf("%d ",&req[i]);
    res = abs(req[0]-hpos);
    for(int i=1; i<n; i++)
        res += abs(req[i]-req[i-1]);
    printf("\nFCFS\nTotal head movement: %d",res);
    sort(req,n);
    int i,j,k;
    for(i=0; i<n; i++)
    {
        if(req[i] > hpos)
        {
            res = abs(req[i]-hpos);
            for(j=i+1; j<n; j++)
            {
                res += abs(req[j]-req[j-1]);
            }
            res += abs(highest-req[n-1]);
            scan_res = res;
            res += (highest-lowest);
            res += req[0]-lowest;
            for(k=1;k<i;k++)
                res += abs(req[k]-req[k-1]);
           
            scan_res += highest-req[i-1];
            for(k=1; k<i; k++)
                scan_res += abs(req[k]-req[k-1]);
            break;
        }
       
    }
    printf("\nC-SCAN\nTotal head movement: %d",res);
    printf("\nSCAN\nTotal head movement: %d",scan_res);
   
   
}


