#include <bits/stdc++.h>

using namespace std;
 

int main() {
    ifstream cin("factory.in");
    ofstream cout("factory.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    set<int> stations;
    map<int, int> belts;
    bool isA = true;
    int a;
    while (stations.size() < n){ // Recieve station data
        int s;
        cin >> s;
        if (isA){
            a = s;
        }else{
            belts.insert(pair<int, int>(a , s));
            stations.insert(a);
            stations.insert(s);
        }
        isA = !isA;
        
    }
    // iterate through every station
    set<int>::iterator sitr;
    int min_all = -1;
    for(sitr = stations.begin(); sitr != stations.end(); sitr++){
        int b = *sitr;
        set<int> check = stations;
        check.erase(*sitr);

        // iterate through every other station
        set<int>::iterator citr;
        int connects = 0;
        for(citr = check.begin(); citr != check.end(); citr++){
            int a = *citr;
            // check if connection exists
            if (belts.count(a) > 0){
                if (belts.at(a) == b){
                    // Connection exists
                    connects++;
                }
            }
        }
        if (connects + 1 == stations.size()){
            // hits everything
            if ((b < min_all && b != -1) || (min_all == -1) ){
                min_all = b;
            }
        }
    }
    cout << min_all << endl;
    return 0;

}
