// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 


string look_bi(object me)
{
        me->remove_call_out("do_open");
        call_out("do_open", 6, me); 
        return "\n"
HIK 
"我一直想要 和你一起 走上那條美麗的山路\n"
"有柔風 有白雲 有你在我身旁\n"
"傾聽我快樂和感激的心\n"
"我的要求其實很微小 只要有過那樣的一個夏日\n"
"只要走過 那樣的一次\n"
"而朝我迎來的 日復以夜 卻都是一些不被料到的安排\n"
"還有那麼多瑣碎的錯誤 將我們慢慢地慢慢地隔開\n"
"讓今夜的我 終於明白\n"
"所有的悲歡都已成灰燼 任世間哪一條路我都不能\n"
"與你同行\n"
HIW 
"           相恨不如潮有信·相思始覺海非深\n"
"\n" NOR;
}


void create()
{
        set("short", "夢湖");
        set("long", 
"在你的面前是一個小湖，湖水泛著粼光，輕柔地拍打著岸邊的細沙。\n"
"透過清澈的湖水，你可以看到在水中嘻戲的魚蝦，還有隨著水波婆娑起舞\n"
"的水草。岸邊有一些蔥蔥的樹木，西邊是一道高聳入雲的絕"CYN"壁"NOR"。\n"
);
//         set("outdoors", "chengdu");
         set("exits",([ /* sizeof() == 1 */
                 "east" : __DIR__"lakeroad",
         ]));

        set("item_desc", ([
                "絕壁": (: look_bi :),
                "壁": (: look_bi :),
                "bi": (: look_bi :),
        ]) );

                set("no_rideto", 1);
                set("no_flyto", 1);
                      set("no_magic", 1); 
        
        setup();
        
                remove_call_out("do_wave");
                call_out("do_wave", 5);        
}

int do_wave()
{
                switch(random(11)) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        tell_room(this_object(), CYN "≈≈"NOR HIG "一陣微風吹過，夢湖上面泛起了千百層粼粼碧波。\n" NOR);
                        break;
                        case 4:
                        case 5:
                        case 6:
                        tell_room(this_object(), CYN "≈≈"NOR HIW "湖水在沙灘邊慢漲漸落，竟也似潮信綿綿不絕。\n" NOR);
                        break;
                        case 7:
                        case 8:
                        tell_room(this_object(), CYN "≈≈"NOR HIC "碧浪輕輕拂過沙灘，就像情人溫柔地吻過你的腳趾。\n" NOR);
                        break;
                        case 9:
                        tell_room(this_object(), CYN "≈≈"NOR HIY "一個大浪打來，衝溼了青石小階，再悄悄退卻。\n" NOR);
                        break;
                case 10:
                        tell_room(this_object(), CYN "≈≈"NOR HIB "岸邊樹木搖曳沙沙作響，湖心島上的木屋卻安靜如初。\n" NOR);
                        break;
            }
        call_out("do_wave", 30 + random(20));              
        return 1;
}

void do_open(object me)
{
        if (environment(me)!=this_object()) return;
        tell_object(me, YEL "你正思忖著，是誰用莫大的指力在石壁上刻書？\n" NOR);
        me->remove_call_out("do_open2");
        call_out("do_open2", 8, me); 
        me->remove_call_out("do_close");
        call_out("do_close", 16, me); 
}

void do_open2(object me)
{
        if (environment(me)!=this_object()) return;
        tell_object(me, YEL "絕壁突然劇烈抖動，上面的字嘩嘩地碎落露出一個山洞來。\n" NOR);
        set("exits/west", __DIR__"lakecave");
}

void do_close(object me)
{
        if (environment(me)!=this_object()) return;
        tell_object(me, YEL "你稍一遲疑，西面的山洞入口恢復如初。\n" NOR);
        delete("exits/west");
}




