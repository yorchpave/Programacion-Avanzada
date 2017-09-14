char* reverseString(char* s) {
 int l = 0;
 int r = strlen(s)-1;
 char c;
 
 while(l<r)
 {
     // swap chars
     c = s[l];
     s[l] = s[r];
     s[r] = c;
     l++;
     r--;
 }
 
 return s;
}
