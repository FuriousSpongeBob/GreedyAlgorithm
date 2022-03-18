/*
给你一个四位正整数num。请你使用num中的数位 ，将num拆成两个新的整数new1和new2。new1和new2中可以有前导0，且num中所有数位都必须使用。
比方说，给你num = 2932，你拥有的数位包括：两个2，一个9和一个3。一些可能的[new1, new2]数对为[22, 93]，[23, 92]，[223, 9] 和[2, 329]。
请你返回可以得到的new1和new2的最小和。

1000 <= num <= 9999
*/

/*
test case:
输入：num = 2932
输出：52
解释：29 + 23 = 52 。

输入：num = 4009
输出：13
解释：04 + 09 = 13 。
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minimumSum(int num){
	vector<int> digits;
	digits.push_back(0);//填充
	int new1;
	int new2;
	int minSum=INT_MAX;
	while(num){
		digits.push_back(num%10);
		num/=10;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(j!=i){
				for(int k=1;k<=4;k++){
					if(k!=i&&k!=j){
							for(int p=1;p<=4;p++){
								if(p!=i&&p!=j&&p!=k){
									new1=digits[i]*10+digits[j];
									// cout<<"new1: "<<new1<<endl;
									new2=digits[k]*10+digits[p];
									// cout<<"new2: "<<new2<<endl;
									// cout<<"new1+new2: "<<new1+new2<<endl;
									minSum=((new1+new2)<minSum)?new1+new2:minSum;
									// cout<<"minSum: "<<minSum<<endl;
								}
							}
					}
				}
			}		
		}
	}		
	return minSum;
}

int main(){
	cout<<minimumSum(4009);
	return 0;
}