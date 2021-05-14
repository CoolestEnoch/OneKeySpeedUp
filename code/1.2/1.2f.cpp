#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include <iomanip>//输出两位小数
using namespace std;

const float app_ver = 1.2;
const int list_ver = 5;
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


char adobe_[][233]
{
	"AdminService.exe", "AdobeIPCBroker.exe", "AdobeNotificationClient.exe", "acrotray.exe"
};
char* getAdobe(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, adobe_[i]);
	return base_cmd;
}

char awcc_[][233]
{
	"AWCC.Background.Server.exe", "AWCC.exe", "AdobeNotificationClient.exe", "AWCC.Service.exe", "GameLibraryAppService.exe", "OCControl.Service.exe"
};
char* getAwcc(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, awcc_[i]);
	return base_cmd;
}

char vmware_[][233]
{
	"vmnat.exe", "vmnetdhcp.exe", "vmware-authd.exe", "vmware-hostd.exe", "vmware-usbarbitrator64.exe"
};
char* getVmware(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, vmware_[i]);
	return base_cmd;
}


char other_[][233]
{
	"Time.exe", "WUDFHost.exe", "WmiPrvSE.exe", "WinStore.App.exe",
	"Video.UI.exe", "SearchUI.exe", "SearchIndexer.exe", "OneApp.IGCC.WinService.exe",
	"DSAPI.exe", "jhi_service.exe", "QQProtect.exe", "XtuService.exe", "WUDFHost.exe"
	"AGMService.exe", "AGSService.exe",
	"DellSupportAssistRemedationService.exe", "SupportAssistAgent.exe", "SupportAssistOsRecovery.exe",
	"SupportAssistAgent.exe", "SupportAssistAppWire.exe", "SupportAssistClientUI.exe"
};
char* getOther(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, other_[i]);
	return base_cmd;
}

char apple_[][233]
{
	"AppleMobileDeviceService.exe", "mDNSResponder.exe"
};
char* getApple(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, apple_[i]);
	return base_cmd;
};

int main()
{
	//bool state = EnableDebugPrivilege();
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
	for (int i = 0; i < sizeof(adobe_) / sizeof(adobe_[0]); i++)
	{
		system(getAdobe(i));
	}
	

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
	for (int i = 0; i < sizeof(awcc_) / sizeof(awcc_[0]); i++)
	{
		system(getAwcc(i));
	}

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
	for (int i = 0; i < sizeof(vmware_) / sizeof(vmware_[0]); i++)
	{
		system(getVmware(i));
	}

other:
	cout << "开始关闭其他,继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n' ) | ( tmp == 'N'))
	{
		goto apple;
	}
	else if ((tmp == 'a') | (tmp == 'A'))
	{
		goto vmware;
	}
	for (int i = 0; i < sizeof(other_) / sizeof(other_[0]); i++)
	{
		system(getOther(i));
	}

apple:
	cout << "开始关闭Apple Services,继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n') | (tmp == 'N'))
	{
		goto last;
	}
	else if ((tmp == 'a') | (tmp == 'A'))
	{
		goto other;
	}
	for (int i = 0; i < sizeof(apple_) / sizeof(apple_[0]); i++)
	{
		system(getApple(i));
	}
last:
	system("exit");
	return 0;
}