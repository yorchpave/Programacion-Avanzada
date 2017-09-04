nt last_word_len(char * string, int n) {
    int count = 0;
    int i = n - 1;
    for(i = n - 1; i >= 0; i--) {
        if(string[i] == ' ') {
            return count;
        }
        else {
            count++;
        }
    }
    if(i < 0) {
        return count;
    }
    return 0;
}
