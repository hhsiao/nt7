inherit ROOM; 
#include <ansi.h> 
void create()
{
    set("short", "三清湖");
    set("long",
"[1;32m湖水清澈透明，不時可以看到幾尾魚跳上水面。湖水盡頭是\n"
"一個大瀑布。在這裡可以聽到瀑布從山上直衝而下，發出的轟轟雷聲。湖\n"
"邊一塊巨石，上寫＂三清湖＂。[2;37;0m\n"
);
    set("item_desc", ([
        "清潭":  "清潭明澈見底，裡面小魚小蝦皆若空遊無所依。\n",
        "pond":  "清潭明澈見底，裡面小魚小蝦皆若空遊無所依。\n",
      ]));
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"taolin", 
        "northwest" : __DIR__"pond", 
        "southwest" : __DIR__"lake2", 
        "west" : __DIR__"lake",
      ]));
}

void fish_notify(object obj, int i)
{
    object me, room, fish, *inv, bait;

    me = this_player();

    switch (i) { 
    case 0:
        bait = present("qiu yin", obj);
        if(!objectp(bait)) {
            message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
            tell_object(me, obj->name() + "上沒有餌怎麼可以釣魚呢？ \n");
        }
        else {
            message_vision("$N揮動了一下，" + obj->name() + "在空中劃了一道漂亮的弧線，魚鉤落入了水中。 \n" , me);
            destruct(bait);
            remove_call_out("do_fishing");              
            call_out("do_fishing", 5, me);
        }
        break;
    }
    return;
}

void do_fishing(object me)
{
    object       fish;

    if(me && environment(me) == this_object()) {
        message_vision("$N很快又扯動了一下魚杆， " , me);
        switch (random(3)) {
        case 0:
            message_vision("卻什麼都沒釣上來！ \n", me);
            break;
        case 1:
            message_vision("魚怪被釣上來啦！！！！ \n", me); 
            fish = new("/quest/tulong/obj/fish1");
            set_temp("m_success/魚怪", 1, me);
            fish->move(environment(me));
            remove_call_out("kill_me");
            call_out("kill_me", 1, me);         break;
        case 2:
            message_vision("魚鉤上釣著一條大魚！！ \n", me);
            fish = new("/quest/tulong/obj/fish");
            fish->move(me);
            break;
        }
    }
    return;
}
