#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include <iomanip>//输出两位小数
using namespace std;

const float app_ver = 1.4f;
const int list_ver = 7;
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

char vmware_srv[][233]
{
	"VMware Authorization Service", "VMware DHCP Service", "VMware NAT Service", "VMware USB Arbitration Service", "VMware Workstation Server"
};
char* getVmwareSrv(int i)
{
	char base_cmd[] = "net stop ";
	strcat(base_cmd, "\"");
	strcat(base_cmd, vmware_srv[i]);
	strcat(base_cmd, "\"");
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
char other_srv[][233]
{
	"Background Intelligent Transfer Service"
};
char* getOtherSrv(int i)
{
	char base_cmd[] = "net stop ";
	strcat(base_cmd, "\"");
	strcat(base_cmd, other_srv[i]);
	strcat(base_cmd, "\"");
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

char sw_process[][233]
{
	 "FNPLicensingService64.exe", "FNPLicensingService.exe", "SWVisualize.BoostService.exe", "SWVisualize.Queue.Server.exe", "sldProc.exe", "SLDWORKS.exe", "sldworks_fs.exe", "swCefSubProc.exe", "sw_d.exe"
};
char* getSwProcess(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, sw_process[i]);
	return base_cmd;
}

char solidWorks_srv[][233]
{
	"SolidWorks Flexnet Server"
};
char* getSolidWorksSrv1(int i)
{
	char base_cmd[] = "net stop ";
	strcat(base_cmd, solidWorks_srv[i]);
	return base_cmd;
}
char* getSolidWorksSrv2(int i)
{
	char base_cmd[] = "sc delete ";
	strcat(base_cmd, solidWorks_srv[i]);
	return base_cmd;
}

char utools_[][233]
{
	"uTools.exe", "uTools.exe", "uTools.exe", "uTools.exe", "uTools.exe", "uTools.exe", "uTools.exe"
};
char* getUTools(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, utools_[i]);
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
	for (int i = 0; i < sizeof(vmware_srv) / sizeof(vmware_srv[0]); i++)
	{
		system(getVmwareSrv(i));
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
	for (int i = 0; i < sizeof(other_srv) / sizeof(other_srv[0]); i++)
	{
		system(getOtherSrv(i));
	}

apple:
	cout << "开始关闭Apple Services,继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n') | (tmp == 'N'))
	{
		goto solidWorks;
	}
	else if ((tmp == 'a') | (tmp == 'A'))
	{
		goto other;
	}
	for (int i = 0; i < sizeof(apple_) / sizeof(apple_[0]); i++)
	{
		system(getApple(i));
	}

solidWorks:
	cout << "开始关闭Solid Works, 继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n') | (tmp == 'N'))
	{
		goto last;
	}
	else if ((tmp == 'a') | (tmp == 'A'))
	{
		goto apple;
	}
	for (int i = 0; i < sizeof(utools_) / sizeof(utools_[0]); i++)
	{
		system(getSwProcess(i));
	}
	for (int i = 0; i < sizeof(vmware_srv) / sizeof(vmware_srv[0]); i++)
	{
		system(getSolidWorksSrv1(i));
	}
	for (int i = 0; i < sizeof(vmware_srv) / sizeof(vmware_srv[0]); i++)
	{
		system(getSolidWorksSrv2(i));
	}

utools:
	cout << "开始关闭uTools, 继续？(Y/N/A)\n";
	cin >> tmp;
	if ((tmp == 'n') | (tmp == 'N'))
	{
		goto last;
	}
	else if ((tmp == 'a') | (tmp == 'A'))
	{
		goto solidWorks;
	}
	for (int i = 0; i < sizeof(utools_) / sizeof(utools_[0]); i++)
	{
		system(getUTools(i));
	}
last:
	system("exit");
	return 0;
}