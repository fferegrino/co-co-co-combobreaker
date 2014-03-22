#include <string>
#include <iostream>

using namespace std;

bool subSequence(string s, string t){
	int ok = s.size();
	int i, iy = 0;
	for(i = 0; i < t.size(); i++){
		if(t[i] == s[iy]){
			for(;i < t.size() && iy < s.size(); i++){
				if(t[i + 1] == s[iy +1] ){					
					iy++;
					ok--;
				}
			}
			/*
			while(t[i++] != s[iy + 1]
				&& i < t.size() 
				&& iy < s.size()){
				cout << t[i+1] << " = " << s[iy + 2] << endl;
				iy++;
				ok--;
			}
			*/
		}
	}
	return ok == 0;
}

int main(){
	string s, t;
	getline(cin, s);
	while(s != ""){
		t = s.substr(s.find(" ") + 1);
		s = s.substr(0,s.find(" "));
		if(subSequence(s, t))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
			getline(cin, s);
	}
	return 0;
}	