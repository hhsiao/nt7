// * TLBB MUDLIB
//* $Header: /home/mud/cvsroot/tlbbmud/tlbb/tlbb_mudlib/t/ly/swing.c,v 1.4 2000/04/15 05:30:46 mud Exp $
// redl 2013/9

#include <ansi.h>
#include <room.h>
#include <transmsg.h>
inherit ROOM;

string look_swing(object me);
string *high_msg = ({
        "嚇得尖聲呼叫“啊～～～”\n",
        "臉色蒼白，緊張得連聲都不敢出了。\n",
        "只覺得頭暈眼花，生怕摔下來。\n",
        "盼著趕緊停下來。\n",
        "大聲叫著“真好玩啊！”\n",
        "顫聲喊道“我怕怕～～～～”\n",
});
string *mid_msg = ({
        "大叫“爽啊！真刺激！”\n",
        "興奮得滿臉通紅，但就是不敢睜眼。\n",
        "似乎還覺得不過癮，還想再高一些。\n",
        "一付很輕鬆的樣子。\n",
        "緊張的汗都出來了。\n",
        "哈哈大笑，從沒這麼高興過。\n",
});
string *low_msg = ({
        "高興的叫個不停。\n",
        "興奮得在鞦韆上手舞足蹈，也不怕摔下來。\n",
        "覺得有點頭暈，不過還可以堅持。\n",
        "不由想起了童年時光。\n",
        "感覺輕鬆自如，還想再高一點。\n",
        "從鞦韆上站了起來，以顯示高超的技術。\n",
});

int clean_up() { return 1;}

int do_clean()
 {
        remove_call_out("do_clean");
        set("enter_num", 0);
        delete_temp("enter_num");
        call_out("do_clean", 3600 + random(1800));
        return 1;
}

int do_gun(object me, int i)
{
                message_vision(NOR + "鞦韆突然無風自動，蕩起來打在$N頭上，將$N打到北方去了。\n" + NOR, me);
                me->move("/d/city/kedian4");
                me->start_busy(i);
                message_vision(NOR + "$N屁滾尿流地從南方滾了過來。\n" + NOR, me);
                me->command("stat");
                tell_object(me, "你一屁股跌坐到地上，半天都爬不起來。\n");
                return 1;
}

void create()
{
        set("short", "鞦韆園");
        set("long",
        "一個廢棄的花園，雜草叢生，落葉繽紛。左邊有一個小石桌，\n"
        "幾尊石凳。右邊有兩棵大樹，樹中間掛著一架"+CYN"鞦韆"NOR+"。一陣風吹過，\n"
        "枯葉在空中飛舞，那曾經熱鬧過的鞦韆也輕輕蕩了起來，彷彿訴\n"
        "說著往日的記憶。\n"
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"kedian4",
                        "northeast" :  "/d/city/qiyuan/xxzl1",
                        "northwest" : "/u/redl/school/gate",
]));
        set("item_desc", ([
                "鞦韆": (: look_swing :),
                "swing": (: look_swing :),
        ]) );
//            set("outdoors", 1);
                set("no_fight", 1);
                set("no_magic", 1);
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_smoke", 1);
                set("no_sleep_room", 1);
                        set("enter_num", 0);

        set("objects", ([
                                                "/u/redl/obj/luckytree" : 1,
                                                     "/adm/npc/btc" : 1,
        ]));

        setup();
        call_out("do_clean", 3600 + random(1800));
                "/clone/board/swing_b"->foo();

}

string look_swing(object me)
{
        return "這是一架用藤條編就的鞦韆(swing)，雖然已久無人用，\n但看起來還結實，可以坐上去(sit)試試，\n也可以抱你心愛的人坐上去(lift)。\n";
}

