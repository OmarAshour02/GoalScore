#include "header.h"
// Club stats

ClubStats::ClubStats() {
    mp = gd = pts = 0;
    name = "N/A";
    form = queue<char>();
}
ClubStats::ClubStats(int &mp, int &gd, int &pts, queue<char> &form) : mp(mp), gd(gd), pts(pts), form(form) {}

void ClubStats::getStats() const {
    cout << "MP\tgd\tpts\t\tform";
    cout << mp << "\t" << gd << "\t"  << pts << "\t\t";
    queue <char> temp = form;
    while(!temp.empty()) {
        cout << temp.front();
        temp.pop();
    }
    cout << '\n';
}


// Club
Club::Club(string &name, string &stadium, string &foundingDate, string &country, ClubStats &stats,
           map<string,vector<int>> &trophies, string &league) : name(name), stadium(stadium), foundingDate(foundingDate),
                                                                  country(country), stats(stats), trophies(trophies), league(league){}

Club::Club() {
    name = stadium = foundingDate = country = league = "N/A";
    trophies = map<string,vector<int>>();
    stats = ClubStats();
}

void Club::getInfromation() const {
    char c = 'y';
    while(c == 'y') {
        cout << "Please choose number of the information of the club you need to represent : \n";
        cout << "1 : Club's name\n";
        cout << "2 : Club's stadium\n";
        cout << "3 : Club's founding date\n";
        cout << "4 : Club's country\n";
        cout << "5 : Club's stats\n";
        cout << "6 : Club's trophies\n";
        cout << "7 : Club's league\n";
        cout << "8 : All Club's information\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Club's name : " << name << '\n';
                break;
            }
            case 2: {
                cout << "Club's stadium : " << stadium << '\n';
                break;
            }
            case 3: {
                cout << "Club's founding date : " << foundingDate << '\n';
                break;
            }
            case 4: {
                cout << "Club's country : " << country << '\n';
                break;
            }
            case 5: {
                cout << "Club's stats : ";
                stats.getStats();
                break;
            }
            case 6: {
                if ((int) trophies.size()) {
                    cout << "Club's trophies : \n";
                    for(pair<string,vector<int>> trophie : trophies) {
                        cout << trophie.first << " ";
                        for (auto &x: trophie.second) {
                            cout << x << " ";
                        }
                        cout << '\n';
                    }
                } else {
                    cout << "The club has no trophies\n";
                }
                break;
            }
            case 7: {
                cout << "Club's league : " << league << '\n';
                break;
            }
            case 8: {
                cout << "Club's name : " << name << '\n';
                cout << "Club's stadium : " << stadium << '\n';
                cout << "Club's founding date : " << foundingDate << '\n';
                cout << "Club's country : " << country << '\n';
                cout << "Club's stats : ";
                stats.getStats();
                if ((int) trophies.size()) {
                    cout << "Club's trophies : \n";
                    for(pair<string,vector<int>> trophie : trophies) {
                        cout <<"The club won "<<trophie.first << (int)trophie.second.size() << " times in : ";
                        for (auto &x: trophie.second) {
                            cout << x << " ";
                        }
                        cout << '\n';
                    }
                } else {
                    cout << "The club has no trophies\n";
                }
                cout << "Club's league : " << league << '\n';
                break;
                default:
                    cout << "Enter a number from 1 - 8 \n";
                break;
            }
        }
        cout << "Do you want to know any other information ? (y/n)\n";
        cin >> c;
    }
}

void Club::setInformation() {
    char c = 'y';
    while(c == 'y') {
        cout << "Please choose number of the information of the club you need to change : \n";
        cout << "1 : Club's name\n";
        cout << "2 : Club's stadium\n";
        cout << "3 : Club's founding date\n";
        cout << "4 : Club's country\n";
        cout << "5 : Add a club Trophies\n";
        cout << "6 : Club's league\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string newName;
                cin >> newName;
                name = newName;
                cout << "Club's name is changed to " << name << " successfully ! \n";
                break;
            }
            case 2: {
                string newStadium;
                cin >> newStadium;
                stadium = newStadium;
                cout << "Club's stadium is changed to " << stadium << " successfully ! \n";
                break;
            }
            case 3: {
                string newFoundingDate;
                cin >> newFoundingDate;
                foundingDate = newFoundingDate;
                cout << "Club's founding date is changed to " << foundingDate << " successfully ! \n";
                break;
            }
            case 4: {
                string newCountry;
                cin >> newCountry;
                country = newCountry;
                cout << "Club's country is changed to " << country << " successfully ! \n";
                break;
            }
            case 5: {
                string trophie;
                cin >> trophie;
                cout << "In which year did the club win the trophie ?\n";
                int year;
                cin >> year;
                trophies[trophie].push_back(year);
                break;
            }
            case 6: {
                // Emad
                break;
            }
            default : {
                cout << "Enter a number between 1 - 6 \n";
                break;
            }
        }
        cout << "Do you want to change any other information ? (y/n)\n";
        cin >> c;
    }
}

//void Club::transferPlayerIn(string name) {
//    players.push_back(name);
//}
//
// void Club::transferPlayerOut(string name) {
//    for(int i = 0; i < (int)players.size();i++){
//        if(players[i].name == name){
//            players.erase(players.begin() + i);
//            break;
//        }
//    }
//}


Match::Match(){
    firstTeam = secondTeam = "N/A";
    goals1 = goals2 = -1;
    goalScorers = vector<string>();
}

Match::Match(string &firstTeam, string &secondTeam, int &goals1, int &goals2, vector<string> &goalScorers) : firstTeam(firstTeam), secondTeam(secondTeam),
goals1(goals1),goals2(goals2),goalScorers(goalScorers){}
