#include <bits/stdc++.h>

using namespace std;
#include "BigDecimalIntClass.h"
#include "BigReal.h"

BigReal::BigReal()
{

}


BigReal::BigReal(string number) {
int index;
theNumber = number ;
if(number[0] == '+'){
number.erase(0,1);
NumberSign = '+';
}
else if (number[0] == '-'){
number.erase(0,1);
NumberSign = '-';
}
else{
NumberSign = '+';
}

index = number.find('.');
if (index == -1) {
    whole = number ;
    fraction = '0' ;
}
else if (index == 0) {
    fraction = number ;
    whole = '0' ;
}
else {


whole = number.substr(0 , index);
fraction = number.substr(index+1 , number.size());
sz = whole.size() + fraction.size() ;
}
}


//------------------------------------------------------------------//

BigReal::BigReal(double realNumber){

string number = to_string(realNumber) ;
int index ;
if(number[0] == '-'){
number.erase(0,1);
NumberSign = '-';
}
else{
NumberSign = '+';
}

index = number.find('.');
if (index == -1) {
    whole = number ;
    fraction = '0' ;
}
else if (index == 0) {
    fraction = number ;
    whole = '0' ;
}
else {


whole = number.substr(0 , index);
fraction = number.substr(index+1 , number.size());
sz = whole.size() + fraction.size() ;
}
}

//----------------------------------------------------------------------------//

ostream& operator<< (ostream& out , BigReal b) {

int counter = 0  ;
if (b.NumberSign == '-'){
out << b.NumberSign ;
}

for (int x= 0 ; x < b.whole.size() ; x++) {
    if (b.whole[x] != '0' ) {
        counter = 1;
        out << b.whole[x] ;
    }
    else if ((b.whole[x] == '0') &&(counter == 1)) {
        out << b.whole[x] ;
    }
    else {
        continue ;
    }

}
out << "." ;

for (int x= 0 ; x <b.fraction.size();x++) {
out << b.fraction[x] ;
}

return out ;
}
//------------------------------------------------------------------------------//

istream& operator >> (istream& in, BigReal& b1) {
cout << "please enter the real number : " ;
in >> b1.theNumber ;

int index ;
index = b1.theNumber.find('.');
if (index == -1) {
    b1.whole = b1.theNumber ;
    b1.fraction = '0' ;
    return in ;
}
else if (index == 0) {
    b1.fraction = b1.theNumber ;
    b1.whole = '0' ;
    return in ;
}
else {
b1.whole = b1.theNumber.substr(0 , index);
b1.fraction = b1.theNumber.substr(index+1 , b1.theNumber.size());
b1.sz = b1.whole.size() + b1.fraction.size();

return in ;

}

}

//------------------------------------------------------------------//
int BigReal::size() {
sz = whole.size() + fraction.size() ;

return sz ;

}

//-----------------------------------------------------------------------------------------//

int BigReal::sign() {
if (NumberSign == '+') {
    return 1 ;
}
else {
    return 0 ;
}

}

//------------------------------------------------------------------------------------------//



void BigReal :: fillzeros(string& a1 , string& a2){
    if (a1.size() > a2.size()){
            for (int i = a2.size() ; i < a1.size();i++){
                a2 += '0' ;
            }

    }
    else if (a1.size() < a2.size()){
        for(int i = a1.size();i < a2.size();i++){
            a1 += '0' ;
        }
    }
}

//------------------------------------------------------------------------------------------------//
void BigReal::fillzeros2(string&a1 , string&a2) {

    if (a1.size() > a2.size()){
            for (int i = a2.size() ; i < a1.size();i++){
                a2 ='0' + a2 ;
            }

    }
    else if (a1.size() < a2.size()){
        for(int i = a1.size();i < a2.size();i++){
            a1 = '0' + a1 ;
        }
    }


}
//------------------------------------------------------------------------//
string BigReal :: addition(string number1, string number2 , int& c) {
string result = "" ;
int x ;
 for(int y = number1.size() -1 ; y >=0 ;y-- ){
        x = (number1[y]-48)+(number2[y]-48)+c;

        if (x > 10){
                x %= 10;
                result += (x+48);
                c = 1;

        }
        else if (x == 10){
                result += '0';
                c = 1;
        }
        else{

            result += (x+48);
            c = 0;
        }

}
return result ;
}
//--------------------------------------------------------------------------------------------------------------------//


