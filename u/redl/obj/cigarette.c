// cigarette.c  by Jane  4.12.1997
// redl 2013/6
#include <ansi.h> 
inherit ITEM;

int smoking(int);

void create()
{
        string *order = ({"紅河", "南京", "黃鶴樓", "利群", "蘇煙"});
        set_name( (order[random(5)]), ({ "cigarette" }) );
        set_weight(80);
                set("long", "一盒香菸，可以(xiyan)。\n");
                set("unit", "盒");
                set("count",12);
                set("value", 200000000);
                set("set_data", 1);  
                set("auto_load", 1); 
                set("no_sell", "多好的煙啊，賣掉多可惜，趕緊抽掉吧..."); 
}

void init()
{
        add_action("do_smoke", "xiyan");
}

void call_pond(object me)
{
        call_other("/u/redl/obj/cigarette_c", "chk_pond", me );
        destruct(this_object());
}

int do_smoke()
{
                int stp, lh = 4 + random(3);
        object me = this_player();
        object obj = this_object();

        if( query("no_smoke", environment(me)) && (wiz_level(me) < wiz_level("(wizard)")) )
                return notify_fail("這裡不準抽菸！\n");

        if( me->is_busy() ) {
                        me->command("cough");
                return 1;
        }
                
        if(query("count") == 12) 
                message_vision("$N抽出一支$n，點著了火，美滋滋地吸了起來。\n", me, this_object());
        else if (query("count") <= 1 ) {
                message_vision(YEL "$N把剩下的菸蒂摁熄在掌心裡，真是內力深厚呀。\n" NOR, me, obj);
                            set("no_give", "菸蒂粘在你的手掌上了...");
                        set("no_store", "菸蒂粘在你的手掌上了...");
                        set("no_drop", "菸蒂粘在你的手掌上了...");
                        set("no_sell", "菸蒂粘在你的手掌上了...");
                        set("no_steal", "菸蒂粘在你的手掌上了...");
                        set("no_beg", "菸蒂粘在你的手掌上了...");
                call_out("call_pond", 1, me);
                me->start_busy(3);
                return 1;
        } else 
        switch(random(12)) {
                case 0: 
                case 1: 
                                message_vision(HIK "$N食指輕輕敲動$n，菸灰積落菸缸裡，猶如一堆灰色的雪。\n" NOR, me, obj );
                                addn("magic_points", lh, me); 
                                write(NOR + "恭喜你吸菸有成，增加了" + chinese_number(lh) + "點靈慧！\n" + NOR);
                        break;
                case 2: 
                                if (time()-query("last_time") < 1+random(2)) {
                                        message_vision(YEL "$N狠狠的吸了一口$n，大概是吸得太快了，一張臉漲的通紅。\n" NOR, me, obj);
                                        me->start_busy(25 + random(6));
                                } else {
                                        message_vision(HIK "$N輕輕一嘆，手裡的菸頭上火星忽明忽暗，心思也晦澀難辯。\n" NOR, me );
                                        addn("magic_points", lh*3, me); 
                                        write(NOR + "恭喜你吸菸悟道，增加了" + chinese_number(lh*5) + "點靈慧！\n" + NOR);
                                }
                        break;
                default:
                                addn("stp", 1);
                                stp = query("stp");
                                switch(stp) {
                                        case 1: 
                                                message_vision(NOR "$N吐出一串菸圈，看著它們往天上一個接一個地飄散開. \n" NOR, me);
                                        break;
                                        case 2: 
                                                message_vision(NOR "$N吐出一串菸圈，看著它們往天上一個接一個地飄散開. 。\n" NOR, me);
                                        break;
                                        case 3: 
                                                message_vision(NOR "$N吐出一串菸圈，看著它們往天上一個接一個地飄散開. 。o\n" NOR, me);
                                        break;
                                        case 4: 
                                                message_vision(NOR "$N吐出一串菸圈，看著它們往天上一個接一個地飄散開. 。o O\n" NOR, me);
                                        break;
                                        default:
                                                message_vision(NOR "$N輕輕呼出一股青煙，在氤氳中靜默著，好像一隻呆鳥。\n" NOR, me);
                                                if (random(3)) set("stp", 0);
                                        break;
                                }
                        break;
        }
        addn("count",-1);
        set("last_time", time());
        return 1;
}



