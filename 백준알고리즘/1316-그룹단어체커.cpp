////#include <iostream>
////#include <cstring>
////#include <string>
////using namespace std;
////bool alpha[26];
////int main() {
////	int num, cnt = 0;
////	string str;
////	bool flag;
////	cin >> num;
////	for (int i = 0; i < num; i++) {
////		cin >> str;
////		flag = false;
////		for (int j = 0; j < str.length(); j++) {
////			if (!alpha[str[j] - 'a']) {
////				alpha[str[j] - 'a'] = true;
////				flag = true;
////			}
////			else {
////				if (str[j] == str[j - 1]) continue;
////				flag = false;
////				break;
////			}
////		}
////		if (flag) cnt++;
////		memset(alpha, false, sizeof(alpha));
////
////	}
////	cout << cnt << endl;
////
////
////	return 0;
////}
//
//
//#include<iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	int tcnt, n, sum, cnt;
//	vector<int> score;
//
//	double avg, res;
//
//	cin >> tcnt;
//	for (int j = 0; j < tcnt; j++) {
//		cin >> n;
//		sum = 0;
//		cnt = 0;
//		int tmp;
//		for (int i = 0; i < n; i++) {
//			cin >> tmp;
//			score.push_back(tmp);
//			sum += tmp;
//		}
//		avg = (double)sum / n;
//
//		for (int i = 0; i < n; i++)
//			if (avg < score[i]) cnt++;
//
//		res = ((double)cnt / n) * 100;
//
//		cout.precision(3);
//		cout << fixed << res << "%" << endl;
//		score.resize(0);
//	}
//	return 0;
//}

