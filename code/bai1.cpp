#include <bits/stdc++.h>
#include "mylib.h"
using namespace std;
int sl=20;
#define MAX 100
void vetuongtd(int x,int y) {
	while(x<=100) {
		gotoXY(x,y);
		cout<<"*";
		x++;
	}
}
void vetuongtp(int x,int y) {
	while(y<=26) {
		gotoXY(x,y);
		cout<<"*";
		y++;
	}
}
void khoitao_ran(int toadoX[],int toadoY[]) {
	int x=50,y=13;
	for(int i=0; i<sl; i++) {
		toadoX[i]=x;
		toadoY[i]=y;
		x--;
	}
}
void ve_ran(int toadoX[],int toadoY[]) {
	for(int i=0; i<sl; i++) {
		gotoXY(toadoX[i],toadoY[i]);
		if(i==0)	{
			SetColor(10);
			cout<<"*";
		} else 	{
			cout<<"*";
			SetColor(10);
		}
	}
}
void xoa_dulieu_cu(int toadoX[],int toadoY[]) {
	for(int i=0; i<sl; i++) {
		gotoXY(toadoX[i],toadoY[i]);
		cout<<" ";
	}
}
void them(int a[],int x) {
	for(int i=sl; i>0; i--) {
		a[i]=a[i-1];
	}
	sl++;
	a[0]=x;
}
void xoa(int a[],int vt) {
	for(int i=vt; i<sl; i++) {
		a[i]=a[i+1];
	}
	sl--;
}
void xuli_ran(int toadoX[],int toadoY[],int x,int y) {
	//b1 them toa do moi dau mang
	them(toadoX,x);
	them(toadoY,y);
	//b2: xoa toa do cuoi mang
	xoa(toadoX,sl-1);
	xoa(toadoY,sl-1);
	// b3 ve ran
	ve_ran(toadoX,toadoY);
}
bool ran_dam_vao_tuong(int x0,int y0) {
	// tuong tren
	if(y0==1 && x0>=10 && x0<=100)
		return true ;
	//tuong duoi
	else if(y0==26 && x0>=10 && x0<=100 )
		return true ;
	//tuong trai
	else if(x0==10 && y0>=1 && y0<=26)
		return true;
	// tuong phai
	else if(x0==100 && y0>=1 && y0<=26)
		return true;
	return false;
}
bool ran_tu_can(int toadoX[],int toadoY[]) {
	for(int i=1; i<sl; i++) {
		if(toadoX[0]==toadoX[i] && toadoY[0]==toadoY[i])
			return true ;
	}
	return false;
}
bool kt_ran(int toadoX[],int toadoY[]) {
	bool kt1 = ran_tu_can(toadoX,toadoY);
	bool kt2= ran_dam_vao_tuong(toadoX[0],toadoY[0]);
	if(kt1 == true || kt2==true )
		return true;
	return false;
}
bool qua_de_ran(int xqua,int yqua,int toadoX[],int toadoY[]) {
	for(int i=0; i<sl; i++)
		if(xqua==toadoX[i] && yqua==toadoY[i])
			return true;
	return false;
}
void tao_qua(int &xqua,int &yqua,int toadoX[],int toadoY[]) {
	do {
		// 10<xqua<100
		xqua=rand()%(99-11+1)+11;
		//1<yqua<26
		yqua=rand()%(26-2+1)+2;
		gotoXY(xqua,yqua);
		cout<<"$";
	} while(qua_de_ran(xqua,yqua,toadoX,toadoY)==true );
}

int main() {

	int x=50,y=13;
	bool gameover=false;
	int check=2;
	int toadoX[MAX];
	int toadoY[MAX];
	vetuongtd(10,1);
	vetuongtd(10,26);
	vetuongtp(10,1);
	vetuongtp(100,1);
	khoitao_ran(toadoX,toadoY);
	ve_ran(toadoX,toadoY);
	srand(time(NULL));
	int xqua,yqua;
	tao_qua(xqua,yqua,toadoX,toadoY);
	while(gameover==false) {
		if(_kbhit()) {
			char kitu=_getch();
			if(kitu==-32) {
				kitu=_getch();
				//len
				if(kitu==72 && check!=0) check=1;
				//xuong
				else if(kitu==80 &&check!=1) check=0;
				//sang trai
				else if(kitu==77 && check!=3) check=2;
				// sang phai
				else if(kitu==75 && check!=2) check=3;
			}
		}
		if(check==0) y++;
		else if(check==1) y--;
		else if(check==2) x++;
		else if(check==3) x--;
		xoa_dulieu_cu(toadoX,toadoY);
		xuli_ran(toadoX,toadoY,x,y);
		gameover =kt_ran(toadoX,toadoY);
		Sleep(100);
	}
	_getch();
}