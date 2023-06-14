	int i = 1,x=0,y=0,check=0;
	int xcu=x;
	int ycu=y;
	while (true) {
		// lam nhay vat the tinhx
		//system("cls");
		gotoXY(xcu,ycu);
		cout <<"            ";
		gotoXY(x, y);
		cout <<"game la de !";
		xcu=x;
		ycu=y;
		// mau 
		SetColor(i);
		i++;
		if(i>15)
			i=1;*/

		// dieu khien
		if(_kbhit()) {
			char kitu=_getch();
			if(kitu==-32) {
				kitu=_getch();
				if(kitu==72)
					check=1;
				else if(kitu==80)
					check=0;
				else if(kitu==75)
					check=3;
				else if(kitu==77)
					check=2;
			}
		}
		// kiem tra huong di chuyen len xuong
		if(check==0)
			y++;
		// vat the di len
		else if(check==1)
			y--;
		//vat the sang phai
		else if(check==2)
			x++;
		// vat the sang trai
		else if(check==3)
			x--;
		//kiem tra bien
		if(y==0)
			check=0;
		else if(y==28)
			check=1;
		else if(x==0)
			check=2;
		else if(x==100)
			check=3;
		Sleep(100);}