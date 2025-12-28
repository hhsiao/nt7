// test.c

inherit F_CLEAN_UP;
#include <ansi.h>

#define         CON_DIR         "/kungfu/condition/"

string get_con_name(string coni)
{
        string name;
        
        switch (coni)
        {
                // 毒類
                case "7bug_poison"      : name = "七蟲軟筋散"; break;           
                case "bee_poison"       : name = "玉蜂毒"; break;
                case "bing_poison"      : name = "冰魄銀針毒"; break;
                case "bt_poison"        : name = "怪蛇毒"; break;               
                case "cold_poison"      : name = "寒毒"; break;
                case "fs_poison"        : name = "腐屍毒"; break;
                case "hb_poison"        : name = "寒冰綿掌毒"; break;           
                case "huagu_poison"     : name = "化骨綿掌毒"; break;
                case "hot_poison"       : name = "火毒"; break; 
                case "lvbo_poison"      : name = "綠波香露奇毒"; break;                                         
                case "man_poison"       : name = "蔓陀蘿花毒"; break;
                case "qianli_poison"    : name = "千里銷魂散"; break;
                case "qtlh_poi"         : name = "青陀羅花毒"; break;
                case "qzhu_poison"      : name = "千蛛萬毒手毒"; break;
                case "sanxiao"          : name = "三笑逍遙散毒"; break;
                case "sl_poison"        : name = "神龍毒"; break;
                case "snake_poison"     : name = "蛇毒"; break; 
                case "sxs_poison"       : name = "三笑散之毒"; break;   
                case "sy_poison"        : name = "大手印掌毒"; break;   
                case "tz_poison"        : name = "鐵掌毒"; break;               
                case "warm_poison"      : name = "熱毒"; break;
                case "xx_poison"        : name = "星宿掌毒"; break;
                case "wh_poison"        : name = "神龍五行毒"; break;   
                        
                case "xuanmin_poison"   : name = "玄冥神掌寒毒"; break;
                case "xx_poison"        : name = "星宿掌毒"; break;
                case "wh_poison"        : name = "神龍五行毒"; break;   
                
                // 傷類
                case "broken_arm"       : name = "斷手"; break;
                case "dgb_ban_wound"    : name = "打狗棒腳傷"; break;
                case "fugu_poison"      : name = "化血腐骨粉"; break;
                case "dsy_poison"       : name = "大手印內傷"; break;           
                case "huagong"          : name = "化功大法內傷"; break;         
                case "hunyuan_hurt"     : name = "混元掌內傷"; break;
                case "hyd_condition"    : name = "火焰刀燒傷"; break;
                case "juehu_hurt"       : name = "虎爪絕戶手傷"; break;
                case "neishang"         : name = "內傷"; break;
                case "nxsz_hurt"        : name = "凝血神爪內傷"; break;
                case "qiankun_wound"    : name = "彈指神通內傷"; break;
                case "qishang_poison"   : name = "七傷拳內傷"; break;
                case "ruanjin_poison"   : name = "軟筋散毒"; break;
                case "yyz_hurt"         : name = "一陽指內傷"; break;
                case "yzc_qiankun"      : name = "一指禪內勁"; break;           
                // 忙類
                case "no_exert"         : name = "閉氣"; break;
                case "no_perform"       : name = "封招"; break;
                case "no_force"         : name = "氣息不勻";break;
                //生病類
                case "ill_fashao"       : name = "發燒"; break;
                case "ill_kesou"        : name = "咳嗽"; break;
                case "ill_shanghan"     : name = "傷寒"; break;
                case "ill_zhongshu"     : name = "中暑"; break;
                case "ill_dongshang"    : name = "凍傷"; break;         
//              // 藥類
//              case "bonze_drug"       : name = "少林丹藥"; break;
//              
//              // 其它
//              case "bonze_jail"       : name = "少林監獄"; break;
                case "job_busy"         : name = "任務繁忙狀態"; break;
                case "gb_job_busy"              : name = "頌摩崖任務倒計時"; break;
                case "qzkj_job_busy"            : name = "全真抗金倒計時"; break;
                case "xykm_job_busy"            : name = "襄陽抗蒙倒計時"; break;
                case "hb_job_busy"           : name = "福州鏢局護鏢倒計時"; break;
              case "lfta_job"               : name = "妖氣襲體"; break;
              case "zwf_job_busy"               : name = "夜探趙王府"; break;
               case "db_exp"               : name = "雙倍經驗"; break;
               case "xs_job"               : name = "雪山強搶美女"; break;
case "fuben"               : name = "副本"; break;
                default                 : name = "不詳"; break;
        }
        
        return name;
}

