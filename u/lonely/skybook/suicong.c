cat suicong.c
// 隨從系統

#include <ansi.h>
inherit F_CLEAN_UP;

#define SUICONG_D    "/adm/daemons/suicongd"

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{

        string arg1, arg2, arg3;
        if (! arg)return help(me);
        
        
        if (! find_object(SUICONG_D))load_object(SUICONG_D);
        
        // 顯示所有可以獲得隨從列表
        if (arg == "list")
        {
                return SUICONG_D->show_suicong(me);             
        }
        
        // 查看指定隨從
        if (sscanf(arg, "cha %s", arg1) == 1)
        {
                return SUICONG_D->show_suicong_target(me, arg1);
        }
        // 查看指定玩家的指定隨從
        if (sscanf(arg, "chaplayer %s %s", arg1, arg2) == 2)
        {
                object ob = find_player(arg1);
                if (! ob)return notify_fail("玩家不存在！\n");
                                
                return SUICONG_D->show_suicong_target(ob, arg2);
        }
        // 召喚隨從     
        if (sscanf(arg, "sum %s", arg1) == 1)
        {
                return SUICONG_D->summon_suicong(me, arg1);
        }
        // 隱藏隨從
        if (arg == "hide")
        {
                return SUICONG_D->hide_suicong(me, arg1);
        }
        // 測試開發期間使用，玩家可領取2名隨從體驗
        if (arg == "tiyan")
        {
                SUICONG_D->give_suicong(me, "少俠·平一指");

                write(HIG "領取了【少俠·平一指】，請使用 suicong sum 少俠·平一指 召喚！\n" NOR);
                return 1;
        }
}

int help(object me)
{
        string sMsg;
        
        write(@TEXT              
        
=--------------------------------------------------------------------------------------=
        隨從系統控制指令  >>

        suicong                   查看指令說明和當前召喚出的隨從
        suicong list              查看所有已經開放的隨從
        suicong cha 隨從名        查看指定隨從的詳細信息
        suicong sum 隨從名        召喚指定隨從出戰，召喚後會替換掉當前已出戰的隨從
        suicong hide 隨從名       將召喚出來的隨從收回
        suicong tiyan             領取1名隨從進行體驗，正式開放後會刪除
TEXT);  
        
        if (wizardp(me))
        {
                write("\n        suicong chaplayer ID 隨從名   ： 可查看指定玩家指定的隨從屬性\n");
        }
        
        
        sMsg = "\n=--------------------------------------------------------------------------------------=\n";
        sMsg+= "當前召喚出的隨從有：" + HIG + SUICONG_D->get_sum(me) + "\n" NOR;
        sMsg+=   "=--------------------------------------------------------------------------------------=\n";
        write(sMsg);
        return 1;
}
