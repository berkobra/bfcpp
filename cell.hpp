#ifndef _CELLH_
#define _CELLH_


class cell{

    private:
        int val;
    public:
        cell(int val = 0);
        cell& operator++();
        cell& operator--();
        void setVal(int newVal);
        const int getVal();

};


#endif
