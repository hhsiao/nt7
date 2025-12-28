// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 
string look_stone(object me);

void create()
{
        set("short", "隨風石");
        set("long", 
"這裡是化樂天最高峰，山巔平臺邊上的一塊巨石(stone)，臨淵\n"
"是懸崖萬丈深不見底。極目四望，數千裡方圓海天無際，浮雲聚散如\n"
"夢似幻。你站在這裡懷有種臨風踏雲飄飄欲仙的感覺，不禁生出想"CYN"隨"NOR"\n"
"風而去的念頭。\n"
);
        set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "southdown" : __DIR__"suiroad3",
        ]));

                set("no_fight", 1); 
                set("no_magic", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        
        set("item_desc", ([
                "石": (: look_stone :),
                "巨石": (: look_stone :),
                "stone": (: look_stone :),
        ]) );

        setup();
}

string look_stone(object me)
{
        return 
HIW + "   《雨蟬》\n" + NOR + 
WHT + "  窮秋迷天賜，\n" +  NOR + 
HIW + "  二百八對辭。\n" +  NOR + 
WHT + "  夜半雨鳴蟬，\n" +  NOR + 
HIW + "  顛倒顛醉思。\n\n" +  NOR + 
HIK + "         sui...\n" +  NOR;
}

void init()
{
        add_action("do_sui", ({"sui", "jump"}));
}


int do_sui()
{
        object me = this_player();
        
        if(me->is_busy()) return 1;
        me->start_busy(20);
        
/*semote goodbye
表情 goodbye 之詳細敘述如下：
────────────────────────────────────────
1.無對象無附加文字    ：微風拂過細細的楊柳，在夕陽的映襯之下，離別是那樣的傷感而美麗，淚水在你眼眶之中，遲遲不肯落下……
2.無對象有附加文字    ：微風拂過細細的楊柳，在夕陽的映襯之下，離別是那樣的傷感而美麗，淚水在你眼眶之中，遲遲不肯落下……
3.對象為自己無附加文字：你站在萬丈懸崖的邊上，舉目望去，雲霧繚繞，恍若仙境，
喃喃低語道：“來過，活過，愛過，也不枉此生了”。說罷，縱身躍入那雲霧之中……
4.對象為自己有附加文字：你站在萬丈懸崖的邊上，舉目望去，雲霧繚繞，恍若仙境，
喃喃低語道：“事物，也不枉此生了”。說罷，縱身躍入那雲霧之中……
5.對象為某人無附加文字：你望著某人低聲說道：“要走了嗎？..還回來嗎？...會記得我嗎？...我...我...我會想你的....永遠會！！”
6.對象為某人有附加文字：你望著某人低聲說道：“要走了嗎？..還回來嗎？...會事物嗎？...我...我...我會事物的....永遠會！！”
7.表情註解            ：無註解
8.使用次數            ：20 次
────────────────────────────────────────*/
 
                set_temp("can_redlsuistone", 1, me);
                message_vision(YEL "$N埋頭，踢了踢腳下的巨石。\n" NOR, me);
                call_out("do_sui2", 2, me); 
                return 1;
}

void do_sui2(object me)
{
                switch(query_temp("can_redlsuistone", me))
                {
                        case 1:
                                addn_temp("can_redlsuistone", 1, me);
                                me->command("goodbye " + query("couple/couple_id", me));
                                call_out("do_sui2", 3, me); 
                break;
                        case 2:
                                addn_temp("can_redlsuistone", 1, me);
                                me->command("goodbye " + query("id", me));
                                call_out("do_sui2", 4, me); 
                break;
                        case 3:
                                delete_temp("can_redlsuistone", me);
                                message_vision(YEL "$N的影子越來越遠，隨著清風徐徐往深淵飄去...\n" NOR, me);
                                call_out("do_sui3", 3, me); 
                break;
        }
}

void do_sui3(object me)
{
        me->move(__DIR__"inwind");
}