int do_action(string arg)
{
                int i, time, flag = 0;
        string action = query_verb();
        object me = this_player();

        time = query_temp("cityswing/action_t", me);
        if ((!time) || ( time && (time()-time > 1) )) {
                set_temp("cityswing/action_t", time(), me);
                set_temp("cityswing/action_n", 0, me);
        }
        addn_temp("cityswing/action_n", 1, me);
        i = query_temp("cityswing/action_n", me);

        if (action=="equip" ||
                        arg=="all")
                flag = 1;

        if (action=="news" || action=="member" || action=="ntstore" || action=="combat" || action=="help" || action=="maphere") flag = 0;

        if (flag ||
                i > 6) {
                        do_gun(me, 90);
                        return -1;
                }
        return 0;
}

int is_owner(object me)
{
        /*if (query("id", me) == "redl" ||
                query("id", me) == "gigi" ||
                query("couple/couple_id", me) == "redl" ||
                wiz_level(me) > 6) return 1;*/
        return 0;
}

int do_push2(string arg)
{
        object me,ob;
        me = this_player();
        if(!arg || !objectp(ob = present(arg, environment(me))))
                return notify_fail("你要推誰啊？\n");
        if( arg == query("id", me))return notify_fail("你沒法自己推自己啊。pig...:P\n");
        if( is_owner(ob) ) return notify_fail("你這樣做不太好吧？...:P\n");
        if( query_temp("marks/swingm", ob)){
                message_vision("$N又使勁推了$n一下，鞦韆蕩的飛了起來。\n",me,ob);
                message_vision(RED"$N腳下一個不穩，從鞦韆上跌了下來，摔了個大屁堆兒！\n"NOR,ob);
                remove_call_out("swing_left");
                remove_call_out("swing_right");
                delete_temp("marks/sitted", ob);
                delete_temp("marks/swingm", ob);
                delete("marks/sitted", this_object());
                ob->start_busy(10);
                return 1;
        } else {
                do_gun(ob, 900);
                return 1;
        }
        return 1;
}

void init()
{
        object me = this_player();
        add_action("do_sit", "sit");
                add_action("do_lift", "lift");
        add_action("do_dang", "dang");
        add_action("do_push", "push");
        add_action("do_down", "down");
        if ( !is_owner(me) ) add_action("do_action", "");
        if ( is_owner(me) ) add_action("do_push2", "push2");
}

int do_sit(string arg)
{
        string sitter, id;
        object me,ob;
        me = this_player();
        id = query("id", me);
        if(me->is_fighting()) return notify_fail("一邊打架一邊盪鞦韆？你沒事吧？\n");
        if(me->is_busy()) return notify_fail("你正忙著，沒空蕩鞦韆。\n");
        if(!arg) {
                //write("你想自己即不是紅蓮也不是芝芝，還是(sit swing)再玩吧。\n");
                if (!is_owner(me)) {
                        if ( query("enter_num") > 25 ) {//可能有人試圖想刷
                                                                do_gun(me, 60);
                                return 1;
                        }
                        if ( query("enter_num") > 9 ||
                                (query("online_time", me) < 43200) ||
                                ( (query("enter_id/"+id)) && (time() - query("enter_id/"+id) < 43200) ) ||
                                wiz_level(me) >= wiz_level("(wizard)") ) {
                                if ( (query_temp("enter_num/"+id)) && (query_temp("enter_num/"+id) > 2) ) {//可能有人試圖想刷
                                        do_gun(me, 300);
                                        return 1;
                                }
                                addn_temp("enter_num/"+id, 1);
                                message_vision("$N坐在了地上。\n",me);
                                me->start_busy(3);
                                return 1;
                        }
                        //rnd = random(2);
                        set("enter_id/"+id, time());
                                                addn("enter_num", 1);
                }
                message_vision("$N坐在了地上。\n",me);
                //if (!rnd) {
                                        set_temp("can_enterredlroom", 1, me);
                                        message_vision(YEL + "$N在" + MAG + "相思樹" + YEL + "下迷迷糊糊地睡著了...\n" + NOR, me);
                                        me->move("/u/redl/private_room/dating");
                                        message_vision(YEL + "大片紫青色煙霧聚攏彌散過後，$N來到了神秘的化樂天遺蹟。\n" + NOR, me);
                    //return 1;
                //}
                //me->start_busy(3);
                return 1;
        }
        if(arg != "swing") return notify_fail("你要坐什麼？\n");
        if(query("marks/sitted")) {
                sitter=query("marks/sitted", this_object());
                ob = present(sitter,environment(me));
                if( (ob) && (query_temp("marks/sitted", ob))){
                        write("鞦韆上已經有人了。\n");
                        return 1;
                }
        }
        message_vision("$N坐到了鞦韆上面。\n", me);
        write("你可以自己盪鞦韆(dang)，也可以讓別人推一把(push)。\n");
        set("marks/sitted",query("id", me));
        set_temp("marks/sitted", 1, me);
        return 1;
}

