#include <iostream>
using namespace std;

void PrintIncreasingOrder(int n) {
    // Print numbers in increasing order
    if (n <= 1) {
        cout<<n<<endl;
        return;
    }
    PrintIncreasingOrder(n - 1);
    cout<<n<<endl;
}

void PrintDecreasingIncreasingOrder(int n) {
    //Print numbers in increasing decreasing order
    if (n<=1) {
        cout<<n<<endl;  
        cout<<n<<endl;  
        return ;
    }
    cout<<n<<endl;  
    PrintDecreasingIncreasingOrder(n - 1);
    cout<<n<<endl;
    
}

int Factorial(int n ) {
   if (n<=1){
    return 1;
   } 
   return n * Factorial(n-1);
}

int Power(int x , int n) {
   if (n==0) return 1;
   if (n==1) return x;
   return x * Power(x,n-1);
}
int LogPower(int x, int n) {
    if (n==0) return 1;
    if (n==1) return x;
    int temp = LogPower(x,n/2 );
    if (n%2==0) return temp * temp;
    return x*temp*temp;
}
void Towerofhanoi(int n, char A , char B , char C) {
    if (n==0) return;
    Towerofhanoi(n-1,A,C,B);
    cout<<"Move disk "<<n<<" from "<<A<<" to "<<B<<endl;
    Towerofhanoi(n-1,C,B,A);

}

void DisplayArray(int *arr , int n , int index) {
    if (index >= n) return ;
    cout<<arr[index]<<" ";
    DisplayArray(arr,n,index+1);
}
void DisplayArrayInReverse(int *arr, int n ,int index) {
    if (index >= n) return ;
    DisplayArrayInReverse(arr,n,index+1);
    cout<<arr[index]<<" ";
}

int MaxInArray(int *arr, int n, int index) {
    if (index >= n) return INT16_MIN;
    int max = MaxInArray(arr,n,index+1);
    return max > arr[index]? max:arr[index];
}
int main() {
   #ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
    // PrintIncreasingOrder(5);
    // PrintDecreasingIncreasingOrder(5);
    // cout<<Factorial(5)<<endl;
    // cout<<Power(2,10)<<endl;
    // cout<<LogPower(2,12)<<endl;
    // Towerofhanoi(5,'A','B','C');
   int arr[] = {82,20,34,14,76,22};
   int n = sizeof(arr)/sizeof(arr[0]);
    // DisplayArray(arr,n,0);
    // DisplayArrayInReverse(arr,n,0);
    cout<<MaxInArray(arr,n,0);
    return 0;  
}

