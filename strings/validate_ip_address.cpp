// 0 - 3 months:
// Apple (2) — Flexport (2) — Turing (2)

// 6 months ago:
// Meta (13) — Microsoft (9) — Amazon (8) — TikTok (6) — Oracle (4) — ServiceNow
// (3) — Sprinklr (3) — Cisco (2) — Nvidia (2) — X (2)

// problem Link: https://leetcode.com/problems/validate-ip-address/description/

#include <bits/stdc++.h>
using namespace std;

bool isIpv4(string ip) {
  vector<string> parts;
  stringstream ss(ip);
  string temp;
  while (getline(ss, temp, '.')) {
    parts.push_back(temp);
  }

  if(parts.size() != 4){
    return false;
  }

  for (auto part : parts) {
    if (part.empty()) {
      return false;
    }

    if (part.size() > 3) {
      return false;
    }

    if (part.size() > 1 && part[0] == '0') {
      return false;
    }

    for (auto s : part) {
      if (!isdigit(s)) {
        return false;
      }
    }
    int num = stoi(part);
    if (num > 255) {
      return false;
    }
  }
  return true;
}

bool isIpv6(string ip) {
  vector<string> parts;
  stringstream ss(ip);
  string temp;
  while (getline(ss, temp, ':')) {
    parts.push_back(temp);
  }
  if(parts.size() != 8){
    return false;
  }
  for (auto part : parts) {
    if (part.empty() || part.size() > 4) {
      return false;
    }

    for (auto s : part) {
      if (!(isdigit(s) || (s >= 'a' && s <= 'f') || (s >= 'A' && s <= 'F'))) {
        return false;
      }
    }
  }
  return true;
}

string validIPAddress(string queryIP) {
  string ans = "Neither";
  if (count(queryIP.begin(), queryIP.end(), '.') == 3) {
    if (isIpv4(queryIP)) {
      ans = "IPv4";
    }
  }

  if (count(queryIP.begin(), queryIP.end(), ':') == 7) {
    if (isIpv6(queryIP)) {
      ans = "IPv6";
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string ip = "172.16.254.1";

  string ans = validIPAddress(ip);
  cout << ans << "\n";
}