int do_lift()
{
        string sitter;
        object me,ob;
        me = this_player();
        if(query("marks/sitted")) {
                sitter=query("marks/sitted", this_object());
                ob = present(sitter,environment(me));
                if( (ob) && (query_temp("marks/sitted", ob))){
                        write("鞦韆上已經有人了。\n");
                        return 1;
                }
        }
        sitter = query("couple/couple_id", me );
        if (!sitter) {
                 write("你還沒有愛人。\n");
                 return 1;
        }
        ob = present(sitter, environment(me));
        if (!objectp(ob)) {
                 write("你想抱誰上鞦韆？\n");
                 return 1;
        }
        if( !ob->is_character() || query("not_living", ob) ) {
                 write("看清楚了，那不是活人！\n");
                 return 1;
        }
        message_vision("$N輕輕抱起$n放到了鞦韆上面。\n", me,ob);
        tell_object(ob, "你可以自己盪鞦韆(dang)，也可以讓別人推一把(push)。\n");
        set("marks/sitted",query("id", ob));
        set_temp("marks/sitted", 1, ob);
        return 1;
}

int do_dang()
{
        int i;
        object me;
        me = this_player();
        if(me->is_fighting()) return notify_fail("一邊打架一邊盪鞦韆？你沒事吧？\n");
        if(me->is_busy()) return notify_fail("你正忙著，沒空蕩鞦韆。\n");
        i=query_temp("marks/swingm", me);
        if( !query_temp("marks/sitted", me) )
        return notify_fail("你還沒坐到鞦韆上。\n");
        if( !query_temp("marks/swingm", me)){
                message_vision("$N腳下一使勁，鞦韆緩緩的蕩了起來。\n",me);
                set_temp("marks/swingm", 3, me);
                call_out("swing_left",7,me);
                return 1;
        }
        if( query_temp("marks/swingm", me)>9){
                message_vision("$N腳下再一使勁，鞦韆蕩的飛了起來。\n",me);
                message_vision(RED"$N腳下一個不穩，從鞦韆上跌了下來，摔了個大屁堆兒！\n"NOR,me);
                remove_call_out("swing_left");
                remove_call_out("swing_right");
                delete_temp("marks/sitted", me);
                delete_temp("marks/swingm", me);
                delete("marks/sitted", this_object());
                return 1;
        }

        message_vision(YEL"$N使勁蕩了一下，鞦韆蕩的更高更快了！\n"NOR,me);
        i = i + 3;
        set_temp("marks/swingm", i, me);
        remove_call_out("swing_left");
        remove_call_out("swing_right");
        call_out("swing_left",10-i,me);
        return 1;
}

