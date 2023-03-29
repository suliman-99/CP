#include <bits/stdc++.h>
using namespace std;

typedef vector<int>       vi;
typedef long long       ll;

// -----------------------------------------------------------------

template<typename T>
class SkippedArray{
    private:
        vi prev, next;
        vector<T> data;

    public:
        SkippedArray(vector<T> a){
            prev.resize(a.size()+1);
            next.resize(a.size()+1);
            for(int i = 0 ; i < prev.size() ; i ++) prev[i] = i-1;
            for(int i = 0 ; i < next.size() ; i ++) next[i] = i;
            data = a;
        }

        void set_prev(int idx, int pr){ prev[idx] = pr; }
        void set_next(int idx, int nx){ next[idx+1] = nx; }

        int get_prev(int idx){ return prev[idx]; }
        int get_next(int idx){ return next[idx+1]; }

        void skip(int idx){
            int pr = get_prev(idx);
            int nx = get_next(idx);
            set_next(pr, nx);
            set_prev(nx, pr);
        }

        T& operator[](int idx){
            return data[idx];
        }

        struct Iterator{
            using iterator_category = forward_iterator_tag;
            using difference_type   = ptrdiff_t;
            using value_type        = T;
            using pointer           = T*;
            using reference         = T&;

            private:
                SkippedArray sa;
                int idx;

            public:
                Iterator(int _idx, SkippedArray _sa) : idx(_idx), sa(_sa) {}

                reference operator*(){ return sa.data[idx]; }
                pointer operator->(){ return &sa.data[idx]; }

                Iterator& operator++(){ idx = sa.get_next(idx); return *this; }  
                Iterator operator++(int){ ++*this; return *this; }
                Iterator& operator--(){ idx = sa.get_prev(idx); return *this; }
                Iterator operator--(int){ --*this; return *this; }

                friend bool operator==(const Iterator& a, const Iterator& b){ return a.idx == b.idx; };
                friend bool operator!=(const Iterator& a, const Iterator& b){ return a.idx != b.idx; }; 
                friend bool operator<(const Iterator& a, const Iterator& b){ return (a.idx < b.idx); }
                friend bool operator>(const Iterator& a, const Iterator& b){ return (a.idx > b.idx); }
                friend bool operator<=(const Iterator& a, const Iterator& b){ return (a.idx <= b.idx); }
                friend bool operator>=(const Iterator& a, const Iterator& b){ return (a.idx >= b.idx); }    
        };

        Iterator begin(){ return Iterator(get_next(-1), *this); }
        Iterator end(){ return Iterator(data.size(), *this); }
        Iterator rbegin(){ return Iterator(get_prev(data.size()), *this); }
        Iterator rend(){ return Iterator(-1, *this); }
};


