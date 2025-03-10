class OneTab{
    public:
        string url;
        OneTab *next, *prev;
        OneTab() : url(""), next(nullptr), prev(nullptr) {};
        OneTab(string url) : url(url), next(nullptr), prev(nullptr) {};
        OneTab(string url, OneTab *next, OneTab *prev) : url(url), next(next), prev(prev) {};     
};

class BrowserHistory {
private:
    OneTab *currentPage = nullptr;
public:
    BrowserHistory(string homepage) {
        currentPage = new OneTab(homepage);
    }
    
    void visit(string url) {
        if(currentPage->next != nullptr){
            //free all nodes
            OneTab *curlink = currentPage->next;
            while(curlink != nullptr){
                OneTab *nextlink = curlink->next;
                delete curlink;
                curlink = nextlink;
            }
        }
        currentPage->next = new OneTab(url, nullptr, currentPage);
        currentPage = currentPage->next;
    }
    
    string back(int steps) {
        while(steps-- ){
            if(currentPage->prev != nullptr) currentPage = currentPage->prev;
            else break;
        }
        return currentPage->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if(currentPage->next != nullptr) currentPage = currentPage->next;
            else break;
        }
        return currentPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */