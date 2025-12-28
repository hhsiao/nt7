// skybook.c 十四天書任務相關指令

#include <ansi.h>

#define DB_D          "/adm/daemons/dbd"
#define DIALOG_D      "/adm/daemons/dialogd"
#define SUICONG_D     "/adm/daemons/suicongd"
#define SKYBOOK_D     "/adm/daemons/skybookd"

inherit F_CLEAN_UP;

int help(object me);

mapping skybooks = ([

        "1" : "飛狐外傳:★★★☆",
        "2" : "雪山飛狐:★★★☆",
        "3" : "連城訣:★★★",
        "4" : "天龍八部:★★★★★",
        "5" : "射鵰英雄傳:★★★★★",
        "6" : "白馬嘯西風:★★★",
        "7" : "鹿鼎記:★★★★",
        "8" : "笑傲江湖:★★★★★",
        "9" : "書劍恩仇錄:★★★★",
        "10" : "神鵰俠侶:★★★★★",
        "11" : "俠客行:★★★★☆",
        "12" : "倚天屠龍記:★★★★★",
        "13" : "碧血劍:★★★★☆",
        "14" : "鴛鴦刀:★★★☆",
]);

// 用於對應天書的管理OB，每本天書對應1個管理OB
mapping skybook_id = ([
        "飛狐外傳"    : "feihuwaizhuan",
        "雪山飛狐"    : "xueshanfeihu", 
        "連城訣"      : "lianchengjue", 
        "天龍八部"    : "tianlongbabu",
        "射鵰英雄傳"  : "shediaoyingxiongzhuan",
        "白馬嘯西風"  : "baimaxiaoxifeng",
        "鹿鼎記"      : "ludingji",
        "笑傲江湖"    : "xiaoaojianghu",
        "書劍恩仇錄"  : "shujianenchoulu",
        "神鵰俠侶"    : "shendiaoxialv", 
        "俠客行"      : "xiakexing",    
        "倚天屠龍記"  : "yitiantulongji",
        "碧血劍"      : "bixuejian",
        "鴛鴦刀"      : "yuanyangdao",
]);

void create() 
{
        seteuid(getuid());

}

string Get_Pingjia(int nPoint)
{
        if (nPoint == 1)return "★";
        if (nPoint == 2)return  "★★";
        if (nPoint == 3)return "★★★";
        
        return "未完成";
}

int main(object me, string arg)
{
        string sBook, msg, sDiff, sJindu, sPingjia;
        int i;

        if (! arg)return help(me);
        
        if (arg == "list")
        {
                msg =  HIY "\n你翻開十四天書，發現記載了以下內容…………\n" NOR;
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg +=  sprintf(HIG "%-20s%-20s%-20s%-20s\n" NOR, "天書", "難度", "完成進度", "完成評價");
                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                
                for (i = 0; i < sizeof(skybooks); i ++)
                {
                        sscanf(skybooks[sprintf("%d", i+1)], "%s:%s", sBook, sDiff);
                        // 完成進度，首先判斷是否激活
                        if (! me->query("skybook14/" + sBook + "/激活"))
                        {
                                sJindu = NOR + WHT "未激活" NOR;
                        }
                        else
                        {
                                // 激活了，判斷是否已經接了任務
                                if (! me->query("skybook14/" + sBook + "/當前章節"))
                                        sJindu = HIR "已激活" NOR;
                                else
                                        sJindu = HIG + me->query("skybook14/" + sBook + "/當前章節") + NOR;
                        }

                        sBook = HIG + sBook[0..1] + NOR + sBook[2..(sizeof(sBook)-1)];
                        // 獲取評價
                        sPingjia = Get_Pingjia(me->query("skybook14/" + sBook + "/完成評價"));

                        msg += sprintf("%-36s%-20s%-20s%20s\n", sBook, sDiff, sJindu, sPingjia);
                }

                msg += HIC"----------------------------------------------------------------------------\n" NOR;
                msg += HIY"skybook cha <天書名> 可查看天書詳情\n" NOR;
                msg += HIY"skybook jihuo <天書名> 可激活\n" NOR;
                msg += HIY"skybook reset <天書名> 可重置天書\n" NOR;
                msg += HIY"skybook start <天書名> 可繼續天書任務\n" NOR;                
                write(msg);
                return 1;
        }
        
        if (sscanf(arg, "cha %s", sBook) == 1)
        {
                if (! me->query("skybook14/" + sBook + "/激活"))
                        return notify_fail(sBook + "還未激活，請用 " HIG + "skybook jihuo " + sBook + NOR " 激活\n");
                        
                if (me->query("skybook14/" + sBook + "/當前章節") == 0)
                        return notify_fail(sBook + "還未開始，請用 " HIG + "skybook start " + sBook + NOR " 開始\n");

                msg = HIY + "\n" + sBook + "天書記載了以下內容…………\n" NOR;
                msg += HIC"----------------------------------------------------------------\n" NOR;
                msg += HIY "當前章節：" + me->query("skybook14/" + sBook + "/當前章節") + "\n" NOR;
                msg += HIY "任務描述：" HIG + me->query("skybook14/" + sBook + "/當前任務") + "\n" NOR;
                if (wizardp(me))
                        msg += HIY "任務編號：" + sprintf("%d", me->query("skybook14/" + sBook + "/任務編號")) +  "\n" NOR;
                msg += HIY "任務狀態：" + (me->query("skybook14/" + sBook + "/任務狀態") == 1 ? HIG "已完成" NOR: HIC "進行中" NOR) + "\n" NOR;
                msg += HIY "完成評價：" + (me->query("skybook14/" + sBook + "/當前章節") != "已完成" ? "未完成" : me->query("skybook14/" + sBook + "/完成評價")) + "\n" NOR;
                msg += HIC"----------------------------------------------------------------\n" NOR;
                msg += HIY"任務若完成，可輸入 skybook start " + sBook + " 來交付任務！\n\n" NOR;
                
                write(msg);
                return 1;
        }
        if (sscanf(arg, "jihuo %s", sBook) == 1)
        {
                string *get2kskills, *keys_myskills;
                mapping getmyskills;
                
                if (! wizardp(me))return notify_fail("暫時未開放，敬請期待！\n");
                
                if (me->query("skybook14/" + sBook + "/激活"))
                        return notify_fail(sBook + "已經激活了！\n");
                
                if (! me->query("scborn/ok"))
                        return notify_fail("你還沒有轉世重生，無法激活天書，轉世說明見 help scborn\n");
                
                
                
                // 不同天書不同激活條件
                switch(sBook)
                {
                         case "連城訣":
                                
                         if (me->query("skybook14/" + sBook + "/激活條件"))
                         {
                                if (! me->query_temp("want_jihuo_skybook/" + sBook) )
                                {
                                        me->set_temp("want_jihuo_skybook/" + sBook, 1);
                                        write(HIG "激活" HIY + sBook + HIG "將損耗你的" + HIY + 
                                              CHINESE_D->chinese(me->query("skybook14/" + sBook + "/激活條件")) + HIG +
                                              "100級，如果確定請再輸入一次該指令！\n" NOR);
                                        
                                        return 1;
                                }
                                
                                me->delete_temp("want_jihuo_skybook/" + sBook);
                                
                                // 降低技能，開始激活
                                me->add_skill(me->query("skybook14/" + sBook + "/激活條件"), -200);

                                me->delete("skybook14/" + sBook + "/激活條件");
                                
                                me->set("skybook14/" + sBook + "/激活", 1);
                                
                                write(HIG "天書" HIY + sBook + HIG "已激活，輸入 skybook start + sBook + 開啟序章！\n" NOR);

                                // 初始化
                                me->set("skybook14/" + sBook + "/當前章節", "序章");
                                me->set("skybook14/" + sBook + "/當前任務", "輸入 skybook start " + sBook + " 打開天書序幕吧!");
                                me->set("skybook14/" + sBook + "/任務編號", 1);
                                
                                __FILE__->main(me, "cha " + sBook);

                                log_file("0激活天書.log", me->query("id") + "激活" + sBook + " 降低技能 " + 
                                         me->query("skybook14/" + sBook + "/激活條件") + " at " + ctime(time()) + "\n");
                                
                                return 1;
                         }

                         // 大於1500LV的技能隨機降低200級，若沒有大於1500的技能，則不能激活
                         getmyskills = me->query_skills();                       
                         if (! sizeof(getmyskills))return notify_fail("你連技能都沒有學，還想闖天書？\n");
                         keys_myskills = keys(getmyskills);
                         get2kskills = ({});
                         for (i = 0; i < sizeof(keys_myskills); i ++)
                                if (getmyskills[keys_myskills[i]] >= 1500)
                                        get2kskills += ({keys_myskills[i]});

                        if (! sizeof(get2kskills))
                                return notify_fail("激活連城訣天書至少需要一項技能達到1500級！\n");

                        me->set_temp("want_jihuo_skybook/" + sBook, 1);

                        // 隨機選擇1個需要損耗的技能
                        me->set("skybook14/" + sBook + "/激活條件", get2kskills[random(sizeof(get2kskills))] );

                        write(HIG "激活" HIY + sBook + HIG "將損耗你的" + HIY + 
                              CHINESE_D->chinese(me->query("skybook14/" + sBook + "/激活條件")) + HIG +
                              "200級，如果確定請再輸入一次該指令！\n" NOR);

                        return 1;                       
                        break; // up 連城訣

                        default:
                                return notify_fail(sBook + "天書不存在或暫未開放！\n");

                }// switch
                
                return 1;
        }
        if (sscanf(arg, "start %s", sBook) == 1)
        {
                object obtianshu;
                string sTianshu;
                
                if (me->is_fighting() || me->is_busy())
                        return notify_fail("你正忙著呢，等下再試吧！\n");
                
                if (! me->query("skybook14/" + sBook + "/激活"))
                        return notify_fail(sBook + "還未激活，請用 " HIG + "skybook jihuo " + sBook + NOR " 激活\n");               

                // 交給天書OB管理
                sTianshu = skybook_id[sBook];
                if (! objectp(obtianshu = find_object("/clone/skybook14/" + sTianshu + "/" + sTianshu)))
                        obtianshu = load_object("/clone/skybook14/" + sTianshu + "/" + sTianshu);

                if (! objectp(obtianshu))return notify_fail("天書管理OB錯誤，請聯繫新手導師或管理員處理！\n");

                obtianshu->startbook(me, sBook);
                
                return 1;               
                
        }
        if (sscanf(arg, "reset %s", sBook) == 1)  // 每次重置需要消耗特殊材料
        {
                if (! me->query("skybook14/" + sBook + "/激活"))
                        return notify_fail(sBook + "還未激活，請用 " HIG + "skybook jihuo " + sBook + NOR " 激活\n");   

                if (me->query("skybook14/" + sBook + "/當前章節") != "已完成")
                        return notify_fail(sBook + "還未完成，不能重置！\n");   
                
                // 重置需要消耗SCB
                if (DB_D->query_data("yhshop/scb/" + me->query("id")) < 99)
                {
                        return notify_fail("重置天書需要花費99商城幣，你沒有足夠的剩餘商城幣！\n");
                }
                
                if (! me->query_temp("want_reset_tianshu/" + sBook))
                {
                        write(HIG "重置" + HIY + sBook + HIG "需要花費99商城幣，如果你確定請再輸入一次該指令！\n" NOR);
                        me->set_temp("want_reset_tianshu/" + sBook, 1);
                        
                        return 1;
                }
                
                me->delete_temp("want_reset_tianshu/" + sBook);

                // 扣除SCB
                DB_D->set_data("yhshop/scb/" + me->query("id"), DB_D->query_data("yhshop/scb/" + me->query("id"))-99);

                log_file("0天書重置.log", me->query("id") + " 重置 " + sBook + " at " + ctime(time()) + "\n");
                
                me->delete("skybook14/" + sBook);
                me->save();

                // 重置後不用幫忙激活
                me->set("skybook14/" + sBook + "/激活", 0);

                write("重置" + sBook + "完畢！\n");

                return 1;
        }       
        if (wizardp(me) && sscanf(arg, "enddialog %s %d", sBook, i) == 2)  // 測試指令，用於巫師直接跳過劇情對話
        {
                object obroom;
                
                if (! objectp(obroom = find_object("/clone/skybook14/" + sBook + "/" + sBook)))
                        obroom = load_object("/clone/skybook14/" + sBook + "/" + sBook);                

                obroom->dialog_end(me, i);
                return 1;
        }
}

int help(object me)
{
        write(@HELP
指令格式 : skybook

skybook list                 ：查看十四天書總覽
skybook cha <天書中文名>     ：查看對應的天書詳情
skybook jihuo <天書中文名>   ：激活對應的天書
skybook start <天書中文名>   ：繼續上次未完的天書任務
skybook reset <天書中文名>   ：當天書完成後，可重置天書後重新再做一次該天書任務

HELP );
    return 1;
}
