#include <bits/stdc++.h>
#include <chrono>
#include <thread>

#define inf 99999
#define V 5
using namespace std;

int unique_id = 0;

struct Node {
  string name;
  int distance;

  Node(string name, int distance) : name(name), distance(distance) {}

  bool operator<(const Node& other) const {
    return distance > other.distance;
  }
};



void mutual_followers(string user_1, string user_2, map<string, int> &db, map<int, string> &temp_db, vector<int> adj[])
{
    if (db.find(user_1) != db.end() && db.find(user_2) != db.end())
    {
        cout << "Mutual Followers of " << user_1 << " with respect to " << user_2 << " : \n";
        for (auto i : adj[db[user_1]])
        {
            for (auto j : adj[db[user_2]])
            {
                if (i == j)
                {
                    cout << temp_db[i] << endl;
                }
            }
        }
    }
    else
    {
        cout << "The user name doesn't exist\n";
    }
}


void no_of_mutual_followers(string user_1, string user_2, map<string, int> &db, map<int, string> &temp_db, vector<int> adj[])
{
    if (db.find(user_1) != db.end() && db.find(user_2) != db.end())
    {
        int cnt = 0;
        cout << "Number of Mutual Followers of " << user_1 << " with respect to " << user_2 << " : \n";
        for (auto i : adj[db[user_1]])
        {
            for (auto j : adj[db[user_2]])
            {
                if (i == j)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    else {
        cout << "\nThe user name doesn't exist";
    }
}


void no_of_friends(string user_1, map<string, int> &db, vector<int> adj[])
{
    if (db.find(user_1) != db.end()) {
        cout << "The number of friends " << user_1 << " got is " << adj[db[user_1]].size() << endl;
    }
    else {
        cout << "\nThe user name doesn't exists";
    }
}


void display_friends_list(string user_1, map<string, int> &db, map<int, string> &temp_db, vector<int> adj[],map<string,vector<string>> list)
{
    if (db.find(user_1) != db.end())
    {
        cout << "\n Friends List of " << user_1 << " : ";    
        // both sided friendship    
        vector<string> v = list[user_1];
        for(int i=0; i<v.size(); i++) {
            vector<string> aa = list[v[i]];
            for(int j=0; j<aa.size(); j++) {
                if(aa[j] == user_1) {
                    cout<< v[i] << " ";
                }
            }
        }
        cout<<endl;
    }
    else
    {
        cout << "\nThe user name doesn't exists";
    }

}


void recommend(string user_1,map<string,vector<string>> list,map<string,int> db)
{

    if (db.find(user_1) != db.end()) {

        vector<string> v = list[user_1];
        unordered_set<string> s;

        for(auto i: v) {
            vector<string> ajj = list[i];
            for(auto j: ajj) {
                if(j != user_1)
                    s.insert(j);
            }
        }

        cout<< "Recommended friends for "<< user_1 << " are: "<<endl;
        for(auto i: s) {
            cout<< i << " ";
        }cout<<endl;

    }   
    else{
        cout<< "\nThe username doesn't exists" <<endl;
    } 

}



// Function to open the file and check whether it has opened correctly or not
void openFile(ifstream &inFile, string fname)
{
    inFile.open(fname);
    if (inFile.is_open())
    {
        cout << "\nSuccessfully opened the file" << endl;
    }
    else
    {
        cout << "\nFailed to open file" << endl;
        exit(-1);
    }

}


void dijkstra(map<string,vector<string>>& adjList, string source) {
    // Initialize distances for all nodes as infinite
    map<string, int> distances;
    for (auto i : adjList) {
        distances[i.first] = inf;
        // distances[node] = inf;
    }

    // Priority queue to store nodes to explore (sorted by distance)
    priority_queue<Node> pq;

    // Set distance of source node to 0 and mark it visited
    distances[source] = 0;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
        // Extract node with minimum distance from the priority queue
        Node current = pq.top();
        pq.pop();

        // Relax edges (update distances) for neighboring nodes
        for (string neighbor : adjList[current.name]) {
        int newDistance = distances[current.name] + 1; // Assuming edge weight is 1

        // Update distance if shorter path is found
        if (distances[neighbor] > newDistance) {
            distances[neighbor] = newDistance;
            pq.push(Node(neighbor, newDistance));
        }
        }
    }

    // Print distances from source to all other nodes
    cout << "Distances from source " << source << ":" << endl;
    for (auto i : distances) {
        if (i.first != source) {
        cout << i.first << ": " << (100/i.second) << "% " << endl;
        }
    }
}



// Function to find an user with maximum number of friends
void max_friends(vector<int> adj[], map<int, string> &temp_db)
{

    int maxi = 0;
    int ans;
    for (auto it = temp_db.begin(); it != temp_db.end(); it++)
    {
        // cout<<adj[it->first].size()<<endl;
        if ((adj[it->first].size()) > maxi)
        {
            maxi = adj[it->first].size();
            // cout<<maxi<<endl;
            ans = it->first;
            // cout<<ans<<endl;
        }
    }

    // Output the name of one user with maximum number of friends
    cout << "User with maximum number of friends : " << temp_db[ans] << endl;

}


// Function to find an user with minimum number of friends
void min_friends(vector<int> adj[], map<int, string> &temp_db)
{

    int mini = INT_MAX;
    int ans;
    for (auto it = temp_db.begin(); it != temp_db.end(); it++)
    {
        // cout<<adj[it->first].size()<<endl;;
        if ((adj[it->first].size()) < mini)
        {
            mini = adj[it->first].size();
            // cout<<maxi<<endl;
            ans = it->first;
            // cout<<ans<<endl;
        }
    }

    // Output the name of one user with minimum number of friends
    cout << "User with minimum number of friends : " << temp_db[ans] << endl;

}



// ERROR IN THIS 
void spreadtime(map<string,vector<string>> list, map<string,int> db, map<int,string> temp_db) {
    
    // greedy approach 
    // find the user with maximum connections

    vector<bool> vis(db.size()+1,false);
   
    int max_val=0;
    string max_user;
    for(auto i: list){
        vector<string> v = i.second;
        if(v.size() >= max_val){ 
            max_val = v.size();
            max_user = i.first;   
        }
    }


    vector<string> ans;

    queue<string> q;
    q.push(max_user);
    q.push("\0");
    vis[db[max_user]] = true; // Mark starting user as visited (assuming id field in db)
    int time=0;
    while (!q.empty()) {
        
        string current = q.front();
        if(current != "\0")
            ans.push_back(current);
        
        q.pop();

        if(current == "\0") {
            time++;
            if(!q.empty()) {
                q.push("\0");
            }
        }

        for(auto follower : list[current]) {
            if (!vis[db[follower]]) { // Check if follower is not visited
                vis[db[follower]] = true;    
                q.push(follower);
            }
        }

    }


    cout<< "Minimum Spread Time is: " << time << " sec !" <<endl;
    cout<< "Sequence of virality is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        if(i == ans.size()-1) {
            cout<< ans[i];
        }
        else{
            cout<< ans[i] << " -- ";
        }

    }cout<<endl;


}


