#include <stdio.h>
#include <stdlib.h>

void enable_firewall() {
	printf("** RUN AS ADMINISTRATOR **\nEnabling firewall... [FORCED]\n");
	system("netsh advfirewall set all state on");
	printf("Done.\n");
	system("pause");
}

void add_rule() {
	system("netsh advfirewall firewall add rule name=\"LoL Chat OFF\" dir=out remoteip=172.65.212.1 protocol=TCP action=block");
	printf("Done.\n");
}

void del_rule() {
	system("netsh advfirewall firewall delete rule name=\"LoL Chat OFF\"");
	printf("Done.\n");
}

void enable_rule() {
	system("netsh advfirewall firewall set rule name=\"LoL Chat OFF\" new enable=yes");
	printf("Done.\n");
}

void disable_rule() {
	system("netsh advfirewall firewall set rule name=\"LoL Chat OFF\" new enable=no");
	printf("Done.\n");
}

int get_int(){
	int x,c;
	scanf(" %d", &x);
    while((c = getchar()) != '\n' && c != EOF){}
	return x;
}

void menu_show(){
	system("cls");
	printf("LoL Chat - Set your status: ** RUN AS ADMINISTRATOR **\n1 - Online\n2 - Offline\n\n8 - Install\n9 - Uninstall\n0 - Exit\n\n>");
}

void menu_action(int opt){
	switch (opt) {
		case 0:
			printf("Bye!\n");
			break;
		case 1:
			disable_rule();
			break;
		case 2:
			enable_rule();
			break;
		case 8:
			add_rule();
			break;
		case 9:
			del_rule();
			break;
		default:
			printf("None selected.");
	}
	system("pause");
}

int main () {
	int opt = 1;
	
	enable_firewall();
	
	while (opt) {
		menu_show();
		opt = get_int();
		menu_action(opt);
	}
	
	return 0;
}
