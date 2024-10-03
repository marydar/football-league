#include <iostream>
#include <string.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <fstream>

using namespace std;

//////// Structs ///////
struct play
{
    char name[100];
    int price;
    int finishing;
    int speed;
    int defence;
    int teamid;
    char pose[50];
};
struct tim
{
    char name[100];
    int money;
    int member;
    int power;
    int goal0; // khorde
    int goal1; // zade
    int win;
    int lose;
    int draw;
    int score;
    int tgoal;
};

//////// Declarations ///////
void pbyweather(int tt1, int tt2, int *ti1, int *ti2, int *power1, int *power2, play *player);
void fmatch(int playerid, int teamid, int t1, int t2, play *player, tim *team);
void sell(int playerid, int teamid, int pid, int tid, play *player, tim *team);
void league(int playerid, int teamid, int t1, int t2, play *player, tim *team);
void buy(int playerid, int teamid, int pid, int tid, play *player, tim *team);
void Match(int playerid, int teamid, int t1, int t2, play *player, tim *team);
void sortPlayers(int pid, play *players, char *command);
void sorting(int teamid, int *sort, tim *team);
int loserGoal(int winnerGoal, int seed);
void recordplayer(int id, play *player);
void position(int pi, play *player);
void recordteam(int id, tim *team);
int prob(int seed);
int weather();
void tarkib(int tt1,int *ti1, play *player);


void colorYellow();
void colorGreen();
void colorWhite();
void colorBlue();
void colorPink();
void colorGrey();
void colorRed();

////////////// main ////////////////
int main()
{
    play player[550];
    tim team[50];
    int teamid = 1;
    int playerid = 1;

    char command[20];
    int pid;
    int tid;
    int t1, t2;

    while (1)
    {
        colorWhite();
        cin >> command;
        if (strcmp(command, "new") == 0)
        {
            cin >> command;
            if (strcmp(command, "player") == 0)
            {
                recordplayer(playerid, player);
                playerid++;
            }
            if (strcmp(command, "team") == 0)
            {
                recordteam(teamid, team);
                teamid++;
            }
        }
        if (strcmp(command, "buy") == 0)
        {
            cin >> pid >> tid;
            buy(playerid, teamid, pid, tid, player, team);
        }
        if (strcmp(command, "sell") == 0)
        {
            cin >> pid >> tid;
            sell(playerid, teamid, pid, tid, player, team);
        }
        if (strcmp(command, "friendlyMatch") == 0)
        {
            cin >> t1 >> t2;
            fmatch(playerid, teamid, t1, t2, player, team);
        }

        if (strcmp(command, "Match") == 0)
        {
            cin >> t1 >> t2;
            Match(playerid, teamid, t1, t2, player, team);
        }
        if (strcmp(command, "BeginLeague") == 0)
        {
            colorWhite();

            for (int i = 1; i < teamid; i++)
            {
                team[i].goal0 = 0;
                team[i].goal1 = 0;
                team[i].lose = 0;
                team[i].win = 0;
                team[i].draw = 0;
            }

            league(playerid, teamid, t1, t2, player, team);
        }
        if (strcmp(command, "Players") == 0)
        {
            cin >> command;
            sortPlayers(playerid, player, command);
        }

        if (strcmp(command, "end") == 0)
        {
            break;
        }
    }

    colorWhite();
    return 0;
}