BigReal BigReal :: operator+ (BigReal num1){
    BigReal num2;
    //BigReal num3 = *this;
    int c = 0;
    int x;
    string number1 = fraction ,number2 = num1.fraction , number3 = whole , number4 = num1.whole;
    if (number1.size() != number2.size()) {
        fillzeros(number1 , number2 ) ;
    }
    if (number3.size()!=number4.size()) {
        fillzeros2(number3 , number4);
    }
    if (NumberSign == num1.NumberSign){
        num2.NumberSign = NumberSign; //++ --
        // 10 -100 + - subt
        // 10 + 100 - + subt

        num2.fraction = addition(number1 , number2 , c ) ;
        num2.whole = bo.addition(number3 , number4 , c) ;

    }
    else if (((NumberSign == '+')&&(num1.NumberSign =='-')) || ((NumberSign == '-')&&(num1.NumberSign =='+'))) {
        for (int x = 0 ; x < number3.size();x++) {
            if (number3[x] > number4[x]) {
            num2.NumberSign = NumberSign ;
            num2.fraction = subract(number1 , number2);
            num2.whole = bo.subtraction(number3 , number4 ) ;
            break ;
            }
            else if (number3[x] < number4[x]){
                num2.NumberSign = num1.NumberSign ;
                num2.fraction = subract(number1 , number2 ) ;
                num2.whole = bo.subtraction(number3 , number4 ) ;
                break ;
            }
            else if ((number3[x] == number4[x]) && ((x == number3.size()-1))) {
                for (int y = 0 ; y < number1.size();x++) {

                    if (number1[x] > number2[x]) {
                    num2.NumberSign = NumberSign ;
                    num2.fraction = subract(number1 , number2);
                    num2.whole = bo.subtraction(number3 , number4 ) ;
                    break ;
                    }
                    else if (number1[x] < number2[x]) {
                    num2.NumberSign = num1.NumberSign ;
                    num2.fraction = subract(number1 , number2 ) ;
                    num2.whole = bo.subtraction(number3 , number4 ) ;
                    break ;
                    }
                }
            }
        }
    }

    reverse (num2.fraction.begin() , num2.fraction.end()) ;
    reverse(num2.whole.begin(),num2.whole.end());
    return num2 ;
}
//------------------------------------------------------------------------------------------------//


