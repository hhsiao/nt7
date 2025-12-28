// hanoi.c
// 漢諾塔是一種古老的數學遊戲，有三個底座(base)，一開始
// 所有的盤子都按從小到大的順序從上到下的放在第一個底座
// (base/A)裡。其要求是把第一個底座中的盤子利用第二個底
// 座(base/B)全部移到第三個底座中。其中小的盤子只能放在
// 大的盤子上面，每次只能移動一個盤子。這個題目可以用遞
// 歸的方法求解(最少的完成步數 = 2 ^ 盤子數目 - 1)。

#include <ansi.h>
#define MAX my["max"] // 總共盤子數
#define START my["start"] // 開始遊戲者
#define BASE my["base"] // 底座的狀態
#define STEP my["step"] // 已走的步數

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;

int do_help(string arg);

int query_autoload() { return 1; }
string query_save_file() { return __DIR__ "hanoi/" + query("start"); }

void create()
{
        set_name(HIY "漢諾塔" NOR, ({ "hanoi" }));
        set_weight(100);

        set("long", "這是一套古老數學遊戲漢諾塔的模型。\n");
        set("unit", "套");

        set("base", ([
                "A" : ({ }),
                "B" : ({ }),
                "C" : ({ }),
        ]));
}

// 提供指令
void init()
{
        add_action("do_new", "new");       // 新 遊 戲
        add_action("do_stop", "stop");     // 結束遊戲
        add_action("do_record", "record"); // 保存遊戲
        add_action("do_load", "load");     // 載入遊戲
        add_action("do_move", "move");     // 移動盤子
        add_action("do_help", "help");     // 幫助信息
}

// 顯示目前狀態
string long()
{
        mapping my = query_entire_dbase();
        mapping info;
        string *msg, line, base, long;
        int i, j, max;

        if( !START )
                return my["long"];

        info = ([ ]);
        max = MAX * 2 + 4;
        foreach( base in keys(BASE) ) {
                msg = ({ });
                BASE[base] = sort_array(BASE[base], 1);
                for( i = 0; i < MAX; i++ ) {
                        j = i - (MAX - sizeof(BASE[base]));

                        if( j < 0 )
                                line = repeat_string(" ", (max - 2) / 2) + WHT "│" NOR +
                                repeat_string(" ", (max - 2) / 2);
                        else {
                                line =  repeat_string(" ", (max - BASE[base][j] * 2) / 2) +
                                        CYN + repeat_string("--", BASE[base][j]) + NOR +
                                        repeat_string(" ", (max - BASE[base][j]* 2) / 2);
                        }

                        msg += ({ line });
                }
                info[base] = msg;
        }
        set("info", info);
        long = WHT "現在" + ((! STEP) ? "第一步還沒走"
                : "已經走了 " + STEP + " 步") + "。\n\n" + NOR;

        for (i = 0; i < MAX; i++)
        {
                long += sprintf("%s%s%s\n", info["A"][i], info["B"][i], info["C"][i]);
        }
        return long;
}

int do_new(string arg)
{
        object me = this_player();
        mapping my = query_entire_dbase();
        int i, max;

        if (stringp(START))
                return notify_fail("遊戲已經開始了，你得先停止它。\n");

        if (! arg) max = 3;
        else if (! sscanf(arg, "%d", max) || max > 9)
                return notify_fail("輸入的格式錯誤。\n");

        START=query("id", me);
        MAX = max;
        STEP = 0;
        for (i = 0; i < max; i++)
        {
                BASE["A"] += ({ i + 1, });
        }

        write("遊戲創建完畢，輸入(help here)可以獲得幫助。\n");
        write(long());
        return 1;
}

void end_game()
{
        delete("max");
        delete("start");
        delete("base");
        delete("step");
        set("base", ([
                "A" : ({ }),
                "B" : ({ }),
                "C" : ({ }),
        ]));
}