/////////// Functions //////////////
void sortPlayers(int pid, play *players, char *command)
{
    int sort[pid];
    for (int i = 1; i < pid; i++)
    {
        sort[i] = i;
    }

    if (strcmp(command, "Speed") == 0)
    {
        for (int i = 1; i < pid - 1; i++)
        {
            for (int j = i; j < pid; j++)
            {
                if (players[sort[i]].speed < players[sort[j]].speed)
                {
                    int temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }

        colorBlue();
        cout << "Players By Speed \n";
        colorYellow();
        cout << "-----------------------\n";
        for (int i = 1; i < pid; i++)
        {
            colorWhite();
            cout << players[sort[i]].name;
            colorGrey();
            cout << "\t(" << players[sort[i]].speed << ")\n";
        }
    }
    if (strcmp(command, "Defense") == 0)
    {
        for (int i = 1; i < pid - 1; i++)
        {
            for (int j = i; j < pid; j++)
            {
                if (players[sort[i]].defence < players[sort[j]].defence)
                {
                    int temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }

        colorBlue();
        cout << "Players By Defense \n";
        colorYellow();
        cout << "-----------------------\n";

        for (int i = 1; i < pid; i++)
        {
            colorWhite();
            cout << players[sort[i]].name;
            colorGrey();
            cout << "\t(" << players[sort[i]].defence << ")\n";
        }
    }
    if (strcmp(command, "Finishing") == 0)
    {
        for (int i = 1; i < pid - 1; i++)
        {
            for (int j = i; j < pid; j++)
            {
                if (players[sort[i]].finishing < players[sort[j]].finishing)
                {
                    int temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }

        colorBlue();
        cout << "Players By Finishing \n";
        colorYellow();
        cout << "-----------------------\n";

        for (int i = 1; i < pid; i++)
        {
            colorWhite();
            cout << players[sort[i]].name;
            colorGrey();
            cout << "\t(" << players[sort[i]].finishing << ")\n";
        }
    }
    if (strcmp(command, "Price") == 0)
    {
        for (int i = 1; i < pid - 1; i++)
        {
            for (int j = i; j < pid; j++)
            {
                if (players[sort[i]].price < players[sort[j]].price)
                {
                    int temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }
        colorBlue();
        cout << "Players By Price \n";
        colorYellow();
        cout << "-----------------------\n";

        for (int i = 1; i < pid; i++)
        {
            colorWhite();
            cout << players[sort[i]].name;
            colorGrey();
            cout << "\t(" << players[sort[i]].price << ")\n";
        }
    }
    colorWhite();
}

void recordplayer(int id, play *player)
{
    cin >> player[id].name;
    cin >> player[id].price;
    cin >> player[id].speed;
    cin >> player[id].finishing;
    cin >> player[id].defence;
    player[id].teamid = 0;
}

void recordteam(int id, tim *team)
{
    cin >> team[id].name;
    cin >> team[id].money;
    team[id].member = 0;
}

void buy(int playerid, int teamid, int pid, int tid, play *player, tim *team)
{
    if (pid > playerid - 1)
    {
        cout << "player with the id playerID doesnt exist" << endl;
        return;
    }
    if (tid > teamid - 1)
    {
        cout << "team with the id teamID doesnt exist" << endl;
        return;
    }
    if (team[tid].member == 11)
    {
        cout << " team is full" << endl;
        return;
    }
    if (player[pid].teamid != 0)
    {
        cout << "player already has a team" << endl;
        return;
    }
    if (team[tid].money < player[pid].price)
    {
        cout << "the team cant afford to buy this player" << endl;
        return;
    }
    else
    {
        team[tid].money -= player[pid].price;
        team[tid].member++;
        player[pid].teamid = tid;
        cout << "player " << pid << " added to the team " << tid << " successfully" << endl;
    }
}

void sell(int playerid, int teamid, int pid, int tid, play *player, tim *team)
{
    if (pid > playerid - 1)
    {
        cout << "player with the id playerID doesnt exist" << endl;
        return;
    }
    if (tid > teamid - 1)
    {
        cout << "team doesnt exist" << endl;
        return;
    }
    if (player[pid].teamid != tid)
    {
        cout << "team doesnt have this player" << endl;
        return;
    }
    else
    {
        team[tid].money += player[pid].price;
        team[tid].member--;
        player[pid].teamid = 0;

        cout << "player " << pid << " removed from the team " << tid << " successfully" << endl;
    }
}

void fmatch(int playerid, int teamid, int t1, int t2, play *player, tim *team)
{
    int power1 = 0;
    int power2 = 0;
    if (t1 > teamid - 1 || t2 > teamid - 1)
    {
        cout << "team doesnt exist" << endl;
        return;
    }
    if (team[t1].member < 11 || team[t2].member < 11)
    {
        cout << "the game can not be held due to loss of the players" << endl;
        return;
    }

    for (int i = 1; i <= playerid - 1; i++)
    {
        if (player[i].teamid == t1)
        {
            power1 += player[i].speed + player[i].defence + player[i].finishing;
        }
        if (player[i].teamid == t2)
        {
            power2 += player[i].speed + player[i].defence + player[i].finishing;
        }
    }

    if (power1 == power2)
    {

        cout << "the match is draw" << endl;
        return;
    }

    if (power1 > power2)
    {
        cout << "team " << t1 << " win" << endl;
        return;
    }

    if (power1 < power2)
    {
        cout << "team " << t2 << " win" << endl;
        return;
    }
}

int weather(int seed)
{
    srand(time(0)+seed);
    return rand() % (4 + 1 - 1) + 1;
}

int loserGoal(int winnerGoal, int seed)
{
    srand(time(0) + seed);
    return rand() % (winnerGoal+1-0)+0;
}

int prob(int seed)
{
    srand(time(0) + seed);
    return rand() % 100;
}

void position(int pi, play *player)
{
    if (player[pi].defence > player[pi].finishing && player[pi].defence > player[pi].speed)
    {
        strcpy(player[pi].pose, "Defender");
    }
    else if (player[pi].finishing > player[pi].defence && player[pi].finishing > player[pi].speed)
    {
        strcpy(player[pi].pose, "Striker");
    }
    else if (player[pi].speed > player[pi].finishing && player[pi].speed > player[pi].defence)
    {
        strcpy(player[pi].pose, "Midfielder");
    }
    else
    {
        strcpy(player[pi].pose, "Normaler");
    }
}

void pbyweather(int tt1, int tt2, int *ti1, int *ti2, int *power1, int *power2, play *player)
{
    int weathernow = weather(ti1[0]*ti2[0]);
    if (weathernow == 1) // abri
    {
        cout << "\t\tWeather: Overcast" << endl;
        for (int i = 0; i < tt1 - 1; i++)
        {
            *power1 += player[ti1[i]].speed + player[ti1[i]].defence + player[ti1[i]].finishing;
            *power2 += player[ti2[i]].speed + player[ti2[i]].defence + player[ti2[i]].finishing;
        }
    }
    if (weathernow == 2) // barfi
    {
        cout << "\t\t Weather: Snowy" << endl;
        for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Defender") == 0)
            {
                *power1 += player[ti1[i]].speed - player[ti1[i]].defence + player[ti1[i]].finishing;
            }
            else
            {
                *power1 += player[ti1[i]].speed + player[ti1[i]].defence + player[ti1[i]].finishing;
            }
            if (strcmp(player[ti2[i]].pose, "Defender") == 0)
            {
                *power2 += player[ti2[i]].speed - player[ti2[i]].defence + player[ti2[i]].finishing;
            }
            else
            {
                *power2 += player[ti2[i]].speed + player[ti2[i]].defence + player[ti2[i]].finishing;
            }
        }
    }
    if (weathernow == 3) // ftabi
    {
        cout << "\t\t Weather: Sunny" << endl;
        for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Striker") == 0)
            {
                *power1 += player[ti1[i]].speed + player[ti1[i]].defence + player[ti1[i]].finishing - 10;
            }
            else
            {
                *power1 += player[ti1[i]].speed + player[ti1[i]].defence + player[ti1[i]].finishing;
            }
            if (strcmp(player[ti2[i]].pose, "Striker") == 0)
            {
                *power2 += player[ti2[i]].speed + player[ti2[i]].defence + player[ti2[i]].finishing - 10;
            }
            else
            {
                *power2 += player[ti2[i]].speed + player[ti2[i]].defence + player[ti2[i]].finishing;
            }
        }
    }
    if (weathernow == 4) // barani
    {
        cout << "\t\t Weather: Rainy" << endl;
        for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Midfielder") == 0)
            {
                *power1 += ((player[ti1[i]].speed - 1) / 2) + player[ti1[i]].defence + player[ti1[i]].finishing;
            }
            else
            {
                *power1 += player[ti1[i]].speed + player[ti1[i]].defence + player[ti1[i]].finishing;
            }
            if (strcmp(player[ti2[i]].pose, "Midfielder") == 0)
            {
                *power2 += ((player[ti2[i]].speed - 1) / 2) + player[ti2[i]].defence + player[ti2[i]].finishing;
            }
            else
            {
                *power2 += player[ti2[i]].speed + player[ti2[i]].defence + player[ti2[i]].finishing;
            }
        }
    }
}

void Match(int playerid, int teamid, int t1, int t2, play *player, tim *team)
{
    int ti1[100];
    int ti2[100];
    int power1 = 0;
    int power2 = 0;

    if (t1 > teamid - 1 || t2 > teamid - 1)
    {
        cout << "team doesnt exist" << endl;
        return;
    }
    if (team[t1].member < 11 || team[t2].member < 11)
    {
        cout << "the game can not be held due to loss of the players" << endl;
        return;
    }

    ////////////post///////////////
    int tt1 = 0;
    int tt2 = 0;
    for (int i = 1; i <= playerid - 1; i++)
    {
        if (player[i].teamid == t1)
        {
            position(i, player);
            ti1[tt1] = i;
            tt1++;
        }
        if (player[i].teamid == t2)
        {
            position(i, player);
            ti2[tt2] = i;
            tt2++;
        }
    }
    int ind;
    colorBlue();
    cout << "Team-" << t1 << " Squad                    Team-"<<t2<<" Squad\n";
    colorYellow();
    cout << "------------------              ------------------\n";
    for (int i = 0; i < tt1; i++)
    {
        colorWhite();
        cout << player[ti1[i]].name;
        colorGrey();
        cout << " (" << player[ti1[i]].pose << ")";
        cout<<"\t\t";
        colorWhite();
        cout << player[ti2[i]].name;
        colorGrey();
        cout << " (" << player[ti2[i]].pose << ")\n";
    }
    cout<<"\n";
    // colorBlue();
    // tarkib(tt1,ti1,player);
    /////////////////powers//////////////////
    colorRed();
    pbyweather(tt1, tt2, ti1, ti2, &power1, &power2, player);
    // tarkib(tt1,ti1,player);

    ///////////////judge/////////////////////
    if (power1 == power2)
    {
        int goals = loserGoal(5, t1 * t2);
        goals = loserGoal(goals, t1 * t2);//khata
        cout << "\t        Team-" << t2 << " " << goals << " - " << goals << " "
             << "Team-" << t1 << "\n";
        cout << "\t\t       Draw!" << endl;
        // for league
        team[t1].draw++;
        team[t2].draw++;
        team[t1].goal1 += goals;
        team[t1].goal0 += goals;
        team[t2].goal1 += goals;
        team[t2].goal0 += goals;
        team[t1].score += 1;
        team[t2].score += 1;
        return;
    }

    if (power1 > power2)
    {
        int p = prob(t1 * t2);
        int goal1, goal2;
        if (p <= 50)
            goal1 = 1;
        if (p > 50 && p <= 80)
            goal1 = 2;
        if (p > 80 && p <= 95)
            goal1 = 3;
        if (p > 95)
            goal1 = 4;
        // goal1 = loserGoal(goal1, t1 * t2);//khatadavari
        goal2 = loserGoal(goal1-1, t1 * t2);
        goal2 = loserGoal(goal2, t1 * t2);//khatadavari
        cout << "\t        Team-" << t1 << " " << goal1 << "-" << goal2 << " "
             << "Team-" << t2 << "\n";
        cout << "\t\t  Team-" << t1 << " Wins" << endl;
        // for league
        team[t1].win++;
        team[t2].lose++;
        team[t1].goal1 += goal1;
        team[t1].goal0 += goal2;
        team[t2].goal1 += goal2;
        team[t2].goal0 += goal1;
        team[t1].score += 3;
        team[t1].tgoal = team[t1].goal1 - team[t1].goal0;
        team[t2].tgoal = team[t2].goal1 - team[t2].goal0;
        return;
    }

    if (power1 < power2)
    {
        int goal1, goal2;
        int p = prob(t1 * t2);
        if (p <= 50)
            goal1 = 1;
        if (p > 50 && p <= 80)
            goal1 = 2;
        if (p > 80 && p <= 95)
            goal1 = 3;
        if (p > 95)
            goal1 = 4;
        // goal1 = loserGoal(goal1, t1 * t2);//khata
        goal2 = loserGoal(goal1-1, t1 * t2);
        goal2 = loserGoal(goal2, t1 * t2);//khata
        cout << "\t        Team-" << t2 << " " << goal1 << "-" << goal2 << " "
             << "Team-" << t1 << "\n";
        cout << "\t\t  Team-" << t2 << " Wins" << endl;
        // for league
        team[t1].lose++;
        team[t2].win++;
        team[t1].goal1 += goal2;
        team[t1].goal0 += goal1;
        team[t2].goal1 += goal1;
        team[t2].goal0 += goal2;
        team[t2].score += 3;
        team[t1].tgoal = team[t1].goal1 - team[t1].goal0;
        team[t2].tgoal = team[t2].goal1 - team[t2].goal0;
        return;
    }
}

void sorting(int teamid, int *sort, tim *team)
{
    for (int i = 1; i < teamid - 1; i++)
    {
        for (int j = i; j < teamid; j++)
        {
            if (team[sort[i]].score < team[sort[j]].score)
            {
                int temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
            else if (team[sort[i]].score == team[sort[j]].score && team[sort[i]].tgoal < team[sort[j]].tgoal)
            {
                int temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
}

void league(int playerid, int teamid, int t1, int t2, play *player, tim *team)
{
    ofstream LeagueFile("league.csv");
    ofstream LeaguepFile("league.txt");

    // Play matches
    for (int i = 1; i < teamid - 1; i++)
    {
        for (int j = i + 1; j < teamid; j++)
        {
            colorGreen();
            cout << endl
                 << "--------------- Team-" << i << " vs Team-" << j << " ---------------" << endl
                 << endl;
            Match(playerid, teamid, i, j, player, team);
            // Beep(800, 3000);
        }
    }

    // Sort teams by score
    int sort[teamid];
    for (int i = 1; i < teamid; i++)
    {
        sort[i] = i;
    }

    sorting(teamid, sort, team);

    // Draw Table
    colorBlue();
    cout << "\n\n\n  Team        Score           Goal+/-          Win            Loss            Draw            Diff\n";
    LeaguepFile << "\n\n\n  Team        Score           Goal+/-          Win            Loss            Draw            Diff\n";
    LeagueFile << "Team,Score,Goal+/-,Win,Loss,Draw,Diff\n";
    colorYellow();
    cout << "----------------------------------------------------------------------------------------------------------\n";
    LeaguepFile << "----------------------------------------------------------------------------------------------------------\n";
    for (int i = 1; i < teamid; i++)
    {
        colorGreen();
        cout << "    " << sort[i];
        LeaguepFile << "    " << sort[i];
        LeagueFile <<sort[i]<<",";
        colorYellow();
        cout << "\t|\t";
        LeaguepFile << "\t|\t";
        colorGreen();
        cout << team[sort[i]].score;
        LeaguepFile << team[sort[i]].score;
        LeagueFile << team[sort[i]].score<<",";
        colorYellow();
        cout << "\t|      ";
        LeaguepFile << "\t|      ";
        colorGreen();
        cout << team[sort[i]].goal1 << "-" << team[sort[i]].goal0;
        LeaguepFile << team[sort[i]].goal1 << "-" << team[sort[i]].goal0;
        LeagueFile << team[sort[i]].goal1 << "-" << team[sort[i]].goal0<<",";
        colorYellow();
        cout << "\t|\t";
        LeaguepFile << "\t|\t";
        colorGreen();
        cout << team[sort[i]].win;
        LeaguepFile << team[sort[i]].win;
        LeagueFile << team[sort[i]].win<<",";
        colorYellow();
        cout << "\t|\t";
        LeaguepFile << "\t|\t";
        colorGreen();
        cout << team[sort[i]].lose;
        LeaguepFile << team[sort[i]].lose;
        LeagueFile << team[sort[i]].lose<<",";
        colorYellow();
        cout << "\t|\t";
        LeaguepFile << "\t|\t";
        colorGreen();
        cout << team[sort[i]].draw;
        LeaguepFile << team[sort[i]].draw;
        LeagueFile << team[sort[i]].draw<<",";
        colorYellow();
        cout << "        |        ";
        LeaguepFile << "\t|        ";
        colorGreen();
        cout << team[sort[i]].tgoal << "\n";
        LeaguepFile << team[sort[i]].tgoal << "\n";
        LeagueFile << team[sort[i]].tgoal << ",\n";
    }
    LeagueFile.close();
    LeaguepFile.close();
}

void colorRed()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
}

void colorYellow()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
}

void colorWhite()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
}

void colorBlue()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
}

void colorGreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
}

void colorPink()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);
}

void colorGrey()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
}

void tarkib(int tt1,int *ti1, play *player)
{
    int flag=0;
    int y=0;
    for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Normaler") == 0 && flag==0)
            {
                cout<<"\t";
                cout<<player[ti1[i]].name;
                flag++;
                y++;
            }
            else if (strcmp(player[ti1[i]].pose, "Normaler") == 0 && flag ==1)
            {
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            if(flag%3==1) cout<<"\n";

        }
    flag=0;
    for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Defender") == 0 && y!=0)
            {
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            else if (strcmp(player[ti1[i]].pose, "Defender") == 0 && y==0)
            {
                cout<<"\t";
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            if(flag%3==1) cout<<"\n";

        }
    flag=0;
    for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Midfielder") == 0 && y!=0)
            {
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            else if (strcmp(player[ti1[i]].pose, "Midfielder") == 0 && y==0)
            {
                cout<<"\t";
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            if(flag%3==1) cout<<"\n";


        }
    flag=0;
    for (int i = 0; i < tt1 - 1; i++)
        {
            if (strcmp(player[ti1[i]].pose, "Striker") == 0 && y!=0)
            {
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            else if (strcmp(player[ti1[i]].pose, "Striker") == 0 && y==0)
            {
                cout<<"\t";
                cout<<player[ti1[i]].name<<"\t";
                flag++;
            }
            if(flag%3==1) cout<<"\n";


        }

}