int do_push(string arg)
{
        int i;
        object me,ob;
        me = this_player();
        if(me->is_fighting()) return notify_fail("一邊打架一邊盪鞦韆？你沒事吧？\n");
        if(me->is_busy()) return notify_fail("你先把手頭的事忙完再說吧。\n");
        if(!arg || !objectp(ob = present(arg, environment(me))))
                return notify_fail("你要推誰啊？\n");
        if( arg == query("id", me))return notify_fail("你沒法自己推自己啊。pig...:P\n");
        if( !query_temp("marks/sitted", ob) )
                return notify_fail("對方不在鞦韆上，你沒法推。\n");
        if(ob->is_fighting()) return notify_fail("一邊打架一邊盪鞦韆？你沒事吧？\n");
        if(ob->is_busy()) return notify_fail("對方正忙著呢。\n");
        i=query_temp("marks/swingm", ob);
        if( !query_temp("marks/swingm", ob)){
                message_vision(YEL"$N輕輕推了$n一下，鞦韆緩緩蕩了起來。\n"NOR,me,ob);
                set_temp("marks/swingm", 3, ob);
                call_out("swing_left",7,ob);
                return 1;
        }
        if( query_temp("marks/swingm", ob)>9){
                message_vision("$N又使勁推了$n一下，鞦韆蕩的飛了起來。\n",me,ob);
                message_vision(RED"$N腳下一個不穩，從鞦韆上跌了下來，摔了個大屁堆兒！\n"NOR,ob);
                remove_call_out("swing_left");
                remove_call_out("swing_right");
                delete_temp("marks/sitted", ob);
                delete_temp("marks/swingm", ob);
                delete("marks/sitted", this_object());
ob->set_short_desc(0);

                return 1;
        }

        message_vision(YEL"$N又輕輕推了$n一下，鞦韆蕩的更高更快了！\n"NOR,me,ob);
        i = i + 3;
        set_temp("marks/swingm", i, ob);
        remove_call_out("swing_left");
        remove_call_out("swing_right");
        call_out("swing_left",10-i,ob);
        return 1;
}
int do_down()
{
        object me;
        me = this_player();
        if( !query_temp("marks/sitted", me) )
        return notify_fail("這個方向沒有出路。\n");
        message_vision("$N從搖盪的鞦韆上蹦了下來。\n",me);
        remove_call_out("swing_left");
        remove_call_out("swing_right");
        delete_temp("marks/sitted", me);
        delete_temp("marks/swingm", me);
        delete("marks/sitted", this_object());
me->set_short_desc(0);

        return 1;
}

void swing_left(object me)
{
        int i;
        string msg;
        i=query_temp("marks/swingm", me);
        if(i>0) {
                if(i>3) {
                        if(i>6) {
                                msg = "鞦韆向前蕩的又高又直，$N"+high_msg[random( sizeof( high_msg ))];
                                message_vision(msg,me);
                                call_out("swing_right",10-i,me);
                                return;
                        }
                        msg = "鞦韆飛一樣向前蕩去，$N"+mid_msg[random( sizeof( mid_msg ))];
                        message_vision(msg,me);
                        call_out("swing_right",10-i,me);
                        return;
                }
                msg = "鞦韆緩緩向前蕩去，$N"+low_msg[random( sizeof( low_msg ))];
                message_vision(msg,me);
                call_out("swing_right",10-i,me);
                return;
        }
}

void swing_right(object me)
{
        int i;
        string msg;
        i=query_temp("marks/swingm", me);
        i = i-1;
        if(i<1) {
                message_vision("鞦韆緩緩停了下來，$N意猶未盡的走下鞦韆。\n",me);
                delete_temp("marks/sitted", me);
                delete_temp("marks/swingm", me);
                delete("marks/sitted", this_object());
                return;
        }
        set_temp("marks/swingm", i, me);
        if(i>0) {
                if(i>3) {
                        if(i>6) {
                                msg = "鞦韆向後蕩的又快又猛，$N"+high_msg[random( sizeof( high_msg ))];
                                message_vision(msg,me);
                                call_out("swing_left",10-i,me);
                                return;
                        }
                        msg = "鞦韆高高的向後蕩去，$N"+mid_msg[random( sizeof( mid_msg ))];
                        message_vision(msg,me);
                        call_out("swing_left",10-i,me);
                        return;
                }
                msg = "鞦韆緩緩向後蕩去，$N"+low_msg[random( sizeof( low_msg ))];
                message_vision(msg,me);
                call_out("swing_left",10-i,me);
                return;
        }
}

int valid_leave(object me, string dir)
{
        if( query_temp("marks/sitted", me) )
        return notify_fail("你先要從鞦韆上下來(down)才能離開。\n");
        return ::valid_leave(me, dir);
        return 1;
}
