#include <ansi.h>
inherit ROOM;
string look_notice();

void create()
{
        set("short", "華山絕頂");
        set("long", @LONG
[1；37m                                                   武林大
會廣場                                                      
  登上此處，只覺眼前是一方圓數十丈的平臺，中央有一凸起約丈高
的石臺，岩石上刻著歷界華山論劍的排行榜(notice)；空坪的東側立
有一丈許高的紫檀木架，架著一面血紅色的大鼓，比武開始後，臺上
會遞出一塊牌子(paizi)，向你展示當前比武的賽程；峰頂四周雲霧飄
渺，彷彿置身大海，眾山猶如海中小島，環繞著主峰，仿如一朵盛開
的蓮花。[2；37；0m
LONG );
        set("item_desc", ([ /* sizeof() == 1 */
                "大鼓" : "這是一隻牛皮製成的巨鼓，武林人士在華山論劍時敲響(knock)它開始比武。",
                "notice" : (: look_notice :),
        ]));
        set("exits", ([ /* sizeof() == 2 */
                "southdown" : "/d/huashan/houzhiwangyu",
        ]));
        
        set("outdoors", "huashan" );

        set("no_fight", 1);
        set("no_quit", 1);
        set("objects", ([
                // "/clone/misc/drum2" : 1,
        ]));
        setup();
}
void init()
{
        object me = this_player();
        add_action("get_weapon", ({ "na", "qu", })); 
        add_action("discmds", ({
                "respitate", "exert", "array", "ansuan", "touxi", "persuade", 
                "teach", "exert", "exercise", "study", "learn", "sleep", "kill",
                "steal", "cast", "conjure", "expell", "fight", "hit", "perform", 
                "prcatice", "scribe", "surrender", "sha", "recall", "quit", "exit"}));
        call_out("do_recover", 1, me);
}
void do_recover(object me)
{
        if (! me || environment(me) != this_object()) return;
                delete("no_get", me);
        if (! living(me)) me->revive();
        set("eff_jing",query("max_jing",  me), me);
        set("jing",query("max_jing",  me), me);
        set("eff_qi",query("max_qi",  me), me);
        set("qi",query("max_qi",  me), me);
        if( query("neili", me)<query("max_neili", me) )
                set("neili",query("max_neili",  me), me);
        if( query("jingli", me)<query("max_jingli", me) )
                set("jingli",query("max_jingli",  me), me);
        me->clear_condition();
        set("food", me->max_food_capacity(), me);
        set("water", me->max_water_capacity(), me);
        me->start_busy(0);
}
int discmds()
{
        tell_object(this_player(), "現在你還是專心看比武吧！\n");

        return 1;
}
int get_weapon(string arg)
{
        object me, ob;
        
        me = this_player();
        
        if (! arg) return notify_fail("你要拿取什麼物品？\n");
        
        switch (arg) 
        {
        case "cloth":
                ob = new("/clone/cloth/cloth");
                break;
        case "sword":
                ob = new("/clone/weapon/changjian");
                break;
        case "blade":
                ob = new("/clone/weapon/blade");
                break;
        case "staff":
                ob = new("/clone/weapon/zhubang");
                break;
        case "whip":
                ob = new("/clone/weapon/changbian");
                break;
        case "hammer":
                ob = new("/clone/weapon/hammer");
                break;
        default:  
                return notify_fail("你要拿取什麼物品？\n"); 
                break;
        }
        
        ob->move(me);
        
        tell_object(me, "你從架上拿下了你需要的物品。\n");
        return 1;
}
        
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j = 0, k;
        
        who = this_player();
        file = read_file("/log/static/lunjian");
        if (! file)
                return "目前沒有任何比武記錄。\n";
        name_list = explode(file,"\n");
        for (i = 0; i < sizeof(name_list); i++) 
        {
                if (name_list[i] == "seperator") 
                {
                        j++;
                        k = 0;
                        printf("\n第" + chinese_number(j) + "屆華山論劍結果：\n");
                        continue;
                }
                k++;
                printf(GRN "第" + chinese_number(k) + "名：%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}
