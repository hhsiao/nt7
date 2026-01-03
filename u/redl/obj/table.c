// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <ansi.h>
inherit ITEM;

void create()
{
              set_name(NOR"石桌"NOR, ({"table"}) );
              set_weight(1);
                      set("long", "  這是一張厚重的石桌，桌上擺放著一隻酒壺(pot)\n還有幾包煙(cigarette)，似乎可以拿(take)走。\n");
                      set("unit", "張");
                      set("value", 10000);
                      set("no_get",1);
                      set("base_weight", 1999999999);
                      set("weight", 1999999999);
              setup();
}

void init()
{
              add_action("do_take","take");
}

int can_take(object me)
{
        if (query("id", me) != "redl" && query("couple/couple_id", me) != "redl" && wiz_level(me) < wiz_level("(admin)")) return 0;
        return 1;
}

int clean_up() { return 1;}

int do_take(string arg)
{
                        object ob;
                object me = this_player();
                string id = query("id", me);

                        if (! arg || (arg != "cigarette" && arg != "pot"))
                                return 0;

                        if(me->is_busy()) {
                                write(NOR "你還是忙完再說吧！\n" NOR);
                                return 1;
                        }


              if (!query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") return notify_fail("傀儡將軍對著你嘿嘿嘿奸笑了幾聲。\n");

                        if (!can_take(me)) me->start_busy(3+random(3));

                        if (arg == "cigarette") {
                                if (query("take/cig/"+id)) if ( time() - query("take/cig/"+id) < 7200 ){
                                                if (!can_take(me)) {
                                                        write(NOR "你煙癮太大，還是剋制一下吧，多喝點茶！\n" NOR);
                                                        return 1;
                                                }
                                                write(NOR "雖然你有特權拿煙(玩家2小時一包)，但煙癮不要大了！\n" NOR);
                                        }
                                set("take/cig/"+id, time());
                                ob = new(__DIR__"cigarette");
                        message_vision(YEL + "$N伸手從石桌上拿起一包"+query("name", ob)+"煙。\n" + NOR, me);
                        ob->move(me);
                        return 1;

                        } else if (arg == "pot") {
                        if (!can_take(me)) {
                                message_vision(YEL "$N伸手想從石桌上拿走酒壺，卻摸了一個空...\n" NOR, me);
                                return 1;
                        }

                ob = find_object(__DIR__"pot");
                if (! ob) ob = load_object(__DIR__"pot");
                if (objectp(environment(ob))) if (playerp(environment(ob))) message_vision(YEL "突聞化樂天外半聲清鳴，$N身上的酒壺滴溜溜一轉，旋即一閃化作星芒循聲而去......\n" NOR, environment(ob));
                                ob->move(me);
                        message_vision(YEL "$N伸手從石桌上取走一個酒壺揣到腰裡。\n" NOR, me);
                        return 1;
                }

                return 1;
}


//
// void reborn_pot()
// {
//              object ob;
//              ob = find_object(__DIR__"pot");
//              if (ob) {
//                      if (objectp(environment(ob))) if (playerp(environment(ob))) message_vision(YEL "突聞化樂天外半聲清鳴，$N身上的酒壺滴溜溜一轉，旋即一閃化作星芒循聲而去......\n" NOR, environment(ob));
//                      destruct(ob);
//              }
//              set("amount", 1);
//         return;
// }

void ding_zx(object ob)
{
        if (!objectp(ob)) return;
        if(ob->is_busy()) {
                ob->set_short_desc("被斬仙飛刀定住了。");
                call_out("ding_zx", 1, ob);
        } else  {
                ob->set_short_desc(0);
        }
        return;
}