int do_move(string arg)
{
        object me = this_player();
        mapping my;
        string from, to;

        if (! arg || sscanf(arg, "%s to %s", from, to) != 2)
                return do_help("move");

        if (from == to)
                return notify_fail("你腦潮了？\n");

        my = query_entire_dbase();

        if( query("id", me) != START )
                return notify_fail("你可別亂動。\n");

        if (member_array(from, keys(BASE)) == -1 ||
            member_array(to, keys(BASE)) == -1)
                return notify_fail("底座只可能是" + implode(keys(BASE), "、") + "其中之一。\n");

        if (! sizeof(BASE[from]))
                return notify_fail("底座" + from + "那裡可沒有盤子呀。\n");

        BASE[from] = sort_array(BASE[from], 1);
        BASE[to] = sort_array(BASE[to], 1);

        if (sizeof(BASE[to]) && sizeof(BASE[from]) && BASE[to][0] < BASE[from][0])
                return notify_fail("大的盤子不能放在小的盤子上面。\n");

        tell_object(me, WHT "你把底座" + from + "的" + chinese_number(BASE[from][0])+ "號盤子移動到了底座" + to + "上。\n" NOR);

        BASE[to] = ({ BASE[from][0] }) + BASE[to];
        BASE[from] -= ({ BASE[from][0] });
        STEP++;
        write(long());

        if (sizeof(BASE["C"]) == MAX)
        {
                write(WHT "\n恭喜你完成了遊戲。\n" NOR);
                end_game();
        }

        return 1;
}

int do_stop(string arg)
{
        object me = this_player();
        mapping my;

        my = query_entire_dbase();

        if (! stringp(START))
                return notify_fail("還沒開始呢，結束個啥？\n");

        if( query("id", me) != START )
                return notify_fail("只有遊戲進行者才能結束這個遊戲。\n");

        end_game();
        write(WHT "你結束了當前的遊戲。\n" NOR);
        return 1;
}

int do_record(string arg)
{
        object me = this_player();
        mapping my;

        my = query_entire_dbase();

        if (! stringp(START))
                return notify_fail("還沒開始呢，保存個啥？\n");

        if( query("id", me) != START )
                return notify_fail("只有遊戲進行者才能保存遊戲。\n");

        save();
        write(WHT "當前遊戲保存完畢。\n" NOR);
        return 1;
}

int do_load(string arg)
{
        object me = this_player();
        mapping my;

        my = query_entire_dbase();

        if (stringp(START))
                return notify_fail("遊戲已經開始了，你還是先把它停止吧。\n");

        if( file_size(__DIR__"hanoi/"+query("id", me)+".o") <= 0 )
                return notify_fail("你並沒有保存過遊戲呀。\n");

        START=query("id", me);
        restore();
        write(WHT "上一次的遊戲載入完畢。\n" NOR);
        write(long());
        return 1;
}

int do_help(string arg)
{
switch (arg)
{
case "here":
        write(@HELP
在這裡你可以使用以下這些和漢諾塔相關的命令：
new 開始一局新遊戲
stop 結束這局遊戲
record 保存當前的遊戲
load 載入保存的遊戲
move 移動一個盤子
HELP );
        break;

case "new":
        write(@HELP_NEW
指令格式 : new [盤子數目]

此指令讓你開始一局新的漢諾塔遊戲，當這套漢諾塔已經開始了遊戲
時，你必須先把這個遊戲關閉(stop)。建議你在關閉前保存(record)。
你可以指定遊戲中初始盤子的數目，但最多不得超過 9個，一開始盤
子會全部被放到底座 A中，你需要把它們全部一個個移(move)到底座
C 中就是贏得勝利。注意：大的盤子不得放在小的盤子上面。

相關指令：stop, record, move
HELP_NEW );
        break;

case "stop":
        write(@HELP_STOP
指令格式 : stop

停止這局遊戲，你必須是這局遊戲的進行者才能這麼做。

HELP_STOP );
        break;

case "record":
        write(@HELP_RECORD
指令格式 : record

此指令讓你保存現在正在進行的遊戲以備下次繼續玩，你必須是這局
遊戲的進行者才能這麼做。保存以後可以用(load)在沒有遊戲正在進
行的情況下調入。注意：假如你這個 ID 以前已經保存過遊戲，那麼
會把以前的遊戲檔案覆蓋掉。

相關指令：load
HELP_RECORD );
        break;

case "load":
        write(@HELP_LOAD
指令格式 : load

載入一個你上次玩的遊戲，得先停止(stop)目前的遊戲再說。

相關指令：record, stop
HELP_LOAD);
        break;

case "move":
        write(@HELP_MOVE
指令格式 : move A to B

把底座 A、B、C 中最上面的一個盤子移動到另一個底座中去，大的
盤子不得放在小的盤子上面。當你把底座 A 的所有盤子都移到了底
座 C 中，就會獲勝並結束這局遊戲。
HELP_MOVE );
        break;

default:
        return notify_fail("你要查看什麼幫助？\n");
}

return 1;
}
