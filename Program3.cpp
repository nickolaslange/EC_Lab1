#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;


int main () {

    //vectors to fill with dept preferences from file reading
    vector<int> dept0;
    vector<int> dept1;
    vector<int> dept2;
    vector<int> dept3;
    vector<int> dept4;

    //vectors to fill with prog preferences from file reading
    vector<int> prog0;
    vector<int> prog1;
    vector<int> prog2;
    vector<int> prog3;
    vector<int> prog4;

    ifstream f;
    f.open("matching-data.txt");

    if (!f.is_open())
    cout << "Error, file not found";

    //variable to fill with current int in the file
    int i;
    //counter for what int we're on
    int x = 1;

    //read file and fill vectors w/ progs and depts
    while (f >> i) {
        //fill dept1 vector
        if (x == 1 | x == 6 | x == 11 | x == 16 | x == 21) {
            dept0.push_back(i);
        }
        //fill dept2
        if (x == 2 | x == 7 | x == 12 | x == 17 | x == 22) {
            dept1.push_back(i);
        }
        //fill dept3
        if (x == 3 | x == 8 | x == 13 | x == 18 | x == 23) {
            dept2.push_back(i);
        }
        //fill dept4
        if (x == 4 | x == 9 | x == 14 | x == 19 | x == 24) {
            dept3.push_back(i);
        }
        //fill dept5
        if (x == 5 | x == 10 | x == 15 | x == 20 | x == 25) {
            dept4.push_back(i);
        }

        //fill prog1
        if (x == 26 | x == 31 | x == 36 | x == 41 | x == 46) {
            prog0.push_back(i);
        }
        //fill prog2
        if (x == 27 | x == 32 | x == 37 | x == 42 | x == 47) {
            prog1.push_back(i);
        }
        //fill prog3
        if (x == 28 | x == 33 | x == 38 | x == 43 | x == 48) {
            prog2.push_back(i);
        }
        //fill prog4
        if (x == 29 | x == 34 | x == 39 | x == 44 | x == 49) {
            prog3.push_back(i);
        }
        //fill prog5
        if (x == 30 | x == 35 | x == 40 | x == 45 | x == 50) {
            prog4.push_back(i);
        }
        //increment x counter for next input
        x++;
    }

        int row = 5;

        //vectors to fill with dept vectors from file reading earlier
        vector<vector<int>> dept(row);

        for (int j = 0; j < 5; j++) {
            dept[0].push_back(dept0[j]);
        }
        //fill dept1
        for (int j = 0; j < 5; j++) {
            dept[1].push_back(dept1[j]);
        }
        //fill dept2
        for (int j = 0; j < 5; j++) {
            dept[2].push_back(dept2[j]);
        }
        //fill dept3
        for (int j = 0; j < 5; j++) {
            dept[3].push_back(dept3[j]);
        }
        //fill dept4
        for (int j = 0; j < 5; j++) {
            dept[4].push_back(dept4[j]);
        }

        //vectors to fill with prog vectors from file reading earlier
        vector<vector<int>> prog(row);
        
        for (int j = 0; j < 5; j++) {
            prog[0].push_back(prog0[j]);
        }
        //fill dept1
        for (int j = 0; j < 5; j++) {
            prog[1].push_back(prog1[j]);
        }
        //fill dept2
        for (int j = 0; j < 5; j++) {
            prog[2].push_back(prog2[j]);
        }
        //fill dept3
        for (int j = 0; j < 5; j++) {
            prog[3].push_back(prog3[j]);
        }
        //fill dept4
        for (int j = 0; j < 5; j++) {
            prog[4].push_back(prog4[j]);
        }

        
        //vector to store each programers final choice
        //while loop will end when 
        vector<int> final_prog = {0, 0, 0, 0, 0};


        while (final_prog[0] == 0 && final_prog[1] == 0 && final_prog[2] == 0 && final_prog[3] == 0 && final_prog[4] == 0) {

            vector<int> dept_first = {dept[0][0], dept[1][0], dept[2][0], dept[3][0], dept[4][0]};

            //iterate until we reach the end of each depts first choice vector
            for (int i = 0; i < dept_first.size(); i++) {
                //num in vector that we are trying to find replicas of
                int compare_num = dept[i][0];
                vector<int> same_prog_pref = {i};
                for (int j = 1; j < dept_first.size(); j++) {
                    if (compare_num == dept[j][0]) {
                        same_prog_pref.push_back(j);
                    }
                }

               vector<int> prog_pref = {prog[compare_num][0], prog[compare_num][1], prog[compare_num][2], prog[compare_num][3], prog[compare_num][4]};
                

                //
                for (int k = 0; k < same_prog_pref.size(); k++) {
                    //variables to store pref
                    //A will be equal to whatever same index 0 is in prog_choice_pref
                    int a = 0, b = 0, c = 0, d= 0, e = 0;

                    for (int l = 0; l < 5; l++) {
                        if (same_prog_pref[k] == same_prog_pref[l]) {
                            int n = k;
                            switch (n) {
                                case '0':
                                    //if k = 0, its the first choice
                                    //l represents what index of prog_choice_pref its in
                                    a = l;
                                    break;
                                case '1':
                                    b = l;
                                    break;
                                case '2':
                                    c = l;
                                    break;
                                case '3':
                                    d = l;
                                    break;
                                case '4':
                                    e = l;
                                    break;
                            }
                        }
                    }
                    //find largest value of a through e
                    //fills vector largest_pref with largest value
                    //(i couldn't figure out how to delete the smaller values)
                    vector<int> largest_pref = {a, b, c, d, e};
                    for (int t = 0; t < 4; t++) {
                        int u = t+1;
                        if (largest_pref[t] > largest_pref[u]) {
                            largest_pref.at(u) = {largest_pref[t]};
                        }
                        else if (largest_pref[t] < largest_pref[u]) {
                            largest_pref.at(t) = {largest_pref[u]};
                        }
                        
                    }

                    int prog_choice = prog_pref[largest_pref[0]];
                    final_prog.at(compare_num) = {prog_choice};


                }
            }
        }
    
    //while loop has ended
    //print results
    for (int i = 0; i < 5; i++) {
        final_prog.at(i) = final_prog[i] + 1;
    }
    cout << "Programmer #1 chose Department #" << final_prog[0] << endl;
    cout << "Programmer #2 chose Department #" << final_prog[1] << endl;
    cout << "Programmer #3 chose Department #" << final_prog[2] << endl;
    cout << "Programmer #4 chose Department #" << final_prog[3] << endl;
    cout << "Programmer #5 chose Department #" << final_prog[4] << endl;

    return 0;

}