#include<iostream>
using namespace std;

class knapSack{
    public:
    int weight;
    int profit;
};


int solve(knapSack arr[], int n, int w){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((arr[i].profit / arr[i].weight) < (arr[i].profit / arr[i].weight)){
                knapSack temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i].weight <= w){
            count += arr[i].profit;
            w = w - arr[i].weight;
        }
        else if(arr[i].weight > w){
            int part = arr[i].profit / arr[i].weight;
            count += part*w;
            break;
        }
    }
    return count;
}

int main(){
    int n, w;
    cout<<"Enter the number of KnapSack :"<<endl;
    cin>>n;
    cout<<"Enter the maximum weight of bag: ";
    cin>>w;
    knapSack arr[n];

    for(int i=0; i<n; i++){
        cout<<"Enter weight of KnapSack : ";
        cin>>arr[i].weight;
        cout<<"Enter Profit : ";
        cin>>arr[i].profit;
    }

    cout<<"Maximum Profit : "<<solve(arr, n, w);
    
return 0;
}