void details(string user, map<string,vector<string>> list, map<string,int> db, map<int,string> temp_db) {

    // number of following, number of followers

    // following 
    vector<string> v = list[user];
    cout<< "Following: " << v.size() <<endl;    

    int flwr=0;
    vector<string> flwrlist;
    for(auto i: list) {
        vector<string> v = i.second;
        for(int j=0; j<v.size(); j++) {
            if(v[j] == user) {
                flwr++;
                flwrlist.push_back(i.first);
            }
        }
    }

    // number of followers
    cout<< "Followers: "<< flwr << endl;

    dijkstra(list,user);



    int op;
    cout<< "Press 1 if you want to see follower list: ";
    cin >> op;

    if(op == 1) {
        for(auto i: flwrlist) {
            cout<< i << " ";
        }cout<<endl;
    }

}

void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
    "distances between every pair of friends \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == inf)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}


// floyd warshall
void allPairShortestPath(int dist[][V]) {

    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
    
                if ( dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != inf && dist[i][k] != inf)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                    
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
    

}




int main()
{
    system("color E4");

    cout << setw(50) << setfill('=') << "" << endl;
    cout << "\t\tFRIENDS FLOW " << endl;
    cout << setw(50) << setfill('=') << "" << endl << endl;

    map<string,vector<string>> list;

    // map to store the user's name
    map<string, int> db;

    // map to store the user's name and for accessing
    map<int, string> temp_db;

    // Adjacency list to represent the graph
    vector<int> adj[1000];

    int dist[5][5] = {

        {0, 1, inf, inf, inf},
        {1, 0, 1, 1, inf},
        {inf, inf, 0, 1, inf},
        {inf, inf, 1, 0, 1},
        {1, inf, inf, inf, 0}

    };


    
    cout << "\n1 . User Input";
    cout << "\n2 . Input from File\n";
    cout << "\nEnter your choice : ";
    int start_choice;

    cin >> start_choice;

    if (start_choice == 2)
    {

        // network.txt => contains all the names of the users

        ifstream inFile;
        openFile(inFile, "network.txt");

        string user_name;
        while (!inFile.eof())
        {
            getline(inFile, user_name);

            // adding the user names in the map
            if (db.find(user_name) == db.end())
            {
                
                vector<string> v;
                list[user_name] = v;
                db[user_name] = unique_id;
                temp_db[unique_id] = user_name;
                unique_id++;
            }
            else
            {
                cout << "\nThe user name already exists";
            }
        }

        inFile.close();

        cout << "network.txt closed" << endl;

        // friends.txt => contains the friends name of the users in network.txt

        inFile;
        openFile(inFile, "friends.txt");

        // 2.process the file
        // read line by line from the file
        string temp_user_name;
        string following_name;
        istringstream iss;
        for (auto it = db.begin(); it != db.end(); it++)
        {
            while (!inFile.eof())
            {

                getline(inFile, temp_user_name);               

                if (inFile.good())
                {
                    iss.clear();
                    iss.str(temp_user_name);
                    while (iss.good())
                    {
                        iss >> following_name;

                        if (following_name != it->first && db.find(following_name) != db.end())
                        {
                            adj[db[it->first]].push_back(db[following_name]);
                            list[it->first].push_back(following_name);
                            list[it->first].shrink_to_fit();
                        }
    
                    }
                    break;
                }
            }
        }

        // 3.close the file friends.txt
        inFile.close();
        cout << "friends.txt file closed" << endl;
    }

    // Menu driven to get user details from output terminal
    else if (start_choice == 1)
    {

        // Input to get number of users
        int no_of_users;

        // Input to get user names
        string user_name;

        cout << "Enter the number of users : ";
        cin >> no_of_users;

        // Input user names
        for (int i = 0; i < no_of_users;)
        {
            cout << "\nEnter User " << i + 1 << " name : ";
            cin >> user_name;

            // adding in the map

            if (db.find(user_name) == db.end())
            {   
                vector<string> v;
                list[user_name] = v;
                db[user_name] = i;
                temp_db[i] = user_name;
                i++;
            }
            else
            {
                cout << "\nThe user name already exists";
            }
        }


        // Input friends name from the user
        cout << "\n Enter Following List ( -1 to complete ) : ";
        for (auto it = db.begin(); it != db.end(); it++)
        {
            cout << "\n" << it->first << " : \n";

            // Input friends name for each user
            string following_name;

            while (1)
            {
                cin >> following_name;

                if (following_name == "-1")
                    break;

                else if (following_name != it->first && db.find(following_name) != db.end())
                {
                    adj[db[it->first]].push_back(db[following_name]);
                    list[it->first].push_back(following_name);
                    list[it->first].shrink_to_fit();
                }
                else
                {
                    cout << "\nThe name doesn't exist";
                }
            }
        }
    }
    else {

        cout << "\n Invalid Input";
        exit(-1);
    }



    while (1)
    {   

        cout << setw(50) << setfill('=') << "" << endl;
        cout << "\t\tFRIENDS FLOW " << endl;
        cout << setw(50) << setfill('=') << "" << endl << endl;

        int option;

        cout << "\n1 . Check Mutual Followers";
        cout << "\n2 . Display Friends List";
        cout << "\n3 . Recommend new Friends";
        cout << "\n4 . Check Connections Strength";
        cout << "\n5 . Users with maximum number of Friends";
        cout << "\n6 . Users with minimum number of Friends";
        cout << "\n7 . Spread Time";
        cout << "\n8 . Details of User";
        cout << "\n9 . How Far The Friends are ?";


        cout << "\nEnter your choice : ";
        cin >> option;

        // sample variables to get user names
        string user_1, user_2;
        string det_user;
        string u;

        switch (option)
        {

        // Check Mutual Followers
        case 1:
            cout << "\nEnter the user name : ";
            cin >> user_1;
            cout << "\nEnter the name of the user to check mutual Followers : ";
            cin >> user_2;
            mutual_followers(user_1, user_2, db, temp_db, adj);
            break;

        // Display Friends List
        case 2:
            cout << "\nEnter the user name : ";
            cin >> user_1;
            display_friends_list(user_1, db, temp_db, adj,list);
            break;

        // Recommend new Friends
        case 3:
            cout << "\nEnter the user name : ";
            cin >> user_1;
            recommend(user_1,list,db);
            break;

        // Check Connections Strength (Dijkstra's algorithm)
        case 4:
            cout << "\nEnter user name to find its connection strength : ";
            cin >> u;
            dijkstra(list,u);
            break;

        // Users with maximum number of Friends
        case 5:
            max_friends(adj, temp_db);
            break;

        // Users with minimum number of Friends
        case 6:
            min_friends(adj, temp_db);
            break;

        // spread time 
        case 7:
            spreadtime(list,db,temp_db);
            break; 

        // Details of user 
        case 8:
            cout<< "Enter User: ";
            cin >> det_user;
            details(det_user, list,db,temp_db);
            break;
        
        // friends closeness
        case 9: 
            allPairShortestPath(dist);
            break;

        default:
            exit(0);
        }

        int m;
            cout<< "enter 0 to clear screen: ";
            cin >> m;
            if(m==0) system("cls");

    }

    return 0;

}