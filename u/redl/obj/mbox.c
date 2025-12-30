// This program is a part of NITAN MudLIB 
// redl 2013/5 
// 私有，小心被利用刷屏和幹擾機器人

#include <ansi.h>
inherit ITEM;


int start_make(object me);
void save_music(string str);

int timeintervals = 3, idx = 0, imax;
string *text = ({});
string qz = "  ∽ ";

void create()
{
        set_name(WHT "音樂盒" NOR, ({"music box", "box"}));
        set_weight(1);
                set("longx", WHT"這是塊拇指大小的檀木，上面橫託著個白銀的核桃，核桃的根\n"
                                           "部伸出來一個小巧的果柄，檀木底部刻著“paroles et musique”。\n"
                                        HIK"(指令：mplay、 mmake、 mdelay)\n"NOR);
                set("unit", "個");
                set("material", "silver");
                set("value", 2000000000);
                set("nj", 20); 
                set("set_data", 1); 
                set("auto_load", 1); 
}

string long()
{
        string *t = query("content");
        int i = sizeof(t);
        if (i < 1) return query("longx") + qz + "空白……\n" + NOR; 
                else return query("longx") + qz + t[0] + "\n" + NOR; 
}

int init()
{
        add_action("do_make", "mmake");
        add_action("do_delay", "mdelay");   
        add_action("do_play", "mplay");   
}

int do_delay(string arg)
{
        if (!arg && arg!="+" && arg!="-") return notify_fail("格式：mdelay + 或者 mdelay -\n"); 
        if (query("timeintervals")) timeintervals = query("timeintervals");
        if (arg=="+") {
                if (timeintervals<9) {
                        timeintervals += 1;
                set("timeintervals", timeintervals);
                }
                return notify_fail("當前播放間隔："+chinese_number(timeintervals)+"秒\n"); 
        }
                if (timeintervals>1) {
                        timeintervals -= 1;
                set("timeintervals", timeintervals);
                }
                return notify_fail("當前播放間隔："+chinese_number(timeintervals)+"秒\n"); 
}


int do_make(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        //if( !arg && arg!="music box" && arg!="box") return 0;

    message_vision(YEL"$N拿出一個銀白色的" + query("name") + YEL "..\n"NOR,me);
    start_make(me);
    return 1;
}


int start_make(object me)
{
        //write("為我寫一首歌嗎？:\n");
        me->edit( (: save_music :) );
        return 1;
}

void save_music(string str)
{
        if (strlen(str)>8192) {
                write(NOR "太臭太長了。\n");
                return;
        }
        message_vision(YEL"$N在" + query("name") + YEL "裡錄入了一首歌。\n"NOR, this_player());
                text = explode( str, sprintf("%c", 10) );
        set("content", text);
}

int do_play(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        //if( !arg && arg!="music box" && arg!="box") return 0;
        if (query_temp("starting")) return notify_fail("這個盒子已經在播放音樂了。\n"); 
        if (query("nj") < 1) return notify_fail("這個盒子已經壞了。\n"); 
        
        addn("nj", -1);
        addn("value", -100000000);
        
        text = query("content");
        imax = sizeof(text);
        if (imax < 1) return notify_fail("請先用 mmake 錄入\n"); 
        
    message_vision(YEL"$N拿出一個"WHT"核桃"YEL"輕輕地搖動果柄，\n"
                                "一陣悅耳動聽的歌聲緩緩的流進你的耳朵...\n"NOR,me);
    idx = 0;
    if (query("timeintervals")) timeintervals = query("timeintervals");
    set_temp("starting", 1);
    set("no_give", "請讓音樂播放完成...");
    set("no_store", "請讓音樂播放完成...");
    set("no_drop", "請讓音樂播放完成...");
    set("no_sell", "請讓音樂播放完成...");
    set("no_steal", "請讓音樂播放完成...");
    set("no_beg", "請讓音樂播放完成...");
    //message_vision(NOR, me);
    call_out("start_play", timeintervals, me);
    return 1;
}

int start_play(object me)
{
        if (idx < imax) {
                message_vision(NOR + HIK + qz + NOR + text[idx] + "\n" + NOR, me);
                call_out("start_play", timeintervals, me);
        }
                else {
                        //message_vision(NOR + HIK + qz + NOR + "(ending...)\n" + NOR, me);
                    delete("no_give");
                delete("no_store");
                delete("no_drop");
                delete("no_sell");
                delete("no_steal");
                delete("no_beg");
                        delete_temp("starting");
                    message_vision(YEL"$N停止了搖動果柄，一種空落的感覺湧上心頭。\n"NOR,me);
                    tell_object(me, NOR "剩餘播放次數：" + chinese_number(query("nj")) + "次。\n" NOR);
                }
        idx += 1;
        return 1;
}



