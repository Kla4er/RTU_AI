#include <bits/stdc++.h>
using namespace std;


struct TCondition{
  int time; // atlikusais laiks
  bool first;
  bool second;
  bool third;
  bool fire;
  vector<int> child;
};

vector<TCondition> g;

void FillGraph(int ptime, bool pfirst, bool psecond, bool pthird, bool pfire, int parrent) {
  if (ptime < 0) return;

  TCondition current;
  current.time = ptime;
  current.first = pfirst;
  current.second = psecond;
  current.third = pthird;
  current.fire = pfire;

  int curpos = g.size();
  if (parrent != -1) g[parrent].child.push_back(curpos);
  g.push_back(current);

  if (pfirst && psecond && pthird) return;

  if (!pfirst && !psecond && !pfire) FillGraph(ptime - 3, 1, 1, pthird,!pfire, curpos);
  if (!pfirst && !pthird && !pfire)  FillGraph(ptime - 5, 1, psecond, 1,!pfire, curpos);
  if (!psecond && !pthird && !pfire) FillGraph(ptime - 5, pfirst, 1, 1,!pfire, curpos);

  if (pfirst && pfire)  FillGraph(ptime - 1, 0, psecond, pthird,!pfire, curpos);
  if (psecond && pfire) FillGraph(ptime - 3, pfirst, 0, pthird,!pfire, curpos);
  if (pthird && pfire)  FillGraph(ptime - 5, pfirst, psecond, 0,!pfire, curpos);
}

void DrawGrahp(int v) {
  cout << "Versotne numurs " << v << endl;
  cout << " laiks = " << g[v].time << "  pirmais = " << g[v].first << " otrais = " << g[v].second << " tresais = " << g[v].third << endl;
  if (g[v].child.size() > 0) {
      cout << "Pecteci = { ";
      for (auto u: g[v].child) {
        cout << u << "; ";
      }
      cout << "}" << endl << endl;
  }
  else cout << "Merka virsotne" << endl << endl;

  for (auto u: g[v].child) {
    DrawGrahp(u);
  }
}

int main() {
  FillGraph(12,0,0,0,0, -1);
  DrawGrahp(0);
  return 0;
}