int main(object me,string arg)
{
        object tar, conob;
        int i, p, h, b, m, d;
        string msg, coni, conn, contp,cont;
        mapping cons;
        
        
        
        if (!userp(me)) return 0;
                seteuid(getuid(me));

        if (!arg) tar = me;
        else if (!objectp(tar = present(arg, environment(me)))) {
                if (wizardp(me) ) {
                        if (!tar) tar = LOGIN_D->find_body(arg);
                        if (!tar) tar = find_living(arg);
                        if (!tar) return notify_fail("你要察看誰的特殊狀態？\n");
                        if (wiz_level(me) < wiz_level(tar))
                                return notify_fail("你要察看誰的特殊狀態？\n");
                }
        }

        if (!wizardp(me) && me!=tar)
                return notify_fail("你要察看誰的特殊狀態？\n");

        if (tar->is_corpse() || !tar->is_character())
                return notify_fail("那不是活物耶！\n");
                
//              if ( sizeof(tar->query_entire_conditions()) < 1 )
//              {
//                      tell_object(me, (tar!=me?tar->name(1):"你")+"身上沒有包括任何特殊狀態。\n");
//                      return 1;
//              }

                msg = (tar!=me?tar->name(1):"你")+"身上包含下列特殊狀態：\n";
                msg += "┌────────────────────────┐
│狀態名稱約剩餘時間      類別│
├────────────────────────┤\n";

                cons = tar->query_entire_conditions();
                
                p = 0;
                h = 0;
                b = 0;
                m = 0;
                d = 0;

                for ( i=0; i<sizeof(cons); i++ )
                {
                        coni = keys(cons)[i];
                        conn = get_con_name(coni);
                        if (conn == "不詳")
                                continue;
                        if (values(cons)[i] < 0){
                                tar->clear_condition(coni);
                                continue;
                        }
                        if (values(cons)[i] < 9)
                                cont = chinese_number(values(cons)[i]*15)+"秒";
                        else
                                cont = chinese_number(values(cons)[i]* 2/ 9)+"分";
                        
                        

                        if ( !(conob = find_object(CON_DIR+coni+".c")) )
                                conob = load_object(CON_DIR+coni+".c");
                        
                        if ( !conob )
                        {
                                //msg += sprintf("│%-48s│\n", "狀態文件無法加載："+CON_DIR+coni+".c");
                                continue;
                        }

                        switch (conob->query_type(me))
                        {
                                case "poison" : contp = HIB"毒"NOR; p++; break;
                                case "hurt"   : contp = HIR"傷"NOR; h++; break;
                                case "wound"  : contp = HIR"傷"NOR; h++; break;
                                case "busy"   : contp = HIY"忙"NOR; b++; break;
                                case "job"    : contp = HIY"忙"NOR; b++; break;
                                case "drug"   : contp = HIG"藥"NOR; d++; break;
                                case "illness"   : contp = HIG"病"NOR; h++; break;
                                default       : contp = WHT"？"NOR; m++; break;
                        }
                        

                        msg += sprintf("│%-16s%-24s%|4s│%s\n", conn, cont, contp, wizardp(me)?(coni+".c"):"");
                }

                msg += "└────────────────────────┘\n";
                if (wizardp(me)) msg += sprintf("%51s\n", sprintf("毒：%d傷：%d忙：%d藥：%d其他：%d共：%d",
                                                 p, h, b, d, m, (p+b+h+d+m)));
                if ( (p+b+h+d+m) < 1 )
                        tell_object(me, (tar!=me?tar->name(1):"你")+"身上沒有包括任何特殊狀態。\n");
                else
                        tell_object(me, msg);
                if (tar->is_robot())
                        tell_object(me, HIY+(tar!=me?tar->name(1):"你")+"被判斷為機器人，趕快用robot命令召喚一個出來吧。\n"+NOR);
                else
                        tell_object(me,"當前"+ (tar!=me?tar->name(1):"你")+"沒有被判斷為機器人。\n");
        
        
        return 1;

}

int help(object me)
{
        write(@HELP
指令格式： cond
           cond <對象名稱>             (巫師專用)

這個指令可以顯示你的中毒情況和受傷情況。

HELP
        );
        return 1;
}

