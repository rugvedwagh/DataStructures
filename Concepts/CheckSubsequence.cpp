bool isSub(string a, string b) {
    int ai = 0, bi = 0;

    while (ai < a.size() and bi < b.size()) {
        if (a[ai] == b[bi]) {
            ai++;
            bi++;
        } else {
            ai++;
        }
    }
    return bi == b.size();
}
