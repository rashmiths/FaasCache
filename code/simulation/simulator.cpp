#include<bits/stdc++.h>

using namespace std;

int simulator(int server_size, int seed) {
    
  bool accept_input = true;
  int  total_size = 0, clock = 1, available = size;
  unordered_map<int, bool> cache; // To keep track of which container is in cache.
  map<int, Container*> all_functions; // To keep track of all the functions used till now.
  unordered_map<int, bool> m; // To keep track of which id has been used.
  set<pair<int, int>> s; // priority, id relation.
  int time_to_live = 10; // fixed time to live interval
  
  
  while(1) {
    cout<<"If you want to enter input, enter 1, else enter 0: ";
    cin>>accept_input;
    if(!accept_input) {
      auto it = s.begin();
      while(it != s.end()) {
        Container *con = all_functions[(*it).second];
        cout<<"Id: "<<con->id<<"; Size: "<<con->size<<"\n";
        it++;
      }
      break;
    }


    clock++;
    cout<<"Enter function id: ";
    int id;
    cin>>id;
    Container *cont;
    if(m.find(id) == m.end()) {
    
      /*
      Simulating a new container
      */
      cout<<"A new container was provisioned!\n";
      m[id] = true;
      cont = new Container();
      cont->id = id;
      cont->size = rand(seed) % 20;
      if(cont->size == 0) cont->size++;
      cont->cost = rand(seed) % 20;
      cont->launch_time = clock;
      all_functions[id] = cont;

      
    }
    else cont = all_functions[id];

  }
}