/*
https://bbs.csdn.net/topics/380151595
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool existDisk()
{
	char diskPath[5]="C:\\";
	int i;
	DWORD allDisk=GetLogicalDrives(); //����һ��32λ����������ת���ɶ����ƺ󣬱�ʾ����,���λΪA��
	if (allDisk!=0)
	{
	    for (i=0;i<24;i++)	//'C'~'Z'
    	{
    		diskPath[0]='C'+i;
			if (GetDriveType(diskPath)==DRIVE_REMOVABLE)
				return true;
		}
	}
	return false;
}

int main()
{
    int i;
	if (existDisk())
	{
	    for (i=1;i<=5;i++)
            Beep(494,200);
        system("TipMusic.mp3");
		MessageBox(NULL,"u��û��","u��û��",MB_OK);
	}

	return 0;
}
