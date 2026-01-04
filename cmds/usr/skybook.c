// skybook.c 十四天書任務相關指令

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

mapping skybooks = ([

    "1": "飛狐外傳:★★★☆",
    "2": "雪山飛狐:★★★☆",
    "3": "連城訣:★★★",
    "4": "天龍八部:★★★★★",
    "5": "射鵰英雄傳:★★★★★",
    "6": "白馬嘯西風:★★★",
    "7": "鹿鼎記:★★★★",
    "8": "笑傲江湖:★★★★★",
    "9": "書劍恩仇錄:★★★★",
    "10": "神鵰俠侶:★★★★★",
    "11": "俠客行:★★★★☆",
    "12": "倚天屠龍記:★★★★★",
    "13": "碧血劍:★★★★☆",
    "14": "鴛鴦刀:★★★☆"
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
    "鴛鴦刀"      : "yuanyangdao"
    ]);

void create() {
    seteuid(getuid());

}

int main(object me, string arg) {
    string sBook, msg, sDiff, sJindu, sNandu, ssk;
    int i;

    if(!arg ) return help(me);

    if(arg == "list" )
    {
        msg = HIY "\n你翻開十四天書，發現記載了以下內容…………\n" NOR;
        msg += HIC"----------------------------------------------------------------------------\n" NOR;
        msg +=  sprintf(HIG "%-20s%-20s%-20s%-20s\n" NOR, "天書", "難度", "當前狀態", "當前難度");
        msg += HIC"----------------------------------------------------------------------------\n" NOR;

        for(i = 0; i<sizeof(skybooks); i++ )
        {
            sscanf(skybooks[sprintf("%d", i + 1)], "%s:%s", sBook, sDiff);
            // 完成進度，首先判斷是否激活
            if(!query("skybook14/" + sBook + "/激活", me) )
            {
                sJindu = NOR + WHT "未激活" NOR;
            }
            else
            {
                // 激活了，判斷是否已經接了任務
                if(!query("skybook14/" + sBook + "/當前章節", me) )
                    sJindu = HIR "已激活" NOR;
                else
                    sJindu = HIG + query("skybook14/" + sBook + "/當前章節", me) + NOR;
            }

            // 如果完成了大結局，則顯示副本狀態為完成
            if(query("skybook14/" + sBook + "/當前章節", me) == "大結局" )
                sJindu = HIY "已完成" NOR;

            sBook = HIG + sBook[0..1] + NOR + sBook[2..(sizeof(sBook) - 1)];
            // 獲取選擇的難度
            sNandu = query("skybook14/" + filter_color(sBook) + "/難度", me);

            if(sNandu == 0 )sNandu = "未激活";

            sJindu = filter_color(sJindu);


            if(sJindu == "未激活" )
            {
                sJindu = NOR + HIR + sJindu + NOR;
                sNandu = NOR + HIR + sNandu + NOR;
            }
            else if(sJindu == "已完成" )
            {
                sJindu = NOR + HIY + sJindu + NOR;
                sNandu = NOR + HIY + sNandu + NOR;
            }
            else
            {
                sJindu = NOR + HIG + sJindu + NOR;
                sNandu = NOR + HIG + sNandu + NOR;
            }

            msg += sprintf("%-20s%-20s%-20s%-20s\n", sBook, sDiff, sJindu, sNandu);
        }

        msg += HIC"----------------------------------------------------------------------------\n" NOR;
        msg += HIY"skybook cha <天書名> 可查看天書詳情\n" NOR;
        msg += HIY"skybook jihuo <天書名> <少俠級/大俠級/宗師級>   可激活\n" NOR;
        msg += HIY"skybook reset <天書名> 可重置天書\n" NOR;
        msg += HIY"skybook start <天書名> 可繼續天書任務\n" NOR;
        msg += HIC"----------------------------------------------------------------------------\n" NOR;
        msg += HIG"當前剩餘氣運：" +
            sprintf(HIY "%d/%d點" HIG, query("skybook14/option/luck", me), 100) +
            "，每次挑戰天書副本都將消耗３點氣運值\n" NOR;
        msg += HIG"每１２小時（無需在線）可恢復１點氣運值，氣運值上限為１００點。\n" NOR;

        write(msg);
        return 1;
    }

    if(sscanf(arg, "cha %s", sBook) == 1 )
    {
        if(!query("skybook14/" + sBook + "/激活", me) )
            return notify_fail(sBook + "還未激活，請用 " HIG + "skybook jihuo " + sBook + " <少俠級/大俠級/宗師級> " NOR" 激活\n");

        if(query("skybook14/" + sBook + "/當前章節", me) == 0)
            return notify_fail(sBook + "還未開始，請用 " HIG + "skybook start " + sBook + NOR " 開始\n");

        msg = HIY + "\n" + sBook + "天書記載了以下內容…………\n" NOR;
        msg += HIC"----------------------------------------------------------------\n" NOR;
        if(query("skybook14/" + sBook + "/當前章節", me) == "大結局")
        {
            msg += HIR + "《" + sBook + "》已經完成，若需重新開啟，可使用 " HIG + "skybook reset " + sBook + HIR " 重置！\n";
        }
        else
        {
            msg += HIY "當前章節：" + query("skybook14/" + sBook + "/當前章節", me) + "\n" NOR;
            msg += HIY "任務描述：" HIG + query("skybook14/" + sBook + "/當前任務", me) + "\n" NOR;
            //msg += HIY "關卡名稱：" HIG + query("skybook14/" + sBook + "/當前標題", me) + "\n" NOR;
            if(wizardp(me) )
                msg += HIY "任務編號：" + query("skybook14/" + sBook + "/任務編號", me) +  "\n" NOR;
            msg += HIY "任務狀態：" + (query("skybook14/" + sBook + "/任務狀態", me) == 1 ? HIG "已完成" NOR: HIC "進行中" NOR) + "\n" NOR;
            msg += HIY "當前難度：" + query("skybook14/" + sBook + "/難度", me) + "\n" NOR;
        }
        msg += HIC"----------------------------------------------------------------\n" NOR;
        msg += HIY"請輸入 " HIG + "skybook start " + sBook + HIY " 來繼續天書任務！\n\n" NOR;
        write(msg);
        return 1;
    }
    if(sscanf(arg, "jihuo %s %s", sBook, sNandu) == 2 )
    {
        string *get2kskills, *keys_myskills;
        mapping getmyskills;

        if(!wizardp(me) ) return notify_fail("暫時未開放，敬請期待！\n");

        if(query("skybook14/" + sBook + "/激活", me) )
            return notify_fail(sBook + "已經激活了！\n");

        if(query("yuanshen_level", me) < 100 )
            return notify_fail("你還沒有修煉成元神到不滅境界，無法激活天書，修煉元神說明見 help yuanshen\n");


        if(sNandu != "少俠級" && sNandu != "大俠級" && sNandu != "宗師級" )
            return notify_fail("天書的難度選擇只能是 少俠級、大俠級、宗師級中的一項！例如:skybook jihuo 笑傲江湖 宗師級\n");


        // 不同天書不同激活條件
        switch(sBook)
        {
        case "連城訣":
            set("skybook14/" + sBook + "/激活", 1, me);
            set("skybook14/" + sBook + "/難度", sNandu, me);
            set("skybook14/" + sBook + "/任務編號", 1, me);
            break;
        case "笑傲江湖":

            if(query("skybook14/" + sBook + "/激活條件", me) )
            {
                if(!query_temp("pending_skybook/" + sBook, me) )
                {
                    set_temp("pending_skybook/" + sBook, 1, me);
                    write(HIG "激活" HIY + sBook + HIG "將損耗你的" + HIY +
                    CHINESE_D->chinese(query("skybook14/" + sBook + "/激活條件", me)) + HIG +
                    "１００級，如果確定請再輸入一次該指令！\n" NOR);

                    return 1;
                }

                delete_temp("pending_skybook/" + sBook, me);

                // 降低技能，開始激活
                me->add_skill(query("skybook14/" + sBook + "/激活條件", me), -200);

                set("skybook14/" + sBook + "/激活", 1, me);

                write(BLINK + HIG "\n天書" HIY + sBook + HIG "已激活，輸入 skybook start " + sBook + " 開啟序章！\n" NOR);

                // 初始化
                set("skybook14/" + sBook + "/當前章節", "第一章", me);
                set("skybook14/" + sBook + "/當前標題", "路見不平", me);
                set("skybook14/" + sBook + "/當前任務", "輸入 skybook start " + sBook + " 打開天書序幕吧!", me);
                set("skybook14/" + sBook + "/難度", sNandu, me);
                set("skybook14/" + sBook + "/任務編號", "1", me);

                __FILE__->main(me, "cha " + sBook);

                log_file("0激活天書.log", me->query_idname() + "激活" + sBook + " 降低技能 " +
                query("skybook14/" + sBook + "/激活條件", me) + " At " + ctime(time()) + "\n");

                delete("skybook14/" + sBook + "/激活條件", me);
                return 1;
            }

            // 大於1500LV的技能隨機降低200級，若沒有大於1500的技能，則不能激活
            getmyskills = me->query_skillc();
            if(!sizeof(getmyskills) ) return notify_fail("你連技能都沒有學，還想闖天書？\n");
            keys_myskills = keys(getmyskills);
            get2kskills = ({});
            for(i = 0; i<sizeof(keys_myskills); i++ )
                if(getmyskills[keys_myskills[i]] >= 1500 )
                get2kskills += ({ keys_myskills[i] });

            if(!sizeof(get2kskills) )
                return notify_fail("激活《" + sBook + "》天書至少需要一項技能達到１５００級！\n");

            set_temp("pending_skybook/" + sBook, 1, me);

            // 隨機選擇1個需要損耗的技能
            ssk = get2kskills[random(sizeof(get2kskills))];
            if(ssk == "martial-cognize" && random(10) < 7 ) ssk = get2kskills[random(sizeof(get2kskills))];

            set("skybook14/" + sBook + "/激活條件", ssk, me);

            write(HIG "激活" HIY + sBook + HIG "將損耗你的" + HIY +
            CHINESE_D->chinese(query("skybook14/" + sBook + "/激活條件", me)) + HIG +
            "２００級，如果確定請再輸入一次該指令！\n" NOR);

            return 1;
            break;  // up 笑傲江湖

        case "雪山飛狐" :
            break;
        default:
            return notify_fail(sBook + "天書不存在或暫未開放！\n");

        }   // switch

        return 1;
    }

    if(sscanf(arg, "start %s", sBook) == 1 )
    {
        object obtianshu;
        string sTianshu;

        if(me->is_fighting() || me->is_busy() )
            return notify_fail("你正忙著呢，等下再試吧！\n");

        if(!query("skybook14/" + sBook + "/激活", me) )
            return notify_fail(sBook + "還未激活，請用 " HIG + "skybook jihuo " + sBook + NOR " <難度:少俠級/大俠級/宗師級>  來激活\n");

        if(query("skybook14/" + sBook + "/當前章節", me) == "大結局")
            return notify_fail(sBook + "已經完成，若需重新開啟，可使用 " HIG + "skybook reset " + sBook + NOR " 重置！\n");

        // 交給天書OB管理
        sTianshu = skybook_id[sBook];
        if(!objectp(obtianshu = find_object("/adm/daemons/skybook/" + sTianshu)))
            obtianshu = load_object("/adm/daemons/skybook/" + sTianshu);

        if(!objectp(obtianshu) ) return notify_fail("天書管理OB錯誤，請聯繫新手導師或管理員處理！\n");

        // 判斷體力和扣除體力
        if(query("skybook14/option/luck", me) < 3 )
            return notify_fail("當前氣運不足，無法開始天書副本！可使用指令" HIY "ntstore buy luck" NOR "購買氣運全滿（價格見ntstore show other）！\n");

        addn("skybook14/option/luck", -3, me);

        tell_object(me, HIY"\n剩餘氣運：" + sprintf("%d/100", query("skybook14/option/luck", me)) + "\n" NOR);

        obtianshu->startbook(me, sBook);

        return 1;

    }
    if(sscanf(arg, "reset %s", sBook) == 1 )    // 每次重置需要消耗特殊材料
    {
        if(!query("skybook14/" + sBook + "/激活", me) )
            return notify_fail(sBook + "還未激活，請用 " HIG + "skybook jihuo " + sBook + NOR " 激活\n");
        /*
         * if( query("skybook14/" + sBook + "/當前章節", me) != "大結局" )
         * return notify_fail(sBook + "還未完成，不能重置！\n");
         */
        // 重置需要消耗NT
        if(MEMBER_D->db_query_member(me, "money") < 99)
        {
            return notify_fail("重置天書需要花費 99 NT幣，你沒有足夠的剩餘NT幣！\n");
        }

        if(!query_temp("pending_reset/" + sBook, me) )
        {
            write(HIG "重置" + HIY + sBook + HIG "需要花費 99 NT幣，如果你確定請再輸入一次該指令！\n" NOR);
            set_temp("pending_reset/" + sBook, 1, me);

            return 1;
        }

        delete_temp("pending_reset/" + sBook, me);

        // 扣除NT
        MEMBER_D->player_pay(me, 99);

        log_file("0天書重置.log", me->query_idname() + " 重置 " + sBook + " at " + ctime(time()) + "\n");

        delete("skybook14/" + sBook, me);
        me->save();

        // 重置後不用幫忙激活
        set("skybook14/" + sBook + "/激活", 0, me);

        write("重置" + sBook + "完畢！\n");

        return 1;
    }

    if(wizardp(me) && sscanf(arg, "enddialog %s %d", sBook, i) == 2 )   // 測試指令，用於巫師直接跳過劇情對話
    {
        object obroom;

        if (! objectp(obroom = find_object("/adm/daemons/skybook//" + sBook + "/" + sBook)))
            obroom = load_object("/adm/daemons/skybook//" + sBook + "/" + sBook);

        obroom->dialog_end(me, i);
        return 1;
    }
}

int help(object me) {
    write(@HELP
指令格式 : skybook

skybook list                                       ：查看十四天書總覽
skybook cha <天書中文名>                           ：查看對應的天書詳情
skybook jihuo <天書中文名> <少俠級/大俠級/宗師級>  ：激活對應難度的天書
skybook start <天書中文名>                         ：繼續上次未完的天書任務
skybook reset <天書中文名>                         ：當天書完成後，可重置天書後重新再做一次該天書任務

HELP );
    return 1;
}
