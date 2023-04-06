#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
 void dijistra(vector<vector<variant<string,int>>> &vec,int vertices,int edges,string source,vector<vector<variant<string,int>>> &par,int menu,string final_destination)
 { if(menu==0)
   { unordered_map <string,vector<vector<variant<string,int>>>> adjlist;
    for(int i=0;i<edges;i++)
    {
      string u=get<string>(vec[i][0]);
      string v=get<string>(vec[i][1]);
      
      string medium=get<string>(par[i][0]);
      // cout<<endl<<"i"<<endl;
      int price=get<int>(par[i][1]);
      // cout<<endl<<price<<endl;
      // cout<<price;
      // cout<<endl<<"i"<<endl;
      int time=get<int>(par[i][2]);
      // cout<<time;
      // int time=0;
      // cout<<endl<<"i"<<endl;
      int type=get<int>(vec[i][2]);
      // cout<<type;
      // cout<<endl<<"i"<<endl;
      vector <variant<string,int>> vec1;
      // cout<<endl<<"i"<<endl;
      if(type==0)
      { vec1.push_back(v);
        // cout<<v;
        vec1.push_back(medium);
        vec1.push_back(price);
        vec1.push_back(time);
        adjlist[u].push_back(vec1);
        }
      else if (type==1)
      { vec1.push_back(v);
        // cout<<v;
        vec1.push_back(medium);
        // cout<<endl<<"medium"<<medium;
        vec1.push_back(price);
        vec1.push_back(time);
        adjlist[u].push_back(vec1);
        vector <variant<string,int>> vec1;
        vec1.push_back(u);
        // cout<<" "<<u;
        vec1.push_back(medium);
        vec1.push_back(price);
        vec1.push_back(time);
        adjlist[v].push_back(vec1);
      }
      // cout<<endl<<"i"<<endl;
      // cout<<endl;
    }
    unordered_map <string,int> dist;
    unordered_map <string,list<pair<string,int>>> dist1;
    for (auto it=adjlist.begin() ;it!=adjlist.end();it++)
    { string key=(it->first);
      dist[key]=INT_MAX;
      for (auto key1:adjlist[key])
      //  {  auto time22=key1[3];
      //     int time23=get<int>(time22);
          {auto medium22=key1[1];
          string medium23=get<string>(medium22);
          dist1[key].push_back(make_pair("",INT_MAX));
      }
    }
    set <pair<int,string>> st;
    set <pair<string,int>> st1;
    dist[source]=0;
    dist1[source].clear();
    dist1[source].push_back(make_pair(source,0));
  
    st.insert(make_pair(0,source));
    st1.insert(make_pair("source",0));
    while(!st.empty())
    {
      auto top=*(st.begin());
      int node_distance=top.first;
      string top_node=top.second;
      auto top1=*(st1.begin());
      string medium_travel=top1.first;
      int time_travel=top1.second;
      st.erase(st.begin());
      st1.erase(st1.begin());
      for (auto neigh:adjlist[top_node])
      
      { auto pr=neigh[2];
        int pri=get<int>(pr);
        auto nod=neigh[0];
        string nod1=(get<string>(nod));
        auto med=neigh[1];
        string med_travel=(get<string>(med));
        auto tim=neigh[3];
        int time_travel1=(get<int>(tim));
        // cout<<endl<<node_distance<<" "<<top_node<<" "<<nod1<<endl;
      if(node_distance+pri<dist[nod1])
      {   auto  p=dist1[nod1];
          auto it = p.begin();
          auto pp=*it;
          string pp1=pp.first;
          int pp2=pp.second;
          auto record=st.find(make_pair(dist[nod1],nod1));
          auto record1=st1.find(make_pair(pp1,pp2));
          
              if (record!=(st.end()))
              {
                  st.erase(record);
              }
          //  cout<<node_distance;
          dist[nod1]=node_distance +pri;
          //  cout<<dist[nod1];
          dist1[nod1].clear();
          dist1[nod1].push_back(make_pair(med_travel,time_travel1));
          //  for (auto h:dist1[nod1])
          //  {cout<<h.first<<endl<<h.second<<endl;}
          st.insert(make_pair(dist[nod1],nod1));
          st1.insert(make_pair(med_travel,time_travel1));
      }
      
      
      }
      
    }
    // vector<vector<variant<string,int>>> dist1_result;
    // for (auto it3=dist1.begin();it3!=dist1.end();it3++)
    // {
    //   vector<variant<string,int>> dist1_result1;

    // }
    string currency;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                      -------------------------------------------------------------------"<<endl;
    cout<<"                      -------------------------------------------------------------------"<<endl;
    cout<<"                     \033[1m\033[3m\033[4mWhat is the currency of the price you entered = ";
    cin>>currency;
    // int h=0;
    for (auto it=dist.begin();it != dist.end();it++)
    // { auto it2=dist1.begin();
      
    { 
      
      cout<<                   it->first<<" "<<"="<<" "<<it->second<<"   "<<endl;
      if(it->first==final_destination)
      cout<<                  "\033[1m\033[3m\033[4mSo the shortest path from source to "<<it->first<<" is  "<<it->second<<" "<<currency<<endl;
      // cout <<" medium  =  "<<it2 ->first<<endl;
      // int h=0;
      // for (auto it212:dist1[it->first])
      //   {
      //     {cout<<"time= " <<it212.second;
      //     cout<<"    medium =  "<<it212.first<<endl;
      //     }
          //  h++;
      //   }
      // it2++;
      // cout<<endl;
      // cout<<endl;
      // cout<<"                -------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      // cout<<"                -------------------------------------------------------------------------------------------------------------------------------------------------------------";
    }
  }
  else if (menu==1)
  {
    { unordered_map <string,vector<vector<variant<string,int>>>> adjlist;
    for(int i=0;i<edges;i++)
    {
      string u=get<string>(vec[i][0]);
      string v=get<string>(vec[i][1]);
      
      string medium=get<string>(par[i][0]);
      // cout<<endl<<"i"<<endl;
      int price=get<int>(par[i][1]);
      // cout<<endl<<price<<endl;
      // cout<<price;
      // cout<<endl<<"i"<<endl;
      int time=get<int>(par[i][2]);
      // cout<<time;
      // int time=0;
      // cout<<endl<<"i"<<endl;
      int type=get<int>(vec[i][2]);
      // cout<<type;
      // cout<<endl<<"i"<<endl;
      vector <variant<string,int>> vec1;
      // cout<<endl<<"i"<<endl;
      if(type==0)
      { vec1.push_back(v);
        // cout<<v;
        vec1.push_back(medium);
        vec1.push_back(price);
        vec1.push_back(time);
        adjlist[u].push_back(vec1);
        }
      else if (type==1)
      { vec1.push_back(v);
        // cout<<v;
        vec1.push_back(medium);
        // cout<<endl<<"medium"<<medium;
        vec1.push_back(price);
        vec1.push_back(time);
        adjlist[u].push_back(vec1);
        vector <variant<string,int>> vec1;
        vec1.push_back(u);
        // cout<<" "<<u;
        vec1.push_back(medium);
        vec1.push_back(price);
        vec1.push_back(time);
        adjlist[v].push_back(vec1);
      }
      // cout<<endl<<"i"<<endl;
      // cout<<endl;
    }
    unordered_map <string,int> dist;
    unordered_map <string,list<pair<string,int>>> dist1;
    for (auto it=adjlist.begin() ;it!=adjlist.end();it++)
    { string key=(it->first);
      dist[key]=INT_MAX;
      for (auto key1:adjlist[key])
      //  {  auto time22=key1[3];
      //     int time23=get<int>(time22);
          {auto medium22=key1[1];
          string medium23=get<string>(medium22);
          dist1[key].push_back(make_pair("",INT_MAX));
      }
    }
    set <pair<int,string>> st;
    set <pair<string,int>> st1;
    dist[source]=0;
    dist1[source].clear();
    dist1[source].push_back(make_pair(source,0));
  
    st.insert(make_pair(0,source));
    st1.insert(make_pair("source",0));
    while(!st.empty())
    {
      auto top=*(st.begin());
      int node_distance=top.first;
      string top_node=top.second;
      auto top1=*(st1.begin());
      string medium_travel=top1.first;
      int time_travel=top1.second;
      st.erase(st.begin());
      st1.erase(st1.begin());
      for (auto neigh:adjlist[top_node])
      
      { 
        auto tm=neigh[3];
        int tim_giv=get<int>(tm);
        auto nod=neigh[0];
        string nod1=(get<string>(nod));
        auto med=neigh[1];
        string med_travel=(get<string>(med));
        auto tim=neigh[3];
        int time_travel1=(get<int>(tim));
        // cout<<endl<<node_distance<<" "<<top_node<<" "<<nod1<<endl;
      if(node_distance+tim_giv<dist[nod1])
      {   auto  p=dist1[nod1];
          auto it = p.begin();
          auto pp=*it;
          string pp1=pp.first;
          int pp2=pp.second;
          auto record=st.find(make_pair(dist[nod1],nod1));
          auto record1=st1.find(make_pair(pp1,pp2));
          
              if (record!=(st.end()))
              {
                  st.erase(record);
              }
          //  cout<<node_distance;
          dist[nod1]=node_distance +tim_giv;
          //  cout<<dist[nod1];
          dist1[nod1].clear();
          dist1[nod1].push_back(make_pair(med_travel,time_travel1));
          //  for (auto h:dist1[nod1])
          //  {cout<<h.first<<endl<<h.second<<endl;}
          st.insert(make_pair(dist[nod1],nod1));
          st1.insert(make_pair(med_travel,time_travel1));
      }
      
      }
      
    }
    // vector<vector<variant<string,int>>> dist1_result;
    // for (auto it3=dist1.begin();it3!=dist1.end();it3++)
    // {
    //   vector<variant<string,int>> dist1_result1;

    // }
    string unit;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                      -------------------------------------------------------------------"<<endl;
    cout<<"                      -------------------------------------------------------------------"<<endl;
    cout<<                                         "\033[1m\033[3m\033[4mWhat is the unit  of the time  you entered = ";
    cin>>unit;
    // int h=0;
    for (auto it=dist.begin();it != dist.end();it++)
    // { auto it2=dist1.begin();
      
    { 
      
      cout<<                                        it->first<<" "<<"="<<" "<<it->second<<"   "<<endl;
      if(it->first==final_destination)
      {cout<<"                                      \033[1m\033[3m\033[4mSo the shortest path from source to "<<it->first<<" is "<<it->second<<" "<<unit<<endl;}
      // cout <<" medium  =  "<<it2 ->first<<endl;
      // int h=0;
      // for (auto it212:dist1[it->first])
      //   {
      //     {cout<<"time= " <<it212.second;
      //     cout<<"    medium =  "<<it212.first<<endl;
      //     }
        //  h++;
      //   }
      // it2++;
      // cout<<endl;
      // cout<<endl;
      // cout<<"                -------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      // cout<<"                -------------------------------------------------------------------------------------------------------------------------------------------------------------";
    }
  }
  
}
 }  
};


