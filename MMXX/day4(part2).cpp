#include <bits/stdc++.h>
using namespace std;
using PassportData = map<string, string>;
vector<PassportData> passports;

void parse() {
    string line;
    PassportData passportData;
    while (getline(cin, line)) {
        if (line.empty()) {
            passports.push_back(passportData);
            passportData.clear();
            continue;
        }
        basic_istringstream<char> entryStream(line);
        string sToken;
        while (entryStream >> sToken) {
            auto splitIt = find(sToken.begin(), sToken.end(), ':');
            string key = string({sToken.begin(), splitIt});
            string data = string({splitIt + 1, sToken.end()});
            passportData[key] = data;
        }
    }
    passports.push_back(passportData);
}

pair<int, string> splitHgt(string hgt) {
    int hgtVal = 0, it = 0;
    while (isdigit(hgt[it])) {
        hgtVal = hgtVal * 10 + int(hgt[it] - '0');
        it++;
    }
    return make_pair(hgtVal, hgt.substr(it));
}

bool validateHCL(string hcl) {
    set<char> s = {'#'};
    for (char c = '0'; c <= '9'; c++)
        s.insert(c);
    for (char c = 'a'; c <= 'f'; c++)
        s.insert(c);
    for (char c : hcl)
        if (!s.count(c))
            return false;
    return true;
}

bool validatePassportData(PassportData passportData) {
    bool ok = true;
    int byr = atoi(passportData["byr"].c_str());
    ok = ok && (1920 <= byr && byr <= 2002);
    int iyr = atoi(passportData["iyr"].c_str());
    ok = ok && (iyr >= 2010 && iyr <= 2020);
    int eyr = atoi(passportData["eyr"].c_str());
    ok = ok && (2020 <= eyr && eyr <= 2030);
    //hgt
    int hgtVal;
    string hgtUnit;
    tie(hgtVal, hgtUnit) = splitHgt(passportData["hgt"]);
    if (hgtUnit == "cm")
        ok = ok && (150 <= hgtVal && hgtVal <= 193);
    else if (hgtUnit == "in")
        ok = ok && (59 <= hgtVal && hgtVal <= 76);
    else
        ok = false;
    //hcl
    ok = ok && validateHCL(passportData["hcl"]);
    const set<string> ss = {"amb", "blu", "blu", "gry", "grn", "hzl", "oth"};
    ok = ok && ss.count(passportData["ecl"]);
    ok = ok && (passportData["pid"].size() == 9);
    for (char c : passportData["pid"])
        if (!isdigit(c))
            ok = false;
    return ok;
}

int main() {
    freopen("text.in", "r", stdin);
    parse();
    cout << count_if(passports.begin(), passports.end(), [](PassportData passportData) {
        map<string, bool> reqKeyDetector {{"byr",false},{"iyr",false},{"eyr",false},{"hgt",false},{"hcl",false},{"ecl",false},{"pid",false}};
        for (auto it : passportData) {
            reqKeyDetector[it.first] = true;
        }
        return accumulate(reqKeyDetector.begin(), reqKeyDetector.end(), true, [](bool acVal, auto p) {
            return acVal && p.second;
        }) && validatePassportData(passportData);//*/
    }) << 'r' << endl;
    return 0;
}
