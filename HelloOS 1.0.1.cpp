/**
        _     /\     _
        \\   /  \   //
         \  /    \  /
          \/      \/
          /\      /\
         /  \    /  \
        /    \  /    \
       /______\/______\
Earth Three-body Organization
         ------------
           ���屣��
           ����bug
         ------------
             --by ETO
*/
/**
           ()
      ____    _____
     /    \__/     \
    /               \
    |               /
    |    ��֧��    |
    |    color      \
    \      __       /
     \____/  \_____/
      MacOS Big Sur

��ϵͳ��֧��MAC����color����
   Mac��color����������룡
**/
/**##*����*##
���������Ϊ����һ�����ã���Ȩ���У�����ת�أ�
�����������ǧ�У�����ļ�����ڴ�������4GB��������������Ը���
������󣬱�������������ĵȴ���
���˲��е��κ��ɳ�������ʹ�ò�������ɵ�������
**/
/**   #System#
----[]        []
    []        []
----[][][][][][]
    []        []
    []        []
----[]<><><><>[]
     HelloOS(R)
*/
/**    #Copiright#
      []        []
     []        []
    []        []
     [][][][][][]
      []        []
       []        []
      []        []
(c) 2021-2022 HelloCompany(Zhou Ziming)
	All Rights Reserved.
*/
/**||                         ||
   \/����Ϊ"HelloOSϵͳ"Դ����\/    **/
/***=============HelloOS v1.0=============***/
/*--------------ע����-------------*/
/**��ʼ���棺2022/04/24
 * ������̴�����2022/05/02
 * �û���2022/05/02
 * �̷���2022/05/02
 * �������룺2022/05/02
 * ����ִ�У�2022/05/02  start
 * ����͹���Ա��2022/05/04
 * HelloStore: 2022/05/21
*/
/**����ִ�У�
 * help: 2022/05/02
 * about/system: 2022/05/02
 * basic: 2022/05/02
 * break: 2022/05/02
 * chguser: 2022/05/02
 * cls/clear: 2022/05/02
 * close: 2022/05/02
 * dir: 2022/05/03
 * dos: 2022/05/03
 * file: 2022/05/03
 * i: 2022/05/03
 * Java:2022/05/03
 * py: 2022/05/03
 * run/open: 2022/05/03;2022/05/07
 * reboot: 2022/05/03
 * ver/version: 2022/05/03
 * chgpass: 2022/05/04
 * kill: 2022/05/07
 * tree: 2022/05/14
 * cop: 2022/05/14
 * logoff: 2022/05/19
 * store: 2022/05/21
 * chkver: 2022/06/01
 * time: 2022/06/01
 * insys: 2022/07/13
*/

