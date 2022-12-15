/*
This file is a kind of Operating System but now it's only a shell.
Copyright (C) 2022 HelloOSMe 
This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
Also add information on how to contact you by electronic and paper mail.
*/
/***============代码正式开始=============***/
#ifndef __HelloOS
#define __HelloOS
/*---------头文件及必要命令区---------*/
#include<bits/stdc++.h>
#include<unistd.h>//又能用了
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::iostream;
//====如果是Windows端====
#if defined(_WIN32)||defined(_AMD64)||defined(_ARM64)
#define SYSTEM 1
#include<windows.h>//WinAPI包含Sleep
#define cls system("cls")
#define c_normal system("color")
#define f_cyan color("09")
#define f_purple color("05")
#define f_blue color("01")
#define f_yellow color("06")
#define f_green color("02")
#define f_red color("04")
#define f_grey color("08")
void color(string cl){
    //cout<<"Windows端不支持!请输入DOS再使用!"<<endl;
    for(int i=0;i<cl.size();i++){
        if(cl[i]>='a'&&cl[i]<='z'){
            cl[i]=cl[i]-32;
        }
    } 
    if(cl=="HELP"){
        system("color /?");
    }else if(cl=="NORMAL"){
        c_normal;
    }
    int a,b;
    if(cl[0]>='0'&&cl[0]<='9'){
        a=cl[0]-'0';
    }else{
        a=cl[0]-55;
    }
    if(cl[1]>='0'&&cl[1]<='9'){
        b=cl[1]-'0';
    }else{
        b=cl[1]-55;
    }
    if(cl=="normal"){
        a=0;b=0;
    }
    HANDLE handle;//1
    handle=GetStdHandle(STD_OUTPUT_HANDLE);//2
    SetConsoleTextAttribute(handle,a*16+b);//3 ----WinAPI
}
string colorset;//Windows没用 
//=====如果是Linux端=====
#else
#define SYSTEM 0
#define clear cout<<"\033c"
void Sleep(int a){
    usleep(a*1000);
}//自定Sleep
#define c_normal cout<<"\033[000m"
#define f_cyan cout<<"\033[36;1m"
#define f_purple cout<<"\033[35;1m"
#define f_blue cout<<"\033[34;1m"
#define f_yellow cout<<"\033[33;1m"
#define f_green cout<<"\033[32;1m"
#define f_red cout<<"\033[31;1m"
#define f_grey cout<<"\033[30;1m"
string colorset="normal";
void cls();
extern void color(string s){
    if(s=="help"){
        cout<<"Linux:  输入"<<endl;
        cout<<"normal  默认"<<endl;
        cout<<"hide    \033[31;1m停用\033[000m"<<endl;
        cout<<"show    \033[31;1m停用\033[000m"<<endl;
        cout<<"0         灰"<<endl;
        cout<<"1         红"<<endl;
        cout<<"2         绿"<<endl;
        cout<<"3         黄"<<endl;
        cout<<"4         蓝"<<endl;
        cout<<"5         紫"<<endl;
        cout<<"6         青"<<endl;
        return;
    }
    if(s=="normal"){
        c_normal;
        colorset=s;
        return;
    }else if(s=="hide"||s=="show"){
        cout<<"\033[31;1m命令已停用\033[000m"<<endl;
        return;
    }
    switch(s[0]){
        case '0':
            colorset=s;
            f_grey;
            break;
        case '1':
            colorset=s;
            f_red;
            break;
        case '2':
            colorset=s;
            f_green;
            break;
        case '3':
            colorset=s;
            f_yellow;
            break;
        case '4':
            colorset=s;
            f_blue;
            break;
        case '5':
            colorset=s;
            f_purple;
            break;
        case '6':
            colorset=s;
            f_cyan;
            break;
        default:
            cout<<"Error!"<<endl;
    }
}
void cls(){
    clear;
    if(colorset=="normal"){
        //无操作(退出函数)
    }else{
        color(colorset);
    }
}
#define cls cls()
#endif
//=======end=======
//==unistd不可用?==
#ifndef UNISTD_H
extern "C" int usleep(useconds_t __useconds);//unistd.h的usleep修复
#endif
//=======end=======
#define Utc 8
#define GT_YEA 0x000000
#define GT_MON 0x000001
#define GT_DAY 0x000002
#define GT_HOU 0x000003
#define GT_MIN 0x000004
#define GT_SEC 0x000005
#define HelloMain main
/*---------------变量区---------------*/
int ver=0;
char* path;
string user,passwd="ZZM@20090309",passdev="text";
char Where[4][22]={
    "H:\%-# ",
    "H:\%System-# ",
    "H:\%Software-# ",
    "H:\%Software\%Dos-# ",
};
int x=31,y=45;
char hlp[31][45]={
    "---------------help---------------",
    "ABOUT                         关于",
    "BASIC                 进入标准模式",
    "BREAK                   退出文件夹",
    "CD                      进入文件夹",
    "CHGPASS         更改密码(仅管理员)",
    "CHGUSER                 更改用户名",
    "CHKVER                    检测版本",
    "CLS/CLEAR                     清屏",
    "CLOSE                         关机",
    "COLOR                     更改颜色",
    "COP                       查看版权",
    "DIR                显示H盘所有文件",
    "DOS             DOS模式(仅Windows)",
    "HELP                          帮助",
    "I                       查看用户名",
    "INSYS               进入系统文件夹",
    "JAVA              编写JAVA(不可用)",
    "FORMAT                      格式化",
    "LOGOFF                    注销用户",
    "OPEN                  打开文本文件",
    "PY                      编写python",
    "RUN                           打开",
    "REBOOT                        重启",
    "STORE                   HelloStore",
    "SYSTEM                       ABOUT",
    "TIME                      获取时间",
    "TREE                  查看磁盘空间",
    "VERSION/VER           查看系统版本",
    "VIRUS                     检测病毒",
    "----------------------------------"
};
int ax=13,ay=45;
char aboutsys[13][45]={
    "----------About System----------",
    "        ----[]        []        ",
    "            []        []        ",
    "        ----[][][][][][]        ",
    "            []        []        ",
    "            []        []        ",
    "        ----[]<><><><>[]        ",
    "HelloOS System 1.0 D30M8Y22     ",
    "操作系统内部版本[300822.4329]   ",//ver
    "HelloOS 普通版 ",
    "内核:HelloNT 1.0                ",
    "--------------------------------"
};
int cx=10,cy=21;
char corp[10][21]={
    "-----Copiright------",
    "    []        []    ",
    "   []        []     ",
    "  []        []      ",
    "   [][][][][][]     ",
    "    []        []    ",
    "     []        []   ",
    "    []        []    ",
    "(c) 2022 HelloOSMe  ",
    "--------------------"
};
int wr=0;
bool basic=0,jiami=0;
short admin=0;
/*------------预定义函数区------------*/
/**共21个函数**/
int GetTimes(int lei);
string GetCmd(string str,int num);
void loading(int num);//Loading动画
void nlogo(int space);
void Logo();
void logo();
void root();//建立虚拟驱动
void newload(int num);
void Start();//开机
void Welcome();
string bts(string str);
void users();//用户，你好
void where(int a);//盘符
void close();
void PrintTime();
void DOSES();
void HAV();
void kill();
void HelloStore();
void HelloUpdata();
void Encrypt();
void Basic();
void jihuo();
void readfile(char filename[]);
void run(string mingling);
void input();
/*---------------次函数区---------------*/
void run(string mingling){
    int a,b,c;
    string str=mingling;
    mingling=bts(mingling);
    mingling=GetCmd(mingling,0);
    str=GetCmd(str,0);
    if(mingling=="help"){
        for(a=0;a<x;a++){
            for(b=0;b<y;b++){
                cout<<hlp[a][b];
            }
            cout<<endl;
        }
        if(basic){
            cout<<"DOS HELPS:"<<endl;
            system("help");
            cout<<"----------------------------------"<<endl;
        }
    }else if(mingling=="about"||mingling=="system"){
        for(a=0;a<ax;a++){
            for(b=0;b<ay;b++){
                cout<<aboutsys[a][b];
            }
            cout<<endl;
        }
    }else if(mingling=="basic"){
        if(basic==0){
            cout<<"-----HelloOS Dos Basic-----"<<endl;
            basic=1;
            Basic();
        }else{
            cout<<"---------End Basic---------"<<endl;
            basic=0;
        }
    }else if(mingling=="break"){
        if(wr==0){
            cout<<"这已是H磁盘!"<<endl;
        }else if(wr==3){
            wr=2;
        }else{
            wr=0;
        }
    }else if(mingling=="chguser"){
        cout<<"--------用户名设置---------"<<endl;
        string pass,userses;
        cout<<"更改用户名：";
        cin>>userses;
        if(user==userses){
            cout<<"用户名一致！"<<endl;
            cout<<"---------------------------"<<endl;
            return;
        }
        if(userses=="Admin"){
            for(int e=9;;){
                cout<<"输入密码(exit退出):";
                cin>>pass;
                if(pass==passwd){
                    admin=1;
                    jiami=1;
                    user=userses;
                    break;
                }else if(pass=="exit"){
                    jiami=0;
                    user="默认user";
                    break;
                }else if(e!=1&&e<=6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n你还有"<<e<<"次机会。请重新";
                }else if(e>6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n请重新";
                }else if(e==1){
                    cout<<"密码错误5次，终止认证。"<<endl;
                    Sleep(3000);
                    jiami=0;
                    user="默认user";
                    break;
                }
            }
            cls;
        }else if(userses=="Dev"){
            for(int e=9;;){
                cout<<"输入密码(exit退出):";
                cin>>pass;
                if(pass==passdev){
                    admin=1;jiami=1;
                    user=userses;
                    break;
                }else if(pass=="exit"){
                    user="默认user";jiami=0;
                    break;
                }else if(e!=1&&e<=6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n你还有"<<e<<"次机会。请重新";
                }else if(e>6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n请重新";
                }else if(e==1){
                    cout<<"密码错误5次，终止认证。"<<endl;
                    Sleep(3000);jiami=0;
                    user="默认user";
                    break;
                }
            }
            cls;
        }else{
            user=userses;
            jiami=0;
            admin=0;
        }
        cout<<"Downloading Files ";
        loading(24);
        cout<<endl<<"更改完成,"<<user<<endl;
        cout<<"---------------------------"<<endl;
    }else if(mingling=="cls"||mingling=="clear"){
        cls;
    }else if(mingling=="close"){
        free(path);
        close();
        exit(0);
    }else if(mingling=="dir"){
        cout<<"-----------dir------------"<<endl;
        cout<<"H"<<endl;
        cout<<"|-System"<<endl;
        cout<<"| |-HelloOS.sys"<<endl;
        cout<<"| |-Start.sys"<<endl;
        cout<<"| |-User.sys"<<endl;
        cout<<"| |-Run.sys"<<endl;
        cout<<"| |-runsys.hexe"<<endl;
        cout<<"| |-runsys.hdll"<<endl;
        cout<<"| |-runhdll.hexe"<<endl;
        cout<<"| |-HelloStore.hexe"<<endl;
        cout<<"|-Software"<<endl;
        cout<<"  |-Dos"<<endl;
        cout<<"  | |-Dos.hexe"<<endl;
        cout<<"  | |-Dos.hdll"<<endl;
        cout<<"  |-HelloAntiVirus.hexe"<<endl;
        if(jiami==1){
            cout<<"  |-HelloEncrypt.hexe"<<endl;
        }
        cout<<"--------------------------"<<endl;
    }else if(mingling=="dos"){
        DOSES();
    }else if(mingling=="cd"){
        cout<<"--------文件夹进入---------"<<endl;
        if(wr==0){
            cout<<"选择文件夹:System"<<endl;
            cout<<"           Software"<<endl;
            cin>>str;
            if(str=="System"){
                wr=1;
            }else if(str=="Software"){
                wr=2;
            }else{
                cout<<"没有此文件夹!"<<endl;
            }
        }else if(wr==2){
            cout<<"选择文件夹:Dos"<<endl;
            cin>>str;
            if(str=="Dos"){
                wr=3;
            }else{
                cout<<"没有此文件夹!"<<endl;
            }
        }else if(wr==5){
            cout<<"权限不够，无法查看宿主系统文件"<<endl;
        }else{
            cout<<"没有文件夹!"<<endl;
        }
        cout<<"---------------------------"<<endl;
    }else if(mingling=="i"){
        cout<<"--------用户名查看---------"<<endl;
        cout<<"用户名:"<<user<<endl;
        cout<<"---------------------------"<<endl;
    }else if(mingling=="java"){
        cout<<"命令不可用!"<<endl;
    }else if(mingling=="py"){
        system("python");
    }else if(mingling=="run"){
        cout<<"-----------打开------------"<<endl;
        cout<<"文件名:";
        char fn[100];
        cin>>fn;
        if(wr==2){
            if(fn=="HelloAntiVirus.hexe"){
                cout<<"---------------------------"<<endl;
                HAV();
            }else if(fn=="HelloEncrypt.hexe"&&jiami==1){
                cout<<"---------------------------"<<endl;
                Encrypt();
            }else{
                cout<<"无此文件！"<<endl;
                cout<<"---------------------------"<<endl;
            }
        }else if(wr==1){
            if(fn=="HelloOS.sys"||fn=="Start.sys"||fn=="User.sys"||fn=="Run.sys"){
                cout<<"系统文件无法查看!"<<endl;
                cout<<"---------------------------"<<endl;
            }else if(fn=="runsys.hexe"||fn=="runhdll.hexe"){
                cout<<"应用没有输入文件！"<<endl;
                cout<<"---------------------------"<<endl;
            }else if(fn=="runsys.hdll"){
                cout<<"应用扩展文件无法查看！"<<endl;
                cout<<"---------------------------"<<endl;
            }else if(fn=="HelloStore.hexe"){
                cout<<"---------------------------"<<endl;
                HelloStore();
            }else{
                cout<<"无此文件！"<<endl;
                cout<<"---------------------------"<<endl;
            }
        }else if(wr==3){
            if(fn=="Dos.hexe"){
                cout<<"---------------------------"<<endl;
                DOSES();
            }else if(fn=="Dos.hdll"){
                cout<<"应用扩展文件无法查看！"<<endl;
                cout<<"---------------------------"<<endl;
            }else{
                cout<<"无此文件！"<<endl;
                cout<<"---------------------------"<<endl;
            }
        }else{
            system(fn);
            cout<<"---------------------------"<<endl;
        }
    }else if(mingling=="reboot"){
        free(path);
        close();
        cls;
        Sleep(4291);
        Start();//开机
        Welcome();//用户，你好
        cout<<"输入<help>获取帮助。"<<endl;
    }else if(mingling=="ver"||mingling=="version"){
        cout<<"----------系统版本-----------"<<endl;
        cout<<"HelloOS System 1.0 D30M8Y22  "<<endl;
        cout<<"操作系统内部版本[300822.4329]"<<endl;//若改变，about也要更改
        cout<<"-----------------------------"<<endl;
    }else if(mingling=="chgpass"){
        cout<<"---------密码设置----------"<<endl;
        if(admin==1){
            string pass;
            for(int e=9;;){
                cout<<"输入密码(exit退出):";
                cin>>pass;
                if(pass==passwd){
                    cout<<"输入新密码:";
                    cin>>passwd;
                    cls;
                    cout<<"更改成功！"<<endl;
                    break;
                }else if(pass=="exit"){
                    cout<<"---------------------------"<<endl;
                    return;
                }else if(e!=1&&e<=6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n你还有"<<e<<"次机会。请重新";
                }else if(e>6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n请重新";
                }else if(e==1){
                    cout<<"密码错误5次，终止认证。"<<endl;
                    cout<<"---------------------------"<<endl;
                    return;
                }
            }
            cls;
        }else if(admin==2||user=="Dev"){
            string pass;
            for(int e=9;;){
                cout<<"输入密码(exit退出):";
                cin>>pass;
                if(pass==passdev){
                    cout<<"输入新密码:";
                    cin>>passdev;
                    cls;
                    cout<<"更改成功！"<<endl;
                    break;
                }else if(pass=="exit"){
                    cout<<"---------------------------"<<endl;
                    return;
                }else if(e!=1&&e<=6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n你还有"<<e<<"次机会。请重新";
                }else if(e>6){
                    e--;
                    cls;
                    cout<<"*密码错误!\n请重新";
                }else if(e==1){
                    cout<<"密码错误5次，终止认证。"<<endl;
                    cout<<"---------------------------"<<endl;
                    return;
                }
            }
            cls;
        }else{
            cout<<"您不是管理员!\n";
        }
        cout<<"---------------------------"<<endl;
    }else if(mingling=="virus"){
        HAV();
    }else if(mingling=="format"){
        kill();
        root();//建立虚拟驱动
        Start();//开机
        users();//创建用户
        Welcome();//用户，你好
        cout<<"输入<help>获取帮助。"<<endl;
        return;
    }else if(mingling=="tree"){
        cout<<"------------tree------------"<<endl;
        cout<<"磁盘    可用空间    已用空间"<<endl;
        cout<<"H:\\     10MB        2MB     "<<endl;
        cout<<"----------------------------"<<endl;
    }else if(mingling=="cop"){
        for(a=0;a<cx;a++){
            for(b=0;b<cy;b++){
                cout<<corp[a][b];
            }
            cout<<endl;
        }
    }else if(mingling=="logoff"){
        cls;
        users();
        Welcome();//用户，你好
        cout<<"输入<help>获取帮助。"<<endl;
        wr=0;
    }else if(mingling=="store"){
        HelloStore();
    }else if(mingling=="chkver"){
        HelloUpdata();
    }else if(mingling=="time"){
        PrintTime();
    }else if(mingling=="color"){
        cout<<"----------个性化----------"<<endl;
        cout<<"COLOR>";
        string colors;
        cin>>colors;
        color(colors);
        cout<<"--------------------------"<<endl;
    }else if(mingling=="insys"){
        cout<<"---------宿主系统文件---------"<<endl;
        cout<<"back回到HelloOS"<<endl;
        cout<<">>>"; 
        string s;
        int b=false;
        char sys[500]={'\0'};
        getline(cin,s);
        if(s=="back"){
            wr=0;
        }else{
            for(int i=0;i<s.size();i++){
                sys[i]=s[i];
            }
            b=chdir(sys);
            if(b==-1){
                cout<<'\"'<<sys<<"\"目录名错误！"<<endl;
            }else{
                wr=5;
            }
        }
        cout<<"------------------------------"<<endl;
    }else if(mingling=="open"){
        cout<<"-----------查看文本-----------"<<endl;
        cout<<"输入文件名>> ";
        char ch[1000];
        cin>>ch;
        readfile(ch);
        cout<<"------------------------------"<<endl;
    }else if(mingling=="\0"){
        //空
    }else{
        if(basic){
            char ch[1000],j;
            int len=str.size();
            for(int i=0;i<1000;i++){
              if(i<len){
                 j=str[i];
                 ch[i]=j;
              }else{
                   ch[i]='\0';
               }
            }
            system(ch);
        }else{
            cout<<"\""<<str<<"\"既不是命令,也不是可执行文件或批处理文件"<<endl;
        }
    }
}//执行
void input(){
    int b,c=0;
    string inp;
    Welcome();//用户，你好
    cout<<"输入<help>获取帮助。"<<endl;
    wr=0;
    for(;;){
        cout<<"\r";
        where(wr);
        getline(cin,inp);
        run(inp);
    }
}//输入
/*--------------主函数区--------------*/
int HelloMain(){
    path=getcwd(NULL,0);
    Start();//开机
    jihuo();//*/
    users();//创建用户
    input();//运行系统
    return 0;
}//主函数
/*---------------函数区---------------*/
int GetTimes(int lei){
    time_t now_time;
    now_time = time(NULL);
    tm* timer=gmtime(&now_time);
    if(lei==0){
        return 1900+timer->tm_year;
    }else if(lei==1){
        return 1+timer->tm_mon;
    }else if(lei==2){
        return timer->tm_mday;
    }else if(lei==3){
        return timer->tm_hour+Utc;
    }else if(lei==4){
        return timer->tm_min;
    }else if(lei==5){
        return timer->tm_sec;
    }else{
        return now_time;
    }
}
string GetCmd(string str,int num){
    int space=0,zb=0;
    string nowstr;
    for(int i=str.size()-1;str[i]==' ';i--){
        str.erase(i);
    }//抹除尾部空格
    for(int i=0;str[i]==' ';i++){
        str[i]='\0';
    }//抹除前缀空格
    if(num==0){
        for(int i=0,j=0;i<str.size();i++){
            if(str[i]==' '){
                break;
            }
            nowstr.push_back(str[i]);
            j++;
        }
        return nowstr;
    }
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            space++;
        }
        if(space==num){
            zb=i+1;
            break;
        }
    }
    if(space==0){
        return str;
    }
    for(int i=zb,j=0;i<str.size();i++){
        if(str[i]==' '){
            break;
        }
        nowstr.push_back(str[i]);
        j++;
    }
    return nowstr;
}//获取输入命令的特定区域（用空格分割）
void loading(int num){
    char load[5]={'-','\\','|','/'};
    int a,b=0;
    cout<<"/";
    for(a=0;a<num;a++){
        if(b==4){
            b=0;
        }
        cout<<'\b'<<load[b];
        Sleep(100);
        b++;
    }
    cout<<'\b'<<" ";
}//Loading动画
void Logo(){
    char ch[6][17]={
        "----[]        []",
        "    []        []",
        "----[][][][][][]",
        "    []        []",
        "    []        []",
        "----[]<><><><>[]"
    };
    int a,b;
    for(a=0;a<6;a++){
        cout<<"          ";
        for(b=0;b<17;b++){
            cout<<ch[a][b];
            if(a==0){
                Sleep(50);
            }
        }
        Sleep(70);
        cout<<endl;
    }
}//logo动画
void logo(){
    char ch[6][17]={
        "----[]        []",
        "    []        []",
        "----[][][][][][]",
        "    []        []",
        "    []        []",
        "----[]<><><><>[]"
    };
    int a,b;
    for(a=0;a<6;a++){
        cout<<"     ";
        for(b=0;b<17;b++){
            cout<<ch[a][b];
        }
        cout<<endl;
    }
}
void nlogo(int space){
    char ch[6][17]={
        "----[]        []",
        "    []        []",
        "----[][][][][][]",
        "    []        []",
        "    []        []",
        "----[]<><><><>[]"
    };
    int a,b;
    for(a=0;a<6;a++){
        for(b=0;b<space;b++){
            cout<<" ";
        }
        for(b=0;b<17;b++){
            cout<<ch[a][b];
        }
        cout<<endl;
    }
}
void root(){
    char ch[6][17]={
        "----[]        []",
        "    []        []",
        "----[][][][][][]",
        "    []        []",
        "    []        []",
        "----[]<><><><>[]"
    };
    char res[26][70]={
        "Format disk H:\%:",
        " Format floder H\%Software",
        "  Format file H\%Software\%HelloAntiVirus.hexe",
        "  Format floder H\%Software\%Dos",
        "   Format file H\%Software\%Dos\%Dos.hexe",
        "   Format file H\%Software\%Dos\%Dos.hdll",
        " Format floder H\%System",
        "  Format file H\%System\%HelloStore.hexe",
        "  Format file H\%System\%Run.sys",
        "  Format file H\%System\%User.sys",//10
        "  Format file H\%System\%Start.sys",
        "  Format file H\%System\%runsys.hdll",
        "  Format file H\%System\%runhdll.hexe",
        "  Format file H\%System\%runsys.hexe",
        "  Makeing file H\%HelloOS.iso",
        "  Format file H\%System\%HelloOS.sys",
        "Starting H:\%HelloOS.iso",
        " Mounting System files",
        " Mounting System files",
        " Mounting System files",
        " Checking...",
        "Mounting commands",
        " Delete format temp files",
        " Delete Updata files",
        "#Info# Error:Don't have file H:\%UpdataTemp\%HelloOSStart.com",
        "#info# Ready for the next try"
    };
    int a,b;
    for(a=0;a<6;a++){
        cout<<"          ";
        for(b=0;b<17;b++){
            cout<<ch[a][b];
        }
        Sleep(80);
        cout<<endl;
    }
    for(a=0;a<=200;a++){
        Sleep(70);
        if(a%8==0&&a!=0){
            cout<<"\r";
            for(b=0;b<a;b=b+4){
                cout<<"\b=>";
            }
        }
        cout<<"Loading..."<<res[a%27]<<endl;
    }
    cout<<"\b";
    cls;
}//建立虚拟驱动
void newload(int num){
    char ch[30][100]={
        "                                  ",
        "·                                 ",
        " ·                                ",
        "· ·                               ",
        " · ·                              ",
        "· · ·                             ",
        " · · ·                            ",
        "· · · ·                           ",
        " · · · ·                          ",
        "· · · · ·                         ",
        " · · · ·  ·                       ",
        "  · · ·  ·   ·                    ",
        "   · ·  ·   ·    ·                ",
        "    ·  ·   ·    ·     ·           ",
        "      ·   ·    ·     ·    ·       ",
        "        ·    ·     ·    ·   ·     ",
        "           ·     ·    ·   ·  ·    ",
        "                ·    ·   ·  · ·   ",
        "                    ·   ·  · · ·  ",
        "                       ·  · · · · ",
        "                         · · · · ·",
        "                          · · · · ",
        "                           · · · ·",
        "                            · · · ",
        "                             · · ·",
        "                              · · ",
        "                               · ·",
        "                                · ",
        "                                 ·",
        "                                  ",
    };
    for(int i=0;i<num;i++){
        for(int j=0;j<30;j++){
            cout<<'\r'<<ch[j];
            Sleep(100);
        }
        Sleep(500);
    }
}
void Start(){
    srand(time(NULL));
    Sleep(1500+rand()%1500);
    cout<<"#State# System self-test";
    Sleep(rand()%400+400);
    cout<<endl<<"#Info# NORMAL"<<endl;
    cout<<"#State# Loading Disk Hardrive...";
    Sleep(rand()%600+600);
    cout<<endl;
    cls;
    Sleep(500);
    //*/
    Logo();
    Sleep(rand()%1500+1500);
    cout<<endl<<endl;
    newload(rand()%2+2);
    cls;
}//开机
string bts(string str){
    int a,len=str.size();
    for(a=0;a<len;a++){
        if(str[a]>='A'&&str[a]<='Z'){
            str[a]=str[a]+32;
        }
    }
    return str;
}
void users(){
    cout<<"创建用户名：";
    cin>>user;
    cout<<"Downloading Files ";
    loading(20);
    cls;
}//创建用户
void Welcome(){
    string pass;
    if(user=="Admin"){
        for(int e=9;;){
            cout<<"输入密码(exit退出):";
            cin>>pass;
            if(pass==passwd){
                admin=1;jiami=1;
                break;
            }else if(pass=="exit"){
                user="默认user";jiami=0;
                break;
            }else if(e!=1&&e<=6){
                e--;
                cls;
                cout<<"*密码错误!\n你还有"<<e<<"次机会。请重新";
            }else if(e>6){
                e--;
                cls;
                cout<<"*密码错误!\n请重新";
            }else if(e==1){
                cout<<"密码错误5次，终止认证。"<<endl;
                Sleep(3000);jiami=0;
                user="默认user";
                break;
            }
        }
        cls;
    }else if(user=="Dev"){
        for(int e=9;;){
            cout<<"输入密码(exit退出):";
            cin>>pass;
            if(pass==passdev){
                admin=2;jiami=1;
                break;
            }else if(pass=="exit"){
                user="默认user";jiami=0;
                break;
            }else if(e!=1&&e<=6){
                e--;
                cls;
                cout<<"*密码错误!\n你还有"<<e<<"次机会。请重新";
            }else if(e>6){
                e--;
                cls;
                cout<<"*密码错误!\n请重新";
            }else if(e==1){
                cout<<"密码错误5次，终止认证。"<<endl;
                Sleep(3000);jiami=0;
                user="默认user";
                break;
            }
        }
        cls;
    }
    cout<<user<<"，你好！"<<endl;
    Sleep(1000);
}//用户，你好
void where(int a){
    if(user=="Admin"){
        cout<<"管理员_";
    }else if(user=="Dev"){
        cout<<"开发者测试账号_";
    }else{
        cout<<user<<"_";
    }
    if(a==5){
        path=getcwd(NULL,0);
        for(int i=0;i<strlen(path);i++){
            if(path[i]=='/'||path[i]=='\\'){
                cout<<'%';
            }else{
                cout<<path[i];
            }
        }
        cout<<"-# ";
        return;
    }
    cout<<Where[a];
}//盘符
void close(){
    srand(time(NULL));
    colorset="normal";
    cls;
    c_normal;
    cout<<"              Shutdown"<<endl<<endl;
    cout<<"           HelloOS正在关机"<<endl<<endl<<endl;
    newload(rand()%5+3);
    cls;
}
void PrintTime(){
    cout<<"------------时间------------"<<endl;
    for(int tex=0;tex<10;tex++){
        cout<<"\r"<<GetTimes(GT_YEA)<<'/'<<GetTimes(GT_MON)<<'/'<<GetTimes(GT_DAY)<<" ";
        if(GetTimes(GT_HOU)<10){
            cout<<0;
        }
        cout<<GetTimes(GT_HOU)<<':';
        if(GetTimes(GT_MIN)<10){
            cout<<0;
        }
        cout<<GetTimes(GT_MIN)<<':';
        if(GetTimes(GT_SEC)<10){
            cout<<0;
        }
            cout<<GetTimes(GT_SEC);
            Sleep(1000);
    }
    cout<<endl;
    cout<<"----------------------------"<<endl;
}
void DOSES(){
    cout<<"----------DOS----------\n";
    string str;
    int i,j,len,cmder=1;
    char ch[10000];
    for(;;){
        if(SYSTEM){
            cout<<getcwd(NULL,0)<<'>';
        }else{
            cout<<"\r\033[32;1m"<<user<<"@HelloOS\033[000m "<<getcwd(NULL,0)<<":~\033[34;1m$\033[000m ";
        }
        getline(cin,str);
        len=str.size();
        for(i=0;i<10000;i++){
            if(i<len){
                j=str[i];
                ch[i]=j;
            }else{
                ch[i]='\0';
            }
        }
        if(str=="dos"){
            cout<<"----About HelloOS DOS----\n";
            cout<<"HelloOS Shell 1.0.2"<<endl;
            cout<<"-------------------------"<<endl;
            continue;
        }else if(str=="exit"){
            cmder--;
            if(cmder==0){
                cout<<"----------end----------"<<endl;
                return;
            }
            continue;
        }
        system(ch);
    }
}
void HAV(){
    string c;
    int b;
    cout<<"------HelloAntiVirus------"<<endl;
    cout<<"系统：安全"<<endl;
    for(;;){
        cout<<"[1]扫描 [2]查杀 [exit]退出"<<endl;
        cin>>c;
        if(c=="1"){
            cout<<0<<"%";
            for(b=0;b<=100;b++){
                if(b<10){
                    cout<<"\b\b";
                }else if(b<=100){
                    cout<<"\b\b\b";
                }
                cout<<b<<"%";
                Sleep(29);
            }
            cls;
            cout<<"扫描完成，安全。"<<endl;
        }else if(c=="2"){
            cout<<"扫描中"<<endl;
            cout<<0<<"%";
            for(b=0;b<=100;b++){
                if(b<10){
                    cout<<"\b\b";
                }else if(b<=100){
                    cout<<"\b\b\b";
                }
                cout<<b<<"%";
                Sleep(29);
            }
            cout<<endl;
            cout<<"查杀中"<<endl;
            cout<<0<<"%";
            for(b=0;b<=100;b++){
                if(b<10){
                    cout<<"\b\b";
                }else if(b<=100){
                    cout<<"\b\b\b";
                }
                cout<<b<<"%";
                Sleep(29);
            }
            cls;
            cout<<"查杀完成。"<<endl;
        }else{
            cout<<"--------------------------"<<endl;
            return;
        }
    }
}
void kill(){
    cout<<"----------格式化----------"<<endl;
    int b;
    cout<<"准备中. . ."<<endl;
    Sleep(5000);
    cout<<0<<"%";
    for(b=0;b<=100;b++){
        if(b<10){
            cout<<"\b\b";
        }else if(b<=100){
            cout<<"\b\b\b";
        }
        cout<<b<<"%";
        Sleep(29);
    }
    cls;
    cout<<"-------格式化成功！-------"<<endl;
    Sleep(1000);
    cls;
}
void HelloStore(){
    int b,ins;
    cout<<"----------HelloStore----------"<<endl;
    string str;
    for(;;){
        cout<<"==========下载/卸载=========="<<endl;
        cout<<"Hello加密        ";
        if(jiami==0){
            cout<<"  install[1]"<<endl;
        }else{
            cout<<"uninstall[1]"<<endl;
        }
        cout<<"输入(exit退出)>";
        getline(cin,str);
        if(str=="1"){
            if(jiami==1){
                jiami=0;
                ins=0;
            }else{
                jiami=1;
                ins=1;
            }
        }else if(str=="exit"){
            cout<<"------------------------------"<<endl;
            return;
        }else{
            cls;
            continue;
        }
        if(ins==1){
            cout<<"下载中"<<endl;
            cout<<0<<"%";
            for(b=0;b<=100;b++){
                if(b<10){
                    cout<<"\b\b";
                }else if(b<=100){
                    cout<<"\b\b\b";
                }
                cout<<b<<"%";
                Sleep(100);
            }
            cout<<endl;
            cout<<"安装中"<<endl;
            cout<<0<<"%";
            for(b=0;b<=100;b++){
                if(b<10){
                    cout<<"\b\b";
                }else if(b<=100){
                    cout<<"\b\b\b";
                }
                cout<<b<<"%";
                Sleep(39);
            }
            cls;
            cout<<"安装成功！"<<endl;
        }else{
            cout<<"卸载中"<<endl;
            cout<<0<<"%";
            for(b=0;b<=100;b++){
                if(b<10){
                    cout<<"\b\b";
                }else if(b<=100){
                    cout<<"\b\b\b";
                }
                cout<<b<<"%";
                Sleep(50);
            }
            cout<<endl;
            cls;
            cout<<"卸载完成！"<<endl;
        }
    }
}
void HelloUpdata(){
    int a,yea=GetTimes(GT_YEA),mon=GetTimes(GT_MON),day=GetTimes(GT_DAY);
    cout<<"----------系统更新-----------"<<endl;
    if(yea>2022||(mon>12&&yea==2022)||(mon==12&&yea==2022&&day>=5)){
        cout<<"发现新版本: v1.0."<<ver+1<<endl;
        cout<<"请下载最新版本"<<endl;
    }else{
        cout<<"您已是最新版本"<<endl;
    }
    cout<<"-----------------------------"<<endl;
}
void Encrypt(){
    string str,s;
    int a,b;
    cout<<"----------Hello加密----------"<<endl;
    cout<<"       --(一款凯撒码加密软件)"<<endl;
    for(b=0;;b++){
        cout<<"[1]加密  [2]解密   [exit]退出"<<endl;
        cout<<"choose>";
        getline(cin,str);
        if(str=="1"){
            cout<<"字符串>";
            getline(cin,s);
            for(a=0;a<s.size();a++){
                if(s[a]>='a'&&s[a]<='w'){
                    s[a]=s[a]+3;
                }else if(s[a]>='x'&&s[a]<='z'){
                    s[a]=s[a]-26+3;
                }else if(s[a]>='0'&&s[a]<='8'){
                    s[a]++;
                }else if(s[a]=='9'){
                    s[a]='0';
                }else if(s[a]>='A'&&s[a]<='W'){
                    s[a]=s[a]+3;
                }else if(s[a]>='X'&&s[a]<='Z'){
                    s[a]=s[a]-26+3;
                }
            }
            cls;
            cout<<"加密后："<<s<<endl;
        }else if(str=="2"){
            cout<<"字符串>";
            getline(cin,s);
            for(a=0;a<s.size();a++){
                if(s[a]>='d'&&s[a]<='z'){
                    s[a]=s[a]-3;
                }else if(s[a]>='a'&&s[a]<='c'){
                    s[a]=s[a]+26-3;
                }else if(s[a]>='1'&&s[a]<='9'){
                    s[a]--;
                }else if(s[a]=='0'){
                    s[a]='9';
                }else if(s[a]>='D'&&s[a]<='Z'){
                    s[a]=s[a]-3;
                }else if(s[a]>='A'&&s[a]<='C'){
                    s[a]=s[a]+26-3;
                }
            }
            cls;
            cout<<"解密后："<<s<<endl;
        }else if(str=="exit"){
            cout<<"-----------------------------"<<endl;
            return;
        }else if(b==0&&str=="\0"){
            cls;
            cout<<"----------Hello加密----------"<<endl;
            cout<<"       --(一款凯撒码加密软件)"<<endl;
        }else{
            cls;
        }
    }
}
void Basic(){
    string inp;
    for(;;){
        cout<<"\r";
        where(wr);
        getline(cin,inp);
        run(inp);
    }
}
bool checkpass(string s){
}
void jihuo(){
	
}
void readfile(char filename[]){
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open()){
        cout<<"没有这个文件或没有权限"<<endl;
    }
    string str;
    while(getline(fin,str)){
        cout<<str<<endl;
    }
    fin.close();
}
#endif /*HelloOS*/
