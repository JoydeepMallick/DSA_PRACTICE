//best for printing indices 
string read(int n, vector<int> book, int target)
{
    unordered_map<int, int> indof;
    for(int i = 0; i < n; i++){
        if(indof.find(target - book[i]) != indof.end()){
            return "YES";
        }
        indof[book[i]] = i;
    }
    return "NO";
}


//best if yes/no needed and no space allowed
string read(int n, vector<int> books, int target)
{
    sort(books.begin(), books.end());
    int lp = 0, rp = n-1;
    while(lp < rp){
        int sum = books[lp] + books[rp];
        if(sum == target) return "YES";
        if(sum < target) lp++;
        else rp--;
    }
    return "NO";
}
