#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


 void leftrotate(vector<int> &arr,int k){
    int n=arr.size();
    k = k % n;
    vector<int> temp;
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    int j=0;
    for(int i=n-k;i<n;i++){
        arr[i]=temp[j];
        j++;
    }
}

void rightrotate(vector<int> &arr,int k){
    int n=arr.size();
    k=k%n;
    vector<int> temp;
    for(int i=k+1;i<n;i++){
        temp.push_back(arr[i]);
        
    }
    for(int i=0;i<n-k;i++){
        arr[n-i-1]=arr[k-i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
}


void arrange(vector<int> &arr){
    vector<int> pos,neg;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] < 0){
            neg.push_back(arr[i]);
        }else{
            pos.push_back(arr[i]);
        }
    }
    int index=0;
    for(int i=0;i<arr.size()/2;i++){
        arr[(2*i)]=pos[index];
        arr[(2*i)+1]=neg[index];
        index++;
    }


}

void arrange2(vector<int> &arr){
    int pos=0;
    int neg=1;
    int n=arr.size();
    vector<int> ans(n,0);
    for(int i=0;i<arr.size();i++){
        if(arr[i] > 0){
            ans[pos] = arr[i];
            pos+=2;
        }else{
            ans[neg]=arr[i];
            neg+=2;
        }
    }
    print(ans);
}

void leaders(vector<int> arr){
    vector<int> ans;
    int n=arr.size();
    int maxi=-323555;
    for(int i=n-1;i>0;i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }

    print(ans);
}

int main(){
    vector<int> arr = {1,2,3,2};
    // rightrotate(arr,3);
    // arrange2(arr);
    leaders(arr);
    // print(arr);
    return 0;
}