


void MoveStrings(vector<string>& source, vector<string>& destination) {
    int size = source.size();
    for (int i = 0;i < size; i++) {
        destination.push_back(source[i]);

    }
    source.clear();
}