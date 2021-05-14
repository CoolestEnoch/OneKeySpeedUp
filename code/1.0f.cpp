#include <iostream>
#include <windows.h>
#include <iomanip>//输出两位小数
using namespace std;

const float app_ver = 1.0;
const float list_ver = 1;
const char app_state[] = "final"; 

void startPic(int tt_len, int waitTime)
{
	//int tt_len = 87;
	float pct = 0.0;
	cout << '[';
	for (int i = 1; i < tt_len + 1; i++)
	{
		pct = 100 * (float(i) / tt_len);
		if (i != 1)
		{
			for (int j = i; j <= tt_len + 1; j++)
			{
				cout << '\b';
			}
		}
		cout << '=';
		for (int j = i; j < tt_len + 1; j++)
		{
			cout << ' ';
		}
		cout << "\b]";
		printf("%3.1f%%", pct);
		if (pct < 10)
		{
			cout << "\b\b\b\b";
		}
		else if (pct >= 10 and pct < 100)
		{
			cout << "\b\b\b\b\b";
		}
		Sleep(waitTime);
	}
	cout << "\n";
}

int main()
{
	
	cout.setf(ios::fixed);
	cout << "启动中...\n" << "软件版本 " << fixed << setprecision(1) << app_ver << app_state[0] << "\t\t进程列表版本" << list_ver << endl;
	startPic(80, 5);
	system("cls");

	char tmp = 0;
adobe:
	cout << "开始关闭adobe,继续？(Y/N)\n";
	cin >> tmp;
	if ((tmp == 'n' ) | ( tmp == 'N'))
	{
		goto awcc;
	}
	system("taskkill /f /t /im AdminService.exe");
	system("taskkill /f /t /im AdobeIPCBroker.exe");
	system("taskkill /f /t /im AdobeNotificationClient.exe");

awcc:
	cout << "开始关闭外星人控制中心,继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n' ) | ( tmp == 'N'))
	{
		goto vmware;
	}else if((tmp == 'a') | (tmp == 'A'))
	{
		goto adobe;
	}
	system("taskkill /f /t /im AWCC.Background.Server.exe");
	system("taskkill /f /t /im AWCC.exe");
	system("taskkill /f /t /im AWCC.Service.exe");
	system("taskkill /f /t /im GameLibraryAppService.exe");
	system("taskkill /f /t /im OCControl.Service.exe");

vmware:
	cout << "开始关闭vmware,继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n' ) | ( tmp == 'N'))
	{
		goto other;
	}else if((tmp == 's') | (tmp == 'S'))
	{
		goto awcc;
	}
	system("taskkill /f /t /im vmnat.exe");
	system("taskkill /f /t /im vmnetdhcp.exe");
	system("taskkill /f /t /im vmware-authd.exe");
	system("taskkill /f /t /im vmware-hostd.exe");
	system("taskkill /f /t /im vmware-usbarbitrator64.exe");

other:
	cout << "开始关闭其他,继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n' ) | ( tmp == 'N'))
	{
		goto last;
	}
	else if ((tmp == 'a') | (tmp == 'A'))
	{
		goto vmware;
	}
	system("taskkill /f /t /im Time.exe");
	system("taskkill /f /t /im WUDFHost.exe");
	system("taskkill /f /t /im WmiPrvSE.exe");
	system("taskkill /f /t /im WinStore.App.exe");
	system("taskkill /f /t /im Video.UI.exe");
	system("taskkill /f /t /im SearchUI.exe");
	system("taskkill /f /t /im SearchIndexer.exe");
	system("taskkill /f /t /im OneApp.IGCC.WinService.exe");
	system("taskkill /f /t /im AppleMobileDeviceService.exe");
	system("taskkill /f /t /im DSAPI.exe");
	system("taskkill /f /t /im jhi_service.exe");

	system("taskkill /f /t /im QQProtect.exe");

last:
	system("exit");
	return 0;
}