/**��飺
 * @FileClass��ϵͳ
 * @FileName��HelloOS 1.0.8.cpp
 * @LastUpdataTime��2022/07/12
 * @LastVersion��1.0.7
 * @Author��HelloCompany
*/
/**���¼�¼��ǩ:
 * (N)-Normal-��������
 * (S)-Special-�ر����
 * (W)-Warning-��������
*/
/**���¼�¼:
 * 2022/04/24: (N)��ʼ��Ŀ(@begintime),���¿�ʼ����
 * 2022/05/02: (N)���»�ӭ����,�������̽���,���н����7������
 * 2022/05/03: (N)����8������,ϵͳ����
 * 2022/05/04: (N)����chgpass��run����,ʹӦ���޷��ڲ���Ӧ�ļ��д�,���˹���Ա
 * 2022/05/06: (N)����chgpass�����bug
 * 2022/05/07: (N)����chguser�����bug��kill��open�����޷�ʹ�õ�bug,�������Զ��ع�H��
 * 2022/05/14: (N)����tree,cop����
 * 2022/05/19: (N)����logoff��������������Ż�
 * 2022/05/21: (N)����HelloStoreӦ��
 * 2022/05/25: (S)525����_�Ż���������
 * 2022/05/27: (S)"527ʡ�������ر��",���Ĵ��̽�������,�������������д��ĸ
 * 2022/06/01:1(W)��������: �޸�Linux������clear����ȱ��
              2(N)���°汾���,time����
 * 2022/06/06: (N)����color����
 * 2022/06/18: (S)"���Լ���"����,����������֤��
 * 2022/06/19: (N)����BASIC���� 
 * 2022/06/29: (N)����time����,����¹���Ա(����)�û�
 * 2022/06/30: (N)���������������,�����¹���Ա����bug
 * 2022/07/13: (N)�����̷����ɽ���ϵͳ�ļ��С�
*/
/***============������ʽ��ʼ=============***/
#ifndef __HelloOS
#define __HelloOS
/*---------ͷ�ļ�����Ҫ������---------*/
#include<bits/stdc++.h>
#include<unistd.h>//��������
using namespace std;
//====�����Windows��====
#if defined(_WIN32)||defined(_AMD64)||defined(_ARM64)
#define SYSTEM 1
#include<windows.h>//WinAPI����Sleep
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
	//cout<<"Windows�˲�֧��!������DOS��ʹ��!"<<endl;
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
string colorset;//Windowsû�� 
//=====�����Linux��=====
#else
#define SYSTEM 0
#define clear cout<<"\033c"
void Sleep(int a){
	usleep(a*1000);
}//�Զ�Sleep
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
		cout<<"Linux:  ����"<<endl;
		cout<<"normal  Ĭ��"<<endl;
		cout<<"hide    \033[31;1mͣ��\033[000m"<<endl;
		cout<<"show    \033[31;1mͣ��\033[000m"<<endl;
		cout<<"0         ��"<<endl;
		cout<<"1         ��"<<endl;
		cout<<"2         ��"<<endl;
		cout<<"3         ��"<<endl;
		cout<<"4         ��"<<endl;
		cout<<"5         ��"<<endl;
		cout<<"6         ��"<<endl;
		return;
	}
	if(s=="normal"){
		c_normal;
		colorset=s;
		return;
	}else if(s=="hide"||s=="show"){
		cout<<"\033[31;1m������ͣ��\033[000m"<<endl;
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
		//�޲���(�˳�����)
	}else{
		color(colorset);
	}
}
#define cls cls()
#endif
//=======end=======
//==unistd������?==
#ifndef UNISTD_H
extern "C" int usleep(useconds_t __useconds);//unistd.h��usleep�޸�
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
/*---------------������---------------*/
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
	"ABOUT                         ����",
	"BASIC                 �����׼ģʽ",
	"BREAK                   �˳��ļ���",
	"CD                      �����ļ���",
	"CHGPASS         ��������(������Ա)",
	"CHGUSER                 �����û���",
	"CHKVER                    ���汾",
	"CLS/CLEAR                     ����",
	"CLOSE                         �ػ�",
	"COLOR                     ������ɫ",
	"COP                       �鿴��Ȩ",
	"DIR                ��ʾH�������ļ�",
	"DOS             DOSģʽ(��Windows)",
	"HELP                          ����",
	"I                       �鿴�û���",
	"INSYS               ����ϵͳ�ļ���",
	"JAVA              ��дJAVA(������)",
	"FORMAT                      ��ʽ��",
	"LOGOFF                    ע���û�",
	"OPEN                  ���ı��ļ�",
	"PY              ��дpython(������)",
	"RUN                           ��",
	"REBOOT                        ����",
	"STORE                   HelloStore",
	"SYSTEM                       ABOUT",
	"TIME                      ��ȡʱ��",
	"TREE                  �鿴���̿ռ�",
	"VERSION/VER           �鿴ϵͳ�汾",
	"VIRUS                     ��ⲡ��",
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
	"����ϵͳ�ڲ��汾[300822.4329]   ",//ver
	"HelloOS ��ͨ�� ",
	"�ں�:HelloNT 1.0                ",
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
/*------------Ԥ���庯����------------*/
/**��21������**/
int GetTimes(int lei);
string GetCmd(string str,int num);
void loading(int num);//Loading����
void nlogo(int space);
void Logo();
void logo();
void root();//������������
void newload(int num);
void Start();//����
void Welcome();
string bts(string str);
void users();//�û������
void where(int a);//�̷�
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
/*---------------�κ�����---------------*/
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
			cout<<"������H����!"<<endl;
		}else if(wr==3){
			wr=2;
		}else{
			wr=0;
		}
	}else if(mingling=="chguser"){
		cout<<"--------�û�������---------"<<endl;
		string pass,userses;
		cout<<"�����û�����";
		cin>>userses;
		if(user==userses){
			cout<<"�û���һ�£�"<<endl;
			cout<<"---------------------------"<<endl;
			return;
		}
		if(userses=="Admin"){
			for(int e=9;;){
				cout<<"��������(exit�˳�):";
				cin>>pass;
				if(pass==passwd){
					admin=1;
					jiami=1;
					user=userses;
					break;
				}else if(pass=="exit"){
					jiami=0;
					user="Ĭ��user";
					break;
				}else if(e!=1&&e<=6){
					e--;
					cls;
					cout<<"*�������!\n�㻹��"<<e<<"�λ��ᡣ������";
				}else if(e>6){
					e--;
					cls;
					cout<<"*�������!\n������";
				}else if(e==1){
					cout<<"�������5�Σ���ֹ��֤��"<<endl;
					Sleep(3000);
					jiami=0;
					user="Ĭ��user";
					break;
				}
			}
			cls;
		}else if(userses=="Dev"){
			for(int e=9;;){
				cout<<"��������(exit�˳�):";
				cin>>pass;
				if(pass==passdev){
					admin=1;jiami=1;
					user=userses;
					break;
				}else if(pass=="exit"){
					user="Ĭ��user";jiami=0;
					break;
				}else if(e!=1&&e<=6){
					e--;
					cls;
					cout<<"*�������!\n�㻹��"<<e<<"�λ��ᡣ������";
				}else if(e>6){
					e--;
					cls;
					cout<<"*�������!\n������";
				}else if(e==1){
					cout<<"�������5�Σ���ֹ��֤��"<<endl;
					Sleep(3000);jiami=0;
					user="Ĭ��user";
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
		cout<<endl<<"�������,"<<user<<endl;
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
		cout<<"--------�ļ��н���---------"<<endl;
		if(wr==0){
			cout<<"ѡ���ļ���:System"<<endl;
			cout<<"           Software"<<endl;
			cin>>str;
			if(str=="System"){
				wr=1;
			}else if(str=="Software"){
				wr=2;
			}else{
				cout<<"û�д��ļ���!"<<endl;
			}
		}else if(wr==2){
			cout<<"ѡ���ļ���:Dos"<<endl;
			cin>>str;
			if(str=="Dos"){
				wr=3;
			}else{
				cout<<"û�д��ļ���!"<<endl;
			}
		}else if(wr==5){
			cout<<"Ȩ�޲������޷��鿴����ϵͳ�ļ�"<<endl;
		}else{
			cout<<"û���ļ���!"<<endl;
		}
		cout<<"---------------------------"<<endl;
	}else if(mingling=="i"){
		cout<<"--------�û����鿴---------"<<endl;
		cout<<"�û���:"<<user<<endl;
		cout<<"---------------------------"<<endl;
	}else if(mingling=="java"){
		cout<<"�������!"<<endl;
	}else if(mingling=="py"){
		system("python");
	}else if(mingling=="run"){
		cout<<"-----------��------------"<<endl;
		cout<<"�ļ���:";
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
				cout<<"�޴��ļ���"<<endl;
				cout<<"---------------------------"<<endl;
			}
		}else if(wr==1){
			if(fn=="HelloOS.sys"||fn=="Start.sys"||fn=="User.sys"||fn=="Run.sys"){
				cout<<"ϵͳ�ļ��޷��鿴!"<<endl;
				cout<<"---------------------------"<<endl;
			}else if(fn=="runsys.hexe"||fn=="runhdll.hexe"){
				cout<<"Ӧ��û�������ļ���"<<endl;
				cout<<"---------------------------"<<endl;
			}else if(fn=="runsys.hdll"){
				cout<<"Ӧ����չ�ļ��޷��鿴��"<<endl;
				cout<<"---------------------------"<<endl;
			}else if(fn=="HelloStore.hexe"){
				cout<<"---------------------------"<<endl;
				HelloStore();
			}else{
				cout<<"�޴��ļ���"<<endl;
				cout<<"---------------------------"<<endl;
			}
		}else if(wr==3){
			if(fn=="Dos.hexe"){
				cout<<"---------------------------"<<endl;
				DOSES();
			}else if(fn=="Dos.hdll"){
				cout<<"Ӧ����չ�ļ��޷��鿴��"<<endl;
				cout<<"---------------------------"<<endl;
			}else{
				cout<<"�޴��ļ���"<<endl;
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
		Start();//����
		Welcome();//�û������
		cout<<"����<help>��ȡ������"<<endl;
	}else if(mingling=="ver"||mingling=="version"){
		cout<<"----------ϵͳ�汾-----------"<<endl;
		cout<<"HelloOS System 1.0 D30M8Y22  "<<endl;
		cout<<"����ϵͳ�ڲ��汾[300822.4329]"<<endl;//���ı䣬aboutҲҪ����
		cout<<"-----------------------------"<<endl;
	}else if(mingling=="chgpass"){
		cout<<"---------��������----------"<<endl;
		if(admin==1){
			string pass;
			for(int e=9;;){
				cout<<"��������(exit�˳�):";
				cin>>pass;
				if(pass==passwd){
					cout<<"����������:";
					cin>>passwd;
					cls;
					cout<<"���ĳɹ���"<<endl;
					break;
				}else if(pass=="exit"){
					cout<<"---------------------------"<<endl;
					return;
				}else if(e!=1&&e<=6){
					e--;
					cls;
					cout<<"*�������!\n�㻹��"<<e<<"�λ��ᡣ������";
				}else if(e>6){
					e--;
					cls;
					cout<<"*�������!\n������";
				}else if(e==1){
					cout<<"�������5�Σ���ֹ��֤��"<<endl;
					cout<<"---------------------------"<<endl;
					return;
				}
			}
			cls;
		}else if(admin==2||user=="Dev"){
			string pass;
			for(int e=9;;){
				cout<<"��������(exit�˳�):";
				cin>>pass;
				if(pass==passdev){
					cout<<"����������:";
					cin>>passdev;
					cls;
					cout<<"���ĳɹ���"<<endl;
					break;
				}else if(pass=="exit"){
					cout<<"---------------------------"<<endl;
					return;
				}else if(e!=1&&e<=6){
					e--;
					cls;
					cout<<"*�������!\n�㻹��"<<e<<"�λ��ᡣ������";
				}else if(e>6){
					e--;
					cls;
					cout<<"*�������!\n������";
				}else if(e==1){
					cout<<"�������5�Σ���ֹ��֤��"<<endl;
					cout<<"---------------------------"<<endl;
					return;
				}
			}
			cls;
		}else{
			cout<<"�����ǹ���Ա!\n";
		}
		cout<<"---------------------------"<<endl;
	}else if(mingling=="virus"){
		HAV();
	}else if(mingling=="format"){
		kill();
		root();//������������
		Start();//����
		users();//�����û�
		Welcome();//�û������
		cout<<"����<help>��ȡ������"<<endl;
		return;
	}else if(mingling=="tree"){
		cout<<"------------tree------------"<<endl;
		cout<<"����    ���ÿռ�    ���ÿռ�"<<endl;
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
		Welcome();//�û������
		cout<<"����<help>��ȡ������"<<endl;
		wr=0;
	}else if(mingling=="store"){
		HelloStore();
	}else if(mingling=="chkver"){
		HelloUpdata();
	}else if(mingling=="time"){
		PrintTime();
	}else if(mingling=="color"){
		cout<<"----------���Ի�----------"<<endl;
		cout<<"COLOR>";
		string colors;
		cin>>colors;
		color(colors);
		cout<<"--------------------------"<<endl;
	}else if(mingling=="insys"){
		cout<<"---------����ϵͳ�ļ�---------"<<endl;
		cout<<"back�ص�HelloOS"<<endl;
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
				cout<<'\"'<<sys<<"\"Ŀ¼������"<<endl;
			}else{
				wr=5;
			}
		}
		cout<<"------------------------------"<<endl;
	}else if(mingling=="open"){
		cout<<"-----------�鿴�ı�-----------"<<endl;
		cout<<"�����ļ���>> ";
		char ch[1000];
		cin>>ch;
		readfile(ch);
		cout<<"------------------------------"<<endl;
	}else if(mingling=="\0"){
		//��
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
			cout<<"\""<<str<<"\"�Ȳ�������,Ҳ���ǿ�ִ���ļ����������ļ�"<<endl;
		}
	}
}//ִ��
void input(){
	int b,c=0;
	string inp;
	Welcome();//�û������
	cout<<"����<help>��ȡ������"<<endl;
	wr=0;
	for(;;){
		cout<<"\r";
		where(wr);
		getline(cin,inp);
		run(inp);
	}
}//����
/*--------------��������--------------*/
int HelloMain(){
	path=getcwd(NULL,0);
	Start();//����
	jihuo();//*/
	users();//�����û�
	input();//����ϵͳ
	return 0;
}//������
/*---------------������---------------*/
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
	}//Ĩ��β���ո�
	for(int i=0;str[i]==' ';i++){
		str[i]='\0';
	}//Ĩ��ǰ׺�ո�
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
}//��ȡ����������ض������ÿո�ָ
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
}//Loading����
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
}//logo����
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
}//������������
void newload(int num){
	char ch[30][100]={
		"                                  ",
		"o                                 ",
		" o                                ",
		"o o                               ",
		" o o                              ",
		"o o o                             ",
		" o o o                            ",
		"o o o o                           ",
		" o o o o                          ",
		"o o o o o                         ",
		" o o o o  o                       ",
		"  o o o  o   o                    ",
		"   o o  o   o    o                ",
		"    o  o   o    o     o           ",
		"      o   o    o     o    o       ",
		"        o    o     o    o   o     ",
		"           o     o    o   o  o    ",
		"                o    o   o  o o   ",
		"                    o   o  o o o  ",
		"                       o  o o o o ",
		"                         o o o o o",
		"                          o o o o ",
		"                           o o o o",
		"                            o o o ",
		"                             o o o",
		"                              o o ",
		"                               o o",
		"                                o ",
		"                                 o",
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
}//����
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
	cout<<"�����û�����";
	cin>>user;
	cout<<"Downloading Files ";
	loading(20);
	cls;
}//�����û�
void Welcome(){
	string pass;
	if(user=="Admin"){
		for(int e=9;;){
			cout<<"��������(exit�˳�):";
			cin>>pass;
			if(pass==passwd){
				admin=1;jiami=1;
				break;
			}else if(pass=="exit"){
				user="Ĭ��user";jiami=0;
				break;
			}else if(e!=1&&e<=6){
				e--;
				cls;
				cout<<"*�������!\n�㻹��"<<e<<"�λ��ᡣ������";
			}else if(e>6){
				e--;
				cls;
				cout<<"*�������!\n������";
			}else if(e==1){
				cout<<"�������5�Σ���ֹ��֤��"<<endl;
				Sleep(3000);jiami=0;
				user="Ĭ��user";
				break;
			}
		}
		cls;
	}else if(user=="Dev"){
		for(int e=9;;){
			cout<<"��������(exit�˳�):";
			cin>>pass;
			if(pass==passdev){
				admin=2;jiami=1;
				break;
			}else if(pass=="exit"){
				user="Ĭ��user";jiami=0;
				break;
			}else if(e!=1&&e<=6){
				e--;
				cls;
				cout<<"*�������!\n�㻹��"<<e<<"�λ��ᡣ������";
			}else if(e>6){
				e--;
				cls;
				cout<<"*�������!\n������";
			}else if(e==1){
				cout<<"�������5�Σ���ֹ��֤��"<<endl;
				Sleep(3000);jiami=0;
				user="Ĭ��user";
				break;
			}
		}
		cls;
	}
	cout<<user<<"����ã�"<<endl;
	Sleep(1000);
}//�û������
void where(int a){
	if(user=="Admin"){
		cout<<"����Ա_";
	}else if(user=="Dev"){
		cout<<"�����߲����˺�_";
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
}//�̷�
void close(){
	srand(time(NULL));
	colorset="normal";
	cls;
	c_normal;
	cout<<"              Shutdown"<<endl<<endl;
	cout<<"           HelloOS���ڹػ�"<<endl<<endl<<endl;
	newload(rand()%5+3);
	cls;
}
void PrintTime(){
	cout<<"------------ʱ��------------"<<endl;
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
	cout<<"ϵͳ����ȫ"<<endl;
	for(;;){
		cout<<"[1]ɨ�� [2]��ɱ [exit]�˳�"<<endl;
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
			cout<<"ɨ����ɣ���ȫ��"<<endl;
		}else if(c=="2"){
			cout<<"ɨ����"<<endl;
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
			cout<<"��ɱ��"<<endl;
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
			cout<<"��ɱ��ɡ�"<<endl;
		}else{
			cout<<"--------------------------"<<endl;
			return;
		}
	}
}
void kill(){
	cout<<"----------��ʽ��----------"<<endl;
	int b;
	cout<<"׼����. . ."<<endl;
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
	cout<<"-------��ʽ���ɹ���-------"<<endl;
	Sleep(1000);
	cls;
}
void HelloStore(){
	int b,ins;
	cout<<"----------HelloStore----------"<<endl;
	string str;
	for(;;){
		cout<<"==========����/ж��=========="<<endl;
		cout<<"Hello����        ";
		if(jiami==0){
			cout<<"  install[1]"<<endl;
		}else{
			cout<<"uninstall[1]"<<endl;
		}
		cout<<"����(exit�˳�)>";
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
			cout<<"������"<<endl;
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
			cout<<"��װ��"<<endl;
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
			cout<<"��װ�ɹ���"<<endl;
		}else{
			cout<<"ж����"<<endl;
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
			cout<<"ж����ɣ�"<<endl;
		}
	}
}
void HelloUpdata(){
	int a,yea=GetTimes(GT_YEA),mon=GetTimes(GT_MON),day=GetTimes(GT_DAY);
	cout<<"----------ϵͳ����-----------"<<endl;
	if(yea>2022||(mon>12&&yea==2022)||(mon==12&&yea==2022&&day>=5)){
		cout<<"�����°汾: v1.0."<<ver+1<<endl;
		cout<<"���������°汾"<<endl;
	}else{
		cout<<"���������°汾"<<endl;
	}
	cout<<"-----------------------------"<<endl;
}
void Encrypt(){
	string str,s;
	int a,b;
	cout<<"----------Hello����----------"<<endl;
	cout<<"       --(һ�����������)"<<endl;
	for(b=0;;b++){
		cout<<"[1]����  [2]����   [exit]�˳�"<<endl;
		cout<<"choose>";
		getline(cin,str);
		if(str=="1"){
			cout<<"�ַ���>";
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
			cout<<"���ܺ�"<<s<<endl;
		}else if(str=="2"){
			cout<<"�ַ���>";
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
			cout<<"���ܺ�"<<s<<endl;
		}else if(str=="exit"){
			cout<<"-----------------------------"<<endl;
			return;
		}else if(b==0&&str=="\0"){
			cls;
			cout<<"----------Hello����----------"<<endl;
			cout<<"       --(һ�����������)"<<endl;
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
void jihuo(){
	//The Normal Version don't need this.
}
void readfile(char filename[]){
	ifstream fin;
	fin.open(filename);
	if(!fin.is_open()){
		cout<<"û������ļ���û��Ȩ��"<<endl;
	}
	string str;
	while(getline(fin,str)){
		cout<<str<<endl;
	}
	fin.close();
}
#endif /*HelloOS*/

/***=================END=================***/
/**
---------------------���---------------------
|    HelloOS��������ʷ������д��������Ŀ�� |
|��ֻ�п�ʼ�����v0.0.1�����ư�v1.0.6��������|
|�Ҵ�Լ2���µ�ʱ�䡣��ĿǰHelloOS����һ��Ӧ��|
|����ֻ��һ��"Windows��Linux������"��      |
|    �����Ŀȷʵ����д������������Ҫ�������|
|�ļ��������޷�������նˣ����������ɫ���⣺|
|���ϵͳ�������Linux��Windows(��Ҫ��IOS����|
|��дC++ֻ������IOS��Linux���ϱ�)��Linux��\03|
|3��WindowsAPI��SetConsoleTextAttribute��ͬ��|
|ǰ�߿���дΪcout<<"\033[xx;ym"����������дһ|
|��Ѻ�������ɾͲ���Ū�ˣ���ֻ����ͣWindows |
|��color����(ֻ����DOS��BASIC����color����)��|
|��Ȼ��������Ū���ˡ�                        |
|    Ŀǰ�����ϵͳ������ǳ����ƣ��Ͼ���ֻ��|
|1000�д��롣���������ڴ����ڳ���Աһ�𣬴���|
|���õ�ϵͳ!!!                               |
|                              by Ziming Zhou|
|                                  2022/06/29|
|                                            |
|       @TheDeveloper:CMD SUTDIO,HelloCompany|
----------------------------------------------
�����е�ϵͳ:Windows 95-Windows 11,Linux���汾
**/
/**
#�ر���л#
����Ȼ����:���̷��Ľ���
--��������Ա��ʾ��л�� 
**/
