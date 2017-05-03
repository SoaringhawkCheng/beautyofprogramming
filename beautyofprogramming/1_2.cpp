//
//  1_2.cpp
//  beautyofprogramming_v1
//
//  Created by 追寻梦之碎片 on 2017/5/2.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution1{
public:
    void check(){
        int chess=0;
        for(setkingpos(chess);getkingpos(chess)<=9;moveking(chess)){
            for(setgeneralpos(chess);getgeneralpos(chess)<=9;movegeneral(chess)){
//                cout<<getkingpos(chess)<<" "<<getgeneralpos(chess)<<endl;
                if(getkingpos(chess)%3!=getgeneralpos(chess)%3){
                    cout<<"King:"<<getkingpos(chess)<<",General:"<<getgeneralpos(chess)<<endl;
                }
            }
        }
    }
private:
    void setkingpos(int &chess){
        chess&=0x1F;
    }
    void setgeneralpos(int &chess){
        chess&=0xF1;
    }
    int getkingpos(int chess){
        return (chess&0xF0)>>4;
    }
    int getgeneralpos(int chess){
        return (chess&0xF);
    }
    void moveking(int &chess){
        chess+=0x10;
    }
    void movegeneral(int &chess){
        chess+=0x1;
    }
};

class Solution2{
public:
    void check(){
        int pos=81;
        while(pos--){
            if(pos/9%3!=pos%9%3)
                cout<<"King:"<<pos/9+1<<",General:"<<pos%9+1<<endl;
        }
    }
};

class Solution3{
public:
    void check(){
        for(pos.king=1;pos.king<=9;++pos.king)
            for(pos.general=1;pos.general<=9;++pos.general)
                if(pos.king%3!=pos.general%3)
                    cout<<"King:"<<(int)pos.king<<",General:"<<(int)pos.general<<endl;
    }
private:
    struct{
        unsigned char king:4;
        unsigned char general:4;
    }pos;
};

int main(int argc,const char *argv[]){
    Solution3 s;
    s.check();
    return 0;
}
