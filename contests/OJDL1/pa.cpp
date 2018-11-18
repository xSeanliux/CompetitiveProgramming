#include <iostream>
#include <map>
#include <set>
using namespace std;

int m, n, k;

map<pair<int, int>, pair<int, int> > dis;
set<pair<int, int> >pos;

pair<int, int> getAncestor(int x, int y)
{
    pair<int, int> p;
    p.first = x;
    p.second = y;
    if(dis[p] != p){
        pair <int, int> newP = getAncestor(dis[p].first, dis[p].second);
        dis[p].first = newP.first;
        dis[p].second = newP.second;
        return newP;
    }
    return p;

}



int main(){
    cin >> m >> n >> k;
    int x, y;
    for(int i = 0 ; i < k; i++){
        cin >> x >> y;
        pair<int, int> point, newPoint;
        point.first = newPoint.first = x;
        point.second = newPoint.second = y;
        dis.insert(pair<pair<int, int>, pair<int, int> >(point, point));
        newPoint.first += 1;
        if(dis.count(newPoint)){
            //cout << "The point at (" << newPoint.first <<", " << newPoint.second << ") is now connected" << endl;
            dis[newPoint] = point;
            getAncestor(newPoint.first, newPoint.second);
            //cout << "ancestor of (" <<newPoint.first <<", " << newPoint.second << ") is (" << dis[newPoint].first << ", " << dis[newPoint].second << ")." << endl;
        }
        newPoint.first -= 2;
        if(dis.count(newPoint)){
            //cout << "The point at (" << newPoint.first <<", " << newPoint.second << ") is now connected" << endl;
            dis[newPoint] = point;
            getAncestor(newPoint.first, newPoint.second);
            //cout << "ancestor of (" <<newPoint.first <<", " << newPoint.second << ") is (" << dis[newPoint].first << ", " << dis[newPoint].second << ")." << endl;
        }
        newPoint.second += 1;
        newPoint.first += 1;
        if(dis.count(newPoint)){
            //cout << "The point at (" << newPoint.first <<", " << newPoint.second << ") is now connected" << endl;
            dis[newPoint] = point;
            getAncestor(newPoint.first, newPoint.second);
            //cout << "ancestor of (" <<newPoint.first <<", " << newPoint.second << ") is (" << dis[newPoint].first << ", " << dis[newPoint].second << ")." << endl;
        }
        newPoint.second -= 2;
        if(dis.count(newPoint)){
            //cout << "The point at (" << newPoint.first <<", " << newPoint.second << ") is now connected" << endl;
            dis[newPoint] = point;
            getAncestor(newPoint.first, newPoint.second);
            //cout << "ancestor of (" <<newPoint.first <<", " << newPoint.second << ") is (" << dis[newPoint].first << ", " << dis[newPoint].second << ")." << endl;
        }
    }
    pair<int ,int> testP;
    testP.first = 0;
    testP.second = 2;
    //cout << "ancestor of (0, 2) is " << dis[testP].first << ", " << dis[testP].second << endl;
    for(std::map<pair<int, int>, pair<int, int> >::iterator it = dis.begin(); it != dis.end(); ++it){
        if(!pos.count(it->second)){
            pos.insert(it->second);
            cout << "New set containing " << it->second.first << ", " << it->second.second << endl;
        }
    }
    cout << pos.size() << endl;
}