int main()
{ std::cout << "                    \033[1m\033[3m\033[4mTravel Planner\033[0m" << std::endl;
  std::cout<<"------------------------------------------------------------------------------------------"<<std::endl;
  cout     <<"                      \033[1m\033[3m\033[4mAn Applcaton to comfort Travelling.......\033[0m "<<endl;
  std::cout<<"------------------------------------------------------------------------------------------"<<std::endl;
  graph g;
  int n,m;
  cout<<endl;
  cout<<"\033[1m\033[3m\033[4mEnter the number of nodes = ";
  cin>>n;
  cout<<"\033[1m\033[3m\033[4mEnter the number of edges = ";
  cin>>m;
  string source;
  using element=variant<string,int>;
  vector<vector<int>> time_vec;
  vector<vector<element>> data; 
  vector <vector<variant<string,int>>> par; 
int menu;
cout<<"\033[1m\033[3m\033[4mEnter your desired function for quickest press 1 or else for cheapest press 0 = ";
cin>>menu;


  for (int i=0 ;i<m;i++)
  { string uu;
  string v;
  int w,type;
      int total;
    set <pair<int,string>> weight;
    cout <<"\033[1m\033[3m\033[4mEnter the nodes :- ";
    cout<<"\033[1m\033[3m\033[4mEnter Initial Node= ";
    cin>>uu;
    string u=uu;
    cout<<"\033[1m\033[3m\033[4mDestination Node= ";
    cin>>v;
    cout<<"\033[1m\033[3m\033[4m Enter '0' for Directed node and '1' for undirected node = ";
    cin>>type;
    vector <element> v1;
    v1.push_back(u);
    v1.push_back(v);
    v1.push_back(type);
    cout<<"\033[1m\033[3m\033[4mHow many mediums are there on this node to travel = ";
    cin>>total;
    vector <variant<string,int>> parameters;
    if (menu==0)
    {for (int k=0;k<total;k++)
     
      {string medium_type;
      cout <<"\033[1m\033[3m\033[4mEnter the name of the medium type = "<<endl;
      cin>>medium_type;
      int price,time;
      cout <<"\033[1m\033[3m\033[4mEnter the price ="<<endl;
      cin>>price;
      cout<<"\033[1m\033[3m\033[4mEnter the time  = "<<endl;
      cin>>time;
      vector <int> time_vec1;
      weight.insert(make_pair(price,medium_type));
      time_vec1.push_back(time);
      time_vec1.push_back(price);
      // cout<<endl<<price<<endl;
      time_vec.push_back(time_vec1);
    //   time_vec.push_back(price);
      }
    //  cout<<"ddd";

      auto price1=*(weight.begin());
      int price=price1.first;
      string medium_type=price1.second;

      for (int b=0;b <time_vec.size();b++)
      {
        if(time_vec[b][1]==price)
        {
            int time_given=time_vec[b][0];
            parameters.push_back(medium_type);
            parameters.push_back(price);
            // cout<<endl<<price<<endl;
            parameters.push_back(time_given);
        }
      }
      
    }
    
    if (menu==1)
    {for (int k=0;k<total;k++)
     
      {string medium_type;
      cout <<"\033[1m\033[3m\033[4mEnter the medium type = "<<endl;
      cin>>medium_type;
      int price,time;
      cout <<"\033[1m\033[3m\033[4mEnter the price  = "<<endl;
      cin>>price;
      cout<<"\033[1m\033[3m\033[4mEnter the  time =  "<<endl;
      cin>>time;
      vector <int> time_vec1;
      weight.insert(make_pair(time,medium_type));
      time_vec1.push_back(time);
      time_vec1.push_back(price);
      // cout<<endl<<price<<endl;
      time_vec.push_back(time_vec1);
    //   time_vec.push_back(price);
      }
    //  cout<<"ddd";

      auto price1=*(weight.begin());
      int price=price1.first;
      string medium_type=price1.second;

      for (int b=0;b <time_vec.size();b++)
      {
        if(time_vec[b][0]==price)
        {
            int time_given=time_vec[b][0];
            parameters.push_back(medium_type);
            parameters.push_back(price);
            // cout<<endl<<price<<endl;
            parameters.push_back(time_given);
        }
      }
      
    }
    
    
    data.push_back(v1);
    par.push_back(parameters);
    //undirected graph
  }
  cout <<"\033[1m\033[3m\033[4mEnter the source";
  cin>>source;
  string  final_destination;
  cout<<"\033[1m\033[3m\033[4mEnter the final destinaton source = ";
  cin>>final_destination;
  g.dijistra(data,n,m,source,par,menu,final_destination);
//   g.print_adj_list();

}