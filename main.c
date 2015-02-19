#include <stdio.h>
#include <stdbool.h>

bool bsearch(int *buf, int buf_size, int n, int *pos){
  // sanity check
  if(buf_size <= 0){
    *pos = -1;
    return false;
  }

  // check if first elem is answer
  if(buf[0] > n){
    *pos = 0;
    return true;
  }
  
  int left = 0, right = buf_size;
  while(true){
    int curr = (right - left)/2 + left;
    
    if(buf[curr] > n){
      right = curr;
    }else{
       left = curr;
    }
    // printf("[%i-%i]\n", left, right); // DBG

    if((right - left) == 1){ // search finished      
      if(buf[right] > n){
	 *pos = right;
	 return true;
      }else{	// end reached, no answer found
	*pos = -1;
	 return false;
      }
    }
  }
}

int main(){
  int buf[] = {0,1,1,2,3,3,4,5,6,10};
  int pos = 0;
  bool res;
  
  res = bsearch(buf, sizeof(buf)/sizeof(int), -1, &pos);
  printf("Test 1 res is %d pos is %d\n", res, pos);
  
  res = bsearch(buf, sizeof(buf)/sizeof(int), 2, &pos);
  printf("Test 2 res is %d pos is %d\n", res, pos);

  res = bsearch(buf, sizeof(buf)/sizeof(int), 10, &pos);
  printf("Test 3 res is %d pos is %d\n", res, pos);

  res = bsearch(buf, sizeof(buf)/sizeof(int), 7, &pos);
  printf("Test 4 res is %d pos is %d\n", res, pos);

  return 0;
}
      
  
