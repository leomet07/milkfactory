#include <bits/stdc++.h>

using namespace std;

void dfs(set<int> &visited, map<int, vector<int>> graph, int node){
    // Do the DFS
    // cout << "Inner DFS" << endl;
    if (visited.find(node) == visited.end()){ // if doesnt exist
        visited.insert(node);
        // cout << "Dfs is on node: " << node <<endl;
        if (graph.count(node) > 0){
            vector<int> neighbors = graph.at(node);
            // cout << "Found neighbors" << endl;
            for (int i = 0; i < neighbors.size(); i++){
                int neighbor = neighbors[i];
                // cout << "Neighbor: " << neighbor << endl;
                
                dfs(visited, graph, neighbor);
                // cout << "dfs neighbor call finished??? " << endl;
                
            }
        }
        
    }
}
void printMap(map<int, vector<int>> &mp){ // & so passes by reference
    cout << "Print map" << endl;
    map<int, vector<int>>::iterator itr;
    
    for (auto itr = mp.begin();
         itr != mp.end(); ++itr) {
        // cout << itr->first << ": " << itr->second << endl;
        cout << itr->first << ": ";
        vector<int> v = itr->second;
        for (int i = 0; i < v.size();i++){
            int c = v[i];
            cout<< c <<" ";
        }
        cout << endl;
    }
    cout << "End print map" << endl;

}
int main() {
    // ifstream cin("factory.in");
    // ofstream cout("factory.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    set<int> stations;
    map<int, vector<int>> belts;
    // bool isA = true;
    // int a;
    // while (stations.size() < n ){ // Recieve station data
    //     int s;
    //     cin >> s;
    //     if (isA){
    //         a = s;
    //     }else{
            
    //         // cout << "S: " << s << " A: "<< a << endl;
    //         // check if connection exists
    //         if (belts.count(s) == 0){
    //             belts.insert(pair<int, vector<int>>(s , {a}));
    //             // cout << "S: " << s << " A: "<< a << endl;
    //             // printMap(belts);
                
    //         } else{
    //             vector<int> h = belts.at(s);
    //             h.push_back(a);
    //             // cout << "New vector len: " << h.size() << endl; 
    //             // belts.insert(pair<int, vector<int>>(s , h));
    //             belts[s] = h;
    //         }

    //         stations.insert(a);
    //         stations.insert(s);
    //     }
    //     isA = !isA;
    // }

    for (int i = 0; i < n -1; i++){
        int a, b;
        cin >> a;
        cin >> b;

        if (belts.count(b) == 0){
                belts.insert(pair<int, vector<int>>(b , {a}));
                // cout << "S: " << s << " A: "<< a << endl;
                // printMap(belts);
                
        } else{
                vector<int> h = belts.at(b);
                h.push_back(a);
                // cout << "New vector len: " << h.size() << endl; 
                // belts.insert(pair<int, vector<int>>(s , h));
                belts[b] = h;
        }

        stations.insert(a);
        stations.insert(b);

    }

    // printMap(belts);
    // cout << "------" << endl;
    // iterate through every station
    set<int>::iterator sitr;
    int min_all = -1;
    for(sitr = stations.begin(); sitr != stations.end(); sitr++){
        int b = *sitr;
        // cout << "Current: " << b << endl;
        set<int> check = stations;
        check.erase(*sitr);

        // iterate through every other station
        set<int>::iterator citr;
        int connects = 0;
        int reached = 0;

        if (belts.count(b) > 0){
            set<int> visited;
            dfs(visited, belts, b );
            // cout << "Full dfs is finished" << endl;
            // cout << "Visited size: " << visited.size() << endl;
            // print the set
            set<int>::iterator vitr;
            for (vitr= visited.begin(); vitr!= visited.end(); vitr++){
                // cout << "Element in visited: " << *vitr << endl;
            }

            for(citr = check.begin(); citr != check.end(); citr++){
                int a = *citr;
                // Check
                // cout << "Citr: " << a << endl;
                
                if (visited.find(a) != visited.end()){
                    // hit all
                    // cout <<"Increment r" << endl;
                    reached++;
                }
            }
        } else{
            // cout << "Does not exist so will not bother" << endl;
        }

        
        // cout << "Reached: " << reached <<endl;
        // cout << "---------------" << endl;

        if (reached == n - 1){
            // cout << "Inside final if" << endl;
            // new record
            if (min_all == -1 || b < min_all){
                min_all = b;
            }

        }
    }
    // cout << "Min all: " << min_all << endl;
    cout << min_all << endl;
    return 0;

}
