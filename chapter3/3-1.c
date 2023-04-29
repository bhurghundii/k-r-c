#include <stdio.h>

int binsearch_doublecheck(int x, int v[], int n);
int binsearch_singlecheck(int x, int v[], int n);

int main (){

}

int binsearch_singlecheck(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n -1;
    // this strategy just moves Low until its larger than High
    // in which that case, its == x if x exists in the partition
    while (low < high)
    {
       if (x > v[mid])
			low = mid + 1;
		else 
        // if x  <= v[mid], 
        // we can guarantee its not in the top partion
        // as x is less than the midpoint
			high = mid;
    }
    return (x == v[low]) ? low : -1;
    
}

int binsearch_doublecheck(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid]){
            high = mid + 1;
        }
        else if (x > v[mid]){
            low = mid + 1;
        } 
        else {
            return mid;
        }
        return -1; // means no match
    }
    
}
