#include <bits/stdc++.h>
using namespace std;


struct TCondition{
  int time; // atlikusais laiks
  bool first;
  bool second;
  bool third;
  vector<int> child;
};

vector<TCondition> g;

void FillGraph(int ptime, bool pfirst, bool psecond, bool pthird, int parrent) {
  if (ptime < 0) return;

  TCondition current;
  current.time = ptime;
  current.first = pfirst;
  current.second = psecond;
  current.third = pthird;

  int curpos = g.size();
  if (parrent != -1) g[parrent].child.push_back(curpos);
  g.push_back(current);

  if (pfirst && psecond && pthird) return;

  if (!pfirst && !psecond) FillGraph(ptime - 3, 1, 1, pthird, curpos);
  if (!pfirst && !pthird)  FillGraph(ptime - 5, 1, psecond, 1, curpos);
  if (!psecond && !pthird) FillGraph(ptime - 5, pfirst, 1, 1, curpos);

  if (pfirst)  FillGraph(ptime - 1, 0, psecond, pthird, curpos);
  if (psecond) FillGraph(ptime - 3, pfirst, 0, pthird, curpos);
  if (pthird)  FillGraph(ptime - 5, pfirst, psecond, 0, curpos);
}

void DrawGrahp(int v) {
  cout << "Versotne numurs " << v << endl;
  cout << " laiks = " << g[v].time << "  pirmais = " << g[v].first << " otrais = " << g[v].second << " tresais = " << g[v].third << endl;
  cout << "Pecteci = { ";
  for (auto u: g[v].child) {
    cout << u << "; ";
  }
  cout << "}" << endl << endl;

  for (auto u: g[v].child) {
    DrawGrahp(u);
  }
}

int main() {
  FillGraph(12,0,0,0, -1);
  DrawGrahp(0);
  return 0;
}
