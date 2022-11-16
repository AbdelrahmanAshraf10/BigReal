#ifndef BIGREAL_H
#define BIGREAL_H


class BigReal
{
    public:
        BigReal();
        BigReal(string ) ;
        BigReal(double realNumber);
        string addition(string , string , int&) ;
        string subract(string, string) ;
        BigReal operator+ (BigReal b1 ) ;
        BigReal operator- (BigReal b1 ) ;
        int size();
        int sign();
        bool operator < (BigReal);
        bool operator > (BigReal);
        bool operator == (BigReal );
        friend ostream& operator << (ostream& out, BigReal num);
        friend istream& operator >> (istream& out, BigReal& num);
        void fillzeros(string& , string& );
        void fillzeros2(string& , string&);
        protected:
        private:
        int sz ;
        char NumberSign ;
        string theNumber , whole , fraction ;
        int carry ;
        BigDecimalInt bo ;

};

#endif // BIGREAL_H
