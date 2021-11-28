#include <iostream>
#include <vector>
#include <set>
#include <map>
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
        // cout << "S: " << s << "IsA: " << isA << endl; 
        if (isA){
            a = s;
        }else{
            // cout << "BBB " << endl;
            belts.insert(pair<int, int>(a , s));
            stations.insert(a);
            stations.insert(s);
        }
        isA = !isA;
        
    }
    // cout << "---" << endl;
    // iterate through every station
    set<int>::iterator sitr;
    int min_all = -1;
    for(sitr = stations.begin(); sitr != stations.end(); sitr++){
        // cout << "Set It: " << *sitr << endl;
        int b = *sitr;
        set<int> check = stations;
        check.erase(*sitr);

        // iterate through every other station
        set<int>::iterator citr;
        int connects = 0;
        for(citr = check.begin(); citr != check.end(); citr++){
            // cout << "Citr: " << *citr << endl;
            int a = *citr;
            // check if connection exists
            if (belts.count(a) > 0){
                if (belts.at(a) == b){
                    // Connection exists
                    connects++;
                }
            }
        }
        // cout << "Connections: " << connects << endl;
        if (connects + 1 == stations.size()){
            // cout << "Hits everything: " << " Stations: " << stations.size() << endl;
            // hits everything
            if ((b < min_all && b != -1) || (min_all == -1) ){
                min_all = b;
                // cout << "Record: " << b << endl;
            }
        }

    }
    cout << min_all << endl;
    // cout << "Comp Template" << endl;    

    return 0;

}
