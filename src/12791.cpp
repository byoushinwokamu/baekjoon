#include <iostream>
#include <string>

using namespace std;
int ss[117];
int a;
string al[25] = {"1967 DavidBowie",
                 "1969 SpaceOddity",
                 "1970 TheManWhoSoldTheWorld",
                 "1971 HunkyDory",
                 "1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
                 "1973 AladdinSane",
                 "1973 PinUps",
                 "1974 DiamondDogs",
                 "1975 YoungAmericans",
                 "1976 StationToStation",
                 "1977 Low",
                 "1977 Heroes",
                 "1979 Lodger",
                 "1980 ScaryMonstersAndSuperCreeps",
                 "1983 LetsDance",
                 "1984 Tonight",
                 "1987 NeverLetMeDown",
                 "1993 BlackTieWhiteNoise",
                 "1995 1.Outside",
                 "1997 Earthling",
                 "1999 Hours",
                 "2002 Heathen",
                 "2003 Reality",
                 "2013 TheNextDay",
                 "2016 BlackStar"};

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  for (int i = 67; i < 117; i++) {
    if (i == 67 || (i >= 69 && i <= 77) || i == 79 || i == 80 || i == 83 ||
        i == 84 || i == 87 || i == 93 || i == 95 || i == 97 || i == 99 ||
        i == 102 || i == 103 || i == 113 || i == 116)
      a++;
    if (i == 73 || i == 77)
      a++;
    ss[i] = a;
  }
  int q, s, e;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> e;
    if (s < 1966)
      s = 1966;
    if (e < 1966)
      e = 1966;
    cout << (ss[e - 1900] - ss[s - 1901]) << '\n';
    for (int j = ss[s - 1901]; j < ss[e - 1900]; j++)
      cout << al[j] << '\n';
  }

  return 0;
}