//
// Created by Administrator on 2020/4/10.
//
#include <iostream>
using namespace std;
void sort(float b[] ,int len){
  int flag =0;
  float temp =0.0;
  for(int i =0;i<len-1;i++){
    flag = 0;
    for(int j=1;j<len-i;j++){
      if(b[j-1]>b[j]) {
        temp = b[j - 1];
        b[j - 1] = b[j];
        b[j] = temp;
        flag = 1;
      }
    }
    if(!flag)
      break;
  }
  return;
}
int main(){
  float a[5]={1,2.2,3.4,1.2,2.1};
  int len = sizeof(a)/sizeof(float);
  sort(a,len);
  for(int i=0;i<len;i++)
    cout<<a[i]<<' ';
  return 0;
}