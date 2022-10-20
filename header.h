
#include <bits/stdc++.h>
using namespace std;
class ClubStats {
private:
    queue<char>form;
    string name;
    int mp, gd, pts;
public:
    ClubStats();
    ClubStats(int &mp, int &gd, int &pts, queue<char> & form);
    void getStats() const;
};

class Club {
private:
    string name, stadium, foundingDate, country, league;
    ClubStats stats;
    map<string,vector<int>> trophies;
//    vector<player> players;
public:
    Club();
    Club(string &name, string &stadium, string &foundingDate, string &country, ClubStats &stats,
         map<string,vector<int>> &trophies,string &league);
    void getInfromation() const;
    void setInformation();
    void transferPlayerIn(string name);
    void transferPlayerOut(string name);
};

class Match{
private:
    string firstTeam, secondTeam;
    int goals1{}, goals2{};
    vector<string>goalScorers;
public:
    Match();
    Match(string &firstTeam, string &secondTeam, int &goals1, int& goals2, vector<string>&goalScorers);
};
// Change league, Add a match in the league