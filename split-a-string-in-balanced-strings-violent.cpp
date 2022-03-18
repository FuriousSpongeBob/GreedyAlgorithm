/*
在一个平衡字符串中，'L' 和 'R' 字符的数量是相同的。
给你一个平衡字符串s，请你将它分割成尽可能多的平衡字符串。
注意：分割得到的每个字符串都必须是平衡字符串，且分割得到的平衡字符串是原平衡字符串的连续子串。
返回可以通过分割得到的平衡字符串的最大数量 。
*/

/*
test cases:
输入：s = "RLRRLLRLRL"
输出：4
解释："RL"、"RRLL"、"RL"、"RL" 

输入：s = "LLLLRRRR"
输出：1
解释：只能保持原样 "LLLLRRRR".
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int RC,LC,StrC;

int balancedStringSplit(string s){
	for(auto it=s.begin();it<s.end();it++){
		if(*it=='L'){
			LC++;
			if(RC==LC){
				StrC++;
				LC=0;
				RC=0;
			}
		}
		else{
			RC++;
			if(RC==LC){
				StrC++;
				LC=0;
				RC=0;
			}
		}
	}
	return StrC;
}

int main(){
	string s="LLLLRRRR";
	cout<<balancedStringSplit(s);
	return 0;
}