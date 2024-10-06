

string dectobin(int num) {
  string res = "";
  while (num > 0) {
      res = to_string(num & 1) + res;
      num >>= 1;
  }
  return res.empty() ? "0" : res;
}


int bintodec(string s) {
  int decimal = 0;
  int n = s.size();
  int base = 1;
  int i = n-1;
  
  while(i>=0){
      if (s[i--] == '1') {
          decimal += base;
      }
      base*=2;
  }
  return decimal;
}
