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

int balancedStringSplit(string s){
	int ans=0,d=0;
	for(char ch:s){
		ch=='L'?++d:--d;
		if(d==0)++ans;
	}
	return ans;
}

int main(){
	string s="RLRRLLRLRL";
	cout<<balancedStringSplit(s);
	return 0;
}
/*
在遍历s时用一个变量d维护L和R字符的数量之差，当d=0时就说明找到了一个平衡字符串，将答案加一。
*/