string BigReal ::subract(string number1 , string number2) {
string result = "" ;

int counter = 0 ;
for (int x = number1.size() -1 ; x >=0 ;x--) {

if (number1[x] > number2[x]) {
    result += number1[x] - number2[x] + 48;
}
//2.1 = 0.8
//1.3
else if (number2[x] > number1[x]) {
if (x == 0) {

        for (int y = whole.size()-1;y >=0 ; y--) {
        START1:
        if (whole[y] > 0) {
            whole[y]-=1 ;
            number1[x]+=10 ;
            result+=number1[x]-number2[x]+48;
            break ;
        }
        else if (whole[y] == 0) {
            for (int w = 1 ; w < whole.size();x++) {
               if (whole[y-w] > 0) {
                whole[y-w]-=1 ;
                whole[y-w+1]+=10;
                goto START1 ;
               }
               else {
                continue ;
               }
            }
        }
}
}
else {
    START :
    if (number1[x-1] > 0) {
    number1[x-1] = number1[x-1] - 1 ;
    number1[x] += 10 ;
    result += number1[x] - number2[x] +48 ;
    }
    else {
        for (int w = 2 ; w <number1.size(); w++) {
            if (number1[x-w] >0) {
                number1[x-w] = number1[x-w] -1 ;
                number1[x-w+1] +=  10 ;
                goto START ;
                break ;
            }
            else {
                continue ;
            }
        }
    }

}

}
else {
    result += number1[x] - number2[x] +48 ;
    counter++;
}

}
if (counter == number1.size()) {
    result = '0' ;
}

return result ;


}
//------------------------------------------------------------------------//
BigReal BigReal :: operator- (BigReal num1){
    BigReal num2;
    int c = 0 ;
    string number1 = fraction , number2 = num1.fraction , number3 , number4  ;
    // ++ sub
    // +- add
    //-+ add and minus sign
    // -- sub and big number for sign
    if (number1.size() != number2.size()) {
        fillzeros(number1,number2);
    }
    if (NumberSign == '+' && num1.NumberSign == '+') {
    num2.fraction = subract(number1 , number2);
    number3 = whole ;
    number4 = num1.whole ;
    if (number3.size() != number4.size()) {
        fillzeros2(number3,number4) ;
    }
    num2.whole = bo.subtraction(number3 , number4) ;
    }

    else if (NumberSign == '+' && num1.NumberSign == '-') {
        num2.fraction = addition(number1 , number2 , c ) ;
        num2.whole = bo.addition(number3 , number4,c) ;
    }
    else if (NumberSign == '-' &&num1.NumberSign == '+') {
        num2.NumberSign = '-' ;
        num2.fraction = addition(number1 , number2 , c ) ;
        num2.whole = bo.addition(number3 , number4,c) ;
    }
    //-24
    //23
    else if (NumberSign == '-' &&NumberSign == '-') {
        for (int x = 0 ; x < number3.size();x++) {
            if (number3[x] > number4[x]) {
            num2.NumberSign = '-' ;
            num2.fraction = subract(number1 , number2);
            num2.whole = bo.subtraction(number3 , number4 ) ;
            break ;
            }
            else if (number3[x] < number4[x]){
                num2.NumberSign = '+' ;
                num2.fraction = subract(number1 , number2 ) ;
                num2.whole = bo.subtraction(number3 , number4 ) ;
                break ;
            }
            else if ((number3[x] == number4[x]) && ((x == number3.size()-1))) {
                for (int y = 0 ; y < number1.size();x++) {

                    if (number1[x] > number2[x]) {
                    num2.NumberSign = '-' ;
                    num2.fraction = subract(number1 , number2);
                    num2.whole = bo.subtraction(number3 , number4 ) ;
                    break ;
                    }
                    else if (number1[x] < number2[x]) {
                    num2.NumberSign = '+' ;
                    num2.fraction = subract(number1 , number2 ) ;
                    num2.whole = bo.subtraction(number3 , number4 ) ;
                    break ;
                    }
                }
            }
        }
    }

    reverse(num2.fraction.begin(),num2.fraction.end()) ;
    reverse(num2.whole.begin(),num2.whole.end());

    return num2 ;
}


//--------------------------------------------------------------------------------------//
bool BigReal::operator< (BigReal r1) {
   // /*
   string comp1 = whole , comp2 = r1.whole , comp3 = fraction , comp4 = r1.fraction ;
    if (fraction.size()!= r1.fraction.size()) {
    fillzeros(comp3 , comp4) ;
    }
    if (whole.size()!=r1.whole.size()){
        fillzeros2(comp1, comp2) ;
    }

    if(NumberSign == '-' && r1.NumberSign == '+')
    {
        return true;
    }
    else if(NumberSign == '+' && r1.NumberSign == '-')
    {
        return false;
    }

    else if(NumberSign == '+' && r1.NumberSign == '+')
    {
    for (long long  x =0 ; x < comp1.size() ; x++) {
        if (comp1[x] < comp2[x]) {
            return true;
            break ;
        }
        else if (comp1[x] > comp2[x]) {
            return false ;
            break ;
            }
        else if ((comp1[x] == comp2[x] ) && (x = comp1.size()-1)) {
            for (long long y = 0 ; y < comp3.size() ; y++ ) {
                if (comp3[y] < comp4[y]) {
                    return true ;
                    break ;
                }
                else if (comp3[y] > comp4[y]) {
                    return false ;
                    break ;
                }
            }

        }
    }
    }
    // -1.5
    //-2.5
    else if (NumberSign == '-' && r1.NumberSign == '-') {
        for (long long  x =0 ; x < comp1.size() ; x++) {
        if (comp1[x] < comp2[x]) {
            return false;
            break ;
        }
        else if (comp1[x] > comp2[x]) {
            return true ;
            break ;
            }
        else if ((comp1[x] == comp2[x] ) && (x = comp1.size()-1)) {
            for (long long y = 0 ; y < comp3.size() ; y++ ) {
                if (comp3[y] < comp4[y]) {
                    return false ;
                    break ;
                }
                else if (comp3[y] > comp4[y]) {
                    return true ;
                    break ;
                }
            }

        }
    }
    }

//*/
//return true ;

}


