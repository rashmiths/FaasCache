#include <bits/stdc++.h>

using namespace std;

// TODO: Add comments
class Container {
  public:
    int id;
    int size {0};
    int priority {0};
    int cost {0};
    int frequency {0};
    int launch_time {0};
};

int run_ttl(int server_size, int seed) {
    
  bool accept_input = true;
  int  total_size = 0, clock = 1, available = size;
  unordered_map<int, bool> cache; // To keep track of which container is in cache.
  map<int, Container*> all_functions; // To keep track of all the functions used till now.
  unordered_map<int, bool> m; // To keep track of which id has been used.
  set<pair<int, int>> s; // priority, id relation.
  int time_to_live = 10; // fixed time to live interval
  
  int hit = 0, miss = 0;
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

    /*
    Evict expired containers
    */
    for(auto it : s) {
        if(clock - it.second->launch_time > time_to_live)
            s.erase(*it);
    }
    clock++;
    cout<<"Enter function id: ";
    int id;
    cin>>id;
    Container *cont;
    if(m.find(id) == m.end()) {
      cout<<"A new container was provisioned!\n";
      m[id] = true;
      cont = new Container();
      cont->id = id;
      cont->size = rand(seed) % 20;
      if(cont->size == 0) cont->size++;
      cont->cost = rand(seed) % 20;
      cont->launch_time = clock;
      all_functions[id] = cont;

      miss++;
    }
    else cont = all_functions[id];

    if(cache[id]) {
      cout<<"Container already present in cache!\n";
      hit++;
      //   cout<<cont->size<<" "<<cont->cost<<" "<<cont->priority<<"\n\n";
      s.erase({cont->priority, id});
      cont->frequency++;
      /*
       TTL priority calculation
      */
      cont->priority = clock;
      s.insert({cont->priority, id});
      cout<<"\n";
      continue;

      
    }

    while(s.size() && available < cont->size) {
      pair<int, int> p = *s.begin();
      s.erase(s.begin());
      Container *cont2 = all_functions[p.second];
      available += cont2->size;
      cache[cont2->id] = false;
      cout<<"Function "<<cont2->id<<" removed from cache, with priority: "<<cont2->priority<<"\n";
      //   cout<<"Available memory after removal: "<<available<<"\n\n";
    }

    cont->frequency++;
    cont->priority = clock;
    cache[id] = true;
    available -= cont->size;
    // cout<<"Memory available after provisioning new container: "<<available<<"\n";
    // cout<<"Server clock: "<<clock<<"\n";
    s.insert({cont->priority, cont->id});
    cout<<"\n\n";
  }
  return hit/miss;
}
