int maxLengthBetweenEqualCharacters(char* s) {
    int alphabet[27] = { -1, };
    for (int i = 0; i < 27; ++i) {
        alphabet[i] = -1;
    }
    int result = -1;
    int len;
    int pos = 0;

    for (char* c = s; *c; ++c) {
        int cur = *c - 97;
        if (alphabet[cur] == -1) {
            alphabet[cur] = pos;
        }
        else {
            len = pos - alphabet[cur] - 1;
            if (result < len) {
                result = len;
            }
        }

        pos++;
    }
    return result;
}