//--------------------------------------------------------------------//


bool BigReal::operator > (BigReal r1) {
   string comp1 = whole , comp2 = r1.whole , comp3 = fraction , comp4 = r1.fraction ;
    if (fraction.size()!= r1.fraction.size()) {
    fillzeros(comp3 , comp4) ;
    }
    if (whole.size()!=r1.whole.size()){
        fillzeros2(comp1, comp2) ;
    }

    if(NumberSign == '-' && r1.NumberSign == '+')
    {
        return false ;
    }
    else if(NumberSign == '+' && r1.NumberSign == '-')
    {
        return true ;
    }
    else if (NumberSign == '+' && r1.NumberSign == '+') {
        for (long long  x =0 ; x < comp1.size() ; x++) {
        if (comp1[x] < comp2[x]) {
            return false;
            break ;
        }
        else if (comp1[x] > comp2[x]) {
            return true ;
            break ;
            }
        else if ((comp1[x] == comp2[x] ) && (x = comp1.size()-1)) {
            for (long long y = 0 ; y < comp3.size() ; y++ ) {
                if (comp3[y] < comp4[y]) {
                    return false ;
                    break ;
                }
                else if (comp3[y] > comp4[y]) {
                    return true ;
                    break ;
                }
            }

        }
    }
    }
    else if (NumberSign == '-' && r1.NumberSign == '-') {
        for (long long  x =0 ; x < comp1.size() ; x++) {
        if (comp1[x] < comp2[x]) {
            return true;
            break ;
        }
        else if (comp1[x] > comp2[x]) {
            return false ;
            break ;
            }
        else if ((comp1[x] == comp2[x] ) && (x = comp1.size()-1)) {
            for (long long y = 0 ; y < comp3.size() ; y++ ) {
                if (comp3[y] < comp4[y]) {
                    return true ;
                    break ;
                }
                else if (comp3[y] > comp4[y]) {
                    return false ;
                    break ;
                }
            }

        }
    }

    }

}


//---------------------------------------------------------------------------------//
bool BigReal:: operator == (BigReal r1) {
   string comp1 = whole , comp2 = r1.whole , comp3 = fraction , comp4 = r1.fraction ;
    if (fraction.size()!= r1.fraction.size()) {
    fillzeros(comp3 , comp4) ;
    }
    if (whole.size()!=r1.whole.size()){
        fillzeros2(comp1, comp2) ;
    }

if (NumberSign == r1.NumberSign) {
       for (long long  x =0 ; x < comp1.size() ; x++) {
        if(comp1[x] != comp2[x]){
            return false ;
            break ;
        }
        else if (comp1[x] == comp2[x] && x ==  comp1.size()-1) {
                    for (long long  y =0 ; y < comp3.size() ; y++) {
                        if (comp3[x] != comp4[x]) {
                            return false ;

                        }
                        else if (comp3[x] == comp4[x] &&  y== comp3.size()-1) {
                            return true ;
                        }

                    }
        }
       }

}
else {
    return false ;
}


}





