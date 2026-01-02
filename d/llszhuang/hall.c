#include <ansi.h>
inherit ROOM;
string *s1 = ({ "問", "蒼", "茫", "大", "地", "誰", "主", "沉", "浮", "數", "風", "流",
    "人", "物", "還", "看", "今", "朝", "江", "山", "如", "此", "多", "嬌"});
void create() {
    set("short", YEL"山莊正廳"NOR);
    set("long",
        "你人尚未到，一絲淡淡的清香已自沁入你的心脾。走進大廳，迎面是\n"
        "一幅極大的潑墨山水，墨跡縱橫淋漓，筆鋒崢嶸有致。畫面上繪的是山河\n"
        "社稷圖，東起茫茫大海，西至皚皚雪山，氣勢不凡，令人頓生仰止之感，\n"
        "旁邊是一幅對聯：「問蒼茫大地誰主沉浮[2;37;0m數風流人物還看今朝\n"
        "」[2;37;0m[2;37;0m橫批：江山如此多嬌[2;37;0m整座大廳雖然富麗\n"
        "堂皇，氣勢恢宏，可是你總感覺有點不太協調的地方。似乎和你一路所見\n"
        "所聞不太相象。你是不是應該好好(think)呢，然後再進去？\n"
    );

    set("exits", ([ /* sizeof() == 2 */
        "south": __DIR__"dynamic/jiuqu16",
        "north": __DIR__"neishi"
        ]));
    set("no_magic", "1");

    setup();
}

int init() {
    add_action("do_think", "think");
    add_action("do_uncover", "uncover");
}

int do_think(string arg) {
    object me;

    me = this_player();
    if(random(query("int", me))<20 )
    {
        write("你想啊想，結果想破了腦袋，白白的腦漿流了一地。\n");
        me->receive_damage("jing", 100);
    }
    else
    {
        write("你悶頭苦思，突然發現地上有一塊方磚(brick)似乎邊緣特別的光
            滑。好象可以(uncover)\n");
        set_temp("marks/xanadu_hall1", 1, me);
    }
    return 1;
}

int do_uncover(string arg) {
    object me;
    int i, j, k, l;

    me = this_player();
    if(!arg || arg != "brick" || !query_temp("marks/xanadu_hall1", me))     // || wizardp(me) )
        return 0;
    message_vision(GRN"$N小心翼翼地把地板磚揭開，只聽“叮”的一聲輕響...\n"NOR, me);
    if(random(10) > 5 ) {
        message_vision(RED"一蓬牛毛細針向$N射來，正好命中，只聽你一聲慘嚎，細針已在你胸前對穿而過。\n"NOR, me);
        me->receive_wound("qi", random(query("kar", me))*50);
        COMBAT_D->report_status(me, me, 1);
    }
    else
        message_vision(RED"一蓬牛毛細針向$N射來，$N輕鬆的躲了開去。\n"NOR, me);
    if(query("qi", me)>100 )
    {
        delete_temp("marks/xanadu_hall1", me);
        i = random(9);
        j = random(9);
        k = random(6);
        l = random(6);
        set_temp("marks/xanadu_hall2", l*1000 + k*100 + j*10 + i, me);
        write("你驚魂甫定，發現地板翻起來的背面刻著一行小字："+s1[i] + s1[9 + j] + s1[18 + k] + s1[18 + l] + "\n");


    }
    return 1